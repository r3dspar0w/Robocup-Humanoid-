#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>
#include <std_msgs/msg/string.hpp>

#include "../include/game_controller_node.h"

GameControllerNode::GameControllerNode(string name) : rclcpp::Node(name)
{
    _socket = -1;

    declare_parameter<int>("port", 3838);
    declare_parameter<bool>("enable_ip_white_list", false);
    declare_parameter<vector<string>>("ip_white_list", vector<string>{});

    get_parameter("port", _port);
    RCLCPP_INFO(get_logger(), "[get_parameter] port: %d", _port);
    get_parameter("enable_ip_white_list", _enable_ip_white_list);
    RCLCPP_INFO(get_logger(), "[get_parameter] enable_ip_white_list: %d", _enable_ip_white_list);
    get_parameter("ip_white_list", _ip_white_list);
    RCLCPP_INFO(get_logger(), "[get_parameter] ip_white_list(len=%ld)", _ip_white_list.size());
    for (size_t i = 0; i < _ip_white_list.size(); i++)
    {
        RCLCPP_INFO(get_logger(), "[get_parameter]     --[%ld]: %s", i, _ip_white_list[i].c_str());
    }

    _publisher = create_publisher<game_controller_interface::msg::GameControlData>("/booster_soccer/game_controller", 10);
}

GameControllerNode::~GameControllerNode()
{
    if (_socket >= 0)
    {
        close(_socket);
    }

    if (_thread.joinable())
    {
        _thread.join();
    }
}


void GameControllerNode::init()
{
    _socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (_socket < 0)
    {
        RCLCPP_ERROR(get_logger(), "socket failed: %s", strerror(errno));
        throw runtime_error(strerror(errno));
    }

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(_port);

    if (bind(_socket, (sockaddr *)&addr, sizeof(addr)) < 0)
    {
        RCLCPP_ERROR(get_logger(), "bind failed: %s (port=%d)", strerror(errno), _port);
        throw runtime_error(strerror(errno));
    }

    RCLCPP_INFO(get_logger(), "Listening for UDP broadcast on 0.0.0.0:%d", _port);
    RCLCPP_INFO(get_logger(), "Expected RoboCupGameControlData size: %ld", sizeof(RoboCupGameControlData));

    _thread = thread(&GameControllerNode::spin, this);
}

void GameControllerNode::spin()
{
    sockaddr_in remote_addr;
    socklen_t remote_addr_len = sizeof(remote_addr);

    RoboCupGameControlData data;
    game_controller_interface::msg::GameControlData msg;

    while (rclcpp::ok())
    {
        ssize_t ret = recvfrom(_socket, &data, sizeof(data), 0, (sockaddr *)&remote_addr, &remote_addr_len);
        if (ret < 0)
        {
            RCLCPP_ERROR(get_logger(), "receiving UDP message failed: %s", strerror(errno));
            continue;
        }

        string remote_ip = inet_ntoa(remote_addr.sin_addr);

        if (ret != sizeof(data))
        {
            RCLCPP_INFO(get_logger(), "packet from %s invalid length=%ld, expected=%ld", remote_ip.c_str(), ret, sizeof(data));
            continue;
        }

		if (std::memcmp(data.header, GAMECONTROLLER_STRUCT_HEADER, 4) != 0)
		{
			RCLCPP_INFO(get_logger(), "packet from %s invalid header", remote_ip.c_str());
			continue;
		}

        if (data.version != GAMECONTROLLER_STRUCT_VERSION)
        {
            RCLCPP_INFO(get_logger(), "packet from %s invalid version: %d", remote_ip.c_str(), data.version);
            continue;
        }

        if (!check_ip_white_list(remote_ip))
        {
            RCLCPP_INFO(get_logger(), "received packet from %s, but not in ip white list, ignore it", remote_ip.c_str());
            continue;
        }

        handle_packet(data, msg);

        // Robot-side inference for official GameController Stop button.
        // This does NOT modify the official GameController.
        // It only changes the local ROS message sent to brain.
        //
        // Stop burst detected while real GC still says PLAYING:
        //   publish local END to /booster_soccer/game_controller
        //
        // This stays active until the real GameController leaves PLAYING
        // by sending READY / SET / FINISHED / INITIAL.
        static rclcpp::Time last_packet_time = this->get_clock()->now();
        static bool saw_playing_before = false;
        static bool currently_inside_stop_burst = false;
        static rclcpp::Time last_fast_packet_time = this->get_clock()->now();
        static bool local_gc_stop_active = false;

        rclcpp::Time now_time = this->get_clock()->now();

        double dt = (now_time - last_packet_time).seconds();
        last_packet_time = now_time;

        bool currently_playing = (data.state == STATE_PLAYING);

        if (currently_playing) {
            saw_playing_before = true;
        }

        bool fast_packet =
            currently_playing &&
            saw_playing_before &&
            dt > 0.02 &&
            dt < 0.35;

        if (fast_packet && !currently_inside_stop_burst) {
            currently_inside_stop_burst = true;
            last_fast_packet_time = now_time;
            local_gc_stop_active = true;

            RCLCPP_WARN(
                get_logger(),
                "[GC_LOCAL_STOP] Stop burst detected dt=%.3f -> local END active",
                dt
            );
        }

        if (fast_packet && currently_inside_stop_burst) {
            last_fast_packet_time = now_time;
        }

        if (
            currently_inside_stop_burst &&
            !fast_packet &&
            (now_time - last_fast_packet_time).seconds() > 1.0
        ) {
            currently_inside_stop_burst = false;
        }

        // If local stop is active, override outgoing ROS GameController message to END.
        if (local_gc_stop_active) {
            msg.state = STATE_FINISHED;
            msg.secondary_state = STATE2_NORMAL;
            msg.secondary_state_info[0] = static_cast<char>(data.kickingTeam);
            msg.secondary_state_info[1] = 0;
            msg.secondary_state_info[2] = 0;
            msg.secondary_state_info[3] = 0;

            RCLCPP_WARN_THROTTLE(
                get_logger(),
                *get_clock(),
                1000,
                "[GC_LOCAL_STOP] overriding outgoing ROS GC msg: state=END"
            );
        }

        // Clear local stop only when the REAL official GC packet leaves PLAYING.
        // Example: you press READY, SET, INITIAL, or END on the real GameController.
        if (!currently_playing) {
            local_gc_stop_active = false;
            currently_inside_stop_burst = false;
            saw_playing_before = false;
        }

        _publisher->publish(msg);

        RCLCPP_INFO(get_logger(), "handle packet successfully ip=%s, packet_number=%d", remote_ip.c_str(), data.packetNumber);
    }
}


bool GameControllerNode::check_ip_white_list(string ip)
{
    if (!_enable_ip_white_list)
    {
        return true;
    }
    for (size_t i = 0; i < _ip_white_list.size(); i++)
    {
        if (ip == _ip_white_list[i])
        {
            return true;
        }
    }
    return false;
}


void GameControllerNode::handle_packet(RoboCupGameControlData &data,
                                       game_controller_interface::msg::GameControlData &msg)
{
    for (int i = 0; i < 4; i++)
    {
        msg.header[i] = data.header[i];
    }

    msg.version = data.version;
    msg.packet_number = data.packetNumber;
    msg.players_per_team = data.playersPerTeam;
    msg.game_type = data.competitionPhase;

    // Main state mapping
    bool is_stop_play = (data.state == STATE_STANDBY);

    if (is_stop_play)
    {
        msg.state = STATE_INITIAL;
    }
    else
    {
        msg.state = data.state;
    }

    msg.first_half = data.firstHalf;
    msg.kick_off_team = data.kickingTeam;

    // Secondary state mapping
    if (is_stop_play)
    {
        msg.secondary_state = STATE2_NORMAL;
    }
    else if (data.gamePhase == GAME_PHASE_PENALTYSHOOT)
    {
        msg.secondary_state = STATE2_PENALTYSHOOT;
    }
    else if (data.gamePhase == GAME_PHASE_OVERTIME)
    {
        msg.secondary_state = STATE2_OVERTIME;
    }
    else if (data.gamePhase == GAME_PHASE_TIMEOUT)
    {
        msg.secondary_state = STATE2_TIMEOUT;
    }
    else
    {
        switch (data.setPlay)
        {
        case SET_PLAY_NONE:
            msg.secondary_state = STATE2_NORMAL;
            break;

        case SET_PLAY_GOAL_KICK:
            msg.secondary_state = STATE2_GOAL_KICK;
            break;

        case SET_PLAY_CORNER_KICK:
            msg.secondary_state = STATE2_CORNER_KICK;
            break;

        case SET_PLAY_PENALTY_KICK:
            msg.secondary_state = STATE2_PENALTYKICK;
            break;

        case SET_PLAY_KICK_IN:
            msg.secondary_state = STATE2_THROW_IN;
            break;

	#ifdef SET_PLAY_PUSHING_FREE_KICK
		case SET_PLAY_PUSHING_FREE_KICK:
			msg.secondary_state = STATE2_INDIRECT_FREEKICK;
			break;
	#endif

        default:
            msg.secondary_state = STATE2_NORMAL;
            break;
        }
    }

    // Restart side + phase
    if (is_stop_play)
    {
        msg.secondary_state_info[0] = 0;
        msg.secondary_state_info[1] = 0;
        msg.secondary_state_info[2] = 0;
        msg.secondary_state_info[3] = 0;
    }
    else
    {
        msg.secondary_state_info[0] = static_cast<char>(data.kickingTeam);

        if (msg.state == STATE_READY)
        {
            msg.secondary_state_info[1] = 1;
        }
        else if (msg.state == STATE_SET)
        {
            msg.secondary_state_info[1] = 2;
        }
        else
        {
            msg.secondary_state_info[1] = 0;
        }

        msg.secondary_state_info[2] = 0;
        msg.secondary_state_info[3] = 0;
    }

    msg.drop_in_team = 0;
    msg.drop_in_time = 0;

    msg.secs_remaining = (data.secsRemaining < 0) ? 0 : data.secsRemaining;
    msg.secondary_time = (data.secondaryTime < 0) ? 0 : data.secondaryTime;

    for (int i = 0; i < 2; i++)
    {
        msg.teams[i].team_number = data.teams[i].teamNumber;
        msg.teams[i].field_player_colour = data.teams[i].fieldPlayerColour;
        msg.teams[i].score = data.teams[i].score;
        msg.teams[i].penalty_shot = data.teams[i].penaltyShot;
        msg.teams[i].single_shots = data.teams[i].singleShots;

        msg.teams[i].coach_sequence = 0;
        msg.teams[i].coach_message.clear();

        msg.teams[i].coach.penalty = 0;
        msg.teams[i].coach.secs_till_unpenalised = 0;
        msg.teams[i].coach.number_of_warnings = 0;
        msg.teams[i].coach.yellow_card_count = 0;
        msg.teams[i].coach.red_card_count = 0;
        msg.teams[i].coach.goal_keeper = false;

		msg.teams[i].players.clear();
		int players_len = sizeof(data.teams[i].players) / sizeof(data.teams[i].players[0]);

		for (int j = 0; j < players_len; j++)
		{
			game_controller_interface::msg::RobotInfo rf;

			if (j < data.playersPerTeam)
			{
				rf.penalty = data.teams[i].players[j].penalty;
				rf.secs_till_unpenalised = data.teams[i].players[j].secsTillUnpenalised;
				rf.goal_keeper = ((j + 1) == data.teams[i].goalkeeper);
			}
			else
			{
				// mark unused slots as substitutes so brain won't treat them as active players
				rf.penalty = PENALTY_SUBSTITUTE;
				rf.secs_till_unpenalised = 0;
				rf.goal_keeper = false;
			}

			rf.number_of_warnings = 0;
			rf.yellow_card_count = 0;
			rf.red_card_count = 0;

			msg.teams[i].players.push_back(rf);
		}
	}
}