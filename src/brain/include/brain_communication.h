#pragma once

#include <string>
#include <atomic>
#include <cstdint>
#include <mutex>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdexcept>


#include "RoboCupGameControlData.h"
#include "utils/print.h"


class Brain; // forward declaration

using namespace std;


class BrainCommunication
{
public:
    BrainCommunication(Brain *argBrain);
    ~BrainCommunication();
    
    void initCommunication();
    bool isTeamChanged();
    void updateGameControllerEndpoint(const std::string &ip, uint16_t source_port = GAMECONTROLLER_DATA_PORT);

private:
    Brain *brain;

    void initGameControllerReturn();
    void clearupGameControllerReturn();
    void unicastGameControllerReturn();
    std::thread _game_controller_return_thread;
    std::atomic<bool> _game_controller_return_flag = false;
    int _game_controller_return_socket = -1;
    sockaddr_in _game_controller_return_addr{};
    std::mutex _game_controller_return_mutex;
    std::string _game_controller_target_ip;
    uint16_t _game_controller_target_port = GAMECONTROLLER_RETURN_PORT;
    int _team_id_at_init = -1;
    static constexpr int GAME_CONTROLLER_RETURN_INTERVAL_MS = 1000;
};
