#include "brain.h"
#include "brain_communication.h"

/*
It handles 3 Critical things:
    1. Game Controller Communication
    2. Discovery -> Robot find teammates on this network
    3. Team Communication -> Robot share game state (ball, roles and decisions)

This is what enables:
    1. Role Switching (Striker <---> Goal Keeper)
    2. Passing Decisions
    3. Avoid Multiple Robots Chasing the same ball
    4. Leader Election
*/

// -------------------- Things to include inside -----------------------
/*
    1. Cost Function Design
    - Who to go for ball
        IF myCost < all tmStatus.cost
            → chase ball
        ELSE
            → reposition
    - Must use `cost` so that not everyone chases ball

    2. Role Assignment
    - Striker / Goalkeeper switching
    - dynamic roles
    - Must use `robotPoseToField` so that robots don't collide

    3. Leader Logic
    - Who decides
    - When to switch leader
    - Use `isLead`

    4. Team Coordination Logic In Behavioral tree
    - Decides who does the 
        - Spacing
        - Passing
        - Fallback Behavior
    - Must modify the `ballPosToField` to ensure that they pass
    
    
*/

BrainCommunication::BrainCommunication(Brain *argBrain) : brain(argBrain)
{
}

BrainCommunication::~BrainCommunication()
{
    clearupGameControllerUnicast();
    clearupRelayPublishLoop();
}

void BrainCommunication::initCommunication()
{
    initGameControllerUnicast();
    
    if (brain->config->get_enable_com())
    {
        int teamId = brain->config->get_team_id();
        cout << RED_CODE << "Communication enabled." << RESET_CODE << endl;
        _team_port = 10000 + teamId;
        initRelayCommunication();

        if (_enable_robot_comm_relay) {
            initRelayPublishLoop();
            RCLCPP_INFO(
                brain->get_logger(),
                "HSL team communication uses robot_communication_node broadcast relay on UDP port %d.",
                _team_port);
        } else {
            RCLCPP_WARN(
                brain->get_logger(),
                "Team communication relay disabled. No robot-to-robot team communication will be published.");
        }
    }
    else
    {
        cout << RED_CODE << "Communication disabled." << RESET_CODE << endl;
    }
}

void BrainCommunication::initRelayCommunication()
{
    brain->get_parameter_or("enable_robot_comm_relay", _enable_robot_comm_relay, true);
    if (!_enable_robot_comm_relay) {
        RCLCPP_INFO(brain->get_logger(), "Robot communication relay disabled.");
        return;
    }

    _relay_pub = brain->create_publisher<game_controller_interface::msg::TeamCommunication>(
        "/booster_soccer/team_comm/out", 10);
    _relay_sub = brain->create_subscription<game_controller_interface::msg::TeamCommunication>(
        "/booster_soccer/team_comm/in",
        10,
        [this](const game_controller_interface::msg::TeamCommunication::SharedPtr msg) {
            this->relayCommunicationCallback(msg);
        });

    RCLCPP_INFO(brain->get_logger(), "Robot communication relay ROS topics enabled.");
}

// soccer agent will switch team_id, determine whether the team has changed based on the port and the current teamId
bool BrainCommunication::isTeamChanged(){
    int teamId = brain->config->get_team_id();
    if (teamId != (_team_port - 10000)) {
        RCLCPP_INFO(brain->get_logger(), "Team changed current team_port=%d, team_id to %d", _team_port, teamId);
        return true;
    }
    return false;
}
    

void BrainCommunication::initGameControllerUnicast()
{
    try
    {
        _gc_send_socket = socket(AF_INET, SOCK_DGRAM, 0);
        if (_gc_send_socket < 0)
        {
        cout << RED_CODE << format("gc socket failed: %s", strerror(errno))
            << RESET_CODE << endl;
        throw std::runtime_error(strerror(errno));
        }
        // Configure target address
        string gamecontrol_ip = brain->config->get_game_control_ip();
        cout << GREEN_CODE << format("GameControl IP: %s", gamecontrol_ip.c_str())
            << RESET_CODE << endl;
        _gcsaddr.sin_family = AF_INET;
        _gcsaddr.sin_addr.s_addr = inet_addr(gamecontrol_ip.c_str());
        _gcsaddr.sin_port = htons(GAMECONTROLLER_RETURN_PORT);

        _unicast_gamecontrol_flag.store(true);
        _gamecontrol_unicast_thread = std::thread([this](){ this->unicastToGameController(); });
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void BrainCommunication::clearupGameControllerUnicast()
{
    _unicast_gamecontrol_flag.store(false);
    if (_gc_send_socket >= 0)
    {
        close(_gc_send_socket);
        _gc_send_socket = -1;
        cout << RED_CODE << format("GameControl send socket has been closed.")
            << RESET_CODE << endl;
    }
    if (_gamecontrol_unicast_thread.joinable())
    {
        _gamecontrol_unicast_thread.join();
    }
}

void BrainCommunication::unicastToGameController() {
    while (_unicast_gamecontrol_flag.load(std::memory_order_relaxed))
    {
        gc_return_data.team = brain->config->get_team_id();
        gc_return_data.player = brain->config->get_player_id(); // return data id is 1,2,3,4
        gc_return_data.message = GAMECONTROLLER_RETURN_MSG_ALIVE;

        int ret = sendto(_gc_send_socket, &gc_return_data, sizeof(gc_return_data), 0, (sockaddr *)&_gcsaddr, sizeof(_gcsaddr));
        if (ret < 0)
        {
            cout << RED_CODE << format("gc sendto failed: %s", strerror(errno))
                << RESET_CODE << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(BROADCAST_GAME_CONTROL_INTERVAL_MS));
    }
}

void BrainCommunication::initRelayPublishLoop() {
    try
    {
        if (!_enable_robot_comm_relay) {
            return;
        }

        _relay_publish_flag.store(true);
        _relay_publish_thread = std::thread([this](){ this->relayPublishLoop(); });
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        brain->log->log("error/communication", format("Failed to initialize relay communication publisher: %s", e.what()));
    }
    
}

TeamCommunicationMsg BrainCommunication::makeTeamCommunicationMsg()
{
    TeamCommunicationMsg msg;
    msg.validation = VALIDATION_COMMUNICATION;
    msg.communicationId = _team_communication_msg_id++;
    msg.teamId = brain->config->get_team_id();
    msg.playerId = brain->config->get_player_id();

    string role = brain->tree->getEntry<string>("player_role");
    if (role == "striker") {
        msg.playerRole = 1;
    } else if (role == "goal_keeper") {
        msg.playerRole = 2;
    } else {
        msg.playerRole = 3;
    }

    msg.isAlive = brain->data->tmImAlive;
    msg.isLead = brain->data->tmImLead;
    msg.ballDetected = brain->data->ballDetected;
    msg.ballLocationKnown = brain->tree->getEntry<bool>("ball_location_known");
    msg.ballConfidence = brain->data->ball.confidence;
    msg.ballRange = brain->data->ball.range;
    msg.cost = brain->data->tmMyCost;
    msg.ballPosToField = brain->data->ball.posToField;
    msg.robotPoseToField = brain->data->robotPoseToField;
    msg.kickDir = brain->data->kickDir;
    msg.thetaRb = brain->data->robotBallAngleToField;
    msg.cmdId = brain->data->tmMyCmdId;
    msg.cmd = brain->data->tmMyCmd;
    return msg;
}

game_controller_interface::msg::TeamCommunication BrainCommunication::toRelayMsg(const TeamCommunicationMsg &msg)
{
    game_controller_interface::msg::TeamCommunication relayMsg;
    relayMsg.validation = msg.validation;
    relayMsg.communication_id = msg.communicationId;
    relayMsg.team_id = msg.teamId;
    relayMsg.player_id = msg.playerId;
    relayMsg.player_role = msg.playerRole;
    relayMsg.is_alive = msg.isAlive;
    relayMsg.is_lead = msg.isLead;
    relayMsg.ball_detected = msg.ballDetected;
    relayMsg.ball_location_known = msg.ballLocationKnown;
    relayMsg.ball_confidence = msg.ballConfidence;
    relayMsg.ball_range = msg.ballRange;
    relayMsg.cost = msg.cost;
    relayMsg.ball_pos_to_field_x = msg.ballPosToField.x;
    relayMsg.ball_pos_to_field_y = msg.ballPosToField.y;
    relayMsg.ball_pos_to_field_z = msg.ballPosToField.z;
    relayMsg.robot_pose_to_field_x = msg.robotPoseToField.x;
    relayMsg.robot_pose_to_field_y = msg.robotPoseToField.y;
    relayMsg.robot_pose_to_field_theta = msg.robotPoseToField.theta;
    relayMsg.kick_dir = msg.kickDir;
    relayMsg.theta_rb = msg.thetaRb;
    relayMsg.cmd_id = msg.cmdId;
    relayMsg.cmd = msg.cmd;
    return relayMsg;
}

TeamCommunicationMsg BrainCommunication::fromRelayMsg(const game_controller_interface::msg::TeamCommunication &relayMsg)
{
    TeamCommunicationMsg msg;
    msg.validation = relayMsg.validation;
    msg.communicationId = relayMsg.communication_id;
    msg.teamId = relayMsg.team_id;
    msg.playerId = relayMsg.player_id;
    msg.playerRole = relayMsg.player_role;
    msg.isAlive = relayMsg.is_alive;
    msg.isLead = relayMsg.is_lead;
    msg.ballDetected = relayMsg.ball_detected;
    msg.ballLocationKnown = relayMsg.ball_location_known;
    msg.ballConfidence = relayMsg.ball_confidence;
    msg.ballRange = relayMsg.ball_range;
    msg.cost = relayMsg.cost;
    msg.ballPosToField = {relayMsg.ball_pos_to_field_x, relayMsg.ball_pos_to_field_y, relayMsg.ball_pos_to_field_z};
    msg.robotPoseToField = {relayMsg.robot_pose_to_field_x, relayMsg.robot_pose_to_field_y, relayMsg.robot_pose_to_field_theta};
    msg.kickDir = relayMsg.kick_dir;
    msg.thetaRb = relayMsg.theta_rb;
    msg.cmdId = relayMsg.cmd_id;
    msg.cmd = relayMsg.cmd;
    return msg;
}

void BrainCommunication::relayCommunicationCallback(const game_controller_interface::msg::TeamCommunication::SharedPtr msg)
{
    processTeamCommunicationMsg(fromRelayMsg(*msg), "relay");
}

void BrainCommunication::processTeamCommunicationMsg(const TeamCommunicationMsg &msg, const string &source)
{
    auto log = [=](string msg) {
        brain->log->debug("receiveMsg", msg);
    };

    if (msg.validation != VALIDATION_COMMUNICATION) {
        cout << RED_CODE << format("received %s TeamCommunicationMsg with invalid validation: %d", source.c_str(), msg.validation)
            << RESET_CODE << endl;
        return;
    }

    if (msg.teamId != brain->config->get_team_id()) {
        cout << YELLOW_CODE << format("Received %s message from team %d, expected team %d", source.c_str(), msg.teamId, brain->config->get_team_id())
            << RESET_CODE << endl;
        return;
    }

    if (msg.playerId == brain->config->get_player_id()) {
        cout << CYAN_CODE <<  format(
            "%s communicationId: %d, alive: %d, ballDetected: %d ballRange: %.2f playerId: %d",
            source.c_str(), msg.communicationId, msg.isAlive, msg.ballDetected, msg.ballRange, msg.playerId)
            << RESET_CODE << endl;
        brain->data->sendId = msg.communicationId;
        brain->data->sendTime = brain->get_clock()->now();
        return;
    }

    auto tmIdx = msg.playerId - 1;

    if (tmIdx < 0 || tmIdx >= HL_MAX_NUM_PLAYERS) {
        cout << YELLOW_CODE << format("Received %s message with invalid playerId: %d", source.c_str(), msg.playerId) << RESET_CODE << endl;
        return;
    }

    if (brain->data->penalty[tmIdx] == SUBSTITUTE) {
        cout << YELLOW_CODE << format("Communication %s playerId %d is substitute", source.c_str(), msg.playerId) << RESET_CODE << endl;
        return;
    }

    log(format("TMID: %.d, alive: %d, lead: %d, cost: %.1f, CmdId: %d, Cmd: %d, source: %s",
        msg.playerId, msg.isAlive, msg.isLead, msg.cost, msg.cmdId, msg.cmd, source.c_str()));

    TMStatus &tmStatus = brain->data->tmStatus[tmIdx];

    switch(msg.playerRole) {
        case 1: tmStatus.role = "striker"; break;
        case 2: tmStatus.role = "goal_keeper"; break;
        default: tmStatus.role = "unknown"; break;
    }
    tmStatus.isAlive = msg.isAlive;
    tmStatus.ballDetected = msg.ballDetected;
    tmStatus.ballLocationKnown = msg.ballLocationKnown;
    tmStatus.ballConfidence = msg.ballConfidence;
    tmStatus.ballRange = msg.ballRange;
    tmStatus.cost = msg.cost;
    tmStatus.isLead = msg.isLead;
    tmStatus.ballPosToField = msg.ballPosToField;
    tmStatus.robotPoseToField = msg.robotPoseToField;
    tmStatus.kickDir = msg.kickDir;
    tmStatus.thetaRb = msg.thetaRb;
    tmStatus.timeLastCom = brain->get_clock()->now();
    tmStatus.cmd = msg.cmd;
    tmStatus.cmdId = msg.cmdId;

    if (msg.cmdId > brain->data->tmCmdId) {
        brain->data->tmCmdId = msg.cmdId;
        brain->data->tmReceivedCmd = msg.cmd;
        brain->data->tmLastCmdChangeTime = brain->get_clock()->now();
        log(format("Received new command from teammate %d through %s: %d", msg.playerId, source.c_str(), msg.cmd));
    }
}

// --------- This is the core data your Behavioral tree depends on -------------
/*
    Your Behavioral Tree can:
        - Decide who to go for ball
        - Decide who becomes the leader
        - Decide Passing vs Shooting
        - Decide Positioning
*/
void BrainCommunication::relayPublishLoop() {
    auto log = [=](string msg) {
        brain->log->debug("sendMsg", msg);
    };
    while (_relay_publish_flag) {
        TeamCommunicationMsg msg = makeTeamCommunicationMsg();
        log(format("ImAlive: %d, ImLead: %d, myCost: %.1f, myCmdId: %d, myCmd: %d", msg.isAlive, msg.isLead, msg.cost, msg.cmdId, msg.cmd));

        if (_enable_robot_comm_relay && _relay_pub) {
            _relay_pub->publish(toRelayMsg(msg));
            this_thread::sleep_for(chrono::milliseconds(RELAY_PUBLISH_INTERVAL_MS));
            continue;
        }

        this_thread::sleep_for(chrono::milliseconds(RELAY_PUBLISH_INTERVAL_MS));
    }
}

void BrainCommunication::clearupRelayPublishLoop() {
    _relay_publish_flag.store(false);
    if (_relay_publish_thread.joinable()) {
        _relay_publish_thread.join();
    }
}
