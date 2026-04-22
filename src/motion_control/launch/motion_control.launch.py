from pathlib import Path

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue


def generate_launch_description():
    package_share = Path(get_package_share_directory("motion_control"))
    default_model_path = package_share / "models" / "walk" / "T1.onnx"

    return LaunchDescription([
        DeclareLaunchArgument("sdk_domain_id", default_value="0"),
        DeclareLaunchArgument("network_interface", default_value=""),
        DeclareLaunchArgument("robot_name", default_value=""),
        DeclareLaunchArgument("model_path", default_value=str(default_model_path)),
        DeclareLaunchArgument("publish_hz", default_value="50.0"),
        DeclareLaunchArgument("start_enabled", default_value="false"),
        DeclareLaunchArgument("auto_change_mode", default_value="false"),
        DeclareLaunchArgument("return_to_prepare_on_disable", default_value="false"),
        DeclareLaunchArgument("cmd_type", default_value="parallel"),
        Node(
            package="motion_control",
            executable="motion_control_node",
            name="motion_control_node",
            output="screen",
            parameters=[{
                "sdk_domain_id": ParameterValue(LaunchConfiguration("sdk_domain_id"), value_type=int),
                "network_interface": LaunchConfiguration("network_interface"),
                "robot_name": LaunchConfiguration("robot_name"),
                "model_path": LaunchConfiguration("model_path"),
                "publish_hz": ParameterValue(LaunchConfiguration("publish_hz"), value_type=float),
                "start_enabled": ParameterValue(
                    LaunchConfiguration("start_enabled"), value_type=bool),
                "auto_change_mode": ParameterValue(
                    LaunchConfiguration("auto_change_mode"), value_type=bool),
                "return_to_prepare_on_disable": ParameterValue(
                    LaunchConfiguration("return_to_prepare_on_disable"), value_type=bool),
                "cmd_type": LaunchConfiguration("cmd_type"),
            }],
        ),
    ])
