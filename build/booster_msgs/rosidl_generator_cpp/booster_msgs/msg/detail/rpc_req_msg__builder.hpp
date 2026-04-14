// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from booster_msgs:msg/RpcReqMsg.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_MSGS__MSG__DETAIL__RPC_REQ_MSG__BUILDER_HPP_
#define BOOSTER_MSGS__MSG__DETAIL__RPC_REQ_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "booster_msgs/msg/detail/rpc_req_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace booster_msgs
{

namespace msg
{

namespace builder
{

class Init_RpcReqMsg_body
{
public:
  explicit Init_RpcReqMsg_body(::booster_msgs::msg::RpcReqMsg & msg)
  : msg_(msg)
  {}
  ::booster_msgs::msg::RpcReqMsg body(::booster_msgs::msg::RpcReqMsg::_body_type arg)
  {
    msg_.body = std::move(arg);
    return std::move(msg_);
  }

private:
  ::booster_msgs::msg::RpcReqMsg msg_;
};

class Init_RpcReqMsg_header
{
public:
  explicit Init_RpcReqMsg_header(::booster_msgs::msg::RpcReqMsg & msg)
  : msg_(msg)
  {}
  Init_RpcReqMsg_body header(::booster_msgs::msg::RpcReqMsg::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RpcReqMsg_body(msg_);
  }

private:
  ::booster_msgs::msg::RpcReqMsg msg_;
};

class Init_RpcReqMsg_uuid
{
public:
  Init_RpcReqMsg_uuid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RpcReqMsg_header uuid(::booster_msgs::msg::RpcReqMsg::_uuid_type arg)
  {
    msg_.uuid = std::move(arg);
    return Init_RpcReqMsg_header(msg_);
  }

private:
  ::booster_msgs::msg::RpcReqMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::booster_msgs::msg::RpcReqMsg>()
{
  return booster_msgs::msg::builder::Init_RpcReqMsg_uuid();
}

}  // namespace booster_msgs

#endif  // BOOSTER_MSGS__MSG__DETAIL__RPC_REQ_MSG__BUILDER_HPP_
