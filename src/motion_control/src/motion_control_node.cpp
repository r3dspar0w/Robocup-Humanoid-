#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <filesystem>
#include <memory>
#include <string>

#include <geometry_msgs/msg/twist.hpp>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/bool.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_srvs/srv/set_bool.hpp>

#include <booster/idl/b1/LowCmd.h>
#include <booster/idl/b1/MotorCmd.h>
#include <booster/robot/b1/b1_api_const.hpp>
#include <booster/robot/b1/b1_loco_client.hpp>
#include <booster/robot/channel/channel_factory.hpp>
#include <booster/robot/channel/channel_publisher.hpp>

namespace motion_control
{
namespace
{
constexpr size_t kJointCount = booster::robot::b1::kJointCnt;

using JointArray = std::array<float, kJointCount>;

JointArray stand_pose()
{
  return {
    0.0F, 0.0F,
    0.10F, -1.50F, 0.0F, -0.20F,
    0.10F, 1.50F, 0.0F, 0.20F,
    0.0F,
    -0.20F, 0.0F, 0.0F, 0.40F, -0.35F, 0.03F,
    -0.20F, 0.0F, 0.0F, 0.40F, -0.35F, -0.03F
  };
}

JointArray base_kp()
{
  return {
    5.0F, 5.0F,
    40.0F, 50.0F, 20.0F, 10.0F,
    40.0F, 50.0F, 20.0F, 10.0F,
    100.0F,
    350.0F, 350.0F, 180.0F, 350.0F, 550.0F, 550.0F,
    350.0F, 350.0F, 180.0F, 350.0F, 550.0F, 550.0F
  };
}

JointArray base_kd()
{
  return {
    0.1F, 0.1F,
    0.5F, 1.5F, 0.2F, 0.2F,
    0.5F, 1.5F, 0.2F, 0.2F,
    5.0F,
    7.5F, 7.5F, 3.0F, 5.5F, 1.5F, 1.5F,
    7.5F, 7.5F, 3.0F, 5.5F, 1.5F, 1.5F
  };
}

booster_interface::msg::CmdType parse_cmd_type(const std::string & value)
{
  if (value == "serial" || value == "SERIAL") {
    return booster_interface::msg::SERIAL;
  }
  return booster_interface::msg::PARALLEL;
}
}  // namespace

class MotionControlNode : public rclcpp::Node
{
public:
  MotionControlNode()
  : Node("motion_control_node"),
    target_pose_(stand_pose()),
    current_pose_(stand_pose()),
    kp_(base_kp()),
    kd_(base_kd())
  {
    const auto domain_id = declare_parameter<int>("sdk_domain_id", 0);
    const auto network_interface = declare_parameter<std::string>("network_interface", "");
    robot_name_ = declare_parameter<std::string>("robot_name", "");
    model_path_ = declare_parameter<std::string>("model_path", "");
    cmd_vel_topic_ = declare_parameter<std::string>(
      "cmd_vel_topic", "/booster_soccer/rl_motion/cmd_vel");
    enable_topic_ = declare_parameter<std::string>(
      "enable_topic", "/booster_soccer/rl_motion/enable");
    set_enabled_service_ = declare_parameter<std::string>(
      "set_enabled_service", "/booster_soccer/rl_motion/set_enabled");
    state_topic_ = declare_parameter<std::string>(
      "state_topic", "/booster_soccer/rl_motion/state");
    publish_hz_ = declare_parameter<double>("publish_hz", 50.0);
    max_joint_velocity_rad_s_ = declare_parameter<double>("max_joint_velocity_rad_s", 1.0);
    kp_scale_ = declare_parameter<double>("kp_scale", 0.25);
    kd_scale_ = declare_parameter<double>("kd_scale", 0.5);
    const auto start_enabled = declare_parameter<bool>("start_enabled", false);
    auto_change_mode_ = declare_parameter<bool>("auto_change_mode", false);
    return_to_prepare_on_disable_ = declare_parameter<bool>("return_to_prepare_on_disable", false);
    const auto cmd_type = declare_parameter<std::string>("cmd_type", "parallel");

    RCLCPP_INFO(
      get_logger(),
      "Starting motion_control_node: model_path='%s', network_interface='%s', sdk_domain_id=%d, "
      "publish_hz=%.1f, start_enabled=%s, auto_change_mode=%s, cmd_type=%s",
      model_path_.c_str(), network_interface.c_str(), domain_id, publish_hz_,
      start_enabled ? "true" : "false",
      auto_change_mode_ ? "true" : "false",
      cmd_type.c_str());
    if (model_path_.empty()) {
      RCLCPP_WARN(get_logger(), "model_path is empty");
    } else if (!std::filesystem::exists(model_path_)) {
      RCLCPP_ERROR(get_logger(), "model_path does not exist: %s", model_path_.c_str());
    } else {
      RCLCPP_INFO(get_logger(), "Found configured model file: %s", model_path_.c_str());
    }
    if (network_interface.empty()) {
      RCLCPP_WARN(
        get_logger(),
        "network_interface is empty. DDS may use the default interface; set "
        "MOTION_CONTROL_NETWORK_INTERFACE before ./scripts/start.sh if this is wrong.");
    }

    booster::robot::ChannelFactory::Instance()->Init(domain_id, network_interface);
    RCLCPP_INFO(get_logger(), "Booster ChannelFactory initialized");
    low_cmd_pub_ =
      std::make_shared<booster::robot::ChannelPublisher<booster_interface::msg::LowCmd>>(
      booster::robot::b1::kTopicJointCtrl);
    low_cmd_pub_->InitChannel();
    RCLCPP_INFO(
      get_logger(), "LowCmd publisher initialized on SDK topic '%s'",
      booster::robot::b1::kTopicJointCtrl.c_str());

    low_cmd_.cmd_type(parse_cmd_type(cmd_type));
    low_cmd_.motor_cmd().resize(kJointCount);

    if (auto_change_mode_) {
      loco_client_ = std::make_unique<booster::robot::b1::B1LocoClient>();
      if (robot_name_.empty()) {
        loco_client_->Init();
      } else {
        loco_client_->Init(robot_name_);
      }
    }

    cmd_vel_sub_ = create_subscription<geometry_msgs::msg::Twist>(
      cmd_vel_topic_, rclcpp::SystemDefaultsQoS(),
      [this](const geometry_msgs::msg::Twist::SharedPtr msg) {
        latest_cmd_vel_ = *msg;
        RCLCPP_INFO_THROTTLE(
          get_logger(), *get_clock(), 1000,
          "Received cmd_vel: x=%.3f y=%.3f yaw=%.3f",
          latest_cmd_vel_.linear.x, latest_cmd_vel_.linear.y, latest_cmd_vel_.angular.z);
      });

    auto enable_qos = rclcpp::QoS(1);
    enable_qos.reliable().transient_local();
    enable_sub_ = create_subscription<std_msgs::msg::Bool>(
      enable_topic_, enable_qos,
      [this](const std_msgs::msg::Bool::SharedPtr msg) {
        set_enabled(msg->data);
      });
    enable_state_pub_ = create_publisher<std_msgs::msg::Bool>(enable_topic_, enable_qos);

    set_enabled_srv_ = create_service<std_srvs::srv::SetBool>(
      set_enabled_service_,
      [this](
        const std::shared_ptr<std_srvs::srv::SetBool::Request> request,
        std::shared_ptr<std_srvs::srv::SetBool::Response> response) {
        const bool ok = set_enabled(request->data);
        if (ok) {
          publish_enable_state(request->data);
        }
        response->success = ok;
        response->message = enabled_ ? "motion_control enabled" : "motion_control disabled";
      });

    state_pub_ = create_publisher<std_msgs::msg::String>(state_topic_, 1);

    const auto period = std::chrono::duration<double>(1.0 / std::max(1.0, publish_hz_));
    timer_ = create_wall_timer(
      std::chrono::duration_cast<std::chrono::nanoseconds>(period),
      [this]() {
        on_timer();
      });

    if (start_enabled) {
      if (set_enabled(true)) {
        publish_enable_state(true);
      }
    }
    publish_state(
      std::string("ready: ") + (enabled_ ? "enabled" : "disabled") +
      "; model_path=" + model_path_);
    RCLCPP_WARN(
      get_logger(),
      "motion_control_node is a safe scaffold. It publishes only when enabled, and the ONNX "
      "observation/action mapping still needs to be connected before walking.");
  }

private:
  bool set_enabled(bool enable)
  {
    if (enable == enabled_) {
      RCLCPP_INFO(
        get_logger(), "motion_control already %s", enabled_ ? "enabled" : "disabled");
      return true;
    }

    if (enable && auto_change_mode_ && loco_client_) {
      RCLCPP_INFO(get_logger(), "Requesting RobotMode::kCustom");
      const int32_t ret = loco_client_->ChangeMode(booster::robot::RobotMode::kCustom);
      if (ret != 0) {
        RCLCPP_ERROR(get_logger(), "Failed to switch robot to kCustom, ret=%d", ret);
        return false;
      }
    }

    enabled_ = enable;
    logged_first_low_cmd_ = false;
    latest_cmd_vel_ = geometry_msgs::msg::Twist{};

    if (!enabled_ && auto_change_mode_ && return_to_prepare_on_disable_ && loco_client_) {
      RCLCPP_INFO(get_logger(), "Requesting RobotMode::kPrepare");
      const int32_t ret = loco_client_->ChangeMode(booster::robot::RobotMode::kPrepare);
      if (ret != 0) {
        RCLCPP_WARN(get_logger(), "Failed to switch robot to kPrepare, ret=%d", ret);
      }
    }

    publish_state(enabled_ ? "enabled" : "disabled");
    RCLCPP_INFO(get_logger(), "motion_control %s", enabled_ ? "enabled" : "disabled");
    return true;
  }

  void on_timer()
  {
    if (!enabled_) {
      return;
    }

    // TODO: Replace this stand target with:
    // low_state + command velocity -> ONNX observation -> action -> joint target.
    target_pose_ = stand_pose();

    const float max_delta =
      static_cast<float>(max_joint_velocity_rad_s_ / std::max(1.0, publish_hz_));
    for (size_t i = 0; i < kJointCount; ++i) {
      const float error = target_pose_[i] - current_pose_[i];
      current_pose_[i] += std::clamp(error, -max_delta, max_delta);

      auto & motor = low_cmd_.motor_cmd()[i];
      motor.q(current_pose_[i]);
      motor.dq(0.0F);
      motor.tau(0.0F);
      motor.kp(static_cast<float>(kp_[i] * kp_scale_));
      motor.kd(static_cast<float>(kd_[i] * kd_scale_));
      motor.weight(0.0F);
    }

    if (!low_cmd_pub_->Write(&low_cmd_)) {
      RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), 2000, "Failed to publish LowCmd");
    } else if (!logged_first_low_cmd_) {
      logged_first_low_cmd_ = true;
      RCLCPP_INFO(
        get_logger(),
        "Publishing LowCmd stand placeholder at %.1f Hz. ONNX inference is not connected yet.",
        publish_hz_);
    }
  }

  void publish_state(const std::string & text)
  {
    std_msgs::msg::String msg;
    msg.data = text;
    if (state_pub_) {
      state_pub_->publish(msg);
    }
  }

  void publish_enable_state(bool enabled)
  {
    std_msgs::msg::Bool msg;
    msg.data = enabled;
    if (enable_state_pub_) {
      enable_state_pub_->publish(msg);
    }
  }

  std::string robot_name_;
  std::string model_path_;
  std::string cmd_vel_topic_;
  std::string enable_topic_;
  std::string set_enabled_service_;
  std::string state_topic_;

  double publish_hz_{50.0};
  double max_joint_velocity_rad_s_{1.0};
  double kp_scale_{0.25};
  double kd_scale_{0.5};
  bool auto_change_mode_{false};
  bool return_to_prepare_on_disable_{false};
  bool enabled_{false};
  bool logged_first_low_cmd_{false};

  geometry_msgs::msg::Twist latest_cmd_vel_;
  JointArray target_pose_;
  JointArray current_pose_;
  JointArray kp_;
  JointArray kd_;
  booster_interface::msg::LowCmd low_cmd_;

  std::shared_ptr<booster::robot::ChannelPublisher<booster_interface::msg::LowCmd>> low_cmd_pub_;
  std::unique_ptr<booster::robot::b1::B1LocoClient> loco_client_;
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;
  rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr enable_sub_;
  rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr enable_state_pub_;
  rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr set_enabled_srv_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr state_pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};
}  // namespace motion_control

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<motion_control::MotionControlNode>());
  rclcpp::shutdown();
  return 0;
}
