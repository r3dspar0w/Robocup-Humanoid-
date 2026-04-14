// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from booster_interface:msg/HandCommand.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__HAND_COMMAND__BUILDER_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__HAND_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "booster_interface/msg/detail/hand_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace booster_interface
{

namespace msg
{

namespace builder
{

class Init_HandCommand_hand_type
{
public:
  explicit Init_HandCommand_hand_type(::booster_interface::msg::HandCommand & msg)
  : msg_(msg)
  {}
  ::booster_interface::msg::HandCommand hand_type(::booster_interface::msg::HandCommand::_hand_type_type arg)
  {
    msg_.hand_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::booster_interface::msg::HandCommand msg_;
};

class Init_HandCommand_hand_index
{
public:
  explicit Init_HandCommand_hand_index(::booster_interface::msg::HandCommand & msg)
  : msg_(msg)
  {}
  Init_HandCommand_hand_type hand_index(::booster_interface::msg::HandCommand::_hand_index_type arg)
  {
    msg_.hand_index = std::move(arg);
    return Init_HandCommand_hand_type(msg_);
  }

private:
  ::booster_interface::msg::HandCommand msg_;
};

class Init_HandCommand_force_mode
{
public:
  explicit Init_HandCommand_force_mode(::booster_interface::msg::HandCommand & msg)
  : msg_(msg)
  {}
  Init_HandCommand_hand_index force_mode(::booster_interface::msg::HandCommand::_force_mode_type arg)
  {
    msg_.force_mode = std::move(arg);
    return Init_HandCommand_hand_index(msg_);
  }

private:
  ::booster_interface::msg::HandCommand msg_;
};

class Init_HandCommand_hand_param
{
public:
  Init_HandCommand_hand_param()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HandCommand_force_mode hand_param(::booster_interface::msg::HandCommand::_hand_param_type arg)
  {
    msg_.hand_param = std::move(arg);
    return Init_HandCommand_force_mode(msg_);
  }

private:
  ::booster_interface::msg::HandCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::booster_interface::msg::HandCommand>()
{
  return booster_interface::msg::builder::Init_HandCommand_hand_param();
}

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__HAND_COMMAND__BUILDER_HPP_
