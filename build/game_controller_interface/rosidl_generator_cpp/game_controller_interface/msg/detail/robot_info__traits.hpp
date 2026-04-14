// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from game_controller_interface:msg/RobotInfo.idl
// generated code does not contain a copyright notice

#ifndef GAME_CONTROLLER_INTERFACE__MSG__DETAIL__ROBOT_INFO__TRAITS_HPP_
#define GAME_CONTROLLER_INTERFACE__MSG__DETAIL__ROBOT_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "game_controller_interface/msg/detail/robot_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace game_controller_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: penalty
  {
    out << "penalty: ";
    rosidl_generator_traits::value_to_yaml(msg.penalty, out);
    out << ", ";
  }

  // member: secs_till_unpenalised
  {
    out << "secs_till_unpenalised: ";
    rosidl_generator_traits::value_to_yaml(msg.secs_till_unpenalised, out);
    out << ", ";
  }

  // member: number_of_warnings
  {
    out << "number_of_warnings: ";
    rosidl_generator_traits::value_to_yaml(msg.number_of_warnings, out);
    out << ", ";
  }

  // member: yellow_card_count
  {
    out << "yellow_card_count: ";
    rosidl_generator_traits::value_to_yaml(msg.yellow_card_count, out);
    out << ", ";
  }

  // member: red_card_count
  {
    out << "red_card_count: ";
    rosidl_generator_traits::value_to_yaml(msg.red_card_count, out);
    out << ", ";
  }

  // member: goal_keeper
  {
    out << "goal_keeper: ";
    rosidl_generator_traits::value_to_yaml(msg.goal_keeper, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: penalty
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "penalty: ";
    rosidl_generator_traits::value_to_yaml(msg.penalty, out);
    out << "\n";
  }

  // member: secs_till_unpenalised
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "secs_till_unpenalised: ";
    rosidl_generator_traits::value_to_yaml(msg.secs_till_unpenalised, out);
    out << "\n";
  }

  // member: number_of_warnings
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "number_of_warnings: ";
    rosidl_generator_traits::value_to_yaml(msg.number_of_warnings, out);
    out << "\n";
  }

  // member: yellow_card_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yellow_card_count: ";
    rosidl_generator_traits::value_to_yaml(msg.yellow_card_count, out);
    out << "\n";
  }

  // member: red_card_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "red_card_count: ";
    rosidl_generator_traits::value_to_yaml(msg.red_card_count, out);
    out << "\n";
  }

  // member: goal_keeper
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_keeper: ";
    rosidl_generator_traits::value_to_yaml(msg.goal_keeper, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotInfo & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace game_controller_interface

namespace rosidl_generator_traits
{

[[deprecated("use game_controller_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const game_controller_interface::msg::RobotInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  game_controller_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use game_controller_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const game_controller_interface::msg::RobotInfo & msg)
{
  return game_controller_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<game_controller_interface::msg::RobotInfo>()
{
  return "game_controller_interface::msg::RobotInfo";
}

template<>
inline const char * name<game_controller_interface::msg::RobotInfo>()
{
  return "game_controller_interface/msg/RobotInfo";
}

template<>
struct has_fixed_size<game_controller_interface::msg::RobotInfo>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<game_controller_interface::msg::RobotInfo>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<game_controller_interface::msg::RobotInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GAME_CONTROLLER_INTERFACE__MSG__DETAIL__ROBOT_INFO__TRAITS_HPP_
