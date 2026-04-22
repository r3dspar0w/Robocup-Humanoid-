from pathlib import Path

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue


def generate_launch_description():
    package_share = Path(get_package_share_directory("motion_control"))
    default_model_path = package_share / "models" / "walk" / "walk.onnx"

    return LaunchDescription([
        DeclareLaunchArgument("sdk_domain_id", default_value="0"),
        DeclareLaunchArgument("network_interface", default_value=""),
        DeclareLaunchArgument("robot_name", default_value=""),
        DeclareLaunchArgument("model_path", default_value=str(default_model_path)),
        DeclareLaunchArgument("low_state_topic", default_value="rt/low_state"),
        DeclareLaunchArgument("publish_hz", default_value="50.0"),
        DeclareLaunchArgument("policy_hz", default_value="50.0"),
        DeclareLaunchArgument("action_scale", default_value="0.25"),
        DeclareLaunchArgument("joint_velocity_factor", default_value="0.1"),
        DeclareLaunchArgument("frequency_base", default_value="1.5"),
        DeclareLaunchArgument("frequency_clip_min", default_value="-0.5"),
        DeclareLaunchArgument("frequency_clip_max", default_value="0.5"),
        DeclareLaunchArgument("max_cmd_vel_x", default_value="0.6"),
        DeclareLaunchArgument("max_cmd_vel_y", default_value="0.4"),
        DeclareLaunchArgument("max_cmd_vel_yaw", default_value="1.0"),
        DeclareLaunchArgument(
            "controlled_joint_indices",
            default_value="10,11,12,13,14,15,16,17,18,19,20,21,22"),
        DeclareLaunchArgument("observation_order", default_value="gravity_ang_vel"),
        DeclareLaunchArgument("start_enabled", default_value="true"),
        DeclareLaunchArgument("auto_change_mode", default_value="true"),
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
                "low_state_topic": LaunchConfiguration("low_state_topic"),
                "publish_hz": ParameterValue(LaunchConfiguration("publish_hz"), value_type=float),
                "policy_hz": ParameterValue(LaunchConfiguration("policy_hz"), value_type=float),
                "action_scale": ParameterValue(
                    LaunchConfiguration("action_scale"), value_type=float),
                "joint_velocity_factor": ParameterValue(
                    LaunchConfiguration("joint_velocity_factor"), value_type=float),
                "frequency_base": ParameterValue(
                    LaunchConfiguration("frequency_base"), value_type=float),
                "frequency_clip_min": ParameterValue(
                    LaunchConfiguration("frequency_clip_min"), value_type=float),
                "frequency_clip_max": ParameterValue(
                    LaunchConfiguration("frequency_clip_max"), value_type=float),
                "max_cmd_vel_x": ParameterValue(
                    LaunchConfiguration("max_cmd_vel_x"), value_type=float),
                "max_cmd_vel_y": ParameterValue(
                    LaunchConfiguration("max_cmd_vel_y"), value_type=float),
                "max_cmd_vel_yaw": ParameterValue(
                    LaunchConfiguration("max_cmd_vel_yaw"), value_type=float),
                "controlled_joint_indices": LaunchConfiguration("controlled_joint_indices"),
                "observation_order": LaunchConfiguration("observation_order"),
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
