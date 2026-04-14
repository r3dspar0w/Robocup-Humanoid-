// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from booster_interface:srv/RpcService.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__SRV__DETAIL__RPC_SERVICE__TRAITS_HPP_
#define BOOSTER_INTERFACE__SRV__DETAIL__RPC_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "booster_interface/srv/detail/rpc_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'msg'
#include "booster_interface/msg/detail/booster_api_req_msg__traits.hpp"

namespace booster_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const RpcService_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: msg
  {
    out << "msg: ";
    to_flow_style_yaml(msg.msg, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RpcService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: msg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "msg:\n";
    to_block_style_yaml(msg.msg, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RpcService_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace booster_interface

namespace rosidl_generator_traits
{

[[deprecated("use booster_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const booster_interface::srv::RpcService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  booster_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use booster_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const booster_interface::srv::RpcService_Request & msg)
{
  return booster_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<booster_interface::srv::RpcService_Request>()
{
  return "booster_interface::srv::RpcService_Request";
}

template<>
inline const char * name<booster_interface::srv::RpcService_Request>()
{
  return "booster_interface/srv/RpcService_Request";
}

template<>
struct has_fixed_size<booster_interface::srv::RpcService_Request>
  : std::integral_constant<bool, has_fixed_size<booster_interface::msg::BoosterApiReqMsg>::value> {};

template<>
struct has_bounded_size<booster_interface::srv::RpcService_Request>
  : std::integral_constant<bool, has_bounded_size<booster_interface::msg::BoosterApiReqMsg>::value> {};

template<>
struct is_message<booster_interface::srv::RpcService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'msg'
#include "booster_interface/msg/detail/booster_api_resp_msg__traits.hpp"

namespace booster_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const RpcService_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: msg
  {
    out << "msg: ";
    to_flow_style_yaml(msg.msg, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RpcService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: msg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "msg:\n";
    to_block_style_yaml(msg.msg, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RpcService_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace booster_interface

namespace rosidl_generator_traits
{

[[deprecated("use booster_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const booster_interface::srv::RpcService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  booster_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use booster_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const booster_interface::srv::RpcService_Response & msg)
{
  return booster_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<booster_interface::srv::RpcService_Response>()
{
  return "booster_interface::srv::RpcService_Response";
}

template<>
inline const char * name<booster_interface::srv::RpcService_Response>()
{
  return "booster_interface/srv/RpcService_Response";
}

template<>
struct has_fixed_size<booster_interface::srv::RpcService_Response>
  : std::integral_constant<bool, has_fixed_size<booster_interface::msg::BoosterApiRespMsg>::value> {};

template<>
struct has_bounded_size<booster_interface::srv::RpcService_Response>
  : std::integral_constant<bool, has_bounded_size<booster_interface::msg::BoosterApiRespMsg>::value> {};

template<>
struct is_message<booster_interface::srv::RpcService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<booster_interface::srv::RpcService>()
{
  return "booster_interface::srv::RpcService";
}

template<>
inline const char * name<booster_interface::srv::RpcService>()
{
  return "booster_interface/srv/RpcService";
}

template<>
struct has_fixed_size<booster_interface::srv::RpcService>
  : std::integral_constant<
    bool,
    has_fixed_size<booster_interface::srv::RpcService_Request>::value &&
    has_fixed_size<booster_interface::srv::RpcService_Response>::value
  >
{
};

template<>
struct has_bounded_size<booster_interface::srv::RpcService>
  : std::integral_constant<
    bool,
    has_bounded_size<booster_interface::srv::RpcService_Request>::value &&
    has_bounded_size<booster_interface::srv::RpcService_Response>::value
  >
{
};

template<>
struct is_service<booster_interface::srv::RpcService>
  : std::true_type
{
};

template<>
struct is_service_request<booster_interface::srv::RpcService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<booster_interface::srv::RpcService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // BOOSTER_INTERFACE__SRV__DETAIL__RPC_SERVICE__TRAITS_HPP_
