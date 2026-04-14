// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vision_interface:msg/DetectedObject.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__DETECTED_OBJECT__TRAITS_HPP_
#define VISION_INTERFACE__MSG__DETAIL__DETECTED_OBJECT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vision_interface/msg/detail/detected_object__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vision_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const DetectedObject & msg,
  std::ostream & out)
{
  out << "{";
  // member: label
  {
    out << "label: ";
    rosidl_generator_traits::value_to_yaml(msg.label, out);
    out << ", ";
  }

  // member: color
  {
    out << "color: ";
    rosidl_generator_traits::value_to_yaml(msg.color, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: xmin
  {
    out << "xmin: ";
    rosidl_generator_traits::value_to_yaml(msg.xmin, out);
    out << ", ";
  }

  // member: ymin
  {
    out << "ymin: ";
    rosidl_generator_traits::value_to_yaml(msg.ymin, out);
    out << ", ";
  }

  // member: xmax
  {
    out << "xmax: ";
    rosidl_generator_traits::value_to_yaml(msg.xmax, out);
    out << ", ";
  }

  // member: ymax
  {
    out << "ymax: ";
    rosidl_generator_traits::value_to_yaml(msg.ymax, out);
    out << ", ";
  }

  // member: target_uv
  {
    if (msg.target_uv.size() == 0) {
      out << "target_uv: []";
    } else {
      out << "target_uv: [";
      size_t pending_items = msg.target_uv.size();
      for (auto item : msg.target_uv) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: received_pos
  {
    if (msg.received_pos.size() == 0) {
      out << "received_pos: []";
    } else {
      out << "received_pos: [";
      size_t pending_items = msg.received_pos.size();
      for (auto item : msg.received_pos) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: position
  {
    if (msg.position.size() == 0) {
      out << "position: []";
    } else {
      out << "position: [";
      size_t pending_items = msg.position.size();
      for (auto item : msg.position) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: position_projection
  {
    if (msg.position_projection.size() == 0) {
      out << "position_projection: []";
    } else {
      out << "position_projection: [";
      size_t pending_items = msg.position_projection.size();
      for (auto item : msg.position_projection) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: position_cam
  {
    if (msg.position_cam.size() == 0) {
      out << "position_cam: []";
    } else {
      out << "position_cam: [";
      size_t pending_items = msg.position_cam.size();
      for (auto item : msg.position_cam) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: position_confidence
  {
    out << "position_confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.position_confidence, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectedObject & msg,
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

  // member: color
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "color: ";
    rosidl_generator_traits::value_to_yaml(msg.color, out);
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

  // member: xmin
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "xmin: ";
    rosidl_generator_traits::value_to_yaml(msg.xmin, out);
    out << "\n";
  }

  // member: ymin
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ymin: ";
    rosidl_generator_traits::value_to_yaml(msg.ymin, out);
    out << "\n";
  }

  // member: xmax
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "xmax: ";
    rosidl_generator_traits::value_to_yaml(msg.xmax, out);
    out << "\n";
  }

  // member: ymax
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ymax: ";
    rosidl_generator_traits::value_to_yaml(msg.ymax, out);
    out << "\n";
  }

  // member: target_uv
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.target_uv.size() == 0) {
      out << "target_uv: []\n";
    } else {
      out << "target_uv:\n";
      for (auto item : msg.target_uv) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: received_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.received_pos.size() == 0) {
      out << "received_pos: []\n";
    } else {
      out << "received_pos:\n";
      for (auto item : msg.received_pos) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.position.size() == 0) {
      out << "position: []\n";
    } else {
      out << "position:\n";
      for (auto item : msg.position) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: position_projection
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.position_projection.size() == 0) {
      out << "position_projection: []\n";
    } else {
      out << "position_projection:\n";
      for (auto item : msg.position_projection) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: position_cam
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.position_cam.size() == 0) {
      out << "position_cam: []\n";
    } else {
      out << "position_cam:\n";
      for (auto item : msg.position_cam) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: position_confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position_confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.position_confidence, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectedObject & msg, bool use_flow_style = false)
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
  const vision_interface::msg::DetectedObject & msg,
  std::ostream & out, size_t indentation = 0)
{
  vision_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vision_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const vision_interface::msg::DetectedObject & msg)
{
  return vision_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vision_interface::msg::DetectedObject>()
{
  return "vision_interface::msg::DetectedObject";
}

template<>
inline const char * name<vision_interface::msg::DetectedObject>()
{
  return "vision_interface/msg/DetectedObject";
}

template<>
struct has_fixed_size<vision_interface::msg::DetectedObject>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vision_interface::msg::DetectedObject>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vision_interface::msg::DetectedObject>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VISION_INTERFACE__MSG__DETAIL__DETECTED_OBJECT__TRAITS_HPP_
