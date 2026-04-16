import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def handle_configuration(context, *args, **kwargs):
    pkg_share = get_package_share_directory("motion_control")
    config_file = os.path.join(pkg_share, "config", "config.yaml")

    config = {}

    robot_name = context.perform_substitution(LaunchConfiguration("robot_name"))
    if robot_name:
        config["robot.robot_name"] = robot_name

    sim = context.perform_substitution(LaunchConfiguration("sim"))
    if sim in ["true", "True", "1"]:
        config["use_sim_time"] = True

    csv_log_dir = context.perform_substitution(LaunchConfiguration("csv_log_dir"))
    if csv_log_dir:
        config["robot.actuator_monitor_csv_log_dir"] = csv_log_dir

    return [
        Node(
            package="motion_control",
            executable="actuator_monitor_node",
            output="screen",
            parameters=[config_file, config],
        )
    ]


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument("robot_name", default_value=""),
        DeclareLaunchArgument("sim", default_value="false"),
        DeclareLaunchArgument("csv_log_dir", default_value=""),
        OpaqueFunction(function=handle_configuration),
    ])
