#pragma once

#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdexcept>


#include "RoboCupGameControlData.h"
#include "team_communication_msg.h"
#include "utils/print.h"
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

    int _discovery_msg_id = 0;

    void initDiscoveryBroadcast();
    void clearupDiscoveryBroadcast();
    void broadcastDiscovery();
    std::thread _discovery_broadcast_thread;
    std::atomic<bool> _broadcast_discovery_flag{false};
    int _discovery_send_socket = -1;
    int _discovery_udp_port = 0;
    sockaddr_in _saddr;
    static constexpr int BROADCAST_DISCOVERY_INTERVAL_MS = 1000;


    void initDiscoveryReceiver();
    void clearupDiscoveryReceiver();
    void spinDiscoveryReceiver();
    std::atomic<bool> _receive_discovery_flag = false;
    std::thread _discovery_recv_thread;
    int _discovery_recv_socket = -1;


    struct TeammateInfo {
        uint32_t ip;
        int playerId;
        rclcpp::Time lastUpdate;
    };
    std::map<uint32_t, TeammateInfo> _teammate_addresses; // playerId -> TeammateInfo
    std::mutex _teammate_addresses_mutex;
    static constexpr int TEAMMATE_TIMEOUT_MS = 20 * 1000; // 20s timeout
    
    void cleanupExpiredTeammates();

    void initCommunicationUnicast();
    void clearupCommunicationUnicast();
    void unicastCommunication();
    TeamCommunicationMsg makeTeamCommunicationMsg();
    void processTeamCommunicationMsg(const TeamCommunicationMsg &msg, const string &source);
    game_controller_interface::msg::TeamCommunication toRelayMsg(const TeamCommunicationMsg &msg);
    TeamCommunicationMsg fromRelayMsg(const game_controller_interface::msg::TeamCommunication &msg);
    void initRelayCommunication();
    void relayCommunicationCallback(const game_controller_interface::msg::TeamCommunication::SharedPtr msg);
    int _team_communication_msg_id = 0;
    std::atomic<bool> _unicast_communication_flag = false;
    std::thread _unicast_thread;
    int _unicast_socket = -1;
    int _unicast_udp_port = 0;
    sockaddr_in _unicast_saddr;
    static constexpr int UNICAST_INTERVAL_MS = 100;
    bool _enable_robot_comm_relay = true;
    rclcpp::Publisher<game_controller_interface::msg::TeamCommunication>::SharedPtr _relay_pub;
    rclcpp::Subscription<game_controller_interface::msg::TeamCommunication>::SharedPtr _relay_sub;


    void initCommunicationReceiver();
    void clearupCommunicationReceiver();
    void spinCommunicationReceiver();
    std::atomic<bool> _receive_communication_flag = false;
    std::thread _communication_recv_thread;
    int _communication_recv_socket = -1;
    int _communication_recv_port = 0;
};
