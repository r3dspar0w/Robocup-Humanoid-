// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from booster_interface:msg/LowCmd.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__LOW_CMD__TRAITS_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__LOW_CMD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "booster_interface/msg/detail/low_cmd__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'motor_cmd'
#include "booster_interface/msg/detail/motor_cmd__traits.hpp"

namespace booster_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const LowCmd & msg,
  std::ostream & out)
{
  out << "{";
  // member: cmd_type
  {
    out << "cmd_type: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_type, out);
    out << ", ";
  }

  // member: motor_cmd
  {
    if (msg.motor_cmd.size() == 0) {
      out << "motor_cmd: []";
    } else {
      out << "motor_cmd: [";
      size_t pending_items = msg.motor_cmd.size();
      for (auto item : msg.motor_cmd) {
        to_flow_style_yaml(item, out);
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
  const LowCmd & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cmd_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd_type: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_type, out);
    out << "\n";
  }

  // member: motor_cmd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.motor_cmd.size() == 0) {
      out << "motor_cmd: []\n";
    } else {
      out << "motor_cmd:\n";
      for (auto item : msg.motor_cmd) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LowCmd & msg, bool use_flow_style = false)
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
  const booster_interface::msg::LowCmd & msg,
  std::ostream & out, size_t indentation = 0)
{
  booster_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use booster_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const booster_interface::msg::LowCmd & msg)
{
  return booster_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<booster_interface::msg::LowCmd>()
{
  return "booster_interface::msg::LowCmd";
}

template<>
inline const char * name<booster_interface::msg::LowCmd>()
{
  return "booster_interface/msg/LowCmd";
}

template<>
struct has_fixed_size<booster_interface::msg::LowCmd>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<booster_interface::msg::LowCmd>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<booster_interface::msg::LowCmd>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__LOW_CMD__TRAITS_HPP_
