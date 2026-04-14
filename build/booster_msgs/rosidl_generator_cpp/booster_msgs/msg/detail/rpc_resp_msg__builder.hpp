// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from booster_msgs:msg/RpcRespMsg.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_MSGS__MSG__DETAIL__RPC_RESP_MSG__BUILDER_HPP_
#define BOOSTER_MSGS__MSG__DETAIL__RPC_RESP_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "booster_msgs/msg/detail/rpc_resp_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace booster_msgs
{

namespace msg
{

namespace builder
{

class Init_RpcRespMsg_body
{
public:
  explicit Init_RpcRespMsg_body(::booster_msgs::msg::RpcRespMsg & msg)
  : msg_(msg)
  {}
  ::booster_msgs::msg::RpcRespMsg body(::booster_msgs::msg::RpcRespMsg::_body_type arg)
  {
    msg_.body = std::move(arg);
    return std::move(msg_);
  }

private:
  ::booster_msgs::msg::RpcRespMsg msg_;
};

class Init_RpcRespMsg_header
{
public:
  explicit Init_RpcRespMsg_header(::booster_msgs::msg::RpcRespMsg & msg)
  : msg_(msg)
  {}
  Init_RpcRespMsg_body header(::booster_msgs::msg::RpcRespMsg::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RpcRespMsg_body(msg_);
  }

private:
  ::booster_msgs::msg::RpcRespMsg msg_;
};

class Init_RpcRespMsg_uuid
{
public:
  Init_RpcRespMsg_uuid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RpcRespMsg_header uuid(::booster_msgs::msg::RpcRespMsg::_uuid_type arg)
  {
    msg_.uuid = std::move(arg);
    return Init_RpcRespMsg_header(msg_);
  }

private:
  ::booster_msgs::msg::RpcRespMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::booster_msgs::msg::RpcRespMsg>()
{
  return booster_msgs::msg::builder::Init_RpcRespMsg_uuid();
}

}  // namespace booster_msgs

#endif  // BOOSTER_MSGS__MSG__DETAIL__RPC_RESP_MSG__BUILDER_HPP_
