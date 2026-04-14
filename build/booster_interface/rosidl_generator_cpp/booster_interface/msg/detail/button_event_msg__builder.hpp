// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from booster_interface:msg/ButtonEventMsg.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__BUTTON_EVENT_MSG__BUILDER_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__BUTTON_EVENT_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "booster_interface/msg/detail/button_event_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace booster_interface
{

namespace msg
{

namespace builder
{

class Init_ButtonEventMsg_button
{
public:
  explicit Init_ButtonEventMsg_button(::booster_interface::msg::ButtonEventMsg & msg)
  : msg_(msg)
  {}
  ::booster_interface::msg::ButtonEventMsg button(::booster_interface::msg::ButtonEventMsg::_button_type arg)
  {
    msg_.button = std::move(arg);
    return std::move(msg_);
  }

private:
  ::booster_interface::msg::ButtonEventMsg msg_;
};

class Init_ButtonEventMsg_event
{
public:
  Init_ButtonEventMsg_event()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ButtonEventMsg_button event(::booster_interface::msg::ButtonEventMsg::_event_type arg)
  {
    msg_.event = std::move(arg);
    return Init_ButtonEventMsg_button(msg_);
  }

private:
  ::booster_interface::msg::ButtonEventMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::booster_interface::msg::ButtonEventMsg>()
{
  return booster_interface::msg::builder::Init_ButtonEventMsg_event();
}

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__BUTTON_EVENT_MSG__BUILDER_HPP_
