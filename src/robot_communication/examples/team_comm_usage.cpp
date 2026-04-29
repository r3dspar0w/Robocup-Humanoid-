// Example only. This file documents how the HSL-compliant communication relay is used.
//
// The robot brain publishes local team state to /booster_soccer/team_comm/out.
// robot_communication_node serializes that ROS message into the compact 5-byte binary
// packet and sends it via UDP broadcast on 10000 + team_id.
//
// Parsed teammate packets received from that same broadcast port are published back on
// /booster_soccer/team_comm/in. Strategy code should treat these as lossy, latest-value
// updates and must not depend on every packet arriving.

#include <chrono>
#include <memory>

#include <rclcpp/rclcpp.hpp>
#include <game_controller_interface/msg/team_communication.hpp>

using TeamCommunication = game_controller_interface::msg::TeamCommunication;

class TeamCommUsageExample : public rclcpp::Node
{
public:
    TeamCommUsageExample() : Node("team_comm_usage_example")
    {
        pub_ = create_publisher<TeamCommunication>("/booster_soccer/team_comm/out", 10);
        sub_ = create_subscription<TeamCommunication>(
            "/booster_soccer/team_comm/in",
            10,
            [this](const TeamCommunication::SharedPtr msg) {
                // Update shared world model with latest valid data only.
                // Ignore duplicates/old packets at the strategy layer if a richer sequence is added later.
                RCLCPP_INFO(
                    get_logger(),
                    "teammate=%d role=%d alive=%d ball_known=%d robot=(%.2f, %.2f, %.2f)",
                    msg->player_id,
                    msg->player_role,
                    msg->is_alive,
                    msg->ball_location_known,
                    msg->robot_pose_to_field_x,
                    msg->robot_pose_to_field_y,
                    msg->robot_pose_to_field_theta);
            });

        timer_ = create_wall_timer(
            std::chrono::seconds(1),
            [this]() {
                TeamCommunication msg;
                msg.validation = 31202;
                msg.communication_id = sequence_++;
                msg.team_id = 67;
                msg.player_id = 1;
                msg.player_role = 2;
                msg.is_alive = true;
                msg.ball_location_known = false;
                msg.robot_pose_to_field_x = -4.0;
                msg.robot_pose_to_field_y = 0.0;
                msg.robot_pose_to_field_theta = 0.0;
                pub_->publish(msg);
            });
    }

private:
    int sequence_ = 0;
    rclcpp::Publisher<TeamCommunication>::SharedPtr pub_;
    rclcpp::Subscription<TeamCommunication>::SharedPtr sub_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TeamCommUsageExample>());
    rclcpp::shutdown();
    return 0;
}
