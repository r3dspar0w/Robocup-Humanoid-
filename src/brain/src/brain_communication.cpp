#include "brain.h"
#include "brain_communication.h"

#include <chrono>
#include <cstring>
#include <iostream>
#include <thread>

/*
It handles communication with the GameController.

This enables:
    1. Receiving referee state through the GameController ROS topic.
    2. Sending robot pose and ball observations through the official return-data packet.
*/

namespace {
bool buildGameControllerAddress(const std::string &ip, uint16_t port, sockaddr_in &addr)
{
    if (ip.empty() || ip == "0.0.0.0")
    {
        return false;
    }

    sockaddr_in resolved{};
    resolved.sin_family = AF_INET;
    resolved.sin_port = htons(port);
    if (inet_pton(AF_INET, ip.c_str(), &resolved.sin_addr) != 1)
    {
        return false;
    }

    if (resolved.sin_addr.s_addr == htonl(INADDR_ANY))
    {
        return false;
    }

    addr = resolved;
    return true;
}
}

BrainCommunication::BrainCommunication(Brain *argBrain) : brain(argBrain)
{
}

BrainCommunication::~BrainCommunication()
{
    clearupGameControllerReturn();
}

void BrainCommunication::initCommunication()
{
    _team_id_at_init = brain->config->get_team_id();

    if (brain->config->get_enable_com())
    {
        cout << RED_CODE << "Communication enabled." << RESET_CODE << endl;
        initGameControllerReturn();
    }
    else
    {
        cout << RED_CODE << "Communication disabled." << RESET_CODE << endl;
    }
}

bool BrainCommunication::isTeamChanged()
{
    int teamId = brain->config->get_team_id();
    if (teamId != _team_id_at_init)
    {
        RCLCPP_INFO(
            brain->get_logger(),
            "Team changed current team_id=%d, new team_id=%d",
            _team_id_at_init,
            teamId);
        return true;
    }
    return false;
}

void BrainCommunication::initGameControllerReturn()
{
    try
    {
        _game_controller_return_socket = socket(AF_INET, SOCK_DGRAM, 0);
        if (_game_controller_return_socket < 0)
        {
            cout << RED_CODE << format("GameController return socket failed: %s", strerror(errno))
                << RESET_CODE << endl;
            throw std::runtime_error(strerror(errno));
        }

        sockaddr_in initial_addr{};
        const string gamecontrol_ip = brain->config->get_game_control_ip();
        if (buildGameControllerAddress(gamecontrol_ip, GAMECONTROLLER_RETURN_PORT, initial_addr))
        {
            std::lock_guard<std::mutex> lock(_game_controller_return_mutex);
            _game_controller_return_addr = initial_addr;
            _game_controller_target_ip = gamecontrol_ip;
            _game_controller_target_port = GAMECONTROLLER_RETURN_PORT;
            RCLCPP_INFO(
                brain->get_logger(),
                "GameController return-data target: %s:%u",
                _game_controller_target_ip.c_str(),
                static_cast<unsigned int>(_game_controller_target_port));
        }
        else
        {
            RCLCPP_WARN(
                brain->get_logger(),
                "Configured game_control_ip '%s' is not valid; waiting for inbound GameController packets to discover return-data target",
                gamecontrol_ip.c_str());
        }

        _game_controller_return_flag.store(true);
        _game_controller_return_thread = std::thread([this]() { this->unicastGameControllerReturn(); });
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void BrainCommunication::updateGameControllerEndpoint(const std::string &ip, uint16_t source_port)
{
    sockaddr_in updated_addr{};
    if (!buildGameControllerAddress(ip, GAMECONTROLLER_RETURN_PORT, updated_addr))
    {
        return;
    }

    std::lock_guard<std::mutex> lock(_game_controller_return_mutex);
    if (_game_controller_target_ip == ip && _game_controller_target_port == GAMECONTROLLER_RETURN_PORT)
    {
        return;
    }

    _game_controller_return_addr = updated_addr;
    _game_controller_target_ip = ip;
    _game_controller_target_port = GAMECONTROLLER_RETURN_PORT;

    RCLCPP_INFO(
        brain->get_logger(),
        "Updated GameController return-data target to %s:%u from inbound referee packet %s:%u",
        _game_controller_target_ip.c_str(),
        static_cast<unsigned int>(_game_controller_target_port),
        ip.c_str(),
        static_cast<unsigned int>(source_port));
}

void BrainCommunication::clearupGameControllerReturn()
{
    _game_controller_return_flag.store(false);
    if (_game_controller_return_thread.joinable())
    {
        _game_controller_return_thread.join();
    }

    if (_game_controller_return_socket >= 0)
    {
        close(_game_controller_return_socket);
        _game_controller_return_socket = -1;
        cout << RED_CODE << "GameController return socket has been closed."
            << RESET_CODE << endl;
    }
}

void BrainCommunication::unicastGameControllerReturn()
{
    rclcpp::Time last_missing_target_log = brain->get_clock()->now();
    while (_game_controller_return_flag.load(std::memory_order_relaxed))
    {
        sockaddr_in target_addr{};
        std::string target_ip;
        uint16_t target_port = GAMECONTROLLER_RETURN_PORT;
        {
            std::lock_guard<std::mutex> lock(_game_controller_return_mutex);
            target_addr = _game_controller_return_addr;
            target_ip = _game_controller_target_ip;
            target_port = _game_controller_target_port;
        }

        if (target_ip.empty())
        {
            auto now = brain->get_clock()->now();
            if ((now - last_missing_target_log).nanoseconds() >= 5LL * 1000 * 1000 * 1000)
            {
                RCLCPP_WARN(
                    brain->get_logger(),
                    "GameController return-data target is unknown; waiting for GameController packets");
                last_missing_target_log = now;
            }
            this_thread::sleep_for(chrono::milliseconds(GAME_CONTROLLER_RETURN_INTERVAL_MS));
            continue;
        }

        RoboCupGameControlReturnData return_data;
        return_data.playerNum = static_cast<uint8_t>(brain->config->get_player_id());
        return_data.teamNum = static_cast<uint8_t>(brain->config->get_team_id());
        return_data.fallen = brain->data->recoveryState == RobotRecoveryState::IS_READY ? 0 : 1;
        return_data.pose[0] = static_cast<float>(brain->data->robotPoseToField.x * 1000.0);
        return_data.pose[1] = static_cast<float>(brain->data->robotPoseToField.y * 1000.0);
        return_data.pose[2] = static_cast<float>(brain->data->robotPoseToField.theta);

        const bool ballKnown = brain->tree->getEntry<bool>("ball_location_known");
        if (ballKnown)
        {
            return_data.ballAge = static_cast<float>(brain->msecsSince(brain->data->ball.timePoint) / 1000.0);
            return_data.ball[0] = static_cast<float>(brain->data->ball.posToRobot.x * 1000.0);
            return_data.ball[1] = static_cast<float>(brain->data->ball.posToRobot.y * 1000.0);
        }
        else
        {
            return_data.ballAge = -1.0f;
            return_data.ball[0] = 0.0f;
            return_data.ball[1] = 0.0f;
        }

        int ret = sendto(
            _game_controller_return_socket,
            &return_data,
            sizeof(return_data),
            0,
            (sockaddr *)&target_addr,
            sizeof(target_addr));
        if (ret < 0)
        {
            RCLCPP_ERROR(
                brain->get_logger(),
                "GameController return-data sendto failed for %s:%u: %s",
                target_ip.c_str(),
                static_cast<unsigned int>(target_port),
                strerror(errno));
        }

        this_thread::sleep_for(chrono::milliseconds(GAME_CONTROLLER_RETURN_INTERVAL_MS));
    }
}
