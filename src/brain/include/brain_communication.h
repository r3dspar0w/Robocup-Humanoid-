#pragma once

#include <atomic>
#include <string>
#include <thread>

#include <netinet/in.h>
#include <rclcpp/rclcpp.hpp>

#include "RoboCupGameControlData.h"
#include "team_communication_msg.h"
#include <game_controller_interface/msg/team_communication.hpp>


class Brain; // forward declaration

using namespace std;


class BrainCommunication
{
public:
    BrainCommunication(Brain *argBrain);
    ~BrainCommunication();
    
    void initCommunication();
    bool isTeamChanged();

private:
    Brain *brain;

    void initGameControllerUnicast();
    std::thread _gamecontrol_unicast_thread;
    void unicastToGameController();
    void clearupGameControllerUnicast();
    std::atomic<bool> _unicast_gamecontrol_flag = false;
    int _gc_send_socket = -1;
    sockaddr_in _gcsaddr;
    HlRoboCupGameControlReturnData gc_return_data;
    static constexpr int BROADCAST_GAME_CONTROL_INTERVAL_MS = 1000;

    void initRelayPublishLoop();
    void clearupRelayPublishLoop();
    void relayPublishLoop();
    TeamCommunicationMsg makeTeamCommunicationMsg();
    void processTeamCommunicationMsg(const TeamCommunicationMsg &msg, const string &source);
    game_controller_interface::msg::TeamCommunication toRelayMsg(const TeamCommunicationMsg &msg);
    TeamCommunicationMsg fromRelayMsg(const game_controller_interface::msg::TeamCommunication &msg);
    void initRelayCommunication();
    void relayCommunicationCallback(const game_controller_interface::msg::TeamCommunication::SharedPtr msg);
    int _team_communication_msg_id = 0;
    std::atomic<bool> _relay_publish_flag = false;
    std::thread _relay_publish_thread;
    int _team_port = 0;
    static constexpr int RELAY_PUBLISH_INTERVAL_MS = 100;
    bool _enable_robot_comm_relay = true;
    rclcpp::Publisher<game_controller_interface::msg::TeamCommunication>::SharedPtr _relay_pub;
    rclcpp::Subscription<game_controller_interface::msg::TeamCommunication>::SharedPtr _relay_sub;
};
