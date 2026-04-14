// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from booster_interface:srv/AgentService.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__SRV__DETAIL__AGENT_SERVICE__BUILDER_HPP_
#define BOOSTER_INTERFACE__SRV__DETAIL__AGENT_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "booster_interface/srv/detail/agent_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace booster_interface
{

namespace srv
{

namespace builder
{

class Init_AgentService_Request_body
{
public:
  Init_AgentService_Request_body()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::booster_interface::srv::AgentService_Request body(::booster_interface::srv::AgentService_Request::_body_type arg)
  {
    msg_.body = std::move(arg);
    return std::move(msg_);
  }

private:
  ::booster_interface::srv::AgentService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::booster_interface::srv::AgentService_Request>()
{
  return booster_interface::srv::builder::Init_AgentService_Request_body();
}

}  // namespace booster_interface


namespace booster_interface
{

namespace srv
{

namespace builder
{

class Init_AgentService_Response_body
{
public:
  Init_AgentService_Response_body()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::booster_interface::srv::AgentService_Response body(::booster_interface::srv::AgentService_Response::_body_type arg)
  {
    msg_.body = std::move(arg);
    return std::move(msg_);
  }

private:
  ::booster_interface::srv::AgentService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::booster_interface::srv::AgentService_Response>()
{
  return booster_interface::srv::builder::Init_AgentService_Response_body();
}

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__SRV__DETAIL__AGENT_SERVICE__BUILDER_HPP_
