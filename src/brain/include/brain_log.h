#pragma once

#include <string>
#include <sstream>
#include <map>
#include <fstream>
#include <mutex>
#include <rclcpp/rclcpp.hpp>
#include <diagnostic_msgs/msg/key_value.hpp>
#include "types.h"


class Brain; // forward declaration

using namespace std;

/**
 * If some logging patterns are repetitive, wrap them in this class.
 */
class BrainLog
{
public:
    /**
     * Constructor initializes the object and sets enabled to false.
     */
    BrainLog(Brain *argBrain);

    // make use of RCLCPP logging macros, and prepend entity_path to the message for easier filtering
    void debug(string_view entity_path, const string& message = "") const;
    void log(string_view entity_path, const string& message = "") const;
    void warn(string_view entity_path, const string& message = "") const;
    void error(string_view entity_path, const string& message = "") const;
    void strategy(const string& message) const;
    void strategy(string_view entity_path, const string& message) const;

    void log_scalar(const string& entity_path, const string& label, double value);
    void log_scalar(const string& entity_path, const string& label, int value);

private:
    string build_log_message(string_view entity_path, const string& message) const;
    void write_strategy_line(const string& line) const;

    Brain *brain;
    // create independent publisher for each entity_path
    map<string, rclcpp::Publisher<diagnostic_msgs::msg::KeyValue>::SharedPtr> scalar_publishers_;
    string strategy_log_path_;
    mutable ofstream strategy_stream_;
    mutable mutex strategy_mutex_;
    mutable string last_strategy_line_;
    
    // get or create publisher
    rclcpp::Publisher<diagnostic_msgs::msg::KeyValue>::SharedPtr get_or_create_publisher(const string& entity_path);
};
