// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from booster_interface:srv/AgentService.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__SRV__DETAIL__AGENT_SERVICE__TRAITS_HPP_
#define BOOSTER_INTERFACE__SRV__DETAIL__AGENT_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "booster_interface/srv/detail/agent_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace booster_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const AgentService_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: body
  {
    out << "body: ";
    rosidl_generator_traits::value_to_yaml(msg.body, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AgentService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
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

inline std::string to_yaml(const AgentService_Request & msg, bool use_flow_style = false)
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
  const booster_interface::srv::AgentService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  booster_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use booster_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const booster_interface::srv::AgentService_Request & msg)
{
  return booster_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<booster_interface::srv::AgentService_Request>()
{
  return "booster_interface::srv::AgentService_Request";
}

template<>
inline const char * name<booster_interface::srv::AgentService_Request>()
{
  return "booster_interface/srv/AgentService_Request";
}

template<>
struct has_fixed_size<booster_interface::srv::AgentService_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<booster_interface::srv::AgentService_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<booster_interface::srv::AgentService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace booster_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const AgentService_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: body
  {
    out << "body: ";
    rosidl_generator_traits::value_to_yaml(msg.body, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AgentService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
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

inline std::string to_yaml(const AgentService_Response & msg, bool use_flow_style = false)
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
  const booster_interface::srv::AgentService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  booster_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use booster_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const booster_interface::srv::AgentService_Response & msg)
{
  return booster_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<booster_interface::srv::AgentService_Response>()
{
  return "booster_interface::srv::AgentService_Response";
}

template<>
inline const char * name<booster_interface::srv::AgentService_Response>()
{
  return "booster_interface/srv/AgentService_Response";
}

template<>
struct has_fixed_size<booster_interface::srv::AgentService_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<booster_interface::srv::AgentService_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<booster_interface::srv::AgentService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<booster_interface::srv::AgentService>()
{
  return "booster_interface::srv::AgentService";
}

template<>
inline const char * name<booster_interface::srv::AgentService>()
{
  return "booster_interface/srv/AgentService";
}

template<>
struct has_fixed_size<booster_interface::srv::AgentService>
  : std::integral_constant<
    bool,
    has_fixed_size<booster_interface::srv::AgentService_Request>::value &&
    has_fixed_size<booster_interface::srv::AgentService_Response>::value
  >
{
};

template<>
struct has_bounded_size<booster_interface::srv::AgentService>
  : std::integral_constant<
    bool,
    has_bounded_size<booster_interface::srv::AgentService_Request>::value &&
    has_bounded_size<booster_interface::srv::AgentService_Response>::value
  >
{
};

template<>
struct is_service<booster_interface::srv::AgentService>
  : std::true_type
{
};

template<>
struct is_service_request<booster_interface::srv::AgentService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<booster_interface::srv::AgentService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // BOOSTER_INTERFACE__SRV__DETAIL__AGENT_SERVICE__TRAITS_HPP_
