// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from booster_interface:srv/RpcService.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__SRV__DETAIL__RPC_SERVICE__BUILDER_HPP_
#define BOOSTER_INTERFACE__SRV__DETAIL__RPC_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "booster_interface/srv/detail/rpc_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace booster_interface
{

namespace srv
{

namespace builder
{

class Init_RpcService_Request_msg
{
public:
  Init_RpcService_Request_msg()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::booster_interface::srv::RpcService_Request msg(::booster_interface::srv::RpcService_Request::_msg_type arg)
  {
    msg_.msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::booster_interface::srv::RpcService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::booster_interface::srv::RpcService_Request>()
{
  return booster_interface::srv::builder::Init_RpcService_Request_msg();
}

}  // namespace booster_interface


namespace booster_interface
{

namespace srv
{

namespace builder
{

class Init_RpcService_Response_msg
{
public:
  Init_RpcService_Response_msg()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::booster_interface::srv::RpcService_Response msg(::booster_interface::srv::RpcService_Response::_msg_type arg)
  {
    msg_.msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::booster_interface::srv::RpcService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::booster_interface::srv::RpcService_Response>()
{
  return booster_interface::srv::builder::Init_RpcService_Response_msg();
}

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__SRV__DETAIL__RPC_SERVICE__BUILDER_HPP_
