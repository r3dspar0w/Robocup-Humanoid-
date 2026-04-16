#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iomanip>
#include <memory>
#include <mutex>
#include <sstream>
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
constexpr size_t kPolicyActionCount = 12;
constexpr size_t kPolicyDofStartIndex = 11;
constexpr float kPi = 3.14159265358979323846f;
constexpr float kPolicyActionScale = 1.0f;

constexpr std::array<float, kMotorCount> kPolicyReferencePose = {
        0.f, 0.f, 0.2f, -1.35f, 0.f, -0.5f, 0.2f, 1.35f, 0.f, 0.5f, 0.f, -0.2f,
        0.f, 0.f, 0.4f, -0.25f, 0.f, -0.2f, 0.f, 0.f, 0.4f, -0.25f, 0.f,
};

constexpr std::array<float, kMotorCount> kDefaultStiffness = {
        20.f, 20.f, 20.f, 20.f, 20.f, 20.f, 20.f, 20.f, 20.f, 20.f, 200.f, 200.f,
        200.f, 200.f, 200.f, 50.f, 50.f, 200.f, 200.f, 200.f, 200.f, 50.f, 50.f,
};

constexpr std::array<float, kMotorCount> kDefaultDamping = {
        0.2f, 0.2f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 5.f, 5.f,
        5.f, 5.f, 5.f, 3.f, 3.f, 5.f, 5.f, 5.f, 5.f, 3.f, 3.f,
};

constexpr std::array<float, kMotorCount> kTorqueLimits = {
        7.f, 7.f, 10.f, 10.f, 10.f, 10.f, 10.f, 10.f, 10.f, 10.f, 30.f, 60.f,
        25.f, 30.f, 60.f, 24.f, 15.f, 60.f, 25.f, 30.f, 60.f, 24.f, 15.f,
};

constexpr std::array<int, 4> kParallelMechanismIndexes = {15, 16, 21, 22};

constexpr std::array<const char *, kMotorCount> kMotorNames = {
        "AAHead_yaw",         "Head_pitch",        "Left_Shoulder_Pitch", "Left_Shoulder_Roll",
        "Left_Elbow_Pitch",   "Left_Elbow_Yaw",   "Right_Shoulder_Pitch","Right_Shoulder_Roll",
        "Right_Elbow_Pitch",  "Right_Elbow_Yaw",  "Waist",               "Left_Hip_Pitch",
        "Left_Hip_Roll",      "Left_Hip_Yaw",     "Left_Knee_Pitch",     "Left_Ankle_Pitch",
        "Left_Ankle_Roll",    "Right_Hip_Pitch",  "Right_Hip_Roll",      "Right_Hip_Yaw",
        "Right_Knee_Pitch",   "Right_Ankle_Pitch","Right_Ankle_Roll",
};

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

std::string makeTimestamp(const char *format) {
    const auto now = std::chrono::system_clock::now();
    const auto time = std::chrono::system_clock::to_time_t(now);
    std::tm local_time{};
#ifdef _WIN32
    localtime_s(&local_time, &time);
#else
    localtime_r(&time, &local_time);
#endif
    std::ostringstream oss;
    oss << std::put_time(&local_time, format);
    return oss.str();
}

std::string formatFloat(float value, int precision = 3) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(precision) << value;
    return oss.str();
}

std::string formatHex(uint32_t value) {
    std::ostringstream oss;
    oss << "0x" << std::hex << std::uppercase << value;
    return oss.str();
}

class RuntimeEventLogger {
public:
    void init(const rclcpp::Logger &logger,
              const std::string &configured_dir,
              const std::string &robot_name) {
        try {
            std::filesystem::path root = configured_dir.empty()
                    ? (std::filesystem::current_path() / "motion_control_logs")
                    : std::filesystem::path(configured_dir);
            if (root.is_relative()) {
                root = std::filesystem::current_path() / root;
            }

            const std::string session_name = robot_name.empty()
                    ? makeTimestamp("%Y%m%d_%H%M%S")
                    : robot_name + "_" + makeTimestamp("%Y%m%d_%H%M%S");
            session_dir_ = root / session_name;
            std::filesystem::create_directories(session_dir_);

            log_path_ = session_dir_ / "events.log";
            stream_.open(log_path_, std::ios::out | std::ios::app);
            enabled_ = stream_.is_open();

            if (enabled_) {
                RCLCPP_INFO(logger, "motion_control event log: %s", log_path_.string().c_str());
                log("INFO", "motion_control log session started");
            } else {
                RCLCPP_WARN(logger, "Failed to open motion_control event log at %s",
                            log_path_.string().c_str());
            }
        } catch (const std::exception &e) {
            enabled_ = false;
            RCLCPP_WARN(logger, "Failed to initialize motion_control event log: %s", e.what());
        }
    }

    void log(const std::string &level, const std::string &message) {
        std::lock_guard<std::mutex> lock(mutex_);
        if (!enabled_ || !stream_.is_open()) {
            return;
        }

        stream_ << makeTimestamp("%Y-%m-%d %H:%M:%S")
                << " [" << level << "] "
                << message << '\n';
        stream_.flush();
    }

    std::string path() const {
        return log_path_.string();
    }

private:
    bool enabled_ = false;
    std::filesystem::path session_dir_;
    std::filesystem::path log_path_;
    std::ofstream stream_;
    std::mutex mutex_;
};

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
        declare_parameter<std::string>("robot.custom_walk_log_dir", "motion_control_logs");
        declare_parameter<double>("robot.custom_walk_cmd_timeout_ms", 250.0);
        declare_parameter<double>("robot.custom_walk_loop_hz", 100.0);
        declare_parameter<double>("robot.custom_walk_gait_frequency", 1.5);

        robot_name_ = get_parameter("robot.robot_name").as_string();
        const std::string log_dir = get_parameter("robot.custom_walk_log_dir").as_string();
        cmd_timeout_ms_ = static_cast<float>(get_parameter("robot.custom_walk_cmd_timeout_ms").as_double());
        loop_hz_ = static_cast<float>(get_parameter("robot.custom_walk_loop_hz").as_double());
        gait_frequency_ = static_cast<float>(get_parameter("robot.custom_walk_gait_frequency").as_double());
        event_logger_.init(get_logger(), log_dir, robot_name_);

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
        logEvent("INFO",
                 "Configured motion_control with state_topic=" + low_state_topic +
                 ", cmd_topic=" + low_cmd_topic +
                 ", walk_cmd_topic=" + command_topic +
                 ", loop_hz=" + formatFloat(loop_hz_, 1) +
                 ", command_timeout_ms=" + formatFloat(cmd_timeout_ms_, 1));

#ifdef MOTION_CONTROL_HAVE_ONNX_RUNTIME
        policy_backend_ = std::make_unique<OnnxPolicyBackend>();
        logEvent("INFO", "motion_control built with ONNX Runtime support");
#else
        policy_backend_ = std::make_unique<NullPolicyBackend>();
        logEvent("WARN", "motion_control was built without ONNX Runtime; policy inference is disabled");
#endif

        const std::string model_path = get_parameter("robot.custom_walk_model_path").as_string();
        policy_loaded_ = policy_backend_->load(model_path, expectedObservationSize(), get_logger());
        if (!policy_loaded_) {
            RCLCPP_WARN(get_logger(),
                        "Locomotion policy backend is not active yet. The node will keep the current stance.");
            logEvent("WARN",
                     "Policy backend inactive for model_path=" + model_path +
                     ". This can happen if the ONNX file is missing or ONNX Runtime was not found.");
        } else {
            logEvent("INFO", "Loaded locomotion policy from " + model_path);
        }

        filtered_targets_.fill(0.f);
        last_actions_.assign(kPolicyActionCount, 0.f);

        const auto loop_period = std::chrono::duration<double>(1.0 / std::max(loop_hz_, 1.0f));
        control_timer_ = create_wall_timer(
                std::chrono::duration_cast<std::chrono::milliseconds>(loop_period),
                std::bind(&CustomMotionNode::controlLoop, this));

        RCLCPP_INFO(get_logger(), "motion_control listening for walk commands on %s", command_topic.c_str());
        logEvent("INFO", "motion_control is ready and waiting for low_state and walk commands");
    }

private:
    size_t expectedObservationSize() const {
        return 3 + 3 + 3 + 7 + 2 + kPolicyActionCount + kPolicyActionCount + kPolicyActionCount;
    }

    void logEvent(const std::string &level, const std::string &message) {
        event_logger_.log(level, message);
    }

    bool shouldLogEvery(rclcpp::Time &last_log_time, double interval_ms) {
        const auto current_time = now();
        if (last_log_time.nanoseconds() == 0 ||
            (current_time - last_log_time).nanoseconds() / 1e6 >= interval_ms) {
            last_log_time = current_time;
            return true;
        }
        return false;
    }

    void onWalkCommand(const geometry_msgs::msg::Twist::SharedPtr msg) {
        last_command_ = *msg;
        last_command_time_ = now();
        has_received_command_ = true;

        const bool has_motion = std::fabs(msg->linear.x) > 1e-3 ||
                                std::fabs(msg->linear.y) > 1e-3 ||
                                std::fabs(msg->angular.z) > 1e-3;
        if (has_motion) {
            logEvent("INFO",
                     "Received walk command vx=" + formatFloat(static_cast<float>(msg->linear.x)) +
                     ", vy=" + formatFloat(static_cast<float>(msg->linear.y)) +
                     ", yaw=" + formatFloat(static_cast<float>(msg->angular.z)));
        }
    }

    void onLowState(const booster_interface::msg::LowState::SharedPtr msg) {
        if (msg->motor_state_serial.size() < kMotorCount) {
            if (!warned_motor_count_) {
                RCLCPP_WARN(get_logger(),
                            "Received %zu serial joints but expected at least %zu for T1.",
                            msg->motor_state_serial.size(),
                            kMotorCount);
                warned_motor_count_ = true;
                logEvent("WARN",
                         "LowState had only " + std::to_string(msg->motor_state_serial.size()) +
                         " serial joints; expected " + std::to_string(kMotorCount));
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
        inspectMotorDiagnostics(*msg);
        updateSensorSnapshot(snapshot);
    }

    void updateSensorSnapshot(const SensorSnapshot &snapshot) {
        std::lock_guard<std::mutex> lock(sensor_mutex_);
        sensor_snapshot_ = snapshot;
        has_sensor_snapshot_ = true;
        last_sensor_time_ = now();
        if (!received_first_sensor_snapshot_) {
            received_first_sensor_snapshot_ = true;
            logEvent("INFO", "Received first LowState snapshot from robot");
        }
        if (!stand_pose_initialized_) {
            stand_pose_ = kPolicyReferencePose;
            filtered_targets_ = snapshot.q;
            stand_pose_initialized_ = true;
            logEvent("INFO", "Initialized policy reference pose from Booster T1 training defaults");
        }
    }

    void controlLoop() {
        SensorSnapshot snapshot;
        std::array<float, kMotorCount> stand_pose{};
        rclcpp::Time last_sensor_time{0, 0, RCL_ROS_TIME};
        {
            std::lock_guard<std::mutex> lock(sensor_mutex_);
            if (!has_sensor_snapshot_ || !stand_pose_initialized_) {
                if (shouldLogEvery(last_waiting_for_sensor_log_time_, 2000.0)) {
                    logEvent("WARN",
                             "controlLoop is waiting for LowState. Without a stable low-level state stream, T1 can fall back to DAMP/PROTECT.");
                }
                return;
            }
            snapshot = sensor_snapshot_;
            stand_pose = stand_pose_;
            last_sensor_time = last_sensor_time_;
        }

        const double sensor_age_ms = (now() - last_sensor_time).nanoseconds() / 1e6;
        if (sensor_age_ms > 500.0 && shouldLogEvery(last_sensor_timeout_log_time_, 1000.0)) {
            logEvent("WARN",
                     "LowState stream is stale for " + formatFloat(static_cast<float>(sensor_age_ms), 1) +
                     " ms. The robot may enter DAMP/PROTECT if low-level control becomes uncontrolled.");
        }

        const bool command_is_fresh =
                (now() - last_command_time_).nanoseconds() / 1e6 < cmd_timeout_ms_;
        if (has_received_command_ && command_is_fresh != last_command_fresh_) {
            last_command_fresh_ = command_is_fresh;
            logEvent(command_is_fresh ? "INFO" : "WARN",
                     command_is_fresh
                             ? "Walk command stream is fresh again"
                             : "Walk command stream is stale, holding the policy reference pose");
        }
        const float cmd_x = command_is_fresh ? static_cast<float>(last_command_.linear.x) : 0.f;
        const float cmd_y = command_is_fresh ? static_cast<float>(last_command_.linear.y) : 0.f;
        const float cmd_yaw = command_is_fresh ? static_cast<float>(last_command_.angular.z) : 0.f;

        std::array<float, kMotorCount> target_positions = snapshot.q;

        if (policy_loaded_ && command_is_fresh) {
            const auto observation = buildObservation(snapshot, stand_pose, cmd_x, cmd_y, cmd_yaw);
            const auto policy_output = policy_backend_->infer(observation);
            if (policy_output.size() >= kPolicyActionCount) {
                target_positions = stand_pose;
                for (size_t i = 0; i < kPolicyActionCount; ++i) {
                    float action = 0.0f;
                    if (std::isfinite(policy_output[i])) {
                        action = std::clamp(policy_output[i], -1.0f, 1.0f);
                    } else if (shouldLogEvery(last_non_finite_action_log_time_, 1000.0)) {
                        logEvent("WARN", "Policy produced a non-finite action at index " + std::to_string(i));
                    }
                    last_actions_[i] = action;
                    const size_t joint_index = kPolicyDofStartIndex + i;
                    target_positions[joint_index] = stand_pose[joint_index] + action * kPolicyActionScale;
                }
            } else if (shouldLogEvery(last_policy_output_warning_time_, 1000.0)) {
                logEvent("WARN",
                         "Policy output had only " + std::to_string(policy_output.size()) +
                         " values; expected at least " + std::to_string(kPolicyActionCount) +
                         ". Holding the policy reference pose.");
            }
        } else {
            std::fill(last_actions_.begin(), last_actions_.end(), 0.0f);
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

        observation.insert(observation.end(), gravity.begin(), gravity.end());
        observation.push_back(snapshot.gyro[0]);
        observation.push_back(snapshot.gyro[1]);
        observation.push_back(snapshot.gyro[2]);

        const bool has_motion = std::fabs(cmd_x) > 1e-3f ||
                                std::fabs(cmd_y) > 1e-3f ||
                                std::fabs(cmd_yaw) > 1e-3f;
        const float gait_frequency = has_motion ? gait_frequency_ : 0.0f;
        const float gait_active = gait_frequency > 1e-8f ? 1.0f : 0.0f;
        const float gait_phase = std::fmod(static_cast<float>(now().seconds()) * gait_frequency, 1.0f);

        observation.push_back(0.0f * gait_active);
        observation.push_back(0.0f * gait_active);
        observation.push_back(0.0f * gait_active);
        observation.push_back(gait_frequency);
        observation.push_back(0.0f);
        observation.push_back(0.0f);
        observation.push_back(0.0f);
        observation.push_back(0.0f);
        observation.push_back(0.0f);
        observation.push_back(0.0f);
        observation.push_back(std::cos(gait_phase * 2.0f * kPi) * gait_active);
        observation.push_back(std::sin(gait_phase * 2.0f * kPi) * gait_active);

        for (size_t i = kPolicyDofStartIndex; i < kMotorCount; ++i) {
            observation.push_back(snapshot.q[i] - stand_pose[i]);
        }
        for (size_t i = kPolicyDofStartIndex; i < kMotorCount; ++i) {
            observation.push_back(snapshot.dq[i] * 0.1f);
        }
        observation.insert(observation.end(), last_actions_.begin(), last_actions_.end());
        return observation;
    }

    void inspectMotorDiagnostics(const booster_interface::msg::LowState &msg) {
        for (size_t i = 0; i < kMotorCount; ++i) {
            const auto &motor = msg.motor_state_serial[i];
            const uint32_t error_flags = motor.reserve[0];

            if (!motor_diagnostics_initialized_) {
                last_motor_modes_[i] = static_cast<int>(motor.mode);
                last_motor_error_flags_[i] = error_flags;
                last_motor_lost_[i] = motor.lost;
                last_motor_temperatures_[i] = static_cast<int>(motor.temperature);

                if (error_flags != 0) {
                    logEvent("WARN",
                             "Motor " + std::string(kMotorNames[i]) +
                             " started with error_flags=" + formatHex(error_flags));
                }
                continue;
            }

            if (static_cast<int>(motor.mode) != last_motor_modes_[i]) {
                logEvent("INFO",
                         "Motor mode change on " + std::string(kMotorNames[i]) +
                         ": " + std::to_string(last_motor_modes_[i]) +
                         " -> " + std::to_string(static_cast<int>(motor.mode)));
                last_motor_modes_[i] = static_cast<int>(motor.mode);
            }

            if (error_flags != last_motor_error_flags_[i]) {
                logEvent(error_flags == 0 ? "INFO" : "WARN",
                         "Motor error flags on " + std::string(kMotorNames[i]) +
                         " changed from " + formatHex(last_motor_error_flags_[i]) +
                         " to " + formatHex(error_flags));
                last_motor_error_flags_[i] = error_flags;
            }

            if (motor.lost > last_motor_lost_[i]) {
                logEvent("WARN",
                         "Motor packet loss increased on " + std::string(kMotorNames[i]) +
                         ": " + std::to_string(last_motor_lost_[i]) +
                         " -> " + std::to_string(motor.lost));
                last_motor_lost_[i] = motor.lost;
            }

            if (motor.temperature >= 80 &&
                (last_motor_temperatures_[i] < 80 ||
                 std::abs(static_cast<int>(motor.temperature) - last_motor_temperatures_[i]) >= 5)) {
                logEvent("WARN",
                         "High motor temperature on " + std::string(kMotorNames[i]) +
                         ": " + std::to_string(static_cast<int>(motor.temperature)) + " C");
            }
            last_motor_temperatures_[i] = static_cast<int>(motor.temperature);
        }

        if (!motor_diagnostics_initialized_) {
            motor_diagnostics_initialized_ = true;
            logEvent("INFO", "Captured initial per-motor diagnostic snapshot");
        }
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

        // Booster's official serial deploy path still converts ankle targets into
        // torque commands for the series-parallel mechanism joints.
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
    bool received_first_sensor_snapshot_ = false;
    bool motor_diagnostics_initialized_ = false;
    bool last_command_fresh_ = false;
    float cmd_timeout_ms_ = 250.f;
    float loop_hz_ = 100.f;
    float gait_frequency_ = 1.5f;

    std::mutex sensor_mutex_;
    SensorSnapshot sensor_snapshot_{};
    geometry_msgs::msg::Twist last_command_;
    rclcpp::Time last_command_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_sensor_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_waiting_for_sensor_log_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_sensor_timeout_log_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_policy_output_warning_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_non_finite_action_log_time_{0, 0, RCL_ROS_TIME};

    std::array<float, kMotorCount> stand_pose_{};
    std::array<float, kMotorCount> filtered_targets_{};
    std::array<int, kMotorCount> last_motor_modes_{};
    std::array<uint32_t, kMotorCount> last_motor_error_flags_{};
    std::array<uint32_t, kMotorCount> last_motor_lost_{};
    std::array<int, kMotorCount> last_motor_temperatures_{};
    std::vector<float> last_actions_;
    std::unique_ptr<PolicyBackend> policy_backend_;
    RuntimeEventLogger event_logger_;

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
