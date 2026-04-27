#include <atomic>
#include <cerrno>
#include <chrono>
#include <cstring>
#include <functional>
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

namespace
{
constexpr int VALIDATION_COMMUNICATION = 31202;

struct UdpTeamCommunicationPacket
{
    int32_t validation;
    int32_t communication_id;
    int32_t team_id;
    int32_t player_id;
    int32_t player_role;
    bool is_alive;
    bool is_lead;
    bool ball_detected;
    bool ball_location_known;
    double ball_confidence;
    double ball_range;
    double cost;
    double ball_pos_to_field_x;
    double ball_pos_to_field_y;
    double ball_pos_to_field_z;
    double robot_pose_to_field_x;
    double robot_pose_to_field_y;
    double robot_pose_to_field_theta;
    double kick_dir;
    double theta_rb;
    int32_t cmd_id;
    int32_t cmd;
};

UdpTeamCommunicationPacket toPacket(const TeamCommunication &msg)
{
    UdpTeamCommunicationPacket packet{};
    packet.validation = msg.validation;
    packet.communication_id = msg.communication_id;
    packet.team_id = msg.team_id;
    packet.player_id = msg.player_id;
    packet.player_role = msg.player_role;
    packet.is_alive = msg.is_alive;
    packet.is_lead = msg.is_lead;
    packet.ball_detected = msg.ball_detected;
    packet.ball_location_known = msg.ball_location_known;
    packet.ball_confidence = msg.ball_confidence;
    packet.ball_range = msg.ball_range;
    packet.cost = msg.cost;
    packet.ball_pos_to_field_x = msg.ball_pos_to_field_x;
    packet.ball_pos_to_field_y = msg.ball_pos_to_field_y;
    packet.ball_pos_to_field_z = msg.ball_pos_to_field_z;
    packet.robot_pose_to_field_x = msg.robot_pose_to_field_x;
    packet.robot_pose_to_field_y = msg.robot_pose_to_field_y;
    packet.robot_pose_to_field_theta = msg.robot_pose_to_field_theta;
    packet.kick_dir = msg.kick_dir;
    packet.theta_rb = msg.theta_rb;
    packet.cmd_id = msg.cmd_id;
    packet.cmd = msg.cmd;
    return packet;
}

TeamCommunication toMsg(const UdpTeamCommunicationPacket &packet)
{
    TeamCommunication msg;
    msg.validation = packet.validation;
    msg.communication_id = packet.communication_id;
    msg.team_id = packet.team_id;
    msg.player_id = packet.player_id;
    msg.player_role = packet.player_role;
    msg.is_alive = packet.is_alive;
    msg.is_lead = packet.is_lead;
    msg.ball_detected = packet.ball_detected;
    msg.ball_location_known = packet.ball_location_known;
    msg.ball_confidence = packet.ball_confidence;
    msg.ball_range = packet.ball_range;
    msg.cost = packet.cost;
    msg.ball_pos_to_field_x = packet.ball_pos_to_field_x;
    msg.ball_pos_to_field_y = packet.ball_pos_to_field_y;
    msg.ball_pos_to_field_z = packet.ball_pos_to_field_z;
    msg.robot_pose_to_field_x = packet.robot_pose_to_field_x;
    msg.robot_pose_to_field_y = packet.robot_pose_to_field_y;
    msg.robot_pose_to_field_theta = packet.robot_pose_to_field_theta;
    msg.kick_dir = packet.kick_dir;
    msg.theta_rb = packet.theta_rb;
    msg.cmd_id = packet.cmd_id;
    msg.cmd = packet.cmd;
    return msg;
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

        UdpTeamCommunicationPacket packet = toPacket(*msg);
        if (packet.validation == 0) {
            packet.validation = VALIDATION_COMMUNICATION;
        }

        ssize_t ret = sendto(
            send_socket_,
            &packet,
            sizeof(packet),
            0,
            reinterpret_cast<sockaddr *>(&send_addr_),
            sizeof(send_addr_));

        if (ret < 0) {
            RCLCPP_WARN(get_logger(), "Robot UDP relay send failed: %s", strerror(errno));
        }

        // Some networks do not loop broadcast packets back to the sender.
        // Send a local UDP copy so the receive path can be verified on this robot.
        if (publish_own_packets_ && enable_local_loopback_echo_) {
            sockaddr_in loopback_addr{};
            loopback_addr.sin_family = AF_INET;
            loopback_addr.sin_port = htons(robot_comm_port_);
            loopback_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
            ssize_t loopback_ret = sendto(
                send_socket_,
                &packet,
                sizeof(packet),
                0,
                reinterpret_cast<sockaddr *>(&loopback_addr),
                sizeof(loopback_addr));

            if (loopback_ret < 0) {
                RCLCPP_WARN(get_logger(), "Robot UDP relay loopback send failed: %s", strerror(errno));
            }
        }
    }

    void receiveLoop()
    {
        sockaddr_in from_addr{};
        socklen_t from_addr_len = sizeof(from_addr);
        UdpTeamCommunicationPacket packet{};

        while (receive_flag_.load(std::memory_order_relaxed)) {
            ssize_t len = recvfrom(
                receive_socket_,
                &packet,
                sizeof(packet),
                0,
                reinterpret_cast<sockaddr *>(&from_addr),
                &from_addr_len);

            if (len < 0) {
                if (receive_flag_.load(std::memory_order_relaxed)) {
                    RCLCPP_WARN(get_logger(), "Robot UDP relay receive failed: %s", strerror(errno));
                }
                continue;
            }

            if (len != static_cast<ssize_t>(sizeof(UdpTeamCommunicationPacket))) {
                RCLCPP_WARN(get_logger(), "Robot UDP relay ignored packet with size %ld, expected %ld",
                            len, sizeof(UdpTeamCommunicationPacket));
                continue;
            }

            if (packet.validation != VALIDATION_COMMUNICATION) {
                RCLCPP_WARN(get_logger(), "Robot UDP relay ignored invalid validation: %d", packet.validation);
                continue;
            }

            if (team_id_ > 0 && packet.team_id != team_id_) {
                continue;
            }

            if (player_id_ > 0 && packet.player_id == player_id_ && !publish_own_packets_) {
                continue;
            }

            TeamCommunication msg = toMsg(packet);
            pub_in_->publish(msg);
            RCLCPP_INFO(get_logger(),
                        "Robot UDP relay received team communication: team=%d player=%d commId=%d cmdId=%d cmd=%d ballKnown=%d ballDetected=%d",
                        msg.team_id, msg.player_id, msg.communication_id, msg.cmd_id, msg.cmd,
                        msg.ball_location_known, msg.ball_detected);
        }
    }

    bool enable_relay_ = true;
    int team_id_ = 0;
    int player_id_ = 0;
    int robot_comm_port_ = 0;
    std::string relay_broadcast_address_;
    bool publish_own_packets_ = true;
    bool enable_local_loopback_echo_ = true;

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
