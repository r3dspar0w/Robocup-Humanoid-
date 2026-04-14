// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vision_interface:msg/Ball.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__BALL__TRAITS_HPP_
#define VISION_INTERFACE__MSG__DETAIL__BALL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vision_interface/msg/detail/ball__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace vision_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const Ball & msg,
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

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Ball & msg,
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

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Ball & msg, bool use_flow_style = false)
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

}  // namespace vision_interface

namespace rosidl_generator_traits
{

[[deprecated("use vision_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vision_interface::msg::Ball & msg,
  std::ostream & out, size_t indentation = 0)
{
  vision_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vision_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const vision_interface::msg::Ball & msg)
{
  return vision_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vision_interface::msg::Ball>()
{
  return "vision_interface::msg::Ball";
}

template<>
inline const char * name<vision_interface::msg::Ball>()
{
  return "vision_interface/msg/Ball";
}

template<>
struct has_fixed_size<vision_interface::msg::Ball>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<vision_interface::msg::Ball>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<vision_interface::msg::Ball>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VISION_INTERFACE__MSG__DETAIL__BALL__TRAITS_HPP_
