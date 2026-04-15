import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def handle_configuration(context, *args, **kwargs):
    pkg_share = get_package_share_directory("motion_control")
    config_file = os.path.join(pkg_share, "config", "config.yaml")
    default_model_path = os.path.join(pkg_share, "model", "policy.onnx")

    config = {
        "robot.custom_walk_model_path": default_model_path,
    }

    robot_name = context.perform_substitution(LaunchConfiguration("robot_name"))
    if robot_name:
        config["robot.robot_name"] = robot_name

    model_path = context.perform_substitution(LaunchConfiguration("model_path"))
    if model_path:
        config["robot.custom_walk_model_path"] = model_path

    sim = context.perform_substitution(LaunchConfiguration("sim"))
    if sim in ["true", "True", "1"]:
        config["use_sim_time"] = True

    return [
        Node(
            package="motion_control",
            executable="custom_motion_node",
            output="screen",
            parameters=[config_file, config],
        )
    ]


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument("robot_name", default_value=""),
        DeclareLaunchArgument("model_path", default_value=""),
        DeclareLaunchArgument("sim", default_value="false"),
        OpaqueFunction(function=handle_configuration),
    ])
