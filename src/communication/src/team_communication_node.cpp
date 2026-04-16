#include "communication/team_communication_node.h"

#include <algorithm>
#include <array>
#include <cerrno>
#include <chrono>
#include <cstring>
#include <limits>
#include <stdexcept>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

namespace
{
constexpr std::array<char, 4> kPacketMagic = {'B', 'R', 'T', 'M'};
constexpr uint8_t kPacketVersion = 1;
constexpr uint8_t kFlagBallValid = 1U << 0;

constexpr uint8_t kStateReady = 1;
constexpr uint8_t kStateSet = 2;
constexpr uint8_t kStatePlaying = 3;
constexpr uint8_t kSecondaryPenaltyShoot = 1;
} // namespace

TeamCommunicationNode::TeamCommunicationNode() : rclcpp::Node("team_communication_node")
{
    declare_parameter<int>("team_id", 67);
    declare_parameter<int>("player_id", 1);
    declare_parameter<int>("udp_port_base", 10000);
    declare_parameter<int>("max_packet_size", 512);
    declare_parameter<std::string>("bind_address", "0.0.0.0");
    declare_parameter<std::string>("broadcast_address", "255.255.255.255");
    declare_parameter<double>("send_hz", 1.0);
    declare_parameter<double>("publish_hz", 5.0);
    declare_parameter<double>("ball_timeout_sec", 1.0);
    declare_parameter<double>("teammate_timeout_sec", 3.0);
    declare_parameter<bool>("send_only_in_counted_states", false);

    team_id_ = static_cast<int>(get_parameter("team_id").as_int());
    player_id_ = static_cast<int>(get_parameter("player_id").as_int());
    udp_port_base_ = static_cast<int>(get_parameter("udp_port_base").as_int());
    max_packet_size_ = static_cast<int>(get_parameter("max_packet_size").as_int());
    bind_address_ = get_parameter("bind_address").as_string();
    broadcast_address_ = get_parameter("broadcast_address").as_string();
    send_hz_ = get_parameter("send_hz").as_double();
    publish_hz_ = get_parameter("publish_hz").as_double();
    ball_timeout_sec_ = get_parameter("ball_timeout_sec").as_double();
    teammate_timeout_sec_ = get_parameter("teammate_timeout_sec").as_double();
    send_only_in_counted_states_ = get_parameter("send_only_in_counted_states").as_bool();

    team_id_ = std::clamp(team_id_, 1, 254);
    player_id_ = std::clamp(player_id_, 1, 20);
    udp_port_base_ = std::max(10000, udp_port_base_);
    max_packet_size_ = std::clamp(max_packet_size_, 64, 512);
    send_hz_ = std::max(send_hz_, 0.1);
    publish_hz_ = std::max(publish_hz_, 0.2);
    ball_timeout_sec_ = std::max(ball_timeout_sec_, 0.1);
    teammate_timeout_sec_ = std::max(teammate_timeout_sec_, 0.5);
    udp_port_ = udp_port_base_ + team_id_;

    RCLCPP_INFO(get_logger(),
                "Team communication config: team_id=%d player_id=%d port=%d send_hz=%.2f max_packet=%d",
                team_id_,
                player_id_,
                udp_port_,
                send_hz_,
                max_packet_size_);

    teammates_pub_ = create_publisher<communication::msg::TeammateBallArray>(
        "/booster_soccer/team_ball_teammates", rclcpp::QoS(10));

    robot_pose_sub_ = create_subscription<geometry_msgs::msg::Pose2D>(
        "/booster_soccer/robot_pose",
        rclcpp::QoS(10),
        std::bind(&TeamCommunicationNode::robotPoseCallback, this, std::placeholders::_1));

    ball_position_sub_ = create_subscription<geometry_msgs::msg::Point>(
        "/booster_soccer/ball_position",
        rclcpp::QoS(10),
        std::bind(&TeamCommunicationNode::ballPositionCallback, this, std::placeholders::_1));

    game_control_sub_ = create_subscription<game_controller_interface::msg::GameControlData>(
        "/booster_soccer/game_controller",
        rclcpp::QoS(10),
        std::bind(&TeamCommunicationNode::gameControlCallback, this, std::placeholders::_1));

    setupSockets();
    receive_running_.store(true, std::memory_order_relaxed);
    receive_thread_ = std::thread(&TeamCommunicationNode::receiveLoop, this);

    const auto send_period =
        std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::duration<double>(1.0 / send_hz_));
    send_timer_ = create_wall_timer(send_period, std::bind(&TeamCommunicationNode::sendPacket, this));

    const auto publish_period =
        std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::duration<double>(1.0 / publish_hz_));
    publish_timer_ = create_wall_timer(publish_period, std::bind(&TeamCommunicationNode::publishTeammates, this));
}

TeamCommunicationNode::~TeamCommunicationNode()
{
    teardownSockets();
}

void TeamCommunicationNode::setupSockets()
{
    send_socket_ = ::socket(AF_INET, SOCK_DGRAM, 0);
    if (send_socket_ < 0)
    {
        throw std::runtime_error(std::string("failed to create send socket: ") + std::strerror(errno));
    }

    int opt = 1;
    if (::setsockopt(send_socket_, SOL_SOCKET, SO_BROADCAST, &opt, sizeof(opt)) < 0)
    {
        throw std::runtime_error(std::string("failed to set SO_BROADCAST: ") + std::strerror(errno));
    }

    recv_socket_ = ::socket(AF_INET, SOCK_DGRAM, 0);
    if (recv_socket_ < 0)
    {
        throw std::runtime_error(std::string("failed to create receive socket: ") + std::strerror(errno));
    }

    if (::setsockopt(recv_socket_, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        throw std::runtime_error(std::string("failed to set SO_REUSEADDR: ") + std::strerror(errno));
    }

    sockaddr_in recv_addr {};
    recv_addr.sin_family = AF_INET;
    recv_addr.sin_port = htons(static_cast<uint16_t>(udp_port_));
    if (bind_address_ == "0.0.0.0")
    {
        recv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    }
    else if (::inet_pton(AF_INET, bind_address_.c_str(), &recv_addr.sin_addr) != 1)
    {
        throw std::runtime_error("invalid bind_address: " + bind_address_);
    }

    if (::bind(recv_socket_, reinterpret_cast<sockaddr *>(&recv_addr), sizeof(recv_addr)) < 0)
    {
        throw std::runtime_error(std::string("failed to bind receive socket: ") + std::strerror(errno));
    }

    sockaddr_in test_broadcast_addr {};
    test_broadcast_addr.sin_family = AF_INET;
    test_broadcast_addr.sin_port = htons(static_cast<uint16_t>(udp_port_));
    if (::inet_pton(AF_INET, broadcast_address_.c_str(), &test_broadcast_addr.sin_addr) != 1)
    {
        throw std::runtime_error("invalid broadcast_address: " + broadcast_address_);
    }

    RCLCPP_INFO(get_logger(),
                "Team communication sockets ready on %s:%d, broadcast=%s",
                bind_address_.c_str(),
                udp_port_,
                broadcast_address_.c_str());
}

void TeamCommunicationNode::teardownSockets()
{
    receive_running_.store(false, std::memory_order_relaxed);

    if (send_socket_ >= 0)
    {
        sockaddr_in wakeup_addr {};
        wakeup_addr.sin_family = AF_INET;
        wakeup_addr.sin_port = htons(static_cast<uint16_t>(udp_port_));
        wakeup_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
        ::sendto(send_socket_, nullptr, 0, 0, reinterpret_cast<sockaddr *>(&wakeup_addr), sizeof(wakeup_addr));
    }

    if (receive_thread_.joinable())
    {
        receive_thread_.join();
    }

    if (recv_socket_ >= 0)
    {
        ::close(recv_socket_);
        recv_socket_ = -1;
    }

    if (send_socket_ >= 0)
    {
        ::close(send_socket_);
        send_socket_ = -1;
    }
}

void TeamCommunicationNode::receiveLoop()
{
    std::array<uint8_t, 1024> buffer {};

    while (receive_running_.load(std::memory_order_relaxed))
    {
        const ssize_t len = ::recvfrom(recv_socket_, buffer.data(), buffer.size(), 0, nullptr, nullptr);
        if (len < 0)
        {
            if (errno == EINTR)
            {
                continue;
            }
            if (!receive_running_.load(std::memory_order_relaxed))
            {
                break;
            }
            RCLCPP_WARN_THROTTLE(
                get_logger(), *get_clock(), 2000, "Team comm recv error: %s", std::strerror(errno));
            continue;
        }

        if (len == 0)
        {
            continue;
        }

        if (len > max_packet_size_)
        {
            RCLCPP_WARN_THROTTLE(
                get_logger(), *get_clock(), 2000, "Ignored oversized team packet (%ld bytes)", len);
            continue;
        }

        if (static_cast<size_t>(len) != sizeof(TeamBallPacket))
        {
            continue;
        }

        TeamBallPacket packet {};
        std::memcpy(&packet, buffer.data(), sizeof(packet));

        if (!std::equal(kPacketMagic.begin(), kPacketMagic.end(), packet.magic))
        {
            continue;
        }
        if (packet.version != kPacketVersion)
        {
            continue;
        }
        if (packet.team_id != static_cast<uint8_t>(team_id_))
        {
            continue;
        }
        if (packet.player_id == 0 || packet.player_id == static_cast<uint8_t>(player_id_))
        {
            continue;
        }

        TeammateState state;
        state.player_id = packet.player_id;
        state.ball_valid = (packet.flags & kFlagBallValid) != 0;
        state.robot_x = packet.robot_x;
        state.robot_y = packet.robot_y;
        state.robot_theta = packet.robot_theta;
        state.ball_x = packet.ball_x;
        state.ball_y = packet.ball_y;
        state.ball_age_sec = packet.ball_age_sec;
        state.sequence = packet.sequence;
        state.sent_time_ms = packet.sent_time_ms;
        state.last_rx_time = now();

        std::lock_guard<std::mutex> lock(teammates_mutex_);
        teammates_[state.player_id] = state;
    }
}

void TeamCommunicationNode::sendPacket()
{
    if (send_only_in_counted_states_ && !isInCountedState())
    {
        return;
    }

    LocalState local_state_copy;
    {
        std::lock_guard<std::mutex> lock(local_state_mutex_);
        local_state_copy = local_state_;
    }

    if (!local_state_copy.have_robot_pose)
    {
        RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), 2000, "Waiting for /booster_soccer/robot_pose");
        return;
    }

    const rclcpp::Time t_now = now();
    const double ball_age_sec =
        local_state_copy.have_ball ? (t_now - local_state_copy.ball_stamp).seconds() : std::numeric_limits<double>::infinity();
    const bool ball_valid = local_state_copy.have_ball && ball_age_sec <= ball_timeout_sec_;

    TeamBallPacket packet {};
    std::copy(kPacketMagic.begin(), kPacketMagic.end(), packet.magic);
    packet.version = kPacketVersion;
    packet.team_id = static_cast<uint8_t>(team_id_);
    packet.player_id = static_cast<uint8_t>(player_id_);
    packet.flags = ball_valid ? kFlagBallValid : 0;
    packet.sequence = sequence_++;
    packet.robot_x = static_cast<float>(local_state_copy.robot_pose.x);
    packet.robot_y = static_cast<float>(local_state_copy.robot_pose.y);
    packet.robot_theta = static_cast<float>(local_state_copy.robot_pose.theta);
    packet.ball_x = ball_valid ? static_cast<float>(local_state_copy.ball_position.x) : 0.0f;
    packet.ball_y = ball_valid ? static_cast<float>(local_state_copy.ball_position.y) : 0.0f;
    packet.ball_age_sec = ball_valid ? static_cast<float>(ball_age_sec) : -1.0f;
    packet.sent_time_ms = nowMilliseconds();

    if (static_cast<int>(sizeof(packet)) > max_packet_size_)
    {
        RCLCPP_ERROR_THROTTLE(get_logger(),
                              *get_clock(),
                              5000,
                              "Packet size (%zu) exceeds configured max_packet_size (%d)",
                              sizeof(packet),
                              max_packet_size_);
        return;
    }

    sockaddr_in target_addr {};
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(static_cast<uint16_t>(udp_port_));
    if (::inet_pton(AF_INET, broadcast_address_.c_str(), &target_addr.sin_addr) != 1)
    {
        RCLCPP_ERROR_THROTTLE(
            get_logger(), *get_clock(), 5000, "Invalid broadcast_address '%s'", broadcast_address_.c_str());
        return;
    }

    const ssize_t ret = ::sendto(send_socket_,
                                 &packet,
                                 sizeof(packet),
                                 0,
                                 reinterpret_cast<sockaddr *>(&target_addr),
                                 sizeof(target_addr));

    if (ret < 0)
    {
        RCLCPP_WARN_THROTTLE(
            get_logger(), *get_clock(), 2000, "Team comm send error: %s", std::strerror(errno));
    }
}

void TeamCommunicationNode::publishTeammates()
{
    communication::msg::TeammateBallArray array_msg;
    const rclcpp::Time t_now = now();
    array_msg.stamp = t_now.to_msg();

    {
        std::lock_guard<std::mutex> lock(teammates_mutex_);
        for (auto it = teammates_.begin(); it != teammates_.end();)
        {
            const double rx_age_sec = (t_now - it->second.last_rx_time).seconds();
            if (rx_age_sec > teammate_timeout_sec_)
            {
                it = teammates_.erase(it);
                continue;
            }

            communication::msg::TeammateBall teammate_msg;
            teammate_msg.player_id = it->second.player_id;
            teammate_msg.ball_valid = it->second.ball_valid;
            teammate_msg.robot_x = it->second.robot_x;
            teammate_msg.robot_y = it->second.robot_y;
            teammate_msg.robot_theta = it->second.robot_theta;
            teammate_msg.ball_x = it->second.ball_x;
            teammate_msg.ball_y = it->second.ball_y;
            teammate_msg.ball_age_sec = it->second.ball_age_sec;
            teammate_msg.rx_age_sec = static_cast<float>(rx_age_sec);
            teammate_msg.sequence = it->second.sequence;
            teammate_msg.sent_time_ms = it->second.sent_time_ms;
            teammate_msg.stamp = it->second.last_rx_time.to_msg();
            array_msg.teammates.push_back(teammate_msg);

            ++it;
        }
    }

    std::sort(array_msg.teammates.begin(),
              array_msg.teammates.end(),
              [](const communication::msg::TeammateBall &a, const communication::msg::TeammateBall &b) {
                  return a.player_id < b.player_id;
              });

    teammates_pub_->publish(array_msg);
}

bool TeamCommunicationNode::isInCountedState() const
{
    const uint8_t state = game_state_.load(std::memory_order_relaxed);
    const uint8_t secondary = game_secondary_state_.load(std::memory_order_relaxed);
    const bool counted_state = (state == kStateReady) || (state == kStateSet) || (state == kStatePlaying);
    const bool penalty_shoot = secondary == kSecondaryPenaltyShoot;
    return counted_state && !penalty_shoot;
}

uint64_t TeamCommunicationNode::nowMilliseconds() const
{
    return static_cast<uint64_t>(now().nanoseconds() / 1000000LL);
}

void TeamCommunicationNode::robotPoseCallback(const geometry_msgs::msg::Pose2D::SharedPtr msg)
{
    std::lock_guard<std::mutex> lock(local_state_mutex_);
    local_state_.robot_pose = *msg;
    local_state_.robot_pose_stamp = now();
    local_state_.have_robot_pose = true;
}

void TeamCommunicationNode::ballPositionCallback(const geometry_msgs::msg::Point::SharedPtr msg)
{
    std::lock_guard<std::mutex> lock(local_state_mutex_);
    local_state_.ball_position = *msg;
    local_state_.ball_stamp = now();
    local_state_.have_ball = true;
}

void TeamCommunicationNode::gameControlCallback(
    const game_controller_interface::msg::GameControlData::SharedPtr msg)
{
    game_state_.store(msg->state, std::memory_order_relaxed);
    game_secondary_state_.store(msg->secondary_state, std::memory_order_relaxed);
}
