// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vision_interface:msg/SegmentationPoint.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_POINT__TRAITS_HPP_
#define VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_POINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vision_interface/msg/detail/segmentation_point__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vision_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const SegmentationPoint & msg,
  std::ostream & out)
{
  out << "{";
  // member: label
  {
    out << "label: ";
    rosidl_generator_traits::value_to_yaml(msg.label, out);
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

  // member: u
  {
    out << "u: ";
    rosidl_generator_traits::value_to_yaml(msg.u, out);
    out << ", ";
  }

  // member: v
  {
    out << "v: ";
    rosidl_generator_traits::value_to_yaml(msg.v, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SegmentationPoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: label
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "label: ";
    rosidl_generator_traits::value_to_yaml(msg.label, out);
    out << "\n";
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

  // member: u
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "u: ";
    rosidl_generator_traits::value_to_yaml(msg.u, out);
    out << "\n";
  }

  // member: v
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v: ";
    rosidl_generator_traits::value_to_yaml(msg.v, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SegmentationPoint & msg, bool use_flow_style = false)
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
  const vision_interface::msg::SegmentationPoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  vision_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vision_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const vision_interface::msg::SegmentationPoint & msg)
{
  return vision_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vision_interface::msg::SegmentationPoint>()
{
  return "vision_interface::msg::SegmentationPoint";
}

template<>
inline const char * name<vision_interface::msg::SegmentationPoint>()
{
  return "vision_interface/msg/SegmentationPoint";
}

template<>
struct has_fixed_size<vision_interface::msg::SegmentationPoint>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vision_interface::msg::SegmentationPoint>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vision_interface::msg::SegmentationPoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_POINT__TRAITS_HPP_
