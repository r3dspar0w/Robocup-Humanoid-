// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from brain:msg/Kick.idl
// generated code does not contain a copyright notice

#ifndef BRAIN__MSG__DETAIL__KICK__TRAITS_HPP_
#define BRAIN__MSG__DETAIL__KICK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "brain/msg/detail/kick__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace brain
{

namespace msg
{

inline void to_flow_style_yaml(
  const Kick & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: dir
  {
    out << "dir: ";
    rosidl_generator_traits::value_to_yaml(msg.dir, out);
    out << ", ";
  }

  // member: goal_x
  {
    out << "goal_x: ";
    rosidl_generator_traits::value_to_yaml(msg.goal_x, out);
    out << ", ";
  }

  // member: goal_y
  {
    out << "goal_y: ";
    rosidl_generator_traits::value_to_yaml(msg.goal_y, out);
    out << ", ";
  }

  // member: robot_theta_to_field
  {
    out << "robot_theta_to_field: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_theta_to_field, out);
    out << ", ";
  }

  // member: power
  {
    out << "power: ";
    rosidl_generator_traits::value_to_yaml(msg.power, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Kick & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: dir
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dir: ";
    rosidl_generator_traits::value_to_yaml(msg.dir, out);
    out << "\n";
  }

  // member: goal_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_x: ";
    rosidl_generator_traits::value_to_yaml(msg.goal_x, out);
    out << "\n";
  }

  // member: goal_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_y: ";
    rosidl_generator_traits::value_to_yaml(msg.goal_y, out);
    out << "\n";
  }

  // member: robot_theta_to_field
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_theta_to_field: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_theta_to_field, out);
    out << "\n";
  }

  // member: power
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "power: ";
    rosidl_generator_traits::value_to_yaml(msg.power, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Kick & msg, bool use_flow_style = false)
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

}  // namespace brain

namespace rosidl_generator_traits
{

[[deprecated("use brain::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const brain::msg::Kick & msg,
  std::ostream & out, size_t indentation = 0)
{
  brain::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use brain::msg::to_yaml() instead")]]
inline std::string to_yaml(const brain::msg::Kick & msg)
{
  return brain::msg::to_yaml(msg);
}

template<>
inline const char * data_type<brain::msg::Kick>()
{
  return "brain::msg::Kick";
}

template<>
inline const char * name<brain::msg::Kick>()
{
  return "brain/msg/Kick";
}

template<>
struct has_fixed_size<brain::msg::Kick>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<brain::msg::Kick>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<brain::msg::Kick>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BRAIN__MSG__DETAIL__KICK__TRAITS_HPP_
