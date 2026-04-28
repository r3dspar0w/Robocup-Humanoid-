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
        DeclareLaunchArgument('publish_own_packets', default_value='true'),
        DeclareLaunchArgument('enable_local_loopback_echo', default_value='true'),
        DeclareLaunchArgument('enable_compact_team_packet', default_value='true'),
        DeclareLaunchArgument('compact_secret_password', default_value='167'),
        DeclareLaunchArgument('compact_packet_size', default_value='8'),
        DeclareLaunchArgument('field_length', default_value='14.0'),
        DeclareLaunchArgument('field_width', default_value='9.0'),
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
                'publish_own_packets': LaunchConfiguration('publish_own_packets'),
                'enable_local_loopback_echo': LaunchConfiguration('enable_local_loopback_echo'),
                'enable_compact_team_packet': LaunchConfiguration('enable_compact_team_packet'),
                'compact_secret_password': LaunchConfiguration('compact_secret_password'),
                'compact_packet_size': LaunchConfiguration('compact_packet_size'),
                'field_length': LaunchConfiguration('field_length'),
                'field_width': LaunchConfiguration('field_width'),
            }]
        )
    ])
