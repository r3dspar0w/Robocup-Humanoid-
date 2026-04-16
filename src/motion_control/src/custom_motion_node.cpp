#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iomanip>
#include <limits>
#include <map>
#include <memory>
#include <mutex>
#include <sstream>
#include <string>
#include <vector>

#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"
#include "booster_interface/msg/low_cmd.hpp"
#include "booster_interface/msg/raw_bytes_msg.hpp"
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

constexpr float degToRad(float degrees) {
    return degrees * kPi / 180.0f;
}

constexpr float kJointLimitWarningTolerance = degToRad(2.0f);
constexpr float kLargeTargetJumpWarning = degToRad(25.0f);
constexpr float kTiltWarningRad = degToRad(35.0f);
constexpr float kTiltCriticalRad = degToRad(50.0f);
constexpr float kAggressiveCmdWarnVx = 0.6f;
constexpr float kAggressiveCmdWarnVy = 0.25f;
constexpr float kAggressiveCmdWarnYaw = 0.5f;
constexpr uint32_t kCommHzWarnThreshold = 80;

constexpr std::array<float, kMotorCount> kJointUpperLimits = {
        1.57f, 1.22f, 1.22f, 1.57f, 2.27f, 0.0f, 1.22f, 1.74f, 2.27f, 2.44f, 1.57f, 1.57f,
        1.57f, 1.0f, 2.34f, 0.35f, 0.44f, 1.57f, 0.2f, 1.0f, 2.34f, 0.35f, 0.44f,
};

constexpr std::array<float, kMotorCount> kJointLowerLimits = {
        -1.57f, -0.35f, -3.31f, -1.74f, -2.27f, -2.44f, -3.31f, -1.57f, -2.27f, 0.0f, -1.57f,
        -1.8f, -0.2f, -1.0f, 0.0f, -0.87f, -0.44f, -1.8f, -1.57f, -1.0f, 0.0f, -0.87f, -0.44f,
};

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

struct RecoveryStateData {
    uint8_t state;
    uint8_t is_recovery_available;
    uint8_t current_planner_index;
};

enum class ControlPhase {
    kWaitingForSensor,
    kHold,
    kPolicyActive
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

std::string summarizeMessages(const std::vector<std::string> &messages, size_t max_items = 4) {
    std::ostringstream oss;
    for (size_t i = 0; i < messages.size() && i < max_items; ++i) {
        if (i > 0) {
            oss << "; ";
        }
        oss << messages[i];
    }
    if (messages.size() > max_items) {
        oss << "; +" << (messages.size() - max_items) << " more";
    }
    return oss.str();
}

std::string formatAgeMs(double age_ms) {
    if (!std::isfinite(age_ms)) {
        return "inf";
    }
    return formatFloat(static_cast<float>(age_ms), 1);
}

std::string controlPhaseName(ControlPhase phase) {
    switch (phase) {
        case ControlPhase::kWaitingForSensor:
            return "waiting_for_sensor";
        case ControlPhase::kHold:
            return "hold";
        case ControlPhase::kPolicyActive:
            return "policy_active";
        default:
            return "unknown";
    }
}

std::string recoveryStateName(uint8_t state) {
    switch (state) {
        case 0:
            return "IS_READY";
        case 1:
            return "IS_FALLING";
        case 2:
            return "HAS_FALLEN";
        case 3:
            return "IS_GETTING_UP";
        default:
            return "UNKNOWN(" + std::to_string(state) + ")";
    }
}

std::string summarizeModeHistogram(const std::map<int, size_t> &mode_counts) {
    std::ostringstream oss;
    bool first = true;
    for (const auto &entry : mode_counts) {
        if (!first) {
            oss << ", ";
        }
        first = false;
        oss << "mode" << entry.first << "=" << entry.second;
    }
    if (first) {
        return "none";
    }
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
        declare_parameter<std::string>("robot.custom_walk_recovery_state_topic", "fall_down_recovery_state");
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
        const auto recovery_state_topic = appendRobotSuffix(
                get_parameter("robot.custom_walk_recovery_state_topic").as_string(), robot_name_);
        low_cmd_topic_name_ = low_cmd_topic;

        low_state_sub_ = create_subscription<booster_interface::msg::LowState>(
                low_state_topic,
                10,
                std::bind(&CustomMotionNode::onLowState, this, std::placeholders::_1));
        recovery_state_sub_ = create_subscription<booster_interface::msg::RawBytesMsg>(
                recovery_state_topic,
                10,
                std::bind(&CustomMotionNode::onRecoveryState, this, std::placeholders::_1));
        low_cmd_pub_ = create_publisher<booster_interface::msg::LowCmd>(low_cmd_topic, 10);

        RCLCPP_INFO(get_logger(),
                    "motion_control using ROS low-level topics: state=%s cmd=%s",
                    low_state_topic.c_str(),
                    low_cmd_topic.c_str());
        logEvent("INFO",
                 "Configured motion_control with state_topic=" + low_state_topic +
                 ", cmd_topic=" + low_cmd_topic +
                 ", walk_cmd_topic=" + command_topic +
                 ", recovery_state_topic=" + recovery_state_topic +
                 ", loop_hz=" + formatFloat(loop_hz_, 1) +
                 ", command_timeout_ms=" + formatFloat(cmd_timeout_ms_, 1));

#ifdef MOTION_CONTROL_HAVE_ONNX_RUNTIME
        policy_backend_ = std::make_unique<OnnxPolicyBackend>();
        logEvent("INFO", "motion_control built with ONNX Runtime support");
#else
        policy_backend_ = std::make_unique<NullPolicyBackend>();
        logEvent("WARN", "motion_control was built without ONNX Runtime; policy inference is disabled");
#endif

        model_path_ = get_parameter("robot.custom_walk_model_path").as_string();
        policy_loaded_ = policy_backend_->load(model_path_, expectedObservationSize(), get_logger());
        if (!policy_loaded_) {
            RCLCPP_WARN(get_logger(),
                        "Locomotion policy backend is not active yet. The node will keep the current stance.");
            logEvent("WARN",
                     "Policy backend inactive for model_path=" + model_path_ +
                     ". This can happen if the ONNX file is missing or ONNX Runtime was not found.");
        } else {
            logEvent("INFO", "Loaded locomotion policy from " + model_path_);
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

    std::string formatCommandTriple(float vx, float vy, float yaw) const {
        return "vx=" + formatFloat(vx) +
               ", vy=" + formatFloat(vy) +
               ", yaw=" + formatFloat(yaw);
    }

    void updateControlPhase(ControlPhase next_phase,
                            const std::string &reason,
                            double sensor_age_ms,
                            double command_age_ms,
                            float cmd_x,
                            float cmd_y,
                            float cmd_yaw) {
        if (control_phase_initialized_ && next_phase == control_phase_) {
            return;
        }

        const std::string previous_phase = control_phase_initialized_
                ? controlPhaseName(control_phase_)
                : std::string("<none>");
        control_phase_ = next_phase;
        control_phase_initialized_ = true;

        const std::string level = next_phase == ControlPhase::kPolicyActive ? "INFO" : "WARN";
        logEvent(level,
                 "Controller phase transition: " + previous_phase +
                 " -> " + controlPhaseName(control_phase_) +
                 ", reason=" + reason +
                 ", sensor_age_ms=" + formatAgeMs(sensor_age_ms) +
                 ", command_age_ms=" + formatAgeMs(command_age_ms) +
                 ", command=" + formatCommandTriple(cmd_x, cmd_y, cmd_yaw));
    }

    void onRecoveryState(const booster_interface::msg::RawBytesMsg::SharedPtr msg) {
        if (msg->msg.size() < sizeof(RecoveryStateData)) {
            if (shouldLogEvery(last_recovery_parse_warning_log_time_, 2000.0)) {
                logEvent("WARN",
                         "Recovery-state packet too short: bytes=" + std::to_string(msg->msg.size()) +
                         ", expected>=" + std::to_string(sizeof(RecoveryStateData)));
            }
            return;
        }

        RecoveryStateData state{};
        std::memcpy(&state, msg->msg.data(), sizeof(RecoveryStateData));

        const bool changed = !recovery_state_initialized_ ||
                             state.state != last_recovery_state_ ||
                             state.is_recovery_available != last_recovery_available_ ||
                             state.current_planner_index != last_planner_index_;

        if (changed) {
            const std::string previous_state = recovery_state_initialized_
                    ? recoveryStateName(last_recovery_state_)
                    : std::string("<none>");
            const std::string message =
                    "Recovery/planner transition: state=" + previous_state +
                    " -> " + recoveryStateName(state.state) +
                    ", recovery_available=" +
                    (recovery_state_initialized_
                             ? std::to_string(static_cast<int>(last_recovery_available_)) + " -> "
                             : std::string("<none> -> ")) +
                    std::to_string(static_cast<int>(state.is_recovery_available)) +
                    ", planner_index=" +
                    (recovery_state_initialized_
                             ? std::to_string(static_cast<int>(last_planner_index_)) + " -> "
                             : std::string("<none> -> ")) +
                    std::to_string(static_cast<int>(state.current_planner_index));
            const bool is_fall_related = state.state == 1 || state.state == 2;
            logEvent(is_fall_related ? "WARN" : "INFO", message);
        }

        if ((state.state == 1 || state.state == 2) &&
            shouldLogEvery(last_recovery_alert_log_time_, 500.0)) {
            const double command_age_ms = has_received_command_
                    ? (now() - last_command_time_).nanoseconds() / 1e6
                    : std::numeric_limits<double>::infinity();
            logEvent("WARN",
                     "Recovery-state indicates instability (state=" + recoveryStateName(state.state) +
                     ", planner_index=" + std::to_string(static_cast<int>(state.current_planner_index)) +
                     ", command_age_ms=" + formatAgeMs(command_age_ms) +
                     ", last_walk_command=" +
                     formatCommandTriple(static_cast<float>(last_command_.linear.x),
                                         static_cast<float>(last_command_.linear.y),
                                         static_cast<float>(last_command_.angular.z)) + ")");
        }

        recovery_state_initialized_ = true;
        last_recovery_state_ = state.state;
        last_recovery_available_ = state.is_recovery_available;
        last_planner_index_ = state.current_planner_index;
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

            const float vx = std::fabs(static_cast<float>(msg->linear.x));
            const float vy = std::fabs(static_cast<float>(msg->linear.y));
            const float yaw = std::fabs(static_cast<float>(msg->angular.z));
            if ((vx > kAggressiveCmdWarnVx || vy > kAggressiveCmdWarnVy || yaw > kAggressiveCmdWarnYaw) &&
                shouldLogEvery(last_aggressive_command_log_time_, 500.0)) {
                logEvent("WARN",
                         "Received aggressive walk command that may exceed policy training envelope: " +
                         formatCommandTriple(static_cast<float>(msg->linear.x),
                                             static_cast<float>(msg->linear.y),
                                             static_cast<float>(msg->angular.z)) +
                         " (warn_thresholds vx<=" + formatFloat(kAggressiveCmdWarnVx, 2) +
                         ", vy<=" + formatFloat(kAggressiveCmdWarnVy, 2) +
                         ", yaw<=" + formatFloat(kAggressiveCmdWarnYaw, 2) + ")");
            }
        } else if (last_received_motion_command_) {
            logEvent("INFO", "Received explicit zero walk command; controller will settle to stance");
        }
        last_received_motion_command_ = has_motion;
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

        const float abs_roll = std::fabs(snapshot.rpy[0]);
        const float abs_pitch = std::fabs(snapshot.rpy[1]);
        const float max_tilt = std::max(abs_roll, abs_pitch);
        if (max_tilt > kTiltWarningRad &&
            shouldLogEvery(last_imu_tilt_log_time_, 250.0)) {
            const std::string level = max_tilt > kTiltCriticalRad ? "WARN" : "INFO";
            logEvent(level,
                     "IMU tilt is high (roll=" + formatFloat(snapshot.rpy[0]) +
                     ", pitch=" + formatFloat(snapshot.rpy[1]) +
                     ", yaw=" + formatFloat(snapshot.rpy[2]) +
                     "). High tilt can trigger protection/damping.");
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
        const auto loop_now = now();
        SensorSnapshot snapshot;
        std::array<float, kMotorCount> stand_pose{};
        rclcpp::Time last_sensor_time{0, 0, RCL_ROS_TIME};
        bool has_sensor_snapshot = false;
        bool stand_pose_initialized = false;
        bool received_first_sensor = false;
        {
            std::lock_guard<std::mutex> lock(sensor_mutex_);
            has_sensor_snapshot = has_sensor_snapshot_;
            stand_pose_initialized = stand_pose_initialized_;
            received_first_sensor = received_first_sensor_snapshot_;
            snapshot = sensor_snapshot_;
            stand_pose = stand_pose_;
            last_sensor_time = last_sensor_time_;
        }

        if (!has_sensor_snapshot || !stand_pose_initialized) {
            std::vector<std::string> blockers;
            if (!has_sensor_snapshot) {
                blockers.emplace_back("no_sensor_snapshot");
            }
            if (!received_first_sensor) {
                blockers.emplace_back("first_low_state_not_received");
            }
            if (!stand_pose_initialized) {
                blockers.emplace_back("stand_pose_not_initialized");
            }
            updateControlPhase(ControlPhase::kWaitingForSensor,
                               summarizeMessages(blockers, 6),
                               std::numeric_limits<double>::infinity(),
                               std::numeric_limits<double>::infinity(),
                               0.0f,
                               0.0f,
                               0.0f);

            if (shouldLogEvery(last_waiting_for_sensor_log_time_, 2000.0)) {
                logEvent("WARN",
                         "controlLoop is blocked while waiting for low-level state (" +
                         summarizeMessages(blockers, 6) +
                         "). Without a stable low-level state stream, T1 can fall back to DAMP/PROTECT.");
            }
            return;
        }

        const double sensor_age_ms = (loop_now - last_sensor_time).nanoseconds() / 1e6;
        if (sensor_age_ms > 500.0 && shouldLogEvery(last_sensor_timeout_log_time_, 1000.0)) {
            logEvent("WARN",
                     "LowState stream is stale for " + formatFloat(static_cast<float>(sensor_age_ms), 1) +
                     " ms. The robot may enter DAMP/PROTECT if low-level control becomes uncontrolled.");
        }

        const double command_age_ms = has_received_command_
                ? (loop_now - last_command_time_).nanoseconds() / 1e6
                : std::numeric_limits<double>::infinity();
        const bool command_is_fresh =
                has_received_command_ && command_age_ms < cmd_timeout_ms_;

        if (!has_received_command_ && shouldLogEvery(last_waiting_for_command_log_time_, 2000.0)) {
            logEvent("WARN",
                     "No walk command has been received yet; holding stance until /custom_walk_cmd is active.");
        }

        if (has_received_command_ && command_is_fresh != last_command_fresh_) {
            last_command_fresh_ = command_is_fresh;
            logEvent(command_is_fresh ? "INFO" : "WARN",
                     command_is_fresh
                             ? ("Walk command stream is fresh again (age_ms=" +
                                formatFloat(static_cast<float>(command_age_ms), 1) + ")")
                             : ("Walk command stream is stale (age_ms=" +
                                formatFloat(static_cast<float>(command_age_ms), 1) +
                                ", timeout_ms=" + formatFloat(cmd_timeout_ms_, 1) +
                                "). Holding the policy reference pose. Last command " +
                                formatCommandTriple(static_cast<float>(last_command_.linear.x),
                                                    static_cast<float>(last_command_.linear.y),
                                                    static_cast<float>(last_command_.angular.z))));
        }
        const float cmd_x = command_is_fresh ? static_cast<float>(last_command_.linear.x) : 0.f;
        const float cmd_y = command_is_fresh ? static_cast<float>(last_command_.linear.y) : 0.f;
        const float cmd_yaw = command_is_fresh ? static_cast<float>(last_command_.angular.z) : 0.f;

        std::vector<std::string> hold_reasons;
        if (!has_received_command_) {
            hold_reasons.emplace_back("walk_command_missing");
        } else if (!command_is_fresh) {
            hold_reasons.emplace_back("walk_command_timed_out");
        }
        if (!policy_loaded_) {
            hold_reasons.emplace_back("policy_backend_inactive");
        }
        if (!hold_reasons.empty() && shouldLogEvery(last_hold_reason_log_time_, 1000.0)) {
            std::string reason_details = summarizeMessages(hold_reasons, 6);
            if (!policy_loaded_) {
                reason_details += " (model_path=" + (model_path_.empty() ? std::string("<empty>") : model_path_) + ")";
            }
            logEvent("WARN",
                     "Control loop is commanding hold behavior because: " + reason_details +
                     ". Command age_ms=" +
                     (has_received_command_
                              ? formatFloat(static_cast<float>(command_age_ms), 1)
                               : std::string("inf")));
        }
        const std::string control_reason = hold_reasons.empty()
                ? std::string("command_fresh_and_policy_loaded")
                : summarizeMessages(hold_reasons, 6);
        const ControlPhase next_phase = hold_reasons.empty()
                ? ControlPhase::kPolicyActive
                : ControlPhase::kHold;
        updateControlPhase(next_phase,
                           control_reason,
                           sensor_age_ms,
                           command_age_ms,
                           cmd_x,
                           cmd_y,
                           cmd_yaw);

        std::array<float, kMotorCount> target_positions = snapshot.q;

        if (policy_loaded_ && command_is_fresh) {
            const auto observation = buildObservation(snapshot, stand_pose, cmd_x, cmd_y, cmd_yaw);
            const auto policy_output = policy_backend_->infer(observation);
            if (policy_output.size() >= kPolicyActionCount) {
                target_positions = stand_pose;
                size_t saturated_actions = 0;
                float max_abs_action = 0.0f;
                size_t max_abs_action_index = 0;
                for (size_t i = 0; i < kPolicyActionCount; ++i) {
                    float action = 0.0f;
                    if (std::isfinite(policy_output[i])) {
                        action = std::clamp(policy_output[i], -1.0f, 1.0f);
                    } else if (shouldLogEvery(last_non_finite_action_log_time_, 1000.0)) {
                        logEvent("WARN", "Policy produced a non-finite action at index " + std::to_string(i));
                    }
                    last_actions_[i] = action;
                    const float abs_action = std::fabs(action);
                    if (abs_action > max_abs_action) {
                        max_abs_action = abs_action;
                        max_abs_action_index = i;
                    }
                    if (abs_action >= 0.999f) {
                        ++saturated_actions;
                    }
                    const size_t joint_index = kPolicyDofStartIndex + i;
                    target_positions[joint_index] = stand_pose[joint_index] + action * kPolicyActionScale;
                }
                if ((saturated_actions > 0 || max_abs_action > 0.95f) &&
                    shouldLogEvery(last_policy_action_stats_log_time_, 1000.0)) {
                    logEvent("WARN",
                             "Policy action magnitude is high (max_abs_action=" +
                             formatFloat(max_abs_action) +
                             " at action_index=" + std::to_string(max_abs_action_index) +
                             ", saturated_actions=" + std::to_string(saturated_actions) +
                             "/" + std::to_string(kPolicyActionCount) +
                             "). This can destabilize the robot if persisted.");
                }
            } else if (shouldLogEvery(last_policy_output_warning_time_, 1000.0)) {
                logEvent("WARN",
                         "Policy output had only " + std::to_string(policy_output.size()) +
                         " values; expected at least " + std::to_string(kPolicyActionCount) +
                         ". Holding the policy reference pose. Observation size=" +
                         std::to_string(observation.size()) +
                         ", command=" + formatCommandTriple(cmd_x, cmd_y, cmd_yaw));
            }
        } else {
            std::fill(last_actions_.begin(), last_actions_.end(), 0.0f);
        }

        checkCurrentJointLimits(snapshot.q);
        checkTargetJointHealth(target_positions, snapshot.q, cmd_x, cmd_y, cmd_yaw);
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
        std::map<int, size_t> mode_counts;
        std::array<int, kMotorCount> current_modes{};
        size_t nonzero_error_count = 0;
        size_t low_comm_hz_count = 0;
        size_t zero_comm_hz_count = 0;
        std::vector<std::string> error_samples;
        std::vector<std::string> low_comm_samples;
        std::vector<std::string> mode_diff_from_baseline_samples;

        for (size_t i = 0; i < kMotorCount; ++i) {
            const auto &motor = msg.motor_state_serial[i];
            const uint32_t error_flags = motor.reserve[0];
            const uint32_t comm_hz = motor.reserve[1];
            const int current_mode = static_cast<int>(motor.mode);

            current_modes[i] = current_mode;
            mode_counts[current_mode] += 1;

            if (error_flags != 0) {
                ++nonzero_error_count;
                if (error_samples.size() < 4) {
                    error_samples.emplace_back(
                            std::string(kMotorNames[i]) + "=" + formatHex(error_flags));
                }
            }

            if (comm_hz == 0) {
                ++zero_comm_hz_count;
                if (low_comm_samples.size() < 4) {
                    low_comm_samples.emplace_back(
                            std::string(kMotorNames[i]) + "=0");
                }
            } else if (comm_hz < kCommHzWarnThreshold) {
                ++low_comm_hz_count;
                if (low_comm_samples.size() < 4) {
                    low_comm_samples.emplace_back(
                            std::string(kMotorNames[i]) + "=" + std::to_string(comm_hz));
                }
            }

            if (baseline_motor_modes_initialized_ && current_mode != baseline_motor_modes_[i] &&
                mode_diff_from_baseline_samples.size() < 4) {
                mode_diff_from_baseline_samples.emplace_back(
                        std::string(kMotorNames[i]) + ":" +
                        std::to_string(baseline_motor_modes_[i]) + "->" +
                        std::to_string(current_mode));
            }

            if (!motor_diagnostics_initialized_) {
                last_motor_modes_[i] = current_mode;
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

            if (current_mode != last_motor_modes_[i]) {
                logEvent("INFO",
                         "Motor mode change on " + std::string(kMotorNames[i]) +
                         ": " + std::to_string(last_motor_modes_[i]) +
                         " -> " + std::to_string(current_mode));
                last_motor_modes_[i] = current_mode;
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

        if (!baseline_motor_modes_initialized_) {
            baseline_motor_modes_ = current_modes;
            baseline_motor_modes_initialized_ = true;
            logEvent("INFO",
                     "Captured motor mode baseline: " + summarizeModeHistogram(mode_counts));
        }

        size_t modes_changed_from_baseline = 0;
        if (baseline_motor_modes_initialized_) {
            for (size_t i = 0; i < kMotorCount; ++i) {
                if (current_modes[i] != baseline_motor_modes_[i]) {
                    ++modes_changed_from_baseline;
                }
            }
        }

        const std::string mode_histogram = summarizeModeHistogram(mode_counts);
        if (!mode_histogram_initialized_ || mode_histogram != last_mode_histogram_) {
            const std::string level = modes_changed_from_baseline > 0 ? "WARN" : "INFO";
            std::string details =
                    "Motor mode histogram changed: " +
                    (mode_histogram_initialized_ ? last_mode_histogram_ : std::string("<none>")) +
                    " -> " + mode_histogram +
                    ", changed_from_baseline=" + std::to_string(modes_changed_from_baseline) +
                    "/" + std::to_string(kMotorCount);
            if (!mode_diff_from_baseline_samples.empty()) {
                details += ", sample=" + summarizeMessages(mode_diff_from_baseline_samples, 4);
            }
            logEvent(level, details);
            mode_histogram_initialized_ = true;
            last_mode_histogram_ = mode_histogram;
        }

        if (!error_flag_count_initialized_ || nonzero_error_count != last_nonzero_error_joint_count_) {
            std::string details =
                    "Motors with non-zero error flags: " +
                    (error_flag_count_initialized_
                             ? std::to_string(last_nonzero_error_joint_count_)
                             : std::string("<none>")) +
                    " -> " + std::to_string(nonzero_error_count);
            if (!error_samples.empty()) {
                details += ", sample=" + summarizeMessages(error_samples, 4);
            }
            logEvent(nonzero_error_count == 0 ? "INFO" : "WARN", details);
            error_flag_count_initialized_ = true;
            last_nonzero_error_joint_count_ = nonzero_error_count;
        }

        if (!comm_hz_count_initialized_ ||
            low_comm_hz_count != last_low_comm_hz_joint_count_ ||
            zero_comm_hz_count != last_zero_comm_hz_joint_count_) {
            std::string details =
                    "Motor comm-hz quality changed: low(<" + std::to_string(kCommHzWarnThreshold) + ")=" +
                    (comm_hz_count_initialized_
                             ? std::to_string(last_low_comm_hz_joint_count_)
                             : std::string("<none>")) +
                    " -> " + std::to_string(low_comm_hz_count) +
                    ", zero=" +
                    (comm_hz_count_initialized_
                             ? std::to_string(last_zero_comm_hz_joint_count_)
                             : std::string("<none>")) +
                    " -> " + std::to_string(zero_comm_hz_count);
            if (!low_comm_samples.empty()) {
                details += ", sample=" + summarizeMessages(low_comm_samples, 4);
            }
            const bool has_comm_issue = low_comm_hz_count > 0 || zero_comm_hz_count > 0;
            logEvent(has_comm_issue ? "WARN" : "INFO", details);
            comm_hz_count_initialized_ = true;
            last_low_comm_hz_joint_count_ = low_comm_hz_count;
            last_zero_comm_hz_joint_count_ = zero_comm_hz_count;
        }

        if (!motor_diagnostics_initialized_) {
            motor_diagnostics_initialized_ = true;
            logEvent("INFO", "Captured initial per-motor diagnostic snapshot");
        }
    }

    void checkCurrentJointLimits(const std::array<float, kMotorCount> &current_positions) {
        std::vector<std::string> violations;
        for (size_t i = 0; i < kMotorCount; ++i) {
            if (current_positions[i] < kJointLowerLimits[i] - kJointLimitWarningTolerance ||
                current_positions[i] > kJointUpperLimits[i] + kJointLimitWarningTolerance) {
                violations.push_back(
                        std::string(kMotorNames[i]) + "=" + formatFloat(current_positions[i]) +
                        " (allowed " + formatFloat(kJointLowerLimits[i]) +
                        " to " + formatFloat(kJointUpperLimits[i]) + ")");
            }
        }

        if (!violations.empty() && shouldLogEvery(last_joint_state_warning_time_, 1000.0)) {
            logEvent("WARN",
                     "Current joints are outside the configured serial joint limits: " +
                     summarizeMessages(violations));
        }
    }

    void checkTargetJointHealth(const std::array<float, kMotorCount> &target_positions,
                                const std::array<float, kMotorCount> &current_positions,
                                float cmd_x,
                                float cmd_y,
                                float cmd_yaw) {
        std::vector<std::string> target_limit_warnings;
        std::vector<std::string> non_finite_targets;
        float max_delta = 0.0f;
        size_t max_delta_index = 0;

        for (size_t i = 0; i < kMotorCount; ++i) {
            if (!std::isfinite(target_positions[i])) {
                non_finite_targets.emplace_back(std::string(kMotorNames[i]) + "=non_finite");
                continue;
            }

            if (target_positions[i] < kJointLowerLimits[i] ||
                target_positions[i] > kJointUpperLimits[i]) {
                target_limit_warnings.push_back(
                        std::string(kMotorNames[i]) + "=" + formatFloat(target_positions[i]) +
                        " (allowed " + formatFloat(kJointLowerLimits[i]) +
                        " to " + formatFloat(kJointUpperLimits[i]) + ")");
            }

            const float delta = std::fabs(target_positions[i] - current_positions[i]);
            if (delta > max_delta) {
                max_delta = delta;
                max_delta_index = i;
            }
        }

        if (!non_finite_targets.empty() && shouldLogEvery(last_non_finite_target_log_time_, 500.0)) {
            logEvent("WARN",
                     "Computed non-finite joint targets: " + summarizeMessages(non_finite_targets));
        }

        if (!target_limit_warnings.empty() && shouldLogEvery(last_joint_target_warning_time_, 1000.0)) {
            logEvent("WARN",
                     "Target joints exceed configured serial joint limits (not clamped): " +
                     summarizeMessages(target_limit_warnings));
        }

        if (max_delta > kLargeTargetJumpWarning && shouldLogEvery(last_large_target_jump_log_time_, 500.0)) {
            logEvent("WARN",
                     "Large joint target step detected on " + std::string(kMotorNames[max_delta_index]) +
                     ": current=" + formatFloat(current_positions[max_delta_index]) +
                     ", target=" + formatFloat(target_positions[max_delta_index]) +
                     ", delta=" + formatFloat(max_delta) +
                     " rad, command=" + formatCommandTriple(cmd_x, cmd_y, cmd_yaw));
        }
    }

    void publishLowCmd(const std::array<float, kMotorCount> &target_positions,
                       const std::array<float, kMotorCount> &current_positions) {
        const auto publish_now = now();
        if (last_low_cmd_publish_time_.nanoseconds() != 0) {
            const double publish_gap_ms = (publish_now - last_low_cmd_publish_time_).nanoseconds() / 1e6;
            const double expected_period_ms = 1000.0 / std::max(loop_hz_, 1.0f);
            if (publish_gap_ms > expected_period_ms * 2.5 &&
                shouldLogEvery(last_low_cmd_publish_gap_log_time_, 500.0)) {
                logEvent("WARN",
                         "LowCmd publish gap detected: gap_ms=" +
                         formatFloat(static_cast<float>(publish_gap_ms), 1) +
                         ", expected_period_ms=" + formatFloat(static_cast<float>(expected_period_ms), 1));
            }
        }
        last_low_cmd_publish_time_ = publish_now;

        const size_t low_cmd_subscribers = low_cmd_pub_->get_subscription_count();
        if (!low_cmd_subscription_count_initialized_ || low_cmd_subscribers != last_low_cmd_subscription_count_) {
            if (low_cmd_subscription_count_initialized_) {
                logEvent("INFO",
                         "low_cmd subscriber count changed: " +
                         std::to_string(last_low_cmd_subscription_count_) + " -> " +
                         std::to_string(low_cmd_subscribers));
            } else {
                logEvent("INFO",
                         "low_cmd subscriber count at startup: " + std::to_string(low_cmd_subscribers));
                low_cmd_subscription_count_initialized_ = true;
            }
            last_low_cmd_subscription_count_ = low_cmd_subscribers;
        }
        if (low_cmd_subscribers == 0 && shouldLogEvery(last_low_cmd_no_subscriber_log_time_, 2000.0)) {
            logEvent("WARN",
                     "No subscribers are currently attached to low_cmd. Commands may not reach the low-level controller.");
        }
        const size_t low_cmd_publishers = count_publishers(low_cmd_topic_name_);
        if (low_cmd_publishers > 1 && shouldLogEvery(last_low_cmd_multi_publisher_log_time_, 1000.0)) {
            logEvent("WARN",
                     "Detected " + std::to_string(low_cmd_publishers) +
                     " publishers on " + low_cmd_topic_name_ +
                     ". Multiple low_cmd publishers can fight each other and destabilize control.");
        }

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
    std::string model_path_;
    std::string low_cmd_topic_name_;
    bool has_received_command_ = false;
    bool has_sensor_snapshot_ = false;
    bool warned_motor_count_ = false;
    bool stand_pose_initialized_ = false;
    bool policy_loaded_ = false;
    bool received_first_sensor_snapshot_ = false;
    bool motor_diagnostics_initialized_ = false;
    bool last_command_fresh_ = false;
    bool last_received_motion_command_ = false;
    bool low_cmd_subscription_count_initialized_ = false;
    bool recovery_state_initialized_ = false;
    bool baseline_motor_modes_initialized_ = false;
    bool mode_histogram_initialized_ = false;
    bool error_flag_count_initialized_ = false;
    bool comm_hz_count_initialized_ = false;
    bool control_phase_initialized_ = false;
    float cmd_timeout_ms_ = 250.f;
    float loop_hz_ = 100.f;
    float gait_frequency_ = 1.5f;
    size_t last_low_cmd_subscription_count_ = 0;
    uint8_t last_recovery_state_ = 0;
    uint8_t last_recovery_available_ = 0;
    uint8_t last_planner_index_ = 0;
    size_t last_nonzero_error_joint_count_ = 0;
    size_t last_low_comm_hz_joint_count_ = 0;
    size_t last_zero_comm_hz_joint_count_ = 0;
    ControlPhase control_phase_ = ControlPhase::kWaitingForSensor;
    std::string last_mode_histogram_;

    std::mutex sensor_mutex_;
    SensorSnapshot sensor_snapshot_{};
    geometry_msgs::msg::Twist last_command_;
    rclcpp::Time last_command_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_sensor_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_waiting_for_sensor_log_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_sensor_timeout_log_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_waiting_for_command_log_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_hold_reason_log_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_policy_output_warning_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_policy_action_stats_log_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_non_finite_action_log_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_aggressive_command_log_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_imu_tilt_log_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_recovery_parse_warning_log_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_recovery_alert_log_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_non_finite_target_log_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_joint_target_warning_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_joint_state_warning_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_large_target_jump_log_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_low_cmd_publish_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_low_cmd_publish_gap_log_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_low_cmd_no_subscriber_log_time_{0, 0, RCL_ROS_TIME};
    rclcpp::Time last_low_cmd_multi_publisher_log_time_{0, 0, RCL_ROS_TIME};

    std::array<float, kMotorCount> stand_pose_{};
    std::array<float, kMotorCount> filtered_targets_{};
    std::array<int, kMotorCount> baseline_motor_modes_{};
    std::array<int, kMotorCount> last_motor_modes_{};
    std::array<uint32_t, kMotorCount> last_motor_error_flags_{};
    std::array<uint32_t, kMotorCount> last_motor_lost_{};
    std::array<int, kMotorCount> last_motor_temperatures_{};
    std::vector<float> last_actions_;
    std::unique_ptr<PolicyBackend> policy_backend_;
    RuntimeEventLogger event_logger_;

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr walk_command_sub_;
    rclcpp::Subscription<booster_interface::msg::LowState>::SharedPtr low_state_sub_;
    rclcpp::Subscription<booster_interface::msg::RawBytesMsg>::SharedPtr recovery_state_sub_;
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
