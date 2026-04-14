// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from booster_interface:msg/LowState.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__LOW_STATE__TRAITS_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__LOW_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "booster_interface/msg/detail/low_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'imu_state'
#include "booster_interface/msg/detail/imu_state__traits.hpp"
// Member 'motor_state_parallel'
// Member 'motor_state_serial'
#include "booster_interface/msg/detail/motor_state__traits.hpp"

namespace booster_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const LowState & msg,
  std::ostream & out)
{
  out << "{";
  // member: imu_state
  {
    out << "imu_state: ";
    to_flow_style_yaml(msg.imu_state, out);
    out << ", ";
  }

  // member: motor_state_parallel
  {
    if (msg.motor_state_parallel.size() == 0) {
      out << "motor_state_parallel: []";
    } else {
      out << "motor_state_parallel: [";
      size_t pending_items = msg.motor_state_parallel.size();
      for (auto item : msg.motor_state_parallel) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: motor_state_serial
  {
    if (msg.motor_state_serial.size() == 0) {
      out << "motor_state_serial: []";
    } else {
      out << "motor_state_serial: [";
      size_t pending_items = msg.motor_state_serial.size();
      for (auto item : msg.motor_state_serial) {
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
  const LowState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: imu_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "imu_state:\n";
    to_block_style_yaml(msg.imu_state, out, indentation + 2);
  }

  // member: motor_state_parallel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.motor_state_parallel.size() == 0) {
      out << "motor_state_parallel: []\n";
    } else {
      out << "motor_state_parallel:\n";
      for (auto item : msg.motor_state_parallel) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: motor_state_serial
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.motor_state_serial.size() == 0) {
      out << "motor_state_serial: []\n";
    } else {
      out << "motor_state_serial:\n";
      for (auto item : msg.motor_state_serial) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LowState & msg, bool use_flow_style = false)
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
  const booster_interface::msg::LowState & msg,
  std::ostream & out, size_t indentation = 0)
{
  booster_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use booster_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const booster_interface::msg::LowState & msg)
{
  return booster_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<booster_interface::msg::LowState>()
{
  return "booster_interface::msg::LowState";
}

template<>
inline const char * name<booster_interface::msg::LowState>()
{
  return "booster_interface/msg/LowState";
}

template<>
struct has_fixed_size<booster_interface::msg::LowState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<booster_interface::msg::LowState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<booster_interface::msg::LowState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__LOW_STATE__TRAITS_HPP_
