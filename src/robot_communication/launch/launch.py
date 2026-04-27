# coding: utf8

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument('enable_robot_comm_relay', default_value='true'),
        DeclareLaunchArgument('team_id', default_value='0'),
        DeclareLaunchArgument('player_id', default_value='0'),
        DeclareLaunchArgument('robot_comm_port', default_value='0'),
        DeclareLaunchArgument('relay_broadcast_address', default_value='255.255.255.255'),
        Node(
            package='robot_communication',
            executable='robot_communication_node',
            output='screen',
            parameters=[{
                'enable_robot_comm_relay': LaunchConfiguration('enable_robot_comm_relay'),
                'team_id': LaunchConfiguration('team_id'),
                'player_id': LaunchConfiguration('player_id'),
                'robot_comm_port': LaunchConfiguration('robot_comm_port'),
                'relay_broadcast_address': LaunchConfiguration('relay_broadcast_address'),
            }]
        )
    ])
