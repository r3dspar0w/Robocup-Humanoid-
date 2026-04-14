// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from booster_interface:msg/RawBytesMsg.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__RAW_BYTES_MSG__BUILDER_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__RAW_BYTES_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "booster_interface/msg/detail/raw_bytes_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace booster_interface
{

namespace msg
{

namespace builder
{

class Init_RawBytesMsg_msg
{
public:
  Init_RawBytesMsg_msg()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::booster_interface::msg::RawBytesMsg msg(::booster_interface::msg::RawBytesMsg::_msg_type arg)
  {
    msg_.msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::booster_interface::msg::RawBytesMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::booster_interface::msg::RawBytesMsg>()
{
  return booster_interface::msg::builder::Init_RawBytesMsg_msg();
}

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__RAW_BYTES_MSG__BUILDER_HPP_
