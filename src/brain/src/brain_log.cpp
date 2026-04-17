#include "brain_log.h"
#include "brain.h"
#include "utils/math.h"
#include "utils/print.h"
#include "utils/misc.h"
#include <chrono>
#include <ctime>
#include <filesystem>
#include <iomanip>

namespace {
string wallTimeString()
{
    auto now = std::chrono::system_clock::now();
    auto time_t_now = std::chrono::system_clock::to_time_t(now);
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()) % 1000;

    std::tm tm_now;
#ifdef _WIN32
    localtime_s(&tm_now, &time_t_now);
#else
    localtime_r(&time_t_now, &tm_now);
#endif

    std::ostringstream oss;
    oss << std::put_time(&tm_now, "%Y-%m-%d %H:%M:%S")
        << "." << std::setfill('0') << std::setw(3) << millis.count();
    return oss.str();
}
}

BrainLog::BrainLog(Brain *argBrain) : brain(argBrain)
{
    brain->get_parameter("strategy.log_path", strategy_log_path_);
    if (strategy_log_path_.empty()) {
        strategy_log_path_ = "strategy.log";
    }

    auto parent_path = std::filesystem::path(strategy_log_path_).parent_path();
    if (!parent_path.empty()) {
        std::error_code ec;
        std::filesystem::create_directories(parent_path, ec);
        if (ec) {
            RCLCPP_WARN(
                brain->get_logger(),
                "Failed to create strategy log directory for %s: %s",
                strategy_log_path_.c_str(),
                ec.message().c_str());
        }
    }

    strategy_stream_.open(strategy_log_path_, std::ios::out | std::ios::trunc);
    if (!strategy_stream_.is_open()) {
        RCLCPP_WARN(brain->get_logger(), "Failed to open strategy log file: %s", strategy_log_path_.c_str());
        return;
    }

    write_strategy_line("strategy log started");
}

string BrainLog::build_log_message(string_view entity_path, const string& message) const
{
    std::ostringstream oss;
    if (!entity_path.empty()) {
        oss << "[" << entity_path << "]";
    }
    if (!message.empty()) {
        if (!entity_path.empty()) {
            oss << " ";
        }
        oss << message;
    }
    return oss.str();
}

void BrainLog::write_strategy_line(const string& line) const
{
    std::lock_guard<std::mutex> lock(strategy_mutex_);
    if (!strategy_stream_.is_open()) {
        return;
    }
    if (line == last_strategy_line_) {
        return;
    }

    strategy_stream_ << "[" << wallTimeString() << "]";
    if (!line.empty()) {
        strategy_stream_ << " " << line;
    }
    strategy_stream_ << std::endl;
    last_strategy_line_ = line;
}

void BrainLog::debug(string_view entity_path, const string& message) const
{
    auto line = build_log_message(entity_path, message);
    RCLCPP_DEBUG(brain->get_logger(), "%s", line.c_str());
}

void BrainLog::log(string_view entity_path, const string& message) const
{
    auto line = build_log_message(entity_path, message);
    RCLCPP_INFO(brain->get_logger(), "%s", line.c_str());
}

void BrainLog::warn(string_view entity_path, const string& message) const
{
    auto line = build_log_message(entity_path, message);
    RCLCPP_WARN(brain->get_logger(), "%s", line.c_str());
}

void BrainLog::error(string_view entity_path, const string& message) const
{
    auto line = build_log_message(entity_path, message);
    RCLCPP_ERROR(brain->get_logger(), "%s", line.c_str());
}

void BrainLog::strategy(const string& message) const
{
    write_strategy_line(message);
}

void BrainLog::strategy(string_view entity_path, const string& message) const
{
    write_strategy_line(build_log_message(entity_path, message));
}

rclcpp::Publisher<diagnostic_msgs::msg::KeyValue>::SharedPtr 
BrainLog::get_or_create_publisher(const string& entity_path)
{
    auto it = scalar_publishers_.find(entity_path);
    if (it == scalar_publishers_.end()) {
        // Create a new publisher with topic name /booster_soccer/log/scalars/{entity_path}
        string topic_name = "/booster_soccer/log/scalars/" + entity_path;
        auto publisher = brain->create_publisher<diagnostic_msgs::msg::KeyValue>(topic_name, 10);
        scalar_publishers_[entity_path] = publisher;
        return publisher;
    }
    return it->second;
}

void BrainLog::log_scalar(const string& entity_path, const string& label, double value)
{
    auto publisher = get_or_create_publisher(entity_path);
    
    diagnostic_msgs::msg::KeyValue msg;
    msg.key = label;
    msg.value = std::to_string(value);
    
    publisher->publish(msg);
}

void BrainLog::log_scalar(const string& entity_path, const string& label, int value)
{
    auto publisher = get_or_create_publisher(entity_path);
    
    diagnostic_msgs::msg::KeyValue msg;
    msg.key = label;
    msg.value = std::to_string(value);
    
    publisher->publish(msg);
}