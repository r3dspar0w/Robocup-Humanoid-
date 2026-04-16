#pragma once

#include <atomic>
#include <cstdint>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>

#include <game_controller_interface/msg/game_control_data.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <geometry_msgs/msg/pose2_d.hpp>
#include <rclcpp/rclcpp.hpp>

#include "communication/msg/teammate_ball_array.hpp"

class TeamCommunicationNode : public rclcpp::Node
{
public:
    TeamCommunicationNode();
    ~TeamCommunicationNode() override;

private:
#pragma pack(push, 1)
    struct TeamBallPacket
    {
        char magic[4];
        uint8_t version;
        uint8_t team_id;
        uint8_t player_id;
        uint8_t flags;
        uint32_t sequence;
        float robot_x;
        float robot_y;
        float robot_theta;
        float ball_x;
        float ball_y;
        float ball_age_sec;
        uint64_t sent_time_ms;
    };
#pragma pack(pop)

    struct LocalState
    {
        bool have_robot_pose = false;
        bool have_ball = false;
        geometry_msgs::msg::Pose2D robot_pose;
        geometry_msgs::msg::Point ball_position;
        rclcpp::Time robot_pose_stamp;
        rclcpp::Time ball_stamp;
    };

    struct TeammateState
    {
        uint8_t player_id = 0;
        bool ball_valid = false;
        float robot_x = 0.0f;
        float robot_y = 0.0f;
        float robot_theta = 0.0f;
        float ball_x = 0.0f;
        float ball_y = 0.0f;
        float ball_age_sec = -1.0f;
        uint32_t sequence = 0;
        uint64_t sent_time_ms = 0;
        rclcpp::Time last_rx_time;
    };

    void setupSockets();
    void teardownSockets();
    void receiveLoop();
    void sendPacket();
    void publishTeammates();
    bool isInCountedState() const;
    uint64_t nowMilliseconds() const;

    void robotPoseCallback(const geometry_msgs::msg::Pose2D::SharedPtr msg);
    void ballPositionCallback(const geometry_msgs::msg::Point::SharedPtr msg);
    void gameControlCallback(const game_controller_interface::msg::GameControlData::SharedPtr msg);

    int team_id_ = 1;
    int player_id_ = 1;
    int udp_port_base_ = 10000;
    int udp_port_ = 10001;
    int max_packet_size_ = 512;
    std::string bind_address_ = "0.0.0.0";
    std::string broadcast_address_ = "255.255.255.255";
    double send_hz_ = 1.0;
    double publish_hz_ = 5.0;
    double ball_timeout_sec_ = 1.0;
    double teammate_timeout_sec_ = 3.0;
    bool send_only_in_counted_states_ = false;

    rclcpp::Subscription<geometry_msgs::msg::Pose2D>::SharedPtr robot_pose_sub_;
    rclcpp::Subscription<geometry_msgs::msg::Point>::SharedPtr ball_position_sub_;
    rclcpp::Subscription<game_controller_interface::msg::GameControlData>::SharedPtr game_control_sub_;
    rclcpp::Publisher<communication::msg::TeammateBallArray>::SharedPtr teammates_pub_;
    rclcpp::TimerBase::SharedPtr send_timer_;
    rclcpp::TimerBase::SharedPtr publish_timer_;

    std::atomic<uint8_t> game_state_{0};
    std::atomic<uint8_t> game_secondary_state_{0};

    std::mutex local_state_mutex_;
    LocalState local_state_;

    std::mutex teammates_mutex_;
    std::unordered_map<uint8_t, TeammateState> teammates_;

    std::atomic<bool> receive_running_{false};
    std::thread receive_thread_;

    int send_socket_ = -1;
    int recv_socket_ = -1;
    uint32_t sequence_ = 0;
};
