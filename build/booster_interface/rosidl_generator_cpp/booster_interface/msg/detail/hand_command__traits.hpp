// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from booster_interface:msg/HandCommand.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__HAND_COMMAND__TRAITS_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__HAND_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "booster_interface/msg/detail/hand_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'hand_param'
#include "booster_interface/msg/detail/hand_param__traits.hpp"

namespace booster_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const HandCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: hand_param
  {
    if (msg.hand_param.size() == 0) {
      out << "hand_param: []";
    } else {
      out << "hand_param: [";
      size_t pending_items = msg.hand_param.size();
      for (auto item : msg.hand_param) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: force_mode
  {
    out << "force_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.force_mode, out);
    out << ", ";
  }

  // member: hand_index
  {
    out << "hand_index: ";
    rosidl_generator_traits::value_to_yaml(msg.hand_index, out);
    out << ", ";
  }

  // member: hand_type
  {
    out << "hand_type: ";
    rosidl_generator_traits::value_to_yaml(msg.hand_type, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HandCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: hand_param
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.hand_param.size() == 0) {
      out << "hand_param: []\n";
    } else {
      out << "hand_param:\n";
      for (auto item : msg.hand_param) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: force_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "force_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.force_mode, out);
    out << "\n";
  }

  // member: hand_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hand_index: ";
    rosidl_generator_traits::value_to_yaml(msg.hand_index, out);
    out << "\n";
  }

  // member: hand_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hand_type: ";
    rosidl_generator_traits::value_to_yaml(msg.hand_type, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HandCommand & msg, bool use_flow_style = false)
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

}  // namespace booster_interface

namespace rosidl_generator_traits
{

[[deprecated("use booster_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const booster_interface::msg::HandCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  booster_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use booster_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const booster_interface::msg::HandCommand & msg)
{
  return booster_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<booster_interface::msg::HandCommand>()
{
  return "booster_interface::msg::HandCommand";
}

template<>
inline const char * name<booster_interface::msg::HandCommand>()
{
  return "booster_interface/msg/HandCommand";
}

template<>
struct has_fixed_size<booster_interface::msg::HandCommand>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<booster_interface::msg::HandCommand>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<booster_interface::msg::HandCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__HAND_COMMAND__TRAITS_HPP_
