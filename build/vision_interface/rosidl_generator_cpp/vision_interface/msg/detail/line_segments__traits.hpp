// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vision_interface:msg/LineSegments.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__LINE_SEGMENTS__TRAITS_HPP_
#define VISION_INTERFACE__MSG__DETAIL__LINE_SEGMENTS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vision_interface/msg/detail/line_segments__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace vision_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const LineSegments & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: coordinates
  {
    if (msg.coordinates.size() == 0) {
      out << "coordinates: []";
    } else {
      out << "coordinates: [";
      size_t pending_items = msg.coordinates.size();
      for (auto item : msg.coordinates) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: coordinates_uv
  {
    if (msg.coordinates_uv.size() == 0) {
      out << "coordinates_uv: []";
    } else {
      out << "coordinates_uv: [";
      size_t pending_items = msg.coordinates_uv.size();
      for (auto item : msg.coordinates_uv) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LineSegments & msg,
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

  // member: coordinates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.coordinates.size() == 0) {
      out << "coordinates: []\n";
    } else {
      out << "coordinates:\n";
      for (auto item : msg.coordinates) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: coordinates_uv
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.coordinates_uv.size() == 0) {
      out << "coordinates_uv: []\n";
    } else {
      out << "coordinates_uv:\n";
      for (auto item : msg.coordinates_uv) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LineSegments & msg, bool use_flow_style = false)
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
  const vision_interface::msg::LineSegments & msg,
  std::ostream & out, size_t indentation = 0)
{
  vision_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vision_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const vision_interface::msg::LineSegments & msg)
{
  return vision_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vision_interface::msg::LineSegments>()
{
  return "vision_interface::msg::LineSegments";
}

template<>
inline const char * name<vision_interface::msg::LineSegments>()
{
  return "vision_interface/msg/LineSegments";
}

template<>
struct has_fixed_size<vision_interface::msg::LineSegments>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vision_interface::msg::LineSegments>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vision_interface::msg::LineSegments>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VISION_INTERFACE__MSG__DETAIL__LINE_SEGMENTS__TRAITS_HPP_
