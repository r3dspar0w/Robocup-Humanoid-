import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    package_share = get_package_share_directory("communication")
    default_config = os.path.join(package_share, "config", "team_communication.yaml")

    return LaunchDescription(
        [
            DeclareLaunchArgument("config_file", default_value=default_config),
            DeclareLaunchArgument("team_id", default_value="67"),
            DeclareLaunchArgument("player_id", default_value="1"),
            DeclareLaunchArgument("broadcast_address", default_value="255.255.255.255"),
            Node(
                package="communication",
                executable="team_communication_node",
                name="team_communication_node",
                output="screen",
                parameters=[
                    LaunchConfiguration("config_file"),
                    {
                        "team_id": LaunchConfiguration("team_id"),
                        "player_id": LaunchConfiguration("player_id"),
                        "broadcast_address": LaunchConfiguration("broadcast_address"),
                    },
                ],
            ),
        ]
    )
