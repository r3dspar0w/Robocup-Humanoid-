// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from booster_interface:msg/RemoteControllerState.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__REMOTE_CONTROLLER_STATE__TRAITS_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__REMOTE_CONTROLLER_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "booster_interface/msg/detail/remote_controller_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace booster_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const RemoteControllerState & msg,
  std::ostream & out)
{
  out << "{";
  // member: event
  {
    out << "event: ";
    rosidl_generator_traits::value_to_yaml(msg.event, out);
    out << ", ";
  }

  // member: lx
  {
    out << "lx: ";
    rosidl_generator_traits::value_to_yaml(msg.lx, out);
    out << ", ";
  }

  // member: ly
  {
    out << "ly: ";
    rosidl_generator_traits::value_to_yaml(msg.ly, out);
    out << ", ";
  }

  // member: rx
  {
    out << "rx: ";
    rosidl_generator_traits::value_to_yaml(msg.rx, out);
    out << ", ";
  }

  // member: ry
  {
    out << "ry: ";
    rosidl_generator_traits::value_to_yaml(msg.ry, out);
    out << ", ";
  }

  // member: a
  {
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << ", ";
  }

  // member: b
  {
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
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

  // member: lb
  {
    out << "lb: ";
    rosidl_generator_traits::value_to_yaml(msg.lb, out);
    out << ", ";
  }

  // member: rb
  {
    out << "rb: ";
    rosidl_generator_traits::value_to_yaml(msg.rb, out);
    out << ", ";
  }

  // member: lt
  {
    out << "lt: ";
    rosidl_generator_traits::value_to_yaml(msg.lt, out);
    out << ", ";
  }

  // member: rt
  {
    out << "rt: ";
    rosidl_generator_traits::value_to_yaml(msg.rt, out);
    out << ", ";
  }

  // member: ls
  {
    out << "ls: ";
    rosidl_generator_traits::value_to_yaml(msg.ls, out);
    out << ", ";
  }

  // member: rs
  {
    out << "rs: ";
    rosidl_generator_traits::value_to_yaml(msg.rs, out);
    out << ", ";
  }

  // member: back
  {
    out << "back: ";
    rosidl_generator_traits::value_to_yaml(msg.back, out);
    out << ", ";
  }

  // member: start
  {
    out << "start: ";
    rosidl_generator_traits::value_to_yaml(msg.start, out);
    out << ", ";
  }

  // member: hat_c
  {
    out << "hat_c: ";
    rosidl_generator_traits::value_to_yaml(msg.hat_c, out);
    out << ", ";
  }

  // member: hat_u
  {
    out << "hat_u: ";
    rosidl_generator_traits::value_to_yaml(msg.hat_u, out);
    out << ", ";
  }

  // member: hat_d
  {
    out << "hat_d: ";
    rosidl_generator_traits::value_to_yaml(msg.hat_d, out);
    out << ", ";
  }

  // member: hat_l
  {
    out << "hat_l: ";
    rosidl_generator_traits::value_to_yaml(msg.hat_l, out);
    out << ", ";
  }

  // member: hat_r
  {
    out << "hat_r: ";
    rosidl_generator_traits::value_to_yaml(msg.hat_r, out);
    out << ", ";
  }

  // member: hat_lu
  {
    out << "hat_lu: ";
    rosidl_generator_traits::value_to_yaml(msg.hat_lu, out);
    out << ", ";
  }

  // member: hat_ld
  {
    out << "hat_ld: ";
    rosidl_generator_traits::value_to_yaml(msg.hat_ld, out);
    out << ", ";
  }

  // member: hat_ru
  {
    out << "hat_ru: ";
    rosidl_generator_traits::value_to_yaml(msg.hat_ru, out);
    out << ", ";
  }

  // member: hat_rd
  {
    out << "hat_rd: ";
    rosidl_generator_traits::value_to_yaml(msg.hat_rd, out);
    out << ", ";
  }

  // member: hat_pos
  {
    out << "hat_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.hat_pos, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RemoteControllerState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: event
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "event: ";
    rosidl_generator_traits::value_to_yaml(msg.event, out);
    out << "\n";
  }

  // member: lx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lx: ";
    rosidl_generator_traits::value_to_yaml(msg.lx, out);
    out << "\n";
  }

  // member: ly
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ly: ";
    rosidl_generator_traits::value_to_yaml(msg.ly, out);
    out << "\n";
  }

  // member: rx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rx: ";
    rosidl_generator_traits::value_to_yaml(msg.rx, out);
    out << "\n";
  }

  // member: ry
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ry: ";
    rosidl_generator_traits::value_to_yaml(msg.ry, out);
    out << "\n";
  }

  // member: a
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << "\n";
  }

  // member: b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
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

  // member: lb
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lb: ";
    rosidl_generator_traits::value_to_yaml(msg.lb, out);
    out << "\n";
  }

  // member: rb
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rb: ";
    rosidl_generator_traits::value_to_yaml(msg.rb, out);
    out << "\n";
  }

  // member: lt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lt: ";
    rosidl_generator_traits::value_to_yaml(msg.lt, out);
    out << "\n";
  }

  // member: rt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rt: ";
    rosidl_generator_traits::value_to_yaml(msg.rt, out);
    out << "\n";
  }

  // member: ls
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ls: ";
    rosidl_generator_traits::value_to_yaml(msg.ls, out);
    out << "\n";
  }

  // member: rs
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rs: ";
    rosidl_generator_traits::value_to_yaml(msg.rs, out);
    out << "\n";
  }

  // member: back
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "back: ";
    rosidl_generator_traits::value_to_yaml(msg.back, out);
    out << "\n";
  }

  // member: start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start: ";
    rosidl_generator_traits::value_to_yaml(msg.start, out);
    out << "\n";
  }

  // member: hat_c
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hat_c: ";
    rosidl_generator_traits::value_to_yaml(msg.hat_c, out);
    out << "\n";
  }

  // member: hat_u
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hat_u: ";
    rosidl_generator_traits::value_to_yaml(msg.hat_u, out);
    out << "\n";
  }

  // member: hat_d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hat_d: ";
    rosidl_generator_traits::value_to_yaml(msg.hat_d, out);
    out << "\n";
  }

  // member: hat_l
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hat_l: ";
    rosidl_generator_traits::value_to_yaml(msg.hat_l, out);
    out << "\n";
  }

  // member: hat_r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hat_r: ";
    rosidl_generator_traits::value_to_yaml(msg.hat_r, out);
    out << "\n";
  }

  // member: hat_lu
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hat_lu: ";
    rosidl_generator_traits::value_to_yaml(msg.hat_lu, out);
    out << "\n";
  }

  // member: hat_ld
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hat_ld: ";
    rosidl_generator_traits::value_to_yaml(msg.hat_ld, out);
    out << "\n";
  }

  // member: hat_ru
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hat_ru: ";
    rosidl_generator_traits::value_to_yaml(msg.hat_ru, out);
    out << "\n";
  }

  // member: hat_rd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hat_rd: ";
    rosidl_generator_traits::value_to_yaml(msg.hat_rd, out);
    out << "\n";
  }

  // member: hat_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hat_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.hat_pos, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RemoteControllerState & msg, bool use_flow_style = false)
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
  const booster_interface::msg::RemoteControllerState & msg,
  std::ostream & out, size_t indentation = 0)
{
  booster_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use booster_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const booster_interface::msg::RemoteControllerState & msg)
{
  return booster_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<booster_interface::msg::RemoteControllerState>()
{
  return "booster_interface::msg::RemoteControllerState";
}

template<>
inline const char * name<booster_interface::msg::RemoteControllerState>()
{
  return "booster_interface/msg/RemoteControllerState";
}

template<>
struct has_fixed_size<booster_interface::msg::RemoteControllerState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<booster_interface::msg::RemoteControllerState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<booster_interface::msg::RemoteControllerState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__REMOTE_CONTROLLER_STATE__TRAITS_HPP_
