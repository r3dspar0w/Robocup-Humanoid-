#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <filesystem>
#include <functional>
#include <memory>
#include <mutex>
#include <string>
#include <vector>

#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"
#include "booster_interface/msg/low_cmd.hpp"
#include "booster_interface/msg/low_state.hpp"

#ifdef MOTION_CONTROL_HAVE_ONNX_RUNTIME
#include <onnxruntime_cxx_api.h>
#endif

namespace {

constexpr size_t kMotorCount = 23;

constexpr std::array<float, kMotorCount> kActionScales = {
        0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
        0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f,
        0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f,
};

constexpr std::array<float, kMotorCount> kDefaultStiffness = {
        12.f, 12.f, 18.f, 20.f, 18.f, 18.f, 18.f, 20.f, 18.f, 18.f, 20.f, 55.f,
        40.f, 30.f, 70.f, 55.f, 55.f, 55.f, 40.f, 30.f, 70.f, 55.f, 55.f,
};

constexpr std::array<float, kMotorCount> kDefaultDamping = {
        0.2f, 0.2f, 0.6f, 0.8f, 0.6f, 0.6f, 0.6f, 0.8f, 0.6f, 0.6f, 0.8f, 4.0f,
        3.0f, 2.0f, 5.0f, 3.5f, 3.5f, 4.0f, 3.0f, 2.0f, 5.0f, 3.5f, 3.5f,
};

constexpr std::array<float, kMotorCount> kTorqueLimits = {
        7.f, 7.f, 10.f, 10.f, 10.f, 10.f, 10.f, 10.f, 10.f, 10.f, 30.f, 60.f,
        25.f, 30.f, 60.f, 24.f, 15.f, 60.f, 25.f, 30.f, 60.f, 24.f, 15.f,
};

constexpr std::array<int, 4> kParallelMechanismIndexes = {15, 16, 21, 22};

struct SensorSnapshot {
    std::array<float, 3> rpy{};
    std::array<float, 3> gyro{};
    std::array<float, kMotorCount> q{};
    std::array<float, kMotorCount> dq{};
};

std::array<float, 3> computeProjectedGravity(float roll, float pitch) {
    const float gx = -std::sin(pitch);
    const float gy = std::sin(roll) * std::cos(pitch);
    const float gz = -std::cos(roll) * std::cos(pitch);
    return {gx, gy, gz};
}

std::string appendRobotSuffix(const std::string &base_topic, const std::string &robot_name) {
    if (robot_name.empty()) {
        return base_topic;
    }
    return base_topic + "/" + robot_name;
}

class PolicyBackend {
public:
    virtual ~PolicyBackend() = default;
    virtual bool load(const std::string &model_path, size_t input_dim,
                      const rclcpp::Logger &logger) = 0;
    virtual std::vector<float> infer(const std::vector<float> &input) = 0;
};

class NullPolicyBackend : public PolicyBackend {
public:
    bool load(const std::string &, size_t, const rclcpp::Logger &) override {
        return false;
    }

    std::vector<float> infer(const std::vector<float> &) override {
        return {};
    }
};

#ifdef MOTION_CONTROL_HAVE_ONNX_RUNTIME
class OnnxPolicyBackend : public PolicyBackend {
public:
    bool load(const std::string &model_path, size_t input_dim,
              const rclcpp::Logger &logger) override {
        if (model_path.empty()) {
            return false;
        }

        if (!std::filesystem::exists(model_path)) {
            RCLCPP_WARN(logger, "Custom walk ONNX model not found: %s", model_path.c_str());
            return false;
        }

        try {
            expected_input_dim_ = input_dim;
            env_ = std::make_unique<Ort::Env>(ORT_LOGGING_LEVEL_WARNING, "motion_control");

            Ort::SessionOptions session_options;
            session_options.SetGraphOptimizationLevel(GraphOptimizationLevel::ORT_ENABLE_EXTENDED);
            session_options.SetIntraOpNumThreads(1);

            session_ = std::make_unique<Ort::Session>(*env_, model_path.c_str(), session_options);

            Ort::AllocatorWithDefaultOptions allocator;
            input_names_storage_.clear();
            output_names_storage_.clear();
            input_names_.clear();
            output_names_.clear();

            for (size_t i = 0; i < session_->GetInputCount(); ++i) {
                auto input_name = session_->GetInputNameAllocated(i, allocator);
                input_names_storage_.emplace_back(input_name.get());
            }
            for (size_t i = 0; i < session_->GetOutputCount(); ++i) {
                auto output_name = session_->GetOutputNameAllocated(i, allocator);
                output_names_storage_.emplace_back(output_name.get());
            }

            for (const auto &name : input_names_storage_) {
                input_names_.push_back(name.c_str());
            }
            for (const auto &name : output_names_storage_) {
                output_names_.push_back(name.c_str());
            }

            if (!input_names_.empty() && !output_names_.empty()) {
                RCLCPP_INFO(logger, "Loaded ONNX locomotion policy: %s", model_path.c_str());
                return true;
            }
        } catch (const std::exception &e) {
            RCLCPP_ERROR(logger, "Failed to load ONNX locomotion policy: %s", e.what());
        }

        session_.reset();
        env_.reset();
        return false;
    }

    std::vector<float> infer(const std::vector<float> &input) override {
        if (!session_ || input.size() != expected_input_dim_) {
            return {};
        }

        std::array<int64_t, 2> input_shape = {1, static_cast<int64_t>(input.size())};
        auto memory_info = Ort::MemoryInfo::CreateCpu(OrtArenaAllocator, OrtMemTypeDefault);
        auto input_tensor = Ort::Value::CreateTensor<float>(
                memory_info,
                const_cast<float *>(input.data()),
                input.size(),
                input_shape.data(),
                input_shape.size());

        auto outputs = session_->Run(Ort::RunOptions{nullptr},
                                     input_names_.data(),
                                     &input_tensor,
                                     1,
                                     output_names_.data(),
                                     output_names_.size());
        if (outputs.empty()) {
            return {};
        }

        auto &output = outputs.front();
        const auto tensor_info = output.GetTensorTypeAndShapeInfo();
        const size_t element_count = tensor_info.GetElementCount();
        const float *data = output.GetTensorData<float>();
        return std::vector<float>(data, data + element_count);
    }

private:
    size_t expected_input_dim_ = 0;
    std::unique_ptr<Ort::Env> env_;
    std::unique_ptr<Ort::Session> session_;
    std::vector<std::string> input_names_storage_;
    std::vector<std::string> output_names_storage_;
    std::vector<const char *> input_names_;
    std::vector<const char *> output_names_;
};
#endif

class CustomMotionNode : public rclcpp::Node {
public:
    CustomMotionNode() : Node("custom_motion_node") {
        declare_parameter<std::string>("robot.robot_name", "");
        declare_parameter<std::string>("robot.custom_walk_cmd_topic", "/custom_walk_cmd");
        declare_parameter<std::string>("robot.custom_walk_low_state_topic", "/low_state");
        declare_parameter<std::string>("robot.custom_walk_low_cmd_topic", "/low_cmd");
        declare_parameter<std::string>("robot.custom_walk_model_path", "");
        declare_parameter<double>("robot.custom_walk_cmd_timeout_ms", 250.0);
        declare_parameter<double>("robot.custom_walk_loop_hz", 100.0);
        declare_parameter<double>("robot.custom_walk_gait_frequency", 1.5);

        robot_name_ = get_parameter("robot.robot_name").as_string();
        cmd_timeout_ms_ = static_cast<float>(get_parameter("robot.custom_walk_cmd_timeout_ms").as_double());
        loop_hz_ = static_cast<float>(get_parameter("robot.custom_walk_loop_hz").as_double());
        gait_frequency_ = static_cast<float>(get_parameter("robot.custom_walk_gait_frequency").as_double());

        const auto command_topic = appendRobotSuffix(
                get_parameter("robot.custom_walk_cmd_topic").as_string(), robot_name_);
        walk_command_sub_ = create_subscription<geometry_msgs::msg::Twist>(
                command_topic,
                10,
                std::bind(&CustomMotionNode::onWalkCommand, this, std::placeholders::_1));

        const auto low_state_topic = appendRobotSuffix(
                get_parameter("robot.custom_walk_low_state_topic").as_string(), robot_name_);
        const auto low_cmd_topic = appendRobotSuffix(
                get_parameter("robot.custom_walk_low_cmd_topic").as_string(), robot_name_);

        low_state_sub_ = create_subscription<booster_interface::msg::LowState>(
                low_state_topic,
                10,
                std::bind(&CustomMotionNode::onLowState, this, std::placeholders::_1));
        low_cmd_pub_ = create_publisher<booster_interface::msg::LowCmd>(low_cmd_topic, 10);

        RCLCPP_INFO(get_logger(),
                    "motion_control using ROS low-level topics: state=%s cmd=%s",
                    low_state_topic.c_str(),
                    low_cmd_topic.c_str());

#ifdef MOTION_CONTROL_HAVE_ONNX_RUNTIME
        policy_backend_ = std::make_unique<OnnxPolicyBackend>();
#else
        policy_backend_ = std::make_unique<NullPolicyBackend>();
#endif

        const std::string model_path = get_parameter("robot.custom_walk_model_path").as_string();
        policy_loaded_ = policy_backend_->load(model_path, expectedObservationSize(), get_logger());
        if (!policy_loaded_) {
            RCLCPP_WARN(get_logger(),
                        "Locomotion policy backend is not active yet. The node will keep the current stance.");
        }

        filtered_targets_.fill(0.f);
        last_actions_.assign(kMotorCount, 0.f);

        const auto loop_period = std::chrono::duration<double>(1.0 / std::max(loop_hz_, 1.0f));
        control_timer_ = create_wall_timer(
                std::chrono::duration_cast<std::chrono::milliseconds>(loop_period),
                std::bind(&CustomMotionNode::controlLoop, this));

        RCLCPP_INFO(get_logger(), "motion_control listening for walk commands on %s", command_topic.c_str());
    }

private:
    size_t expectedObservationSize() const {
        return 3 + 3 + 3 + kMotorCount + kMotorCount + kMotorCount;
    }

    void onWalkCommand(const geometry_msgs::msg::Twist::SharedPtr msg) {
        last_command_ = *msg;
        last_command_time_ = now();
        has_received_command_ = true;
    }

    void onLowState(const booster_interface::msg::LowState::SharedPtr msg) {
        if (msg->motor_state_serial.size() < kMotorCount) {
            if (!warned_motor_count_) {
                RCLCPP_WARN(get_logger(),
                            "Received %zu serial joints but expected at least %zu for T1.",
                            msg->motor_state_serial.size(),
                            kMotorCount);
                warned_motor_count_ = true;
            }
            return;
        }

        SensorSnapshot snapshot;
        snapshot.rpy[0] = msg->imu_state.rpy[0];
        snapshot.rpy[1] = msg->imu_state.rpy[1];
        snapshot.rpy[2] = msg->imu_state.rpy[2];
        snapshot.gyro[0] = msg->imu_state.gyro[0];
        snapshot.gyro[1] = msg->imu_state.gyro[1];
        snapshot.gyro[2] = msg->imu_state.gyro[2];
        for (size_t i = 0; i < kMotorCount; ++i) {
            snapshot.q[i] = msg->motor_state_serial[i].q;
            snapshot.dq[i] = msg->motor_state_serial[i].dq;
        }
        updateSensorSnapshot(snapshot);
    }

    void updateSensorSnapshot(const SensorSnapshot &snapshot) {
        std::lock_guard<std::mutex> lock(sensor_mutex_);
        sensor_snapshot_ = snapshot;
        has_sensor_snapshot_ = true;
        if (!stand_pose_initialized_) {
            stand_pose_ = snapshot.q;
            filtered_targets_ = stand_pose_;
            stand_pose_initialized_ = true;
        }
    }

    void controlLoop() {
        if (!has_received_command_) {
            return;
        }

        SensorSnapshot snapshot;
        std::array<float, kMotorCount> stand_pose{};
        {
            std::lock_guard<std::mutex> lock(sensor_mutex_);
            if (!has_sensor_snapshot_ || !stand_pose_initialized_) {
                return;
            }
            snapshot = sensor_snapshot_;
            stand_pose = stand_pose_;
        }

        const bool command_is_fresh =
                (now() - last_command_time_).nanoseconds() / 1e6 < cmd_timeout_ms_;
        const float cmd_x = command_is_fresh ? static_cast<float>(last_command_.linear.x) : 0.f;
        const float cmd_y = command_is_fresh ? static_cast<float>(last_command_.linear.y) : 0.f;
        const float cmd_yaw = command_is_fresh ? static_cast<float>(last_command_.angular.z) : 0.f;

        std::array<float, kMotorCount> target_positions = snapshot.q;

        if (policy_loaded_) {
            const auto observation = buildObservation(snapshot, stand_pose, cmd_x, cmd_y, cmd_yaw);
            const auto policy_output = policy_backend_->infer(observation);
            if (policy_output.size() >= kMotorCount) {
                for (size_t i = 0; i < kMotorCount; ++i) {
                    const float action = std::clamp(policy_output[i], -1.0f, 1.0f);
                    last_actions_[i] = action;
                    if (kActionScales[i] > 0.f) {
                        target_positions[i] = stand_pose[i] + action * kActionScales[i];
                    }
                }
            }
        }

        publishLowCmd(target_positions, snapshot.q);
    }

    std::vector<float> buildObservation(const SensorSnapshot &snapshot,
                                        const std::array<float, kMotorCount> &stand_pose,
                                        float cmd_x,
                                        float cmd_y,
                                        float cmd_yaw) const {
        const auto gravity = computeProjectedGravity(snapshot.rpy[0], snapshot.rpy[1]);

        std::vector<float> observation;
        observation.reserve(expectedObservationSize());

        observation.push_back(snapshot.gyro[0] * 0.25f);
        observation.push_back(snapshot.gyro[1] * 0.25f);
        observation.push_back(snapshot.gyro[2] * 0.25f);
        observation.insert(observation.end(), gravity.begin(), gravity.end());
        observation.push_back(cmd_x);
        observation.push_back(cmd_y);
        observation.push_back(cmd_yaw);

        for (size_t i = 0; i < kMotorCount; ++i) {
            observation.push_back(snapshot.q[i] - stand_pose[i]);
        }
        for (size_t i = 0; i < kMotorCount; ++i) {
            observation.push_back(snapshot.dq[i] * 0.05f);
        }
        observation.insert(observation.end(), last_actions_.begin(), last_actions_.end());
        return observation;
    }

    void publishLowCmd(const std::array<float, kMotorCount> &target_positions,
                       const std::array<float, kMotorCount> &current_positions) {
        for (size_t i = 0; i < kMotorCount; ++i) {
            filtered_targets_[i] = filtered_targets_[i] * 0.8f + target_positions[i] * 0.2f;
        }

        booster_interface::msg::LowCmd cmd;
        cmd.cmd_type = booster_interface::msg::LowCmd::CMD_TYPE_SERIAL;
        cmd.motor_cmd.resize(kMotorCount);

        for (size_t i = 0; i < kMotorCount; ++i) {
            auto &motor = cmd.motor_cmd[i];
            motor.mode = 0;
            motor.q = filtered_targets_[i];
            motor.dq = 0.f;
            motor.tau = 0.f;
            motor.kp = kDefaultStiffness[i];
            motor.kd = kDefaultDamping[i];
            motor.weight = 1.f;
        }

        for (int index : kParallelMechanismIndexes) {
            const float torque = std::clamp(
                    (filtered_targets_[index] - current_positions[index]) * kDefaultStiffness[index],
                    -kTorqueLimits[index],
                    kTorqueLimits[index]);
            auto &motor = cmd.motor_cmd[index];
            motor.q = current_positions[index];
            motor.tau = torque;
            motor.kp = 0.f;
        }

        low_cmd_pub_->publish(cmd);
    }

    std::string robot_name_;
    bool has_received_command_ = false;
    bool has_sensor_snapshot_ = false;
    bool warned_motor_count_ = false;
    bool stand_pose_initialized_ = false;
    bool policy_loaded_ = false;
    float cmd_timeout_ms_ = 250.f;
    float loop_hz_ = 100.f;
    float gait_frequency_ = 1.5f;

    std::mutex sensor_mutex_;
    SensorSnapshot sensor_snapshot_{};
    geometry_msgs::msg::Twist last_command_;
    rclcpp::Time last_command_time_{0, 0, RCL_ROS_TIME};

    std::array<float, kMotorCount> stand_pose_{};
    std::array<float, kMotorCount> filtered_targets_{};
    std::vector<float> last_actions_;
    std::unique_ptr<PolicyBackend> policy_backend_;

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr walk_command_sub_;
    rclcpp::Subscription<booster_interface::msg::LowState>::SharedPtr low_state_sub_;
    rclcpp::Publisher<booster_interface::msg::LowCmd>::SharedPtr low_cmd_pub_;

    rclcpp::TimerBase::SharedPtr control_timer_;
};

}  // namespace

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CustomMotionNode>());
    rclcpp::shutdown();
    return 0;
}
