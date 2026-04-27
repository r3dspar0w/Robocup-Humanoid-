#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <atomic>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <rclcpp/rclcpp.hpp>

#include "RoboCupGameControlData.h"

#include "game_controller_interface/msg/game_control_data.hpp"
#include "game_controller_interface/msg/team_communication.hpp"

using namespace std;

class GameControllerNode : public rclcpp::Node
{
public:
    GameControllerNode(string name);
    ~GameControllerNode();

    void init();

    void spin();

private:
    struct TeamRelayPacket {
        int32_t validation;
        int32_t communicationId;
        int32_t teamId;
        int32_t playerId;
        int32_t playerRole;
        bool isAlive;
        bool isLead;
        bool ballDetected;
        bool ballLocationKnown;
        double ballConfidence;
        double ballRange;
        double cost;
        double ballX;
        double ballY;
        double ballZ;
        double robotX;
        double robotY;
        double robotTheta;
        double kickDir;
        double thetaRb;
        int32_t cmdId;
        int32_t cmd;
    };

    bool check_ip_white_list(string ip);

    void handle_packet(RoboCupGameControlData &data, game_controller_interface::msg::GameControlData &msg);
    void initTeamRelay();
    void clearupTeamRelay();
    void relayOutgoingTeamCommunication(const game_controller_interface::msg::TeamCommunication::SharedPtr msg);
    void spinTeamRelayReceiver();
    TeamRelayPacket toRelayPacket(const game_controller_interface::msg::TeamCommunication &msg);
    game_controller_interface::msg::TeamCommunication toRosTeamCommunication(const TeamRelayPacket &packet);

    int _port;
    bool _enable_ip_white_list;
    vector<string> _ip_white_list;
    bool _enable_team_relay = true;
    int _team_id = 0;
    int _player_id = 0;
    int _team_relay_port = 0;
    string _relay_broadcast_address;

    // UDP Socket
    int _socket;
    int _team_relay_send_socket = -1;
    int _team_relay_recv_socket = -1;
    sockaddr_in _team_relay_addr{};
    std::atomic<bool> _team_relay_receive_flag{false};
    // thread
    
    thread _thread;
    thread _team_relay_thread;

    // Ros2 publisher
    rclcpp::Publisher<game_controller_interface::msg::GameControlData>::SharedPtr _publisher;
    rclcpp::Publisher<game_controller_interface::msg::TeamCommunication>::SharedPtr _team_relay_publisher;
    rclcpp::Subscription<game_controller_interface::msg::TeamCommunication>::SharedPtr _team_relay_subscription;
};
