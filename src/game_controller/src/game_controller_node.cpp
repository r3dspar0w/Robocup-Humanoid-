#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>

#include "../include/game_controller_node.h"

GameControllerNode::GameControllerNode(string name) : rclcpp::Node(name)
{
    _socket = -1;

    declare_parameter<int>("port", 3838);
    declare_parameter<bool>("enable_ip_white_list", false);
    declare_parameter<vector<string>>("ip_white_list", vector<string>{});
    declare_parameter<bool>("enable_team_relay", true);
    declare_parameter<int>("team_id", 0);
    declare_parameter<int>("player_id", 0);
    declare_parameter<int>("team_relay_port", 0);
    declare_parameter<string>("relay_broadcast_address", "255.255.255.255");

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
    get_parameter("enable_team_relay", _enable_team_relay);
    get_parameter("team_id", _team_id);
    get_parameter("player_id", _player_id);
    get_parameter("team_relay_port", _team_relay_port);
    get_parameter("relay_broadcast_address", _relay_broadcast_address);
    if (_team_relay_port <= 0)
    {
        _team_relay_port = 31000 + _team_id;
    }
    RCLCPP_INFO(get_logger(), "[get_parameter] enable_team_relay: %d", _enable_team_relay);
    RCLCPP_INFO(get_logger(), "[get_parameter] team_id: %d player_id: %d team_relay_port: %d relay_broadcast_address: %s",
                _team_id, _player_id, _team_relay_port, _relay_broadcast_address.c_str());

    _publisher = create_publisher<game_controller_interface::msg::GameControlData>("/booster_soccer/game_controller", 10);
    _team_relay_publisher = create_publisher<game_controller_interface::msg::TeamCommunication>("/booster_soccer/team_comm/in", 10);
    _team_relay_subscription = create_subscription<game_controller_interface::msg::TeamCommunication>(
        "/booster_soccer/team_comm/out",
        10,
        [this](const game_controller_interface::msg::TeamCommunication::SharedPtr msg) {
            this->relayOutgoingTeamCommunication(msg);
        });
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

    clearupTeamRelay();
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
    initTeamRelay();
}

void GameControllerNode::initTeamRelay()
{
    if (!_enable_team_relay)
    {
        RCLCPP_INFO(get_logger(), "Team relay disabled.");
        return;
    }

    _team_relay_send_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (_team_relay_send_socket < 0)
    {
        RCLCPP_ERROR(get_logger(), "team relay send socket failed: %s", strerror(errno));
        return;
    }

    int broadcast = 1;
    if (setsockopt(_team_relay_send_socket, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast)) < 0)
    {
        RCLCPP_ERROR(get_logger(), "team relay failed to set SO_BROADCAST: %s", strerror(errno));
    }

    _team_relay_addr.sin_family = AF_INET;
    _team_relay_addr.sin_addr.s_addr = inet_addr(_relay_broadcast_address.c_str());
    _team_relay_addr.sin_port = htons(_team_relay_port);

    _team_relay_recv_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (_team_relay_recv_socket < 0)
    {
        RCLCPP_ERROR(get_logger(), "team relay receive socket failed: %s", strerror(errno));
        return;
    }

    int reuse = 1;
    if (setsockopt(_team_relay_recv_socket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0)
    {
        RCLCPP_ERROR(get_logger(), "team relay failed to set SO_REUSEADDR: %s", strerror(errno));
    }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(_team_relay_port);

    if (bind(_team_relay_recv_socket, (sockaddr *)&addr, sizeof(addr)) < 0)
    {
        RCLCPP_ERROR(get_logger(), "team relay bind failed: %s (port=%d)", strerror(errno), _team_relay_port);
        return;
    }

    _team_relay_receive_flag.store(true);
    _team_relay_thread = thread(&GameControllerNode::spinTeamRelayReceiver, this);
    RCLCPP_INFO(get_logger(), "Team relay enabled on UDP port %d.", _team_relay_port);
}

void GameControllerNode::clearupTeamRelay()
{
    _team_relay_receive_flag.store(false);
    if (_team_relay_send_socket >= 0)
    {
        close(_team_relay_send_socket);
        _team_relay_send_socket = -1;
    }
    if (_team_relay_recv_socket >= 0)
    {
        close(_team_relay_recv_socket);
        _team_relay_recv_socket = -1;
    }
    if (_team_relay_thread.joinable())
    {
        _team_relay_thread.join();
    }
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

GameControllerNode::TeamRelayPacket GameControllerNode::toRelayPacket(const game_controller_interface::msg::TeamCommunication &msg)
{
    TeamRelayPacket packet{};
    packet.validation = msg.validation;
    packet.communicationId = msg.communication_id;
    packet.teamId = msg.team_id;
    packet.playerId = msg.player_id;
    packet.playerRole = msg.player_role;
    packet.isAlive = msg.is_alive;
    packet.isLead = msg.is_lead;
    packet.ballDetected = msg.ball_detected;
    packet.ballLocationKnown = msg.ball_location_known;
    packet.ballConfidence = msg.ball_confidence;
    packet.ballRange = msg.ball_range;
    packet.cost = msg.cost;
    packet.ballX = msg.ball_x;
    packet.ballY = msg.ball_y;
    packet.ballZ = msg.ball_z;
    packet.robotX = msg.robot_x;
    packet.robotY = msg.robot_y;
    packet.robotTheta = msg.robot_theta;
    packet.kickDir = msg.kick_dir;
    packet.thetaRb = msg.theta_rb;
    packet.cmdId = msg.cmd_id;
    packet.cmd = msg.cmd;
    return packet;
}

game_controller_interface::msg::TeamCommunication GameControllerNode::toRosTeamCommunication(const TeamRelayPacket &packet)
{
    game_controller_interface::msg::TeamCommunication msg;
    msg.validation = packet.validation;
    msg.communication_id = packet.communicationId;
    msg.team_id = packet.teamId;
    msg.player_id = packet.playerId;
    msg.player_role = packet.playerRole;
    msg.is_alive = packet.isAlive;
    msg.is_lead = packet.isLead;
    msg.ball_detected = packet.ballDetected;
    msg.ball_location_known = packet.ballLocationKnown;
    msg.ball_confidence = packet.ballConfidence;
    msg.ball_range = packet.ballRange;
    msg.cost = packet.cost;
    msg.ball_x = packet.ballX;
    msg.ball_y = packet.ballY;
    msg.ball_z = packet.ballZ;
    msg.robot_x = packet.robotX;
    msg.robot_y = packet.robotY;
    msg.robot_theta = packet.robotTheta;
    msg.kick_dir = packet.kickDir;
    msg.theta_rb = packet.thetaRb;
    msg.cmd_id = packet.cmdId;
    msg.cmd = packet.cmd;
    return msg;
}

void GameControllerNode::relayOutgoingTeamCommunication(const game_controller_interface::msg::TeamCommunication::SharedPtr msg)
{
    if (!_enable_team_relay || _team_relay_send_socket < 0)
    {
        return;
    }

    TeamRelayPacket packet = toRelayPacket(*msg);
    ssize_t ret = sendto(_team_relay_send_socket, &packet, sizeof(packet), 0, (sockaddr *)&_team_relay_addr, sizeof(_team_relay_addr));
    if (ret < 0)
    {
        RCLCPP_ERROR(get_logger(), "team relay sendto failed: %s", strerror(errno));
        return;
    }
    RCLCPP_INFO_THROTTLE(
        get_logger(),
        *get_clock(),
        1000,
        "team relay TX team=%d player=%d commId=%d cmdId=%d cmd=%d",
        packet.teamId,
        packet.playerId,
        packet.communicationId,
        packet.cmdId,
        packet.cmd);
}

void GameControllerNode::spinTeamRelayReceiver()
{
    sockaddr_in remote_addr{};
    socklen_t remote_addr_len = sizeof(remote_addr);
    TeamRelayPacket packet{};

    while (_team_relay_receive_flag.load(std::memory_order_relaxed) && rclcpp::ok())
    {
        ssize_t ret = recvfrom(_team_relay_recv_socket, &packet, sizeof(packet), 0, (sockaddr *)&remote_addr, &remote_addr_len);
        if (!_team_relay_receive_flag.load(std::memory_order_relaxed))
        {
            break;
        }
        if (ret < 0)
        {
            RCLCPP_ERROR(get_logger(), "team relay recvfrom failed: %s", strerror(errno));
            continue;
        }
        if (ret != sizeof(packet))
        {
            RCLCPP_INFO(get_logger(), "team relay packet invalid length=%ld, expected=%ld", ret, sizeof(packet));
            continue;
        }
        if (_team_id > 0 && packet.teamId != _team_id)
        {
            continue;
        }

        RCLCPP_INFO_THROTTLE(
            get_logger(),
            *get_clock(),
            1000,
            "team relay RX team=%d player=%d commId=%d cmdId=%d cmd=%d",
            packet.teamId,
            packet.playerId,
            packet.communicationId,
            packet.cmdId,
            packet.cmd);
        _team_relay_publisher->publish(toRosTeamCommunication(packet));
    }
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
