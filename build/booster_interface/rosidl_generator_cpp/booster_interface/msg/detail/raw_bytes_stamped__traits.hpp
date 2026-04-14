// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from booster_interface:msg/RawBytesStamped.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__RAW_BYTES_STAMPED__TRAITS_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__RAW_BYTES_STAMPED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "booster_interface/msg/detail/raw_bytes_stamped__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace booster_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const RawBytesStamped & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: msg
  {
    if (msg.msg.size() == 0) {
      out << "msg: []";
    } else {
      out << "msg: [";
      size_t pending_items = msg.msg.size();
      for (auto item : msg.msg) {
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
  const RawBytesStamped & msg,
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

  // member: msg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.msg.size() == 0) {
      out << "msg: []\n";
    } else {
      out << "msg:\n";
      for (auto item : msg.msg) {
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

inline std::string to_yaml(const RawBytesStamped & msg, bool use_flow_style = false)
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
  const booster_interface::msg::RawBytesStamped & msg,
  std::ostream & out, size_t indentation = 0)
{
  booster_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use booster_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const booster_interface::msg::RawBytesStamped & msg)
{
  return booster_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<booster_interface::msg::RawBytesStamped>()
{
  return "booster_interface::msg::RawBytesStamped";
}

template<>
inline const char * name<booster_interface::msg::RawBytesStamped>()
{
  return "booster_interface/msg/RawBytesStamped";
}

template<>
struct has_fixed_size<booster_interface::msg::RawBytesStamped>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<booster_interface::msg::RawBytesStamped>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<booster_interface::msg::RawBytesStamped>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__RAW_BYTES_STAMPED__TRAITS_HPP_
