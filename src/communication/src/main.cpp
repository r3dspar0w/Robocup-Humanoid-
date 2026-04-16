#include <memory>

#include <rclcpp/rclcpp.hpp>

#include "communication/team_communication_node.h"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TeamCommunicationNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
