// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vision_interface:msg/SegmentationLine.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_LINE__TRAITS_HPP_
#define VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_LINE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vision_interface/msg/detail/segmentation_line__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vision_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const SegmentationLine & msg,
  std::ostream & out)
{
  out << "{";
  // member: label
  {
    out << "label: ";
    rosidl_generator_traits::value_to_yaml(msg.label, out);
    out << ", ";
  }

  // member: x1
  {
    out << "x1: ";
    rosidl_generator_traits::value_to_yaml(msg.x1, out);
    out << ", ";
  }

  // member: y1
  {
    out << "y1: ";
    rosidl_generator_traits::value_to_yaml(msg.y1, out);
    out << ", ";
  }

  // member: x2
  {
    out << "x2: ";
    rosidl_generator_traits::value_to_yaml(msg.x2, out);
    out << ", ";
  }

  // member: y2
  {
    out << "y2: ";
    rosidl_generator_traits::value_to_yaml(msg.y2, out);
    out << ", ";
  }

  // member: u1
  {
    out << "u1: ";
    rosidl_generator_traits::value_to_yaml(msg.u1, out);
    out << ", ";
  }

  // member: v1
  {
    out << "v1: ";
    rosidl_generator_traits::value_to_yaml(msg.v1, out);
    out << ", ";
  }

  // member: u2
  {
    out << "u2: ";
    rosidl_generator_traits::value_to_yaml(msg.u2, out);
    out << ", ";
  }

  // member: v2
  {
    out << "v2: ";
    rosidl_generator_traits::value_to_yaml(msg.v2, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SegmentationLine & msg,
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

  // member: x1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x1: ";
    rosidl_generator_traits::value_to_yaml(msg.x1, out);
    out << "\n";
  }

  // member: y1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y1: ";
    rosidl_generator_traits::value_to_yaml(msg.y1, out);
    out << "\n";
  }

  // member: x2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x2: ";
    rosidl_generator_traits::value_to_yaml(msg.x2, out);
    out << "\n";
  }

  // member: y2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y2: ";
    rosidl_generator_traits::value_to_yaml(msg.y2, out);
    out << "\n";
  }

  // member: u1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "u1: ";
    rosidl_generator_traits::value_to_yaml(msg.u1, out);
    out << "\n";
  }

  // member: v1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v1: ";
    rosidl_generator_traits::value_to_yaml(msg.v1, out);
    out << "\n";
  }

  // member: u2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "u2: ";
    rosidl_generator_traits::value_to_yaml(msg.u2, out);
    out << "\n";
  }

  // member: v2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v2: ";
    rosidl_generator_traits::value_to_yaml(msg.v2, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SegmentationLine & msg, bool use_flow_style = false)
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
  const vision_interface::msg::SegmentationLine & msg,
  std::ostream & out, size_t indentation = 0)
{
  vision_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vision_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const vision_interface::msg::SegmentationLine & msg)
{
  return vision_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vision_interface::msg::SegmentationLine>()
{
  return "vision_interface::msg::SegmentationLine";
}

template<>
inline const char * name<vision_interface::msg::SegmentationLine>()
{
  return "vision_interface/msg/SegmentationLine";
}

template<>
struct has_fixed_size<vision_interface::msg::SegmentationLine>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vision_interface::msg::SegmentationLine>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vision_interface::msg::SegmentationLine>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_LINE__TRAITS_HPP_
