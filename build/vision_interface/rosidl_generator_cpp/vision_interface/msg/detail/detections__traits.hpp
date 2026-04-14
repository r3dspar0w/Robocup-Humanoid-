// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vision_interface:msg/Detections.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__DETECTIONS__TRAITS_HPP_
#define VISION_INTERFACE__MSG__DETAIL__DETECTIONS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vision_interface/msg/detail/detections__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'detected_objects'
#include "vision_interface/msg/detail/detected_object__traits.hpp"

namespace vision_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const Detections & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: detected_objects
  {
    if (msg.detected_objects.size() == 0) {
      out << "detected_objects: []";
    } else {
      out << "detected_objects: [";
      size_t pending_items = msg.detected_objects.size();
      for (auto item : msg.detected_objects) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: radar_x
  {
    if (msg.radar_x.size() == 0) {
      out << "radar_x: []";
    } else {
      out << "radar_x: [";
      size_t pending_items = msg.radar_x.size();
      for (auto item : msg.radar_x) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: radar_y
  {
    if (msg.radar_y.size() == 0) {
      out << "radar_y: []";
    } else {
      out << "radar_y: [";
      size_t pending_items = msg.radar_y.size();
      for (auto item : msg.radar_y) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: corner_pos
  {
    if (msg.corner_pos.size() == 0) {
      out << "corner_pos: []";
    } else {
      out << "corner_pos: [";
      size_t pending_items = msg.corner_pos.size();
      for (auto item : msg.corner_pos) {
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
  const Detections & msg,
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

  // member: detected_objects
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.detected_objects.size() == 0) {
      out << "detected_objects: []\n";
    } else {
      out << "detected_objects:\n";
      for (auto item : msg.detected_objects) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: radar_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.radar_x.size() == 0) {
      out << "radar_x: []\n";
    } else {
      out << "radar_x:\n";
      for (auto item : msg.radar_x) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: radar_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.radar_y.size() == 0) {
      out << "radar_y: []\n";
    } else {
      out << "radar_y:\n";
      for (auto item : msg.radar_y) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: corner_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.corner_pos.size() == 0) {
      out << "corner_pos: []\n";
    } else {
      out << "corner_pos:\n";
      for (auto item : msg.corner_pos) {
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

inline std::string to_yaml(const Detections & msg, bool use_flow_style = false)
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
  const vision_interface::msg::Detections & msg,
  std::ostream & out, size_t indentation = 0)
{
  vision_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vision_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const vision_interface::msg::Detections & msg)
{
  return vision_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vision_interface::msg::Detections>()
{
  return "vision_interface::msg::Detections";
}

template<>
inline const char * name<vision_interface::msg::Detections>()
{
  return "vision_interface/msg/Detections";
}

template<>
struct has_fixed_size<vision_interface::msg::Detections>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vision_interface::msg::Detections>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vision_interface::msg::Detections>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VISION_INTERFACE__MSG__DETAIL__DETECTIONS__TRAITS_HPP_
