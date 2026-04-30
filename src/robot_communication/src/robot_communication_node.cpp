#include <algorithm>
#include <array>
#include <atomic>
#include <cerrno>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <map>
#include <memory>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <thread>
#include <utility>

#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <rclcpp/rclcpp.hpp>
#include <game_controller_interface/msg/team_communication.hpp>

using TeamCommunication = game_controller_interface::msg::TeamCommunication;

namespace
{
constexpr int VALIDATION_COMMUNICATION = 31202;
constexpr int TEAM_PORT_BASE = 10000;
constexpr std::size_t COMPACT_PACKET_SIZE = 5;
constexpr std::size_t MAX_TEAM_PACKET_SIZE = 512;
constexpr std::size_t RECEIVE_BUFFER_SIZE = MAX_TEAM_PACKET_SIZE;
constexpr double PI = 3.14159265358979323846;
constexpr uint8_t COMPACT_PLAYER_ID_MASK = 0x0F;
constexpr uint8_t COMPACT_ROLE_MASK = 0x30;
constexpr uint8_t COMPACT_READY_MASK = 0x40;
constexpr uint8_t COMPACT_ROLE_SHIFT = 4;
constexpr uint8_t COMPACT_UNKNOWN_BALL = 0xFF;
constexpr uint8_t COMPACT_MIN_BALL_ZONE = 1;
constexpr uint8_t COMPACT_MAX_BALL_ZONE = 9;
constexpr int FIELD_ZONE_ROWS = 3;
constexpr int FIELD_ZONE_COLS = 3;
constexpr uint16_t COMPACT_POSE_COMPONENT_MASK = 0x1F;
constexpr int COMPACT_ROBOT_Y_SHIFT = 5;
constexpr int COMPACT_ROBOT_THETA_SHIFT = 10;

enum CompactRole : uint8_t
{
    ROLE_UNKNOWN = 0,
    ROLE_STRIKER = 1,
    ROLE_GOALIE = 2,
    ROLE_DEFENDER = 3,
};

struct CompactTeamPacket
{
    // Existing compact wire format, kept at 5 bytes:
    // [password][id/role/alive][ball zone][pose byte 0][pose byte 1 ]
    // Byte 2 is 1..9 for a 3x3 field zone, or 0xFF when the ball position is unknown.
    std::array<uint8_t, COMPACT_PACKET_SIZE> bytes{};

    static uint16_t decodeCompactRobotPose(const uint8_t *packet)
    {
        return static_cast<uint16_t>(packet[3]) | (static_cast<uint16_t>(packet[4]) << 8);
    }

    static bool validate(const uint8_t *packet, std::size_t len, uint8_t password)
    {
        if (len != COMPACT_PACKET_SIZE || len > MAX_TEAM_PACKET_SIZE) return false;
        if (packet[0] != password) return false;

        const uint8_t role = (packet[1] & COMPACT_ROLE_MASK) >> COMPACT_ROLE_SHIFT;
        if (role > ROLE_DEFENDER) return false;

        const uint8_t ball = packet[2];
        if (ball != COMPACT_UNKNOWN_BALL
            && (ball < COMPACT_MIN_BALL_ZONE || ball > COMPACT_MAX_BALL_ZONE)) {
            return false;
        }

        return true;
    }

    int playerId() const
    {
        return bytes[1] & COMPACT_PLAYER_ID_MASK;
    }

};

std::string describeCompactPacket(const CompactTeamPacket &packet)
{
    const uint8_t identity = packet.bytes[1];
    const int player_id = identity & COMPACT_PLAYER_ID_MASK;
    const int role = (identity & COMPACT_ROLE_MASK) >> COMPACT_ROLE_SHIFT;
    const bool ready = (identity & COMPACT_READY_MASK) != 0;
    const bool ball_known = packet.bytes[2] != COMPACT_UNKNOWN_BALL;
    const int ball_zone = ball_known ? static_cast<int>(packet.bytes[2]) : 0;
    const uint16_t robot_pose = CompactTeamPacket::decodeCompactRobotPose(packet.bytes.data());
    const int robot_x = robot_pose & COMPACT_POSE_COMPONENT_MASK;
    const int robot_y = (robot_pose >> COMPACT_ROBOT_Y_SHIFT) & COMPACT_POSE_COMPONENT_MASK;
    const int robot_theta = (robot_pose >> COMPACT_ROBOT_THETA_SHIFT) & COMPACT_POSE_COMPONENT_MASK;

    std::ostringstream stream;
    stream << "player_id=" << player_id
           << " role=" << role
           << " state=" << (ready ? "ready" : "fallen_or_not_ready")
           << " ball_known=" << ball_known
           << " ball_zone=" << ball_zone
           << " robot_grid_x=" << robot_x
           << " robot_grid_y=" << robot_y
           << " robot_theta=" << robot_theta;
    return stream.str();
}

std::string compactPacketToHex(const CompactTeamPacket &packet)
{
    std::ostringstream stream;
    stream << std::hex << std::uppercase << std::setfill('0');
    for (std::size_t i = 0; i < packet.bytes.size(); ++i) {
        if (i > 0) stream << ' ';
        stream << "0x" << std::setw(2) << static_cast<int>(packet.bytes[i]);
    }
    return stream.str();
}

double normalizeAngle(double theta)
{
    while (theta < -PI) theta += 2.0 * PI;
    while (theta >= PI) theta -= 2.0 * PI;
    return theta;
}

bool isUnicastIpv4(in_addr_t address)
{
    const uint32_t host_order = ntohl(address);
    const uint8_t first_octet = static_cast<uint8_t>((host_order >> 24) & 0xFF);
    const uint8_t last_octet = static_cast<uint8_t>(host_order & 0xFF);

    return address != INADDR_NONE
        && address != INADDR_ANY
        && address != INADDR_BROADCAST
        && first_octet > 0
        && first_octet < 224
        && last_octet != 0
        && last_octet != 255;
}

bool isBroadcastIpv4(in_addr_t address)
{
    const uint32_t host_order = ntohl(address);
    const uint8_t first_octet = static_cast<uint8_t>((host_order >> 24) & 0xFF);
    const uint8_t last_octet = static_cast<uint8_t>(host_order & 0xFF);

    return address == INADDR_BROADCAST
        || (first_octet > 0 && first_octet < 224 && last_octet == 255);
}

uint8_t compactRoleFromTeamCommunication(int32_t player_role)
{
    switch (player_role) {
        case 1: return ROLE_STRIKER;
        case 2: return ROLE_GOALIE;
        case 3: return ROLE_DEFENDER;
        default: return ROLE_UNKNOWN;
    }
}
}

class UdpBroadcastNetwork
{
public:
    UdpBroadcastNetwork(
        rclcpp::Logger logger,
        int team_port,
        const std::string &broadcast_address)
        : logger_(logger), team_port_(team_port), broadcast_address_(broadcast_address)
    {
    }

    ~UdpBroadcastNetwork()
    {
        closeSockets();
    }

    void open()
    {
        socket_ = socket(AF_INET, SOCK_DGRAM, 0);
        if (socket_ < 0) {
            throw std::runtime_error(std::string("failed to create team broadcast socket: ") + strerror(errno));
        }

        int broadcast = 1;
        if (setsockopt(socket_, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast)) < 0) {
            throw std::runtime_error(std::string("failed to set team SO_BROADCAST: ") + strerror(errno));
        }

        int reuse = 1;
        if (setsockopt(socket_, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
            throw std::runtime_error(std::string("failed to set team SO_REUSEADDR: ") + strerror(errno));
        }

        send_addr_.sin_family = AF_INET;
        send_addr_.sin_port = htons(team_port_);
        if (inet_pton(AF_INET, broadcast_address_.c_str(), &send_addr_.sin_addr) != 1
            || !isBroadcastIpv4(send_addr_.sin_addr.s_addr)) {
            throw std::runtime_error("invalid team broadcast address: " + broadcast_address_);
        }

        sockaddr_in local_addr{};
        local_addr.sin_family = AF_INET;
        local_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        local_addr.sin_port = htons(team_port_);

        if (bind(socket_, reinterpret_cast<sockaddr *>(&local_addr), sizeof(local_addr)) < 0) {
            throw std::runtime_error(std::string("failed to bind team broadcast socket: ") + strerror(errno));
        }

        const int flags = fcntl(socket_, F_GETFL, 0);
        if (flags >= 0) {
            fcntl(socket_, F_SETFL, flags | O_NONBLOCK);
        }
    }

    bool send(const CompactTeamPacket &packet)
    {
        const ssize_t ret = sendto(
            socket_,
            packet.bytes.data(),
            packet.bytes.size(),
            0,
            reinterpret_cast<const sockaddr *>(&send_addr_),
            sizeof(send_addr_));

        if (ret < 0) {
            RCLCPP_WARN(logger_, "Team broadcast send failed: %s", strerror(errno));
            return false;
        }

        return true;
    }

    std::optional<CompactTeamPacket> receive()
    {
        std::array<uint8_t, RECEIVE_BUFFER_SIZE> buffer{};
        sockaddr_in from_addr{};
        socklen_t from_addr_len = sizeof(from_addr);

        const ssize_t len = recvfrom(
            socket_,
            buffer.data(),
            buffer.size(),
            0,
            reinterpret_cast<sockaddr *>(&from_addr),
            &from_addr_len);

        if (len < 0) {
            if (errno != EAGAIN && errno != EWOULDBLOCK) {
                RCLCPP_WARN(logger_, "Team broadcast receive failed: %s", strerror(errno));
            }
            return std::nullopt;
        }

        CompactTeamPacket packet;
        if (static_cast<std::size_t>(len) <= packet.bytes.size()) {
            std::copy(buffer.begin(), buffer.begin() + len, packet.bytes.begin());
        }
        packet_len_ = static_cast<std::size_t>(len);
        return packet;
    }

    std::size_t lastPacketLength() const
    {
        return packet_len_;
    }

    void closeSockets()
    {
        if (socket_ >= 0) {
            close(socket_);
            socket_ = -1;
        }
    }

private:
    rclcpp::Logger logger_;
    int team_port_ = 0;
    std::string broadcast_address_;
    int socket_ = -1;
    sockaddr_in send_addr_{};
    std::size_t packet_len_ = 0;
};

class RobotCommunicationNode : public rclcpp::Node
{
public:
    RobotCommunicationNode() : Node("robot_communication_node")
    {
        enabled_ = declare_parameter<bool>("team_communication.enabled", true);
        team_id_ = declare_parameter<int>("team_id", 0);
        player_id_ = declare_parameter<int>("player_id", 0);
        broadcast_address_ = declare_parameter<std::string>("team_communication.broadcast_address", "255.255.255.255");
        max_hz_ = declare_parameter<double>("team_communication.max_hz", 5.0);
        max_packets_per_game_ = declare_parameter<int>("team_communication.max_packets_per_game", 12000);
        event_driven_ = declare_parameter<bool>("team_communication.event_driven", true);
        compact_secret_password_ = declare_parameter<int>("compact_secret_password", 0xA7);
        field_length_ = declare_parameter<double>("field_length", 14.0);
        field_width_ = declare_parameter<double>("field_width", 9.0);

        const bool debug_enabled = declare_parameter<bool>("debug_communication.enabled", false);
        const std::string debug_target_ip = declare_parameter<std::string>("debug_communication.target_ip", "192.168.0.100");
        const int debug_port = declare_parameter<int>("debug_communication.port", 11000);
        const double debug_max_hz = std::min(declare_parameter<double>("debug_communication.max_hz", 1.0), 1.0);

        compact_secret_password_ = std::clamp(compact_secret_password_, 0, 255);
        field_length_ = std::max(field_length_, 1e-3);
        field_width_ = std::max(field_width_, 1e-3);
        team_port_ = TEAM_PORT_BASE + team_id_;
        if (debug_enabled && debug_port == team_port_) {
            throw std::runtime_error("debug_communication.port must not equal the team broadcast port");
        }
        if (debug_enabled) {
            in_addr debug_addr{};
            if (inet_pton(AF_INET, debug_target_ip.c_str(), &debug_addr) != 1
                || !isUnicastIpv4(debug_addr.s_addr)) {
                throw std::runtime_error("invalid debug target IP: " + debug_target_ip);
            }
            RCLCPP_WARN(
                get_logger(),
                "debug_communication is configured for %s:%d at max %.2f Hz, but no debug payload publisher is implemented in robot_communication_node. Team packets are not sent on the debug channel.",
                debug_target_ip.c_str(),
                debug_port,
                debug_max_hz);
        }
        min_send_interval_ms_ = static_cast<int64_t>(std::ceil(1000.0 / std::max(max_hz_, 0.001)));

        pub_in_ = create_publisher<TeamCommunication>("/booster_soccer/team_comm/in", 10);
        sub_out_ = create_subscription<TeamCommunication>(
            "/booster_soccer/team_comm/out",
            10,
            std::bind(&RobotCommunicationNode::outgoingCallback, this, std::placeholders::_1));

        if (enabled_) {
            network_ = std::make_unique<UdpBroadcastNetwork>(get_logger(), team_port_, broadcast_address_);
            network_->open();

            receive_flag_.store(true);
            receive_thread_ = std::thread([this]() { receiveLoop(); });
            send_timer_ = create_wall_timer(
                std::chrono::milliseconds(20),
                std::bind(&RobotCommunicationNode::sendTimerCallback, this));

            RCLCPP_INFO(
                get_logger(),
                "HSL team broadcast enabled: team=%d player=%d port=%d max_hz=%.2f budget=%d broadcast=%s debug=%s",
                team_id_, player_id_, team_port_, max_hz_, max_packets_per_game_, broadcast_address_.c_str(),
                debug_enabled ? "enabled" : "disabled");
        } else {
            RCLCPP_INFO(get_logger(), "HSL team broadcast disabled");
        }
    }

    ~RobotCommunicationNode() override
    {
        receive_flag_.store(false);
        if (receive_thread_.joinable()) {
            receive_thread_.join();
        }
    }

private:
    void outgoingCallback(const TeamCommunication::SharedPtr msg)
    {
        if (!enabled_ || msg->team_id != team_id_ || msg->player_id != player_id_) return;

        const CompactTeamPacket packet = makeCompactPacket(*msg);
        if (!pending_packet_ || pending_packet_->bytes != packet.bytes) {
            pending_packet_ = packet;
            pending_packet_changed_ = true;
        }
    }

    void sendTimerCallback()
    {
        if (!enabled_ || !network_ || !pending_packet_) return;
        if (packets_sent_ >= max_packets_per_game_) return;

        const auto now = get_clock()->now();
        if (last_send_time_.nanoseconds() != 0
            && (now - last_send_time_).nanoseconds() < min_send_interval_ms_ * 1000000LL) {
            return;
        }

        if (event_driven_ && !pending_packet_changed_) return;

        const CompactTeamPacket tx_packet = *pending_packet_;
        if (network_->send(tx_packet)) {
            packets_sent_++;
            last_send_time_ = now;
            pending_packet_changed_ = false;
            RCLCPP_DEBUG(
                get_logger(),
                "TX team broadcast packet %d/%d: %s",
                packets_sent_,
                max_packets_per_game_,
                describeCompactPacket(tx_packet).c_str());
        }
    }

    CompactTeamPacket makeCompactPacket(const TeamCommunication &msg) const
    {
        CompactTeamPacket packet;
        packet.bytes[0] = static_cast<uint8_t>(compact_secret_password_);
        packet.bytes[1] = makeCompactIdentityByte(msg);
        packet.bytes[2] = makeCompactBallPosition(msg);
        const uint16_t robot_pose = makeCompactRobotPose(msg);
        packet.bytes[3] = static_cast<uint8_t>(robot_pose & 0xFF);
        packet.bytes[4] = static_cast<uint8_t>((robot_pose >> 8) & 0xFF);
        return packet;
    }

    uint8_t makeCompactIdentityByte(const TeamCommunication &msg) const
    {
        const uint8_t player_id = static_cast<uint8_t>(msg.player_id) & COMPACT_PLAYER_ID_MASK;
        const uint8_t role = compactRoleFromTeamCommunication(msg.player_role);
        const uint8_t state = msg.is_alive ? COMPACT_READY_MASK : 0;
        return player_id | static_cast<uint8_t>(role << COMPACT_ROLE_SHIFT) | state;
    }

    uint16_t makeCompactRobotPose(const TeamCommunication &msg) const
    {
        const uint8_t x = calcCoordinateGridIndex(msg.robot_pose_to_field_x, -field_length_ * 0.5, field_length_ * 0.5);
        const uint8_t y = calcCoordinateGridIndex(msg.robot_pose_to_field_y, -field_width_ * 0.5, field_width_ * 0.5);
        const uint8_t theta = calcThetaGridIndex(msg.robot_pose_to_field_theta);
        return static_cast<uint16_t>(
            x |
            (static_cast<uint16_t>(y) << COMPACT_ROBOT_Y_SHIFT) |
            (static_cast<uint16_t>(theta) << COMPACT_ROBOT_THETA_SHIFT));
    }

    uint8_t calcCoordinateGridIndex(double value, double min_value, double max_value) const
    {
        const double clamped = std::clamp(value, min_value, max_value);
        const double span = std::max(max_value - min_value, 1e-3);
        const int index = std::clamp(static_cast<int>(std::floor(((clamped - min_value) / span) * 32.0)), 0, 31);
        return static_cast<uint8_t>(index);
    }

    double gridIndexToCoordinateCenter(int index, double min_value, double max_value) const
    {
        const double span = std::max(max_value - min_value, 1e-3);
        return min_value + ((std::clamp(index, 0, 31) + 0.5) * (span / 32.0));
    }

    uint8_t calcThetaGridIndex(double theta) const
    {
        const double normalized = normalizeAngle(theta);
        const int index = std::clamp(static_cast<int>(std::floor(((normalized + PI) / (2.0 * PI)) * 32.0)), 0, 31);
        return static_cast<uint8_t>(index);
    }

    double thetaGridIndexToAngleCenter(int index) const
    {
        return -PI + ((std::clamp(index, 0, 31) + 0.5) * ((2.0 * PI) / 32.0));
    }

    uint8_t zoneForFieldPoint(double x, double y) const
    {
        const double half_length = field_length_ * 0.5;
        const double half_width = field_width_ * 0.5;

        if (x < -half_length || x > half_length || y < -half_width || y > half_width) {
            return 0;
        }

        int col = static_cast<int>((x + half_length) / (field_length_ / FIELD_ZONE_COLS));
        int row_from_bottom = static_cast<int>((y + half_width) / (field_width_ / FIELD_ZONE_ROWS));

        col = std::clamp(col, 0, FIELD_ZONE_COLS - 1);
        row_from_bottom = std::clamp(row_from_bottom, 0, FIELD_ZONE_ROWS - 1);

        const int row_from_top = FIELD_ZONE_ROWS - 1 - row_from_bottom;
        return static_cast<uint8_t>(col * FIELD_ZONE_ROWS + row_from_top + 1);
    }

    std::pair<double, double> zoneCenter(int zone) const
    {
        const int clamped_zone = std::clamp(zone, 1, FIELD_ZONE_ROWS * FIELD_ZONE_COLS);
        const int zero_based = clamped_zone - 1;
        const int col = zero_based / FIELD_ZONE_ROWS;
        const int row_from_top = zero_based % FIELD_ZONE_ROWS;
        const double half_length = field_length_ * 0.5;
        const double half_width = field_width_ * 0.5;

        return {
            -half_length + field_length_ * (col + 0.5) / FIELD_ZONE_COLS,
            half_width - field_width_ * (row_from_top + 0.5) / FIELD_ZONE_ROWS
        };
    }

    std::string describeCompactPacketInFieldUnits(const CompactTeamPacket &packet) const
    {
        const bool ball_known = packet.bytes[2] != COMPACT_UNKNOWN_BALL;
        const int ball_zone = ball_known ? static_cast<int>(packet.bytes[2]) : 0;
        const uint16_t robot_pose = CompactTeamPacket::decodeCompactRobotPose(packet.bytes.data());
        const int robot_x = robot_pose & COMPACT_POSE_COMPONENT_MASK;
        const int robot_y = (robot_pose >> COMPACT_ROBOT_Y_SHIFT) & COMPACT_POSE_COMPONENT_MASK;
        const int robot_theta = (robot_pose >> COMPACT_ROBOT_THETA_SHIFT) & COMPACT_POSE_COMPONENT_MASK;

        std::ostringstream stream;
        stream << std::fixed << std::setprecision(2);
        stream << "robot_x_m=" << gridIndexToCoordinateCenter(robot_x, -field_length_ * 0.5, field_length_ * 0.5)
               << " robot_y_m=" << gridIndexToCoordinateCenter(robot_y, -field_width_ * 0.5, field_width_ * 0.5)
               << " robot_theta_rad=" << thetaGridIndexToAngleCenter(robot_theta);

        if (ball_known) {
            const auto [ball_x, ball_y] = zoneCenter(ball_zone);
            stream << " ball_zone=" << ball_zone
                   << " ball_x_m=" << ball_x
                   << " ball_y_m=" << ball_y;
        } else {
            stream << " ball_position=unknown";
        }

        return stream.str();
    }

    uint8_t makeCompactBallPosition(const TeamCommunication &msg) const
    {
        if (!msg.ball_location_known) return COMPACT_UNKNOWN_BALL;

        const uint8_t zone = zoneForFieldPoint(msg.ball_pos_to_field_x, msg.ball_pos_to_field_y);
        return zone == 0 ? COMPACT_UNKNOWN_BALL : zone;
    }

    TeamCommunication makeMinimalMessageFromCompactPacket(const CompactTeamPacket &packet) const
    {
        TeamCommunication msg;
        const bool ball_known = packet.bytes[2] != COMPACT_UNKNOWN_BALL;
        const int ball_zone = ball_known ? static_cast<int>(packet.bytes[2]) : 0;
        const uint8_t identity = packet.bytes[1];
        const uint16_t robot_pose = CompactTeamPacket::decodeCompactRobotPose(packet.bytes.data());
        const int robot_x = robot_pose & COMPACT_POSE_COMPONENT_MASK;
        const int robot_y = (robot_pose >> COMPACT_ROBOT_Y_SHIFT) & COMPACT_POSE_COMPONENT_MASK;
        const int robot_theta = (robot_pose >> COMPACT_ROBOT_THETA_SHIFT) & COMPACT_POSE_COMPONENT_MASK;

        msg.validation = VALIDATION_COMMUNICATION;
        msg.communication_id = 0;
        msg.team_id = team_id_;
        msg.player_id = identity & COMPACT_PLAYER_ID_MASK;
        msg.player_role = (identity & COMPACT_ROLE_MASK) >> COMPACT_ROLE_SHIFT;
        msg.is_alive = (identity & COMPACT_READY_MASK) != 0;
        msg.robot_pose_to_field_x = gridIndexToCoordinateCenter(robot_x, -field_length_ * 0.5, field_length_ * 0.5);
        msg.robot_pose_to_field_y = gridIndexToCoordinateCenter(robot_y, -field_width_ * 0.5, field_width_ * 0.5);
        msg.robot_pose_to_field_theta = thetaGridIndexToAngleCenter(robot_theta);
        msg.ball_location_known = ball_known;
        msg.ball_detected = msg.ball_location_known;

        if (msg.ball_location_known) {
            const auto [ball_x, ball_y] = zoneCenter(ball_zone);
            msg.ball_pos_to_field_x = ball_x;
            msg.ball_pos_to_field_y = ball_y;
            msg.ball_pos_to_field_z = 0.0;
        }

        return msg;
    }

    void receiveLoop()
    {
        while (receive_flag_.load(std::memory_order_relaxed)) {
            auto packet = network_->receive();
            if (!packet) {
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                continue;
            }

            if (!CompactTeamPacket::validate(packet->bytes.data(), network_->lastPacketLength(), static_cast<uint8_t>(compact_secret_password_))) {
                RCLCPP_WARN(get_logger(), "Dropped invalid team packet with size %zu", network_->lastPacketLength());
                continue;
            }

            const int compact_player_id = packet->playerId();
            if (player_id_ > 0 && compact_player_id == (player_id_ & COMPACT_PLAYER_ID_MASK)) {
                continue;
            }

            const auto last_packet_it = last_packet_by_player_.find(compact_player_id);
            if (last_packet_it != last_packet_by_player_.end()
                && last_packet_it->second == packet->bytes) {
                continue;
            }
            last_packet_by_player_[compact_player_id] = packet->bytes;

            RCLCPP_INFO(get_logger(), "Received team broadcast raw: [%s]", compactPacketToHex(*packet).c_str());
            RCLCPP_INFO(get_logger(), "Received team broadcast decoded: [%s]", describeCompactPacket(*packet).c_str());
            RCLCPP_INFO(get_logger(), "Received team broadcast field: [%s]", describeCompactPacketInFieldUnits(*packet).c_str());
            pub_in_->publish(makeMinimalMessageFromCompactPacket(*packet));
        }
    }

    bool enabled_ = true;
    int team_id_ = 0;
    int player_id_ = 0;
    int team_port_ = 0;
    std::string broadcast_address_;
    double max_hz_ = 5.0;
    int max_packets_per_game_ = 12000;
    bool event_driven_ = true;
    int64_t min_send_interval_ms_ = 200;
    int compact_secret_password_ = 0xA7;
    double field_length_ = 14.0;
    double field_width_ = 9.0;

    std::unique_ptr<UdpBroadcastNetwork> network_;
    std::optional<CompactTeamPacket> pending_packet_;
    bool pending_packet_changed_ = false;
    int packets_sent_ = 0;
    rclcpp::Time last_send_time_{0, 0, RCL_ROS_TIME};
    std::map<int, std::array<uint8_t, COMPACT_PACKET_SIZE>> last_packet_by_player_;

    std::atomic<bool> receive_flag_{false};
    std::thread receive_thread_;
    rclcpp::TimerBase::SharedPtr send_timer_;
    rclcpp::Publisher<TeamCommunication>::SharedPtr pub_in_;
    rclcpp::Subscription<TeamCommunication>::SharedPtr sub_out_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<RobotCommunicationNode>());
    rclcpp::shutdown();
    return 0;
}
