// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from booster_interface:msg/BoosterApiReqMsg.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__BOOSTER_API_REQ_MSG__BUILDER_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__BOOSTER_API_REQ_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "booster_interface/msg/detail/booster_api_req_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace booster_interface
{

namespace msg
{

namespace builder
{

class Init_BoosterApiReqMsg_body
{
public:
  explicit Init_BoosterApiReqMsg_body(::booster_interface::msg::BoosterApiReqMsg & msg)
  : msg_(msg)
  {}
  ::booster_interface::msg::BoosterApiReqMsg body(::booster_interface::msg::BoosterApiReqMsg::_body_type arg)
  {
    msg_.body = std::move(arg);
    return std::move(msg_);
  }

private:
  ::booster_interface::msg::BoosterApiReqMsg msg_;
};

class Init_BoosterApiReqMsg_api_id
{
public:
  Init_BoosterApiReqMsg_api_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoosterApiReqMsg_body api_id(::booster_interface::msg::BoosterApiReqMsg::_api_id_type arg)
  {
    msg_.api_id = std::move(arg);
    return Init_BoosterApiReqMsg_body(msg_);
  }

private:
  ::booster_interface::msg::BoosterApiReqMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::booster_interface::msg::BoosterApiReqMsg>()
{
  return booster_interface::msg::builder::Init_BoosterApiReqMsg_api_id();
}

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__BOOSTER_API_REQ_MSG__BUILDER_HPP_
