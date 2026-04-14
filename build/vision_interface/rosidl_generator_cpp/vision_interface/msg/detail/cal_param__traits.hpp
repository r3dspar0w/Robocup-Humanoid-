// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vision_interface:msg/CalParam.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__CAL_PARAM__TRAITS_HPP_
#define VISION_INTERFACE__MSG__DETAIL__CAL_PARAM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vision_interface/msg/detail/cal_param__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vision_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const CalParam & msg,
  std::ostream & out)
{
  out << "{";
  // member: pitch_compensation
  {
    out << "pitch_compensation: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_compensation, out);
    out << ", ";
  }

  // member: yaw_compensation
  {
    out << "yaw_compensation: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_compensation, out);
    out << ", ";
  }

  // member: z_compensation
  {
    out << "z_compensation: ";
    rosidl_generator_traits::value_to_yaml(msg.z_compensation, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CalParam & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pitch_compensation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch_compensation: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_compensation, out);
    out << "\n";
  }

  // member: yaw_compensation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_compensation: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_compensation, out);
    out << "\n";
  }

  // member: z_compensation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z_compensation: ";
    rosidl_generator_traits::value_to_yaml(msg.z_compensation, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CalParam & msg, bool use_flow_style = false)
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
  const vision_interface::msg::CalParam & msg,
  std::ostream & out, size_t indentation = 0)
{
  vision_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vision_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const vision_interface::msg::CalParam & msg)
{
  return vision_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vision_interface::msg::CalParam>()
{
  return "vision_interface::msg::CalParam";
}

template<>
inline const char * name<vision_interface::msg::CalParam>()
{
  return "vision_interface/msg/CalParam";
}

template<>
struct has_fixed_size<vision_interface::msg::CalParam>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vision_interface::msg::CalParam>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vision_interface::msg::CalParam>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VISION_INTERFACE__MSG__DETAIL__CAL_PARAM__TRAITS_HPP_
