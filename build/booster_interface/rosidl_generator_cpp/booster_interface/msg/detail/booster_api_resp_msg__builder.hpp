// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from booster_interface:msg/BoosterApiRespMsg.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__BOOSTER_API_RESP_MSG__BUILDER_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__BOOSTER_API_RESP_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "booster_interface/msg/detail/booster_api_resp_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace booster_interface
{

namespace msg
{

namespace builder
{

class Init_BoosterApiRespMsg_body
{
public:
  explicit Init_BoosterApiRespMsg_body(::booster_interface::msg::BoosterApiRespMsg & msg)
  : msg_(msg)
  {}
  ::booster_interface::msg::BoosterApiRespMsg body(::booster_interface::msg::BoosterApiRespMsg::_body_type arg)
  {
    msg_.body = std::move(arg);
    return std::move(msg_);
  }

private:
  ::booster_interface::msg::BoosterApiRespMsg msg_;
};

class Init_BoosterApiRespMsg_status
{
public:
  Init_BoosterApiRespMsg_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoosterApiRespMsg_body status(::booster_interface::msg::BoosterApiRespMsg::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_BoosterApiRespMsg_body(msg_);
  }

private:
  ::booster_interface::msg::BoosterApiRespMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::booster_interface::msg::BoosterApiRespMsg>()
{
  return booster_interface::msg::builder::Init_BoosterApiRespMsg_status();
}

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__BOOSTER_API_RESP_MSG__BUILDER_HPP_
