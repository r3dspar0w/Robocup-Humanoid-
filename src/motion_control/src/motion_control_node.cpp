#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <filesystem>
#include <memory>
#include <mutex>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include <geometry_msgs/msg/twist.hpp>
#include <onnxruntime_cxx_api.h>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/bool.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_srvs/srv/set_bool.hpp>

#include <booster/idl/b1/LowCmd.h>
#include <booster/idl/b1/LowState.h>
#include <booster/idl/b1/MotorCmd.h>
#include <booster/robot/b1/b1_api_const.hpp>
#include <booster/robot/b1/b1_loco_client.hpp>
#include <booster/robot/channel/channel_factory.hpp>
#include <booster/robot/channel/channel_publisher.hpp>
#include <booster/robot/channel/channel_subscriber.hpp>

namespace motion_control
{
namespace
{
constexpr size_t kJointCount = booster::robot::b1::kJointCnt;
constexpr size_t kPolicyInputSize = 51;
constexpr size_t kPolicyControlledJointCount = 13;
constexpr size_t kPolicyOutputSize = 14;
constexpr float kTwoPi = 6.2831853071795864769F;
constexpr float kCommandDeadband = 1e-4F;

using JointArray = std::array<float, kJointCount>;
using PolicyArray = std::array<float, kPolicyOutputSize>;
using ControlledJointArray = std::array<float, kPolicyControlledJointCount>;

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

std::vector<size_t> parse_joint_indices(const std::string & text)
{
  std::vector<size_t> result;
  std::stringstream ss(text);
  std::string token;
  while (std::getline(ss, token, ',')) {
    if (token.empty()) {
      continue;
    }
    const auto value = static_cast<size_t>(std::stoul(token));
    if (value >= kJointCount) {
      throw std::out_of_range("controlled joint index is outside Booster joint count");
    }
    result.push_back(value);
  }
  return result;
}

std::array<float, 3> projected_gravity_from_rpy(const std::array<float, 3> & rpy)
{
  const float roll = rpy[0];
  const float pitch = rpy[1];
  const float yaw = rpy[2];
  const float cr = std::cos(roll);
  const float sr = std::sin(roll);
  const float cp = std::cos(pitch);
  const float sp = std::sin(pitch);
  const float cy = std::cos(yaw);
  const float sy = std::sin(yaw);

  const float r00 = cy * cp;
  const float r01 = cy * sp * sr - sy * cr;
  const float r02 = cy * sp * cr + sy * sr;
  const float r10 = sy * cp;
  const float r11 = sy * sp * sr + cy * cr;
  const float r12 = sy * sp * cr - cy * sr;
  const float r20 = -sp;
  const float r21 = cp * sr;
  const float r22 = cp * cr;

  const float gx = 0.0F;
  const float gy = 0.0F;
  const float gz = -1.0F;
  return {
    r00 * gx + r10 * gy + r20 * gz,
    r01 * gx + r11 * gy + r21 * gz,
    r02 * gx + r12 * gy + r22 * gz};
}

std::string join_indices(const std::vector<size_t> & indices)
{
  std::ostringstream out;
  for (size_t i = 0; i < indices.size(); ++i) {
    if (i > 0) {
      out << ",";
    }
    out << indices[i];
  }
  return out.str();
}

class OnnxPolicy
{
public:
  explicit OnnxPolicy(const std::string & model_path)
  : env_(ORT_LOGGING_LEVEL_WARNING, "motion_control_policy"),
    session_options_(),
    memory_info_(Ort::MemoryInfo::CreateCpu(OrtArenaAllocator, OrtMemTypeDefault))
  {
    session_options_.SetIntraOpNumThreads(1);
    session_options_.SetGraphOptimizationLevel(GraphOptimizationLevel::ORT_ENABLE_EXTENDED);

#ifdef _WIN32
    std::wstring wide_path(model_path.begin(), model_path.end());
    session_ = std::make_unique<Ort::Session>(env_, wide_path.c_str(), session_options_);
#else
    session_ = std::make_unique<Ort::Session>(env_, model_path.c_str(), session_options_);
#endif

    Ort::AllocatorWithDefaultOptions allocator;
    auto input_name = session_->GetInputNameAllocated(0, allocator);
    auto output_name = session_->GetOutputNameAllocated(0, allocator);
    input_name_ = input_name.get();
    output_name_ = output_name.get();
    const auto input_info = session_->GetInputTypeInfo(0).GetTensorTypeAndShapeInfo();
    const auto output_info = session_->GetOutputTypeInfo(0).GetTensorTypeAndShapeInfo();
    input_shape_ = input_info.GetShape();
    output_shape_ = output_info.GetShape();

    if (
      input_shape_.empty() || output_shape_.empty() ||
      input_shape_.back() != static_cast<int64_t>(kPolicyInputSize) ||
      output_shape_.back() != static_cast<int64_t>(kPolicyOutputSize))
    {
      throw std::runtime_error(
              "walk policy has unexpected tensor size: expected 51 inputs and 14 outputs");
    }
  }

  PolicyArray run(const std::array<float, kPolicyInputSize> & input)
  {
    std::array<float, kPolicyInputSize> input_copy = input;
    std::array<int64_t, 2> input_shape{1, static_cast<int64_t>(kPolicyInputSize)};
    auto input_tensor = Ort::Value::CreateTensor<float>(
      memory_info_, input_copy.data(), input_copy.size(), input_shape.data(), input_shape.size());

    const char * input_names[] = {input_name_.c_str()};
    const char * output_names[] = {output_name_.c_str()};
    auto outputs = session_->Run(
      Ort::RunOptions{nullptr}, input_names, &input_tensor, 1, output_names, 1);

    const float * output_data = outputs.front().GetTensorData<float>();
    PolicyArray actions{};
    std::copy(output_data, output_data + actions.size(), actions.begin());
    return actions;
  }

private:
  Ort::Env env_;
  Ort::SessionOptions session_options_;
  Ort::MemoryInfo memory_info_;
  std::unique_ptr<Ort::Session> session_;
  std::string input_name_;
  std::string output_name_;
  std::vector<int64_t> input_shape_;
  std::vector<int64_t> output_shape_;
};
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
    low_state_topic_ = declare_parameter<std::string>(
      "low_state_topic", booster::robot::b1::kTopicLowState);
    set_enabled_service_ = declare_parameter<std::string>(
      "set_enabled_service", "/booster_soccer/rl_motion/set_enabled");
    state_topic_ = declare_parameter<std::string>(
      "state_topic", "/booster_soccer/rl_motion/state");
    publish_hz_ = declare_parameter<double>("publish_hz", 50.0);
    policy_hz_ = declare_parameter<double>("policy_hz", 50.0);
    max_joint_velocity_rad_s_ = declare_parameter<double>("max_joint_velocity_rad_s", 1.0);
    action_scale_ = declare_parameter<double>("action_scale", 0.25);
    joint_velocity_factor_ = declare_parameter<double>("joint_velocity_factor", 0.1);
    frequency_base_ = declare_parameter<double>("frequency_base", 1.5);
    frequency_clip_min_ = declare_parameter<double>("frequency_clip_min", -0.5);
    frequency_clip_max_ = declare_parameter<double>("frequency_clip_max", 0.5);
    kp_scale_ = declare_parameter<double>("kp_scale", 0.25);
    kd_scale_ = declare_parameter<double>("kd_scale", 0.5);
    command_scale_x_ = declare_parameter<double>("command_scale_x", 1.0);
    command_scale_y_ = declare_parameter<double>("command_scale_y", 1.0);
    command_scale_yaw_ = declare_parameter<double>("command_scale_yaw", 1.0);
    max_cmd_vel_x_ = declare_parameter<double>("max_cmd_vel_x", 0.6);
    max_cmd_vel_y_ = declare_parameter<double>("max_cmd_vel_y", 0.4);
    max_cmd_vel_yaw_ = declare_parameter<double>("max_cmd_vel_yaw", 1.0);
    observation_order_ = declare_parameter<std::string>("observation_order", "gravity_ang_vel");
    const auto controlled_joint_indices = declare_parameter<std::string>(
      "controlled_joint_indices", "10,11,12,13,14,15,16,17,18,19,20,21,22");
    const auto start_enabled = declare_parameter<bool>("start_enabled", false);
    auto_change_mode_ = declare_parameter<bool>("auto_change_mode", false);
    return_to_prepare_on_disable_ = declare_parameter<bool>("return_to_prepare_on_disable", false);
    const auto cmd_type = declare_parameter<std::string>("cmd_type", "parallel");

    try {
      controlled_joint_indices_ = parse_joint_indices(controlled_joint_indices);
    } catch (const std::exception & error) {
      RCLCPP_FATAL(get_logger(), "Invalid controlled_joint_indices: %s", error.what());
      throw;
    }
    if (controlled_joint_indices_.size() != kPolicyControlledJointCount) {
      throw std::runtime_error(
              "controlled_joint_indices must contain exactly 13 comma-separated entries");
    }
    frequency_ = static_cast<float>(frequency_base_);
    raw_frequency_ = static_cast<float>(frequency_base_);

    RCLCPP_INFO(
      get_logger(),
      "Starting motion_control_node: model_path='%s', network_interface='%s', sdk_domain_id=%d, "
      "publish_hz=%.1f, start_enabled=%s, auto_change_mode=%s, cmd_type=%s",
      model_path_.c_str(), network_interface.c_str(), domain_id, publish_hz_,
      start_enabled ? "true" : "false",
      auto_change_mode_ ? "true" : "false",
      cmd_type.c_str());
    RCLCPP_INFO(
      get_logger(), "Controlled policy joints: [%s]",
      join_indices(controlled_joint_indices_).c_str());
    if (model_path_.empty()) {
      RCLCPP_WARN(get_logger(), "model_path is empty");
    } else if (!std::filesystem::exists(model_path_)) {
      RCLCPP_ERROR(get_logger(), "model_path does not exist: %s", model_path_.c_str());
    } else {
      RCLCPP_INFO(get_logger(), "Found configured model file: %s", model_path_.c_str());
      try {
        policy_ = std::make_unique<OnnxPolicy>(model_path_);
        RCLCPP_INFO(
          get_logger(),
          "Loaded ONNX walk policy: 51 inputs -> 13 joint targets + 1 frequency output");
      } catch (const std::exception & error) {
        RCLCPP_FATAL(get_logger(), "Failed to load ONNX walk policy: %s", error.what());
        throw;
      }
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
    low_state_sub_ =
      std::make_shared<booster::robot::ChannelSubscriber<booster_interface::msg::LowState>>(
      low_state_topic_,
      [this](const void * msg) {
        on_low_state(static_cast<const booster_interface::msg::LowState *>(msg));
      });
    low_state_sub_->InitChannel();
    RCLCPP_INFO(
      get_logger(), "LowState subscriber initialized on SDK topic '%s'",
      low_state_topic_.c_str());

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
        latest_cmd_vel_.linear.x =
          std::clamp(latest_cmd_vel_.linear.x, -max_cmd_vel_x_, max_cmd_vel_x_);
        latest_cmd_vel_.linear.y =
          std::clamp(latest_cmd_vel_.linear.y, -max_cmd_vel_y_, max_cmd_vel_y_);
        latest_cmd_vel_.angular.z =
          std::clamp(latest_cmd_vel_.angular.z, -max_cmd_vel_yaw_, max_cmd_vel_yaw_);
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
      "motion_control_node publishes low-level ONNX policy commands only when enabled. Start with "
      "small cmd_vel values and keep the robot supported for the first test.");
  }

private:
  struct LowStateSnapshot
  {
    std::array<float, 3> rpy{};
    std::array<float, 3> gyro{};
    JointArray q{};
    JointArray dq{};
    rclcpp::Time stamp;
  };

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
    last_requested_offsets_.fill(0.0F);
    phase_ = 0.0F;
    frequency_ = static_cast<float>(frequency_base_);
    raw_frequency_ = static_cast<float>(frequency_base_);
    target_pose_ = stand_pose_;
    current_pose_ = stand_pose_;
    next_policy_time_ = std::chrono::steady_clock::now();
    last_policy_time_.reset();

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

    const auto low_state = latest_low_state();
    if (!low_state) {
      RCLCPP_WARN_THROTTLE(
        get_logger(), *get_clock(), 2000,
        "No LowState received yet on '%s'; holding stand pose", low_state_topic_.c_str());
      target_pose_ = stand_pose_;
      publish_low_cmd();
      return;
    }

    const double state_age = (now() - low_state->stamp).seconds();
    if (state_age > 0.5) {
      RCLCPP_WARN_THROTTLE(
        get_logger(), *get_clock(), 2000,
        "Latest LowState is stale (%.3fs old); holding stand pose", state_age);
      target_pose_ = stand_pose_;
      publish_low_cmd();
      return;
    }

    if (!policy_) {
      RCLCPP_WARN_THROTTLE(
        get_logger(), *get_clock(), 2000,
        "ONNX policy is not loaded; holding stand pose");
      target_pose_ = stand_pose_;
      publish_low_cmd();
      return;
    }

    const auto period = std::chrono::duration<double>(1.0 / std::max(1.0, policy_hz_));
    const auto now_time = std::chrono::steady_clock::now();
    if (now_time >= next_policy_time_) {
      next_policy_time_ =
        now_time + std::chrono::duration_cast<std::chrono::steady_clock::duration>(period);
      try {
        update_walk_phase(now_time);
        const auto observation = build_observation(*low_state);
        const auto policy_output = policy_->run(observation);
        std::array<float, kPolicyOutputSize> clipped_output = policy_output;
        for (float & value : clipped_output) {
          value = std::clamp(value, -1.0F, 1.0F);
        }

        target_pose_ = stand_pose_;
        for (size_t i = 0; i < controlled_joint_indices_.size(); ++i) {
          const size_t joint = controlled_joint_indices_[i];
          const float requested_offset =
            static_cast<float>(action_scale_) * clipped_output[i];
          target_pose_[joint] += requested_offset;
          last_requested_offsets_[i] = requested_offset;
        }
        raw_frequency_ = clipped_output[kPolicyControlledJointCount];
        frequency_ =
          std::clamp(raw_frequency_, static_cast<float>(frequency_clip_min_),
          static_cast<float>(frequency_clip_max_)) +
          static_cast<float>(frequency_base_);
      } catch (const std::exception & error) {
        RCLCPP_ERROR_THROTTLE(
          get_logger(), *get_clock(), 2000,
          "ONNX policy inference failed: %s; holding previous target", error.what());
      }
    }

    publish_low_cmd();
  }

  void publish_low_cmd()
  {
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
        "Publishing ONNX LowCmd at %.1f Hz with policy_hz=%.1f and action_scale=%.3f",
        publish_hz_, policy_hz_, action_scale_);
    }
  }

  std::array<float, kPolicyInputSize> build_observation(const LowStateSnapshot & state) const
  {
    std::array<float, kPolicyInputSize> observation{};
    size_t offset = 0;
    const auto gravity = projected_gravity_from_rpy(state.rpy);

    auto append3 = [&observation, &offset](const std::array<float, 3> & values) {
        for (float value : values) {
          observation[offset++] = value;
        }
      };

    if (observation_order_ == "gravity_ang_vel") {
      append3(gravity);
      append3(state.gyro);
    } else {
      append3(state.gyro);
      append3(gravity);
    }

    observation[offset++] = static_cast<float>(latest_cmd_vel_.linear.x * command_scale_x_);
    observation[offset++] = static_cast<float>(latest_cmd_vel_.linear.y * command_scale_y_);
    observation[offset++] = static_cast<float>(latest_cmd_vel_.angular.z * command_scale_yaw_);

    if (is_walk_command_active()) {
      observation[offset++] = std::cos(kTwoPi * phase_);
      observation[offset++] = std::sin(kTwoPi * phase_);
    } else {
      observation[offset++] = 0.0F;
      observation[offset++] = 0.0F;
    }

    for (const size_t joint : controlled_joint_indices_) {
      observation[offset++] = state.q[joint] - stand_pose_[joint];
    }
    for (const size_t joint : controlled_joint_indices_) {
      observation[offset++] = state.dq[joint] * static_cast<float>(joint_velocity_factor_);
    }
    for (float requested_offset : last_requested_offsets_) {
      observation[offset++] = requested_offset;
    }
    observation[offset++] = raw_frequency_;

    return observation;
  }

  bool is_walk_command_active() const
  {
    return std::abs(latest_cmd_vel_.linear.x) > kCommandDeadband ||
           std::abs(latest_cmd_vel_.linear.y) > kCommandDeadband ||
           std::abs(latest_cmd_vel_.angular.z) > kCommandDeadband;
  }

  void update_walk_phase(const std::chrono::steady_clock::time_point & now_time)
  {
    if (!last_policy_time_) {
      last_policy_time_ = now_time;
      return;
    }

    const float dt = std::chrono::duration<float>(now_time - *last_policy_time_).count();
    last_policy_time_ = now_time;
    if (!is_walk_command_active()) {
      phase_ = 0.0F;
      return;
    }

    phase_ += std::max(0.0F, dt) * std::max(0.0F, frequency_);
    phase_ -= std::floor(phase_);
  }

  void on_low_state(const booster_interface::msg::LowState * msg)
  {
    if (msg == nullptr) {
      return;
    }

    const auto & serial = msg->motor_state_serial();
    const auto & parallel = msg->motor_state_parallel();
    const auto & motors = serial.size() >= kJointCount ? serial : parallel;
    if (motors.size() < kJointCount) {
      RCLCPP_WARN_THROTTLE(
        get_logger(), *get_clock(), 2000,
        "LowState has too few motors: serial=%zu parallel=%zu",
        serial.size(), parallel.size());
      return;
    }

    LowStateSnapshot snapshot;
    snapshot.rpy = msg->imu_state().rpy();
    snapshot.gyro = msg->imu_state().gyro();
    snapshot.stamp = now();
    for (size_t i = 0; i < kJointCount; ++i) {
      snapshot.q[i] = motors[i].q();
      snapshot.dq[i] = motors[i].dq();
    }

    {
      std::lock_guard<std::mutex> lock(low_state_mutex_);
      latest_low_state_ = snapshot;
    }
  }

  std::optional<LowStateSnapshot> latest_low_state() const
  {
    std::lock_guard<std::mutex> lock(low_state_mutex_);
    return latest_low_state_;
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
  std::string low_state_topic_;
  std::string set_enabled_service_;
  std::string state_topic_;
  std::string observation_order_;

  double publish_hz_{50.0};
  double policy_hz_{50.0};
  double max_joint_velocity_rad_s_{1.0};
  double action_scale_{0.25};
  double joint_velocity_factor_{0.1};
  double frequency_base_{1.5};
  double frequency_clip_min_{-0.5};
  double frequency_clip_max_{0.5};
  double kp_scale_{0.25};
  double kd_scale_{0.5};
  double command_scale_x_{1.0};
  double command_scale_y_{1.0};
  double command_scale_yaw_{1.0};
  double max_cmd_vel_x_{0.6};
  double max_cmd_vel_y_{0.4};
  double max_cmd_vel_yaw_{1.0};
  bool auto_change_mode_{false};
  bool return_to_prepare_on_disable_{false};
  bool enabled_{false};
  bool logged_first_low_cmd_{false};

  geometry_msgs::msg::Twist latest_cmd_vel_;
  const JointArray stand_pose_{stand_pose()};
  JointArray target_pose_;
  JointArray current_pose_;
  JointArray kp_;
  JointArray kd_;
  ControlledJointArray last_requested_offsets_{};
  float phase_{0.0F};
  float frequency_{1.5F};
  float raw_frequency_{1.5F};
  std::vector<size_t> controlled_joint_indices_;
  std::unique_ptr<OnnxPolicy> policy_;
  std::chrono::steady_clock::time_point next_policy_time_{std::chrono::steady_clock::now()};
  std::optional<std::chrono::steady_clock::time_point> last_policy_time_;
  mutable std::mutex low_state_mutex_;
  std::optional<LowStateSnapshot> latest_low_state_;
  booster_interface::msg::LowCmd low_cmd_;

  std::shared_ptr<booster::robot::ChannelPublisher<booster_interface::msg::LowCmd>> low_cmd_pub_;
  std::shared_ptr<booster::robot::ChannelSubscriber<booster_interface::msg::LowState>> low_state_sub_;
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
