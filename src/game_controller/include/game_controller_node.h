#pragma once

#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <rclcpp/rclcpp.hpp>

#include "RoboCupGameControlData.h"

#include "game_controller_interface/msg/game_control_data.hpp"

using namespace std;

class GameControllerNode : public rclcpp::Node
{
public:
    GameControllerNode(string name);
    ~GameControllerNode();

    void init();

    void spin();

private:
    bool check_ip_white_list(string ip);

    void handle_packet(RoboCupGameControlData &data, game_controller_interface::msg::GameControlData &msg);

    int _port;
    bool _enable_ip_white_list;
    vector<string> _ip_white_list;
    int _min_publish_interval_ms;

    // UDP Socket
    int _socket;
    // thread
    
    thread _thread;
    std::chrono::steady_clock::time_point _last_publish_time{};
    bool _has_published_once = false;

    // Ros2 publisher
    rclcpp::Publisher<game_controller_interface::msg::GameControlData>::SharedPtr _publisher;
};
