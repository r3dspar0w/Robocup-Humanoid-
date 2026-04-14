// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from booster_interface:msg/HandDdsMsg.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__HAND_DDS_MSG__TRAITS_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__HAND_DDS_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "booster_interface/msg/detail/hand_dds_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'hands_vec'
#include "booster_interface/msg/detail/hand_command__traits.hpp"

namespace booster_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const HandDdsMsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: hands_vec
  {
    if (msg.hands_vec.size() == 0) {
      out << "hands_vec: []";
    } else {
      out << "hands_vec: [";
      size_t pending_items = msg.hands_vec.size();
      for (auto item : msg.hands_vec) {
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
  const HandDdsMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: hands_vec
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.hands_vec.size() == 0) {
      out << "hands_vec: []\n";
    } else {
      out << "hands_vec:\n";
      for (auto item : msg.hands_vec) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HandDdsMsg & msg, bool use_flow_style = false)
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
  const booster_interface::msg::HandDdsMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  booster_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use booster_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const booster_interface::msg::HandDdsMsg & msg)
{
  return booster_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<booster_interface::msg::HandDdsMsg>()
{
  return "booster_interface::msg::HandDdsMsg";
}

template<>
inline const char * name<booster_interface::msg::HandDdsMsg>()
{
  return "booster_interface/msg/HandDdsMsg";
}

template<>
struct has_fixed_size<booster_interface::msg::HandDdsMsg>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<booster_interface::msg::HandDdsMsg>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<booster_interface::msg::HandDdsMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__HAND_DDS_MSG__TRAITS_HPP_
