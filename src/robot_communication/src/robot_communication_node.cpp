#include <atomic>
#include <algorithm>
#include <array>
#include <cerrno>
#include <cmath>
#include <cstdint>
#include <functional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <thread>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <rclcpp/rclcpp.hpp>
#include <game_controller_interface/msg/team_communication.hpp>

using TeamCommunication = game_controller_interface::msg::TeamCommunication;

// Right now, our secret key is:
// 167 decimal
// 0xA7 hex
// 10100111 binary
// [ password ][ id/role/state ][ ball zone ][ pose byte 0 ][ pose byte 1 ]

namespace
{
constexpr int VALIDATION_COMMUNICATION = 31202;
constexpr std::size_t COMPACT_PACKET_SIZE = 5;
constexpr std::size_t RECEIVE_BUFFER_SIZE = 2048;
constexpr double PI = 3.14159265358979323846;
constexpr uint8_t COMPACT_PLAYER_ID_MASK = 0x0F;
constexpr uint8_t COMPACT_ROLE_MASK = 0x30;
constexpr uint8_t COMPACT_READY_MASK = 0x40;
constexpr int COMPACT_ROLE_SHIFT = 4;
constexpr uint16_t COMPACT_POSE_COMPONENT_MASK = 0x1F;
constexpr int COMPACT_ROBOT_Y_SHIFT = 5;
constexpr int COMPACT_ROBOT_THETA_SHIFT = 10;
constexpr uint8_t COMPACT_THETA_MASK = 0x1F;

// Byte 1 layout: bits 0-3 player id, bits 4-5 role, bit 6 ready/alive, bit 7 reserved.
// Bytes 3-4 layout: bits 0-4 robot x index, bits 5-9 robot y index, bits 10-14 robot theta index, bit 15 reserved.
enum CompactRole : uint8_t
{
    ROLE_UNKNOWN = 0,
    ROLE_STRIKER = 1,
    ROLE_GOALIE = 2,
    ROLE_DEFENDER = 3,
};

std::string bytesToBinaryString(const void *data, std::size_t size)
{
    const auto *bytes = static_cast<const uint8_t *>(data);
    std::ostringstream stream;

    for (std::size_t i = 0; i < size; ++i) {
        if (i > 0) {
            stream << ' ';
        }

        for (int bit = 7; bit >= 0; --bit) {
            stream << ((bytes[i] >> bit) & 0x01);
        }
    }

    return stream.str();
}

uint16_t decodeCompactRobotPose(const uint8_t *packet)
{
    return static_cast<uint16_t>(packet[3]) | (static_cast<uint16_t>(packet[4]) << 8);
}

std::string describeCompactPacket(const uint8_t *packet)
{
    const uint8_t identity = packet[1];
    const int player_id = identity & COMPACT_PLAYER_ID_MASK;
    const int role = (identity & COMPACT_ROLE_MASK) >> COMPACT_ROLE_SHIFT;
    const bool ready = (identity & COMPACT_READY_MASK) != 0;
    const uint16_t robot_pose = decodeCompactRobotPose(packet);
    const int robot_x = robot_pose & COMPACT_POSE_COMPONENT_MASK;
    const int robot_y = (robot_pose >> COMPACT_ROBOT_Y_SHIFT) & COMPACT_POSE_COMPONENT_MASK;
    const int robot_theta = (robot_pose >> COMPACT_ROBOT_THETA_SHIFT) & COMPACT_POSE_COMPONENT_MASK;
    std::ostringstream stream;
    stream << "player_id=" << player_id
           << " role=" << role
           << " state=" << (ready ? "ready" : "fallen_or_not_ready")
           << " ball_zone=" << static_cast<int>(packet[2])
           << " robot_grid_x=" << robot_x
           << " robot_grid_y=" << robot_y
           << " robot_theta=" << robot_theta;
    return stream.str();
}
}

class RobotCommunicationNode : public rclcpp::Node
{
public:
    RobotCommunicationNode() : Node("robot_communication_node")
    {
        enable_relay_ = declare_parameter<bool>("enable_robot_comm_relay", true);
        team_id_ = declare_parameter<int>("team_id", 0);
        player_id_ = declare_parameter<int>("player_id", 0);
        robot_comm_port_ = declare_parameter<int>("robot_comm_port", 0);
        relay_broadcast_address_ = declare_parameter<std::string>("relay_broadcast_address", "255.255.255.255");
        publish_own_packets_ = declare_parameter<bool>("publish_own_packets", true);
        enable_local_loopback_echo_ = declare_parameter<bool>("enable_local_loopback_echo", true);
        declare_parameter<bool>("enable_compact_team_packet", true);
        compact_secret_password_ = declare_parameter<int>("compact_secret_password", 0xA7);
        declare_parameter<int>("compact_packet_size", static_cast<int>(COMPACT_PACKET_SIZE));
        field_length_ = declare_parameter<double>("field_length", 14.0);
        field_width_ = declare_parameter<double>("field_width", 9.0);

        compact_secret_password_ = std::clamp(compact_secret_password_, 0, 255);
        field_length_ = std::max(field_length_, 1e-3);
        field_width_ = std::max(field_width_, 1e-3);

        if (robot_comm_port_ <= 0) {
            robot_comm_port_ = 31000 + team_id_;
        }

        pub_in_ = create_publisher<TeamCommunication>("/booster_soccer/team_comm/in", 10);
        sub_out_ = create_subscription<TeamCommunication>(
            "/booster_soccer/team_comm/out",
            10,
            std::bind(&RobotCommunicationNode::outgoingCallback, this, std::placeholders::_1));

        if (enable_relay_) {
            initSockets();
            receive_flag_.store(true);
            receive_thread_ = std::thread([this]() { receiveLoop(); });
            RCLCPP_INFO(get_logger(), "Robot UDP relay enabled on port %d for team=%d player=%d",
                        robot_comm_port_, team_id_, player_id_);
            RCLCPP_INFO(get_logger(),
                        "Compact-only team packet enabled: size=%zu password=0x%02X field=%.2fx%.2f",
                        COMPACT_PACKET_SIZE, compact_secret_password_, field_length_, field_width_);
        } else {
            RCLCPP_INFO(get_logger(), "Robot UDP relay disabled");
        }
    }

    ~RobotCommunicationNode() override
    {
        receive_flag_.store(false);
        unblockReceiver();
        if (send_socket_ >= 0) {
            close(send_socket_);
            send_socket_ = -1;
        }
        if (receive_socket_ >= 0) {
            close(receive_socket_);
            receive_socket_ = -1;
        }
        if (receive_thread_.joinable()) {
            receive_thread_.join();
        }
    }

private:
    void initSockets()
    {
        send_socket_ = socket(AF_INET, SOCK_DGRAM, 0);
        if (send_socket_ < 0) {
            throw std::runtime_error(std::string("failed to create relay send socket: ") + strerror(errno));
        }

        int broadcast = 1;
        if (setsockopt(send_socket_, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast)) < 0) {
            throw std::runtime_error(std::string("failed to set relay SO_BROADCAST: ") + strerror(errno));
        }

        send_addr_.sin_family = AF_INET;
        send_addr_.sin_port = htons(robot_comm_port_);
        send_addr_.sin_addr.s_addr = inet_addr(relay_broadcast_address_.c_str());

        receive_socket_ = socket(AF_INET, SOCK_DGRAM, 0);
        if (receive_socket_ < 0) {
            throw std::runtime_error(std::string("failed to create relay receive socket: ") + strerror(errno));
        }

        int reuse = 1;
        if (setsockopt(receive_socket_, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
            throw std::runtime_error(std::string("failed to set relay SO_REUSEADDR: ") + strerror(errno));
        }

        sockaddr_in local_addr{};
        local_addr.sin_family = AF_INET;
        local_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        local_addr.sin_port = htons(robot_comm_port_);

        if (bind(receive_socket_, reinterpret_cast<sockaddr *>(&local_addr), sizeof(local_addr)) < 0) {
            throw std::runtime_error(std::string("failed to bind relay receive socket: ") + strerror(errno));
        }
    }

    void unblockReceiver()
    {
        if (send_socket_ < 0 || robot_comm_port_ <= 0) {
            return;
        }

        sockaddr_in local_addr{};
        local_addr.sin_family = AF_INET;
        local_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
        local_addr.sin_port = htons(robot_comm_port_);
        sendto(send_socket_, nullptr, 0, 0, reinterpret_cast<sockaddr *>(&local_addr), sizeof(local_addr));
    }

    void outgoingCallback(const TeamCommunication::SharedPtr msg)
    {
        if (!enable_relay_ || send_socket_ < 0) {
            return;
        }

        if (team_id_ > 0 && msg->team_id != team_id_) {
            return;
        }

        if (player_id_ > 0 && msg->player_id != player_id_) {
            return;
        }

        auto compact_packet = makeCompactPacket(*msg);
        sendCompactPacket(compact_packet, send_addr_, "TX compact broadcast");

        // Some networks do not loop broadcast packets back to the sender.
        // Send a local UDP copy so the receive path can be verified on this robot.
        if (publish_own_packets_ && enable_local_loopback_echo_) {
            sockaddr_in loopback_addr{};
            loopback_addr.sin_family = AF_INET;
            loopback_addr.sin_port = htons(robot_comm_port_);
            loopback_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
            sendCompactPacket(compact_packet, loopback_addr, "TX compact loopback");
        }
    }

    void sendCompactPacket(
        const std::array<uint8_t, COMPACT_PACKET_SIZE> &packet,
        const sockaddr_in &addr,
        const char *label)
    {
        ssize_t ret = sendto(
            send_socket_,
            packet.data(),
            packet.size(),
            0,
            reinterpret_cast<const sockaddr *>(&addr),
            sizeof(addr));

        if (ret < 0) {
            RCLCPP_WARN(get_logger(), "Robot UDP relay %s send failed: %s", label, strerror(errno));
        } else {
            logCompactPacket(label, packet.data());
        }
    }

    void logCompactPacket(const char *label, const uint8_t *packet) const
    {
        RCLCPP_INFO(get_logger(), "Robot UDP relay %s binary: %s",
                    label, bytesToBinaryString(packet, COMPACT_PACKET_SIZE).c_str());
        RCLCPP_INFO(get_logger(), "Robot UDP relay %s interpreted: %s",
                    label, describeCompactPacket(packet).c_str());
    }

    std::array<uint8_t, COMPACT_PACKET_SIZE> makeCompactPacket(const TeamCommunication &msg) const
    {
        std::array<uint8_t, COMPACT_PACKET_SIZE> packet{};
        packet[0] = static_cast<uint8_t>(compact_secret_password_);
        packet[1] = makeCompactIdentityByte(msg);
        packet[2] = calcBallZone(msg);
        const uint16_t robot_pose = makeCompactRobotPose(msg);
        packet[3] = static_cast<uint8_t>(robot_pose & 0xFF);
        packet[4] = static_cast<uint8_t>((robot_pose >> 8) & 0xFF);
        return packet;
    }

    uint8_t makeCompactIdentityByte(const TeamCommunication &msg) const
    {
        const uint8_t player_id = static_cast<uint8_t>(msg.player_id) & COMPACT_PLAYER_ID_MASK;
        const uint8_t role = compactRoleFromTeamCommunication(msg.player_role);
        const uint8_t state = msg.is_alive ? COMPACT_READY_MASK : 0;
        return player_id | static_cast<uint8_t>(role << COMPACT_ROLE_SHIFT) | state;
    }

    uint8_t compactRoleFromTeamCommunication(int32_t player_role) const
    {
        switch (player_role) {
            case 1:
                return ROLE_STRIKER;
            case 2:
                return ROLE_GOALIE;
            case 3:
                return ROLE_DEFENDER;
            default:
                return ROLE_UNKNOWN;
        }
    }

    uint16_t makeCompactRobotPose(const TeamCommunication &msg) const
    {
        const uint8_t x = calcCoordinateGridIndex(
            msg.robot_pose_to_field_x,
            -field_length_ * 0.5,
            field_length_ * 0.5);
        const uint8_t y = calcCoordinateGridIndex(
            msg.robot_pose_to_field_y,
            -field_width_ * 0.5,
            field_width_ * 0.5);
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

    double normalizeAngle(double theta) const
    {
        while (theta < -PI) {
            theta += 2.0 * PI;
        }
        while (theta >= PI) {
            theta -= 2.0 * PI;
        }
        return theta;
    }

    uint8_t calcBallZone(const TeamCommunication &msg) const
    {
        if (!msg.ball_location_known) {
            return 0;
        }

        const double half_length = field_length_ * 0.5;
        const double half_width = field_width_ * 0.5;
        const double x = std::clamp(msg.ball_pos_to_field_x, -half_length, half_length);
        const double y = std::clamp(msg.ball_pos_to_field_y, -half_width, half_width);

        // Rows are numbered from opponent side to own side.
        const int row = std::clamp(static_cast<int>(std::floor((half_length - x) / (field_length_ / 3.0))), 0, 2);
        // Columns are numbered left to right when facing the opponent goal.
        const int col = std::clamp(static_cast<int>(std::floor((half_width - y) / (field_width_ / 3.0))), 0, 2);
        return static_cast<uint8_t>(row * 3 + col + 1);
    }

    TeamCommunication makeMinimalMessageFromCompactPacket(const uint8_t *packet) const
    {
        TeamCommunication msg;
        const int ball_zone = packet[2];
        const uint8_t identity = packet[1];
        const uint16_t robot_pose = decodeCompactRobotPose(packet);
        const int robot_x = robot_pose & COMPACT_POSE_COMPONENT_MASK;
        const int robot_y = (robot_pose >> COMPACT_ROBOT_Y_SHIFT) & COMPACT_POSE_COMPONENT_MASK;
        const int robot_theta = (robot_pose >> COMPACT_ROBOT_THETA_SHIFT) & COMPACT_POSE_COMPONENT_MASK;
        msg.validation = VALIDATION_COMMUNICATION;
        msg.team_id = team_id_;
        msg.player_id = identity & COMPACT_PLAYER_ID_MASK;
        msg.player_role = (identity & COMPACT_ROLE_MASK) >> COMPACT_ROLE_SHIFT;
        msg.is_alive = (identity & COMPACT_READY_MASK) != 0;
        msg.robot_pose_to_field_x = gridIndexToCoordinateCenter(robot_x, -field_length_ * 0.5, field_length_ * 0.5);
        msg.robot_pose_to_field_y = gridIndexToCoordinateCenter(robot_y, -field_width_ * 0.5, field_width_ * 0.5);
        msg.robot_pose_to_field_theta = thetaGridIndexToAngleCenter(robot_theta);
        msg.ball_location_known = ball_zone >= 1 && ball_zone <= 9;
        msg.ball_detected = msg.ball_location_known;

        if (msg.ball_location_known) {
            const int row = (ball_zone - 1) / 3;
            const int col = (ball_zone - 1) % 3;
            msg.ball_pos_to_field_x = (field_length_ * 0.5) - ((row + 0.5) * (field_length_ / 3.0));
            msg.ball_pos_to_field_y = (field_width_ * 0.5) - ((col + 0.5) * (field_width_ / 3.0));
            msg.ball_pos_to_field_z = 0.0;
        }

        return msg;
    }

    void handleCompactPacket(const uint8_t *packet, ssize_t len)
    {
        if (len != static_cast<ssize_t>(COMPACT_PACKET_SIZE)) {
            RCLCPP_WARN(get_logger(), "Robot UDP relay ignored non-compact packet with size %ld, expected %zu",
                        len, COMPACT_PACKET_SIZE);
            return;
        }

        if (packet[0] != static_cast<uint8_t>(compact_secret_password_)) {
            logCompactPacket("RX compact rejected", packet);
            RCLCPP_WARN(get_logger(), "Compact team packet ignored wrong password: 0x%02X", packet[0]);
            return;
        }

        const int compact_player_id = packet[1] & COMPACT_PLAYER_ID_MASK;
        const int ball_zone = packet[2];

        if (player_id_ > 0 && compact_player_id == (player_id_ & COMPACT_PLAYER_ID_MASK) && !publish_own_packets_) {
            return;
        }

        logCompactPacket("RX compact", packet);
        RCLCPP_INFO(get_logger(), "Compact team packet received: player=%d zone=%d", compact_player_id, ball_zone);
        pub_in_->publish(makeMinimalMessageFromCompactPacket(packet));
    }

    void receiveLoop()
    {
        sockaddr_in from_addr{};
        socklen_t from_addr_len = sizeof(from_addr);
        std::array<uint8_t, RECEIVE_BUFFER_SIZE> buffer{};

        while (receive_flag_.load(std::memory_order_relaxed)) {
            ssize_t len = recvfrom(
                receive_socket_,
                buffer.data(),
                buffer.size(),
                0,
                reinterpret_cast<sockaddr *>(&from_addr),
                &from_addr_len);

            if (len < 0) {
                if (receive_flag_.load(std::memory_order_relaxed)) {
                    RCLCPP_WARN(get_logger(), "Robot UDP relay receive failed: %s", strerror(errno));
                }
                continue;
            }

            handleCompactPacket(buffer.data(), len);
        }
    }

    bool enable_relay_ = true;
    int team_id_ = 0;
    int player_id_ = 0;
    int robot_comm_port_ = 0;
    std::string relay_broadcast_address_;
    bool publish_own_packets_ = true;
    bool enable_local_loopback_echo_ = true;
    int compact_secret_password_ = 0xA7;
    double field_length_ = 14.0;
    double field_width_ = 9.0;

    int send_socket_ = -1;
    int receive_socket_ = -1;
    sockaddr_in send_addr_{};

    std::atomic<bool> receive_flag_{false};
    std::thread receive_thread_;

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
