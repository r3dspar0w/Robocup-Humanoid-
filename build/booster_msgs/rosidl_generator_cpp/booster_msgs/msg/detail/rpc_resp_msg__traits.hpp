// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from booster_msgs:msg/RpcRespMsg.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_MSGS__MSG__DETAIL__RPC_RESP_MSG__TRAITS_HPP_
#define BOOSTER_MSGS__MSG__DETAIL__RPC_RESP_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "booster_msgs/msg/detail/rpc_resp_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace booster_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RpcRespMsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: uuid
  {
    out << "uuid: ";
    rosidl_generator_traits::value_to_yaml(msg.uuid, out);
    out << ", ";
  }

  // member: header
  {
    out << "header: ";
    rosidl_generator_traits::value_to_yaml(msg.header, out);
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
  const RpcRespMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: uuid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uuid: ";
    rosidl_generator_traits::value_to_yaml(msg.uuid, out);
    out << "\n";
  }

  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header: ";
    rosidl_generator_traits::value_to_yaml(msg.header, out);
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

inline std::string to_yaml(const RpcRespMsg & msg, bool use_flow_style = false)
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

}  // namespace booster_msgs

namespace rosidl_generator_traits
{

[[deprecated("use booster_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const booster_msgs::msg::RpcRespMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  booster_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use booster_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const booster_msgs::msg::RpcRespMsg & msg)
{
  return booster_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<booster_msgs::msg::RpcRespMsg>()
{
  return "booster_msgs::msg::RpcRespMsg";
}

template<>
inline const char * name<booster_msgs::msg::RpcRespMsg>()
{
  return "booster_msgs/msg/RpcRespMsg";
}

template<>
struct has_fixed_size<booster_msgs::msg::RpcRespMsg>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<booster_msgs::msg::RpcRespMsg>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<booster_msgs::msg::RpcRespMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BOOSTER_MSGS__MSG__DETAIL__RPC_RESP_MSG__TRAITS_HPP_
