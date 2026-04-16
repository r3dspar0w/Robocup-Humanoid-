#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iomanip>
#include <memory>
#include <mutex>
#include <sstream>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "booster_interface/msg/low_state.hpp"

namespace {

constexpr size_t kMotorCount = 23;

constexpr std::array<const char *, kMotorCount> kMotorNames = {
        "AAHead_yaw",         "Head_pitch",        "Left_Shoulder_Pitch", "Left_Shoulder_Roll",
        "Left_Elbow_Pitch",   "Left_Elbow_Yaw",   "Right_Shoulder_Pitch","Right_Shoulder_Roll",
        "Right_Elbow_Pitch",  "Right_Elbow_Yaw",  "Waist",               "Left_Hip_Pitch",
        "Left_Hip_Roll",      "Left_Hip_Yaw",     "Left_Knee_Pitch",     "Left_Ankle_Pitch",
        "Left_Ankle_Roll",    "Right_Hip_Pitch",  "Right_Hip_Roll",      "Right_Hip_Yaw",
        "Right_Knee_Pitch",   "Right_Ankle_Pitch","Right_Ankle_Roll",
};

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

std::string formatHex(uint32_t value) {
    std::ostringstream oss;
    oss << "0x" << std::hex << std::uppercase << value;
    return oss.str();
}

struct MotorSnapshot {
    int mode = 0;
    float q = 0.f;
    float dq = 0.f;
    float ddq = 0.f;
    float tau_est = 0.f;
    int temperature = 0;
    uint32_t lost = 0;
    uint32_t error_flags = 0;
    uint32_t comm_hz = 0;
};

class ActuatorMonitorNode : public rclcpp::Node {
public:
    ActuatorMonitorNode() : Node("actuator_monitor_node") {
        declare_parameter<std::string>("robot.robot_name", "");
        declare_parameter<std::string>("robot.actuator_monitor_low_state_topic", "/low_state");
        declare_parameter<double>("robot.actuator_monitor_console_period_s", 1.0);
        declare_parameter<bool>("robot.actuator_monitor_print_all_joints", true);
        declare_parameter<bool>("robot.actuator_monitor_csv_enabled", true);
        declare_parameter<int>("robot.actuator_monitor_csv_sample_every_n", 10);
        declare_parameter<std::string>("robot.actuator_monitor_csv_log_dir", "motion_control_logs");
        declare_parameter<int>("robot.actuator_monitor_temp_warn_c", 80);

        robot_name_ = get_parameter("robot.robot_name").as_string();
        print_all_joints_ = get_parameter("robot.actuator_monitor_print_all_joints").as_bool();
        csv_enabled_ = get_parameter("robot.actuator_monitor_csv_enabled").as_bool();
        csv_sample_every_n_ = std::max(1, get_parameter("robot.actuator_monitor_csv_sample_every_n").as_int());
        temp_warn_c_ = get_parameter("robot.actuator_monitor_temp_warn_c").as_int();

        const auto low_state_topic = appendRobotSuffix(
                get_parameter("robot.actuator_monitor_low_state_topic").as_string(),
                robot_name_);

        const double console_period_s = std::max(
                0.1, get_parameter("robot.actuator_monitor_console_period_s").as_double());

        low_state_sub_ = create_subscription<booster_interface::msg::LowState>(
                low_state_topic,
                10,
                std::bind(&ActuatorMonitorNode::onLowState, this, std::placeholders::_1));

        const auto period = std::chrono::duration<double>(console_period_s);
        console_timer_ = create_wall_timer(
                std::chrono::duration_cast<std::chrono::milliseconds>(period),
                std::bind(&ActuatorMonitorNode::onConsoleTimer, this));

        if (csv_enabled_) {
            const auto configured_dir =
                    get_parameter("robot.actuator_monitor_csv_log_dir").as_string();
            initCsvLog(configured_dir);
        }

        RCLCPP_INFO(
                get_logger(),
                "actuator_monitor_node ready. state_topic=%s console_period=%.2fs csv_enabled=%s sample_every_n=%d",
                low_state_topic.c_str(),
                console_period_s,
                csv_enabled_ ? "true" : "false",
                csv_sample_every_n_);
    }

private:
    void initCsvLog(const std::string &configured_dir) {
        try {
            std::filesystem::path root = configured_dir.empty()
                    ? (std::filesystem::current_path() / "motion_control_logs")
                    : std::filesystem::path(configured_dir);
            if (root.is_relative()) {
                root = std::filesystem::current_path() / root;
            }

            const std::string session_name = robot_name_.empty()
                    ? "actuator_monitor_" + makeTimestamp("%Y%m%d_%H%M%S")
                    : robot_name_ + "_actuator_monitor_" + makeTimestamp("%Y%m%d_%H%M%S");
            const auto session_dir = root / session_name;
            std::filesystem::create_directories(session_dir);
            const auto csv_path = session_dir / "actuator_samples.csv";

            csv_stream_.open(csv_path, std::ios::out | std::ios::app);
            if (!csv_stream_.is_open()) {
                RCLCPP_WARN(get_logger(), "Failed to open actuator monitor CSV log at %s",
                            csv_path.string().c_str());
                csv_enabled_ = false;
                return;
            }

            csv_stream_ << "stamp_s,frame,motor_index,motor_name,mode,q,dq,ddq,tau_est,temperature_c,lost,error_flags,comm_hz\n";
            csv_stream_.flush();
            RCLCPP_INFO(get_logger(), "Actuator monitor CSV: %s", csv_path.string().c_str());
        } catch (const std::exception &e) {
            RCLCPP_WARN(get_logger(), "Failed to initialize actuator monitor CSV log: %s", e.what());
            csv_enabled_ = false;
        }
    }

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

        std::array<MotorSnapshot, kMotorCount> current{};
        for (size_t i = 0; i < kMotorCount; ++i) {
            const auto &motor = msg->motor_state_serial[i];
            current[i].mode = static_cast<int>(motor.mode);
            current[i].q = motor.q;
            current[i].dq = motor.dq;
            current[i].ddq = motor.ddq;
            current[i].tau_est = motor.tau_est;
            current[i].temperature = static_cast<int>(motor.temperature);
            current[i].lost = motor.lost;
            current[i].error_flags = motor.reserve[0];
            current[i].comm_hz = motor.reserve[1];
        }

        {
            std::lock_guard<std::mutex> lock(snapshot_mutex_);
            latest_snapshot_ = current;
            has_snapshot_ = true;
            last_snapshot_time_ = now();
        }

        inspectTransitions(current);
        ++frame_counter_;

        if (csv_enabled_ && frame_counter_ % static_cast<uint64_t>(csv_sample_every_n_) == 0U) {
            writeCsv(current);
        }
    }

    void inspectTransitions(const std::array<MotorSnapshot, kMotorCount> &current) {
        if (!diagnostics_initialized_) {
            last_snapshot_for_diagnostics_ = current;
            diagnostics_initialized_ = true;
            RCLCPP_INFO(get_logger(), "Captured initial actuator diagnostic snapshot");
            for (size_t i = 0; i < kMotorCount; ++i) {
                if (current[i].error_flags != 0) {
                    RCLCPP_WARN(get_logger(), "%s started with error_flags=%s",
                                kMotorNames[i],
                                formatHex(current[i].error_flags).c_str());
                }
            }
            return;
        }

        for (size_t i = 0; i < kMotorCount; ++i) {
            const auto &previous = last_snapshot_for_diagnostics_[i];
            const auto &sample = current[i];

            if (sample.mode != previous.mode) {
                RCLCPP_INFO(get_logger(), "%s mode change: %d -> %d",
                            kMotorNames[i], previous.mode, sample.mode);
            }

            if (sample.error_flags != previous.error_flags) {
                if (sample.error_flags == 0) {
                    RCLCPP_INFO(get_logger(), "%s error flags cleared: %s -> %s",
                                kMotorNames[i],
                                formatHex(previous.error_flags).c_str(),
                                formatHex(sample.error_flags).c_str());
                } else {
                    RCLCPP_WARN(get_logger(), "%s error flags changed: %s -> %s",
                                kMotorNames[i],
                                formatHex(previous.error_flags).c_str(),
                                formatHex(sample.error_flags).c_str());
                }
            }

            if (sample.lost > previous.lost) {
                RCLCPP_WARN(get_logger(), "%s packet loss increased: %u -> %u",
                            kMotorNames[i], previous.lost, sample.lost);
            }

            if (sample.temperature >= temp_warn_c_ &&
                (previous.temperature < temp_warn_c_ ||
                 std::abs(sample.temperature - previous.temperature) >= 5)) {
                RCLCPP_WARN(get_logger(), "%s high temperature: %d C",
                            kMotorNames[i], sample.temperature);
            }
        }

        last_snapshot_for_diagnostics_ = current;
    }

    void writeCsv(const std::array<MotorSnapshot, kMotorCount> &samples) {
        if (!csv_stream_.is_open()) {
            return;
        }
        const double stamp_s = now().nanoseconds() / 1e9;

        for (size_t i = 0; i < kMotorCount; ++i) {
            const auto &sample = samples[i];
            csv_stream_ << std::fixed << std::setprecision(6)
                        << stamp_s << ','
                        << frame_counter_ << ','
                        << i << ','
                        << kMotorNames[i] << ','
                        << sample.mode << ','
                        << sample.q << ','
                        << sample.dq << ','
                        << sample.ddq << ','
                        << sample.tau_est << ','
                        << sample.temperature << ','
                        << sample.lost << ','
                        << sample.error_flags << ','
                        << sample.comm_hz << '\n';
        }
        csv_stream_.flush();
    }

    void onConsoleTimer() {
        std::array<MotorSnapshot, kMotorCount> snapshot{};
        rclcpp::Time last_snapshot_time{0, 0, RCL_ROS_TIME};
        bool has_snapshot = false;
        {
            std::lock_guard<std::mutex> lock(snapshot_mutex_);
            has_snapshot = has_snapshot_;
            snapshot = latest_snapshot_;
            last_snapshot_time = last_snapshot_time_;
        }

        if (!has_snapshot) {
            RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), 2000,
                                 "Waiting for /low_state actuator stream...");
            return;
        }

        int max_temp = snapshot[0].temperature;
        int min_temp = snapshot[0].temperature;
        size_t nonzero_error_count = 0;
        for (size_t i = 0; i < kMotorCount; ++i) {
            max_temp = std::max(max_temp, snapshot[i].temperature);
            min_temp = std::min(min_temp, snapshot[i].temperature);
            if (snapshot[i].error_flags != 0) {
                ++nonzero_error_count;
            }
        }

        const double age_ms = (now() - last_snapshot_time).nanoseconds() / 1e6;
        RCLCPP_INFO(get_logger(),
                    "Actuator snapshot age=%.1f ms temp[min,max]=[%d,%d] nonzero_error_motors=%zu",
                    age_ms,
                    min_temp,
                    max_temp,
                    nonzero_error_count);

        if (!print_all_joints_) {
            return;
        }

        for (size_t i = 0; i < kMotorCount; ++i) {
            const auto &sample = snapshot[i];
            RCLCPP_INFO(
                    get_logger(),
                    "[%02zu] %-20s mode=%d q=%+.4f dq=%+.4f tau=%+.4f temp=%d lost=%u err=%s comm=%u",
                    i,
                    kMotorNames[i],
                    sample.mode,
                    sample.q,
                    sample.dq,
                    sample.tau_est,
                    sample.temperature,
                    sample.lost,
                    formatHex(sample.error_flags).c_str(),
                    sample.comm_hz);
        }
    }

    std::string robot_name_;
    bool warned_motor_count_ = false;
    bool print_all_joints_ = true;
    bool csv_enabled_ = true;
    bool diagnostics_initialized_ = false;
    int csv_sample_every_n_ = 10;
    int temp_warn_c_ = 80;
    uint64_t frame_counter_ = 0;

    std::mutex snapshot_mutex_;
    bool has_snapshot_ = false;
    std::array<MotorSnapshot, kMotorCount> latest_snapshot_{};
    rclcpp::Time last_snapshot_time_{0, 0, RCL_ROS_TIME};
    std::array<MotorSnapshot, kMotorCount> last_snapshot_for_diagnostics_{};

    std::ofstream csv_stream_;

    rclcpp::Subscription<booster_interface::msg::LowState>::SharedPtr low_state_sub_;
    rclcpp::TimerBase::SharedPtr console_timer_;
};

}  // namespace

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ActuatorMonitorNode>());
    rclcpp::shutdown();
    return 0;
}
