// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from booster_interface:msg/BoosterApiReqMsg.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__BOOSTER_API_REQ_MSG__TRAITS_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__BOOSTER_API_REQ_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "booster_interface/msg/detail/booster_api_req_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace booster_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const BoosterApiReqMsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: api_id
  {
    out << "api_id: ";
    rosidl_generator_traits::value_to_yaml(msg.api_id, out);
    out << ", ";
  }

  // member: body
  {
    out << "body: ";
    rosidl_generator_traits::value_to_yaml(msg.body, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BoosterApiReqMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: api_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "api_id: ";
    rosidl_generator_traits::value_to_yaml(msg.api_id, out);
    out << "\n";
  }

  // member: body
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "body: ";
    rosidl_generator_traits::value_to_yaml(msg.body, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BoosterApiReqMsg & msg, bool use_flow_style = false)
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
  const booster_interface::msg::BoosterApiReqMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  booster_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use booster_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const booster_interface::msg::BoosterApiReqMsg & msg)
{
  return booster_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<booster_interface::msg::BoosterApiReqMsg>()
{
  return "booster_interface::msg::BoosterApiReqMsg";
}

template<>
inline const char * name<booster_interface::msg::BoosterApiReqMsg>()
{
  return "booster_interface/msg/BoosterApiReqMsg";
}

template<>
struct has_fixed_size<booster_interface::msg::BoosterApiReqMsg>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<booster_interface::msg::BoosterApiReqMsg>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<booster_interface::msg::BoosterApiReqMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__BOOSTER_API_REQ_MSG__TRAITS_HPP_
