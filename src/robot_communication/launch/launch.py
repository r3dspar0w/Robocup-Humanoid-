# coding: utf8

import os

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node


def _scalar(value):
    value = value.strip().strip('"\'')
    if value.lower() in ['true', 'false']:
        return value.lower() == 'true'
    try:
        return int(value)
    except ValueError:
        pass
    try:
        return float(value)
    except ValueError:
        return value


def _load_brain_config_defaults():
    config_file = os.path.join(
        get_package_share_directory('brain'),
        'config',
        'config.yaml')
    defaults = {}
    stack = []

    with open(config_file, 'r', encoding='utf-8') as stream:
        for raw_line in stream:
            line = raw_line.split('#', 1)[0].rstrip()
            if not line.strip() or ':' not in line:
                continue

            indent = len(line) - len(line.lstrip(' '))
            key, value = line.strip().split(':', 1)
            level = indent // 2
            stack = stack[:level]

            if value.strip() == '':
                stack.append(key)
                continue

            full_key = '.'.join(stack + [key])
            defaults[full_key] = _scalar(value)

    return defaults


def _arg_or_default(context, name, default):
    value = context.perform_substitution(LaunchConfiguration(name))
    return default if value == '' else _scalar(value)


def launch_robot_communication(context, *args, **kwargs):
    defaults = _load_brain_config_defaults()

    team_id = _arg_or_default(context, 'team_id', defaults.get('brain_node.ros__parameters.game.team_id', 0))
    player_id = _arg_or_default(context, 'player_id', defaults.get('brain_node.ros__parameters.game.player_id', 0))

    return [
        Node(
            package='robot_communication',
            executable='robot_communication_node',
            output='screen',
            parameters=[{
                'team_communication.enabled': _arg_or_default(
                    context, 'team_communication_enabled',
                    defaults.get('brain_node.ros__parameters.team_communication.enabled', True)),
                'team_id': team_id,
                'player_id': player_id,
                'team_communication.broadcast_address': _arg_or_default(
                    context, 'team_broadcast_address',
                    defaults.get('brain_node.ros__parameters.team_communication.broadcast_address', '255.255.255.255')),
                'team_communication.max_hz': _arg_or_default(
                    context, 'team_max_hz',
                    defaults.get('brain_node.ros__parameters.team_communication.max_hz', 5.0)),
                'team_communication.max_packets_per_game': _arg_or_default(
                    context, 'team_max_packets_per_game',
                    defaults.get('brain_node.ros__parameters.team_communication.max_packets_per_game', 12000)),
                'team_communication.event_driven': _arg_or_default(
                    context, 'team_event_driven',
                    defaults.get('brain_node.ros__parameters.team_communication.event_driven', True)),
                'team_communication.heartbeat_sec': _arg_or_default(
                    context, 'team_heartbeat_sec',
                    defaults.get('brain_node.ros__parameters.team_communication.heartbeat_sec', 2.0)),
                'debug_communication.enabled': _arg_or_default(
                    context, 'debug_communication_enabled',
                    defaults.get('brain_node.ros__parameters.debug_communication.enabled', False)),
                'debug_communication.target_ip': _arg_or_default(
                    context, 'debug_target_ip',
                    defaults.get('brain_node.ros__parameters.debug_communication.target_ip', '192.168.0.100')),
                'debug_communication.port': _arg_or_default(
                    context, 'debug_port',
                    defaults.get('brain_node.ros__parameters.debug_communication.port', 11000)),
                'debug_communication.max_hz': _arg_or_default(
                    context, 'debug_max_hz',
                    defaults.get('brain_node.ros__parameters.debug_communication.max_hz', 1.0)),
                'compact_secret_password': _arg_or_default(context, 'compact_secret_password', 167),
                'field_length': _arg_or_default(context, 'field_length', 14.0),
                'field_width': _arg_or_default(context, 'field_width', 9.0),
            }]
        )
    ]


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument('team_communication_enabled', default_value=''),
        DeclareLaunchArgument('team_id', default_value=''),
        DeclareLaunchArgument('player_id', default_value=''),
        DeclareLaunchArgument('team_broadcast_address', default_value=''),
        DeclareLaunchArgument('team_max_hz', default_value=''),
        DeclareLaunchArgument('team_max_packets_per_game', default_value=''),
        DeclareLaunchArgument('team_event_driven', default_value=''),
        DeclareLaunchArgument('team_heartbeat_sec', default_value=''),
        DeclareLaunchArgument('debug_communication_enabled', default_value=''),
        DeclareLaunchArgument('debug_target_ip', default_value=''),
        DeclareLaunchArgument('debug_port', default_value=''),
        DeclareLaunchArgument('debug_max_hz', default_value=''),
        DeclareLaunchArgument('compact_secret_password', default_value=''),
        DeclareLaunchArgument('field_length', default_value=''),
        DeclareLaunchArgument('field_width', default_value=''),
        OpaqueFunction(function=launch_robot_communication),
    ])
