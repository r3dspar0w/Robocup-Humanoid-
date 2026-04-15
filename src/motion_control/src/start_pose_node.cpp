#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <functional>
#include <memory>
#include <mutex>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "booster_interface/msg/low_cmd.hpp"
#include "booster_interface/msg/low_state.hpp"

namespace {

constexpr size_t kMotorCount = 23;

constexpr std::array<float, kMotorCount> kTrainingReferencePose = {
        0.f,   0.f,   0.02f, -1.50f, 0.05f, 0.f,   0.02f, 1.50f, 0.05f, 0.f, 0.f, -0.32f,
        0.f,   0.f,   0.64f, -0.34f, 0.f,   -0.32f, 0.f,  0.f,   0.64f, -0.34f, 0.f,
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

std::string appendRobotSuffix(const std::string &base_topic, const std::string &robot_name) {
    if (robot_name.empty()) {
        return base_topic;
    }
    return base_topic + "/" + robot_name;
}

class StartPoseNode : public rclcpp::Node {
public:
    StartPoseNode() : Node("start_pose_node") {
        declare_parameter<std::string>("robot.robot_name", "");
        declare_parameter<std::string>("robot.start_pose_low_state_topic", "/low_state");
        declare_parameter<std::string>("robot.start_pose_low_cmd_topic", "/low_cmd");
        declare_parameter<double>("robot.start_pose_loop_hz", 100.0);
        declare_parameter<double>("robot.start_pose_transition_s", 3.0);

        robot_name_ = get_parameter("robot.robot_name").as_string();
        loop_hz_ = static_cast<float>(get_parameter("robot.start_pose_loop_hz").as_double());
        transition_s_ = static_cast<float>(get_parameter("robot.start_pose_transition_s").as_double());

        const auto low_state_topic = appendRobotSuffix(
                get_parameter("robot.start_pose_low_state_topic").as_string(), robot_name_);
        const auto low_cmd_topic = appendRobotSuffix(
                get_parameter("robot.start_pose_low_cmd_topic").as_string(), robot_name_);

        low_state_sub_ = create_subscription<booster_interface::msg::LowState>(
                low_state_topic,
                10,
                std::bind(&StartPoseNode::onLowState, this, std::placeholders::_1));
        low_cmd_pub_ = create_publisher<booster_interface::msg::LowCmd>(low_cmd_topic, 10);

        const auto loop_period = std::chrono::duration<double>(1.0 / std::max(loop_hz_, 1.0f));
        control_timer_ = create_wall_timer(
                std::chrono::duration_cast<std::chrono::milliseconds>(loop_period),
                std::bind(&StartPoseNode::controlLoop, this));

        RCLCPP_INFO(get_logger(),
                    "start_pose_node ready. state_topic=%s cmd_topic=%s transition_s=%.2f",
                    low_state_topic.c_str(),
                    low_cmd_topic.c_str(),
                    transition_s_);
    }

private:
    void onLowState(const booster_interface::msg::LowState::SharedPtr msg) {
        if (msg->motor_state_serial.size() < kMotorCount) {
            if (!warned_motor_count_) {
                warned_motor_count_ = true;
                RCLCPP_WARN(get_logger(),
                            "Received %zu serial joints but expected at least %zu.",
                            msg->motor_state_serial.size(),
                            kMotorCount);
            }
            return;
        }

        std::array<float, kMotorCount> q{};
        for (size_t i = 0; i < kMotorCount; ++i) {
            q[i] = msg->motor_state_serial[i].q;
        }

        std::lock_guard<std::mutex> lock(mutex_);
        current_q_ = q;
        has_state_ = true;
        if (!transition_started_) {
            start_q_ = q;
            transition_started_ = true;
            transition_start_time_ = now();
            RCLCPP_INFO(get_logger(), "Captured initial joint state, starting transition to training start pose.");
        }
    }

    void controlLoop() {
        std::array<float, kMotorCount> current_q{};
        std::array<float, kMotorCount> start_q{};
        rclcpp::Time transition_start_time;
        bool has_state = false;
        bool transition_started = false;

        {
            std::lock_guard<std::mutex> lock(mutex_);
            has_state = has_state_;
            transition_started = transition_started_;
            current_q = current_q_;
            start_q = start_q_;
            transition_start_time = transition_start_time_;
        }

        if (!has_state || !transition_started) {
            return;
        }

        const float elapsed_s = static_cast<float>((now() - transition_start_time).nanoseconds() / 1e9);
        const float alpha = std::clamp(elapsed_s / std::max(transition_s_, 0.1f), 0.0f, 1.0f);

        std::array<float, kMotorCount> target_q{};
        for (size_t i = 0; i < kMotorCount; ++i) {
            target_q[i] = start_q[i] + alpha * (kTrainingReferencePose[i] - start_q[i]);
        }

        publishLowCmd(target_q, current_q);

        if (!transition_logged_done_ && alpha >= 1.0f) {
            transition_logged_done_ = true;
            RCLCPP_INFO(get_logger(),
                        "Reached Robot Lab training start pose and now holding it.");
        }
    }

    void publishLowCmd(const std::array<float, kMotorCount> &target_q,
                       const std::array<float, kMotorCount> &current_q) {
        booster_interface::msg::LowCmd cmd;
        cmd.cmd_type = booster_interface::msg::LowCmd::CMD_TYPE_SERIAL;
        cmd.motor_cmd.resize(kMotorCount);

        for (size_t i = 0; i < kMotorCount; ++i) {
            auto &motor = cmd.motor_cmd[i];
            motor.mode = 0;
            motor.q = target_q[i];
            motor.dq = 0.f;
            motor.tau = 0.f;
            motor.kp = kDefaultStiffness[i];
            motor.kd = kDefaultDamping[i];
            motor.weight = 1.f;
        }

        // Keep ankle control consistent with Booster's serial deploy path.
        for (int index : kParallelMechanismIndexes) {
            const float torque = std::clamp(
                    (target_q[index] - current_q[index]) * kDefaultStiffness[index],
                    -kTorqueLimits[index],
                    kTorqueLimits[index]);
            auto &motor = cmd.motor_cmd[index];
            motor.q = current_q[index];
            motor.tau = torque;
            motor.kp = 0.f;
        }

        low_cmd_pub_->publish(cmd);
    }

    std::string robot_name_;
    float loop_hz_ = 100.0f;
    float transition_s_ = 3.0f;
    bool warned_motor_count_ = false;
    bool has_state_ = false;
    bool transition_started_ = false;
    bool transition_logged_done_ = false;

    std::mutex mutex_;
    std::array<float, kMotorCount> current_q_{};
    std::array<float, kMotorCount> start_q_{};
    rclcpp::Time transition_start_time_{0, 0, RCL_ROS_TIME};

    rclcpp::Subscription<booster_interface::msg::LowState>::SharedPtr low_state_sub_;
    rclcpp::Publisher<booster_interface::msg::LowCmd>::SharedPtr low_cmd_pub_;
    rclcpp::TimerBase::SharedPtr control_timer_;
};

}  // namespace

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<StartPoseNode>());
    rclcpp::shutdown();
    return 0;
}
