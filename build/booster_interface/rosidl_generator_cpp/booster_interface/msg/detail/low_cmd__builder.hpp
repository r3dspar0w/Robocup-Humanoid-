// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from booster_interface:msg/LowCmd.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__LOW_CMD__BUILDER_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__LOW_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "booster_interface/msg/detail/low_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace booster_interface
{

namespace msg
{

namespace builder
{

class Init_LowCmd_motor_cmd
{
public:
  explicit Init_LowCmd_motor_cmd(::booster_interface::msg::LowCmd & msg)
  : msg_(msg)
  {}
  ::booster_interface::msg::LowCmd motor_cmd(::booster_interface::msg::LowCmd::_motor_cmd_type arg)
  {
    msg_.motor_cmd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::booster_interface::msg::LowCmd msg_;
};

class Init_LowCmd_cmd_type
{
public:
  Init_LowCmd_cmd_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LowCmd_motor_cmd cmd_type(::booster_interface::msg::LowCmd::_cmd_type_type arg)
  {
    msg_.cmd_type = std::move(arg);
    return Init_LowCmd_motor_cmd(msg_);
  }

private:
  ::booster_interface::msg::LowCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::booster_interface::msg::LowCmd>()
{
  return booster_interface::msg::builder::Init_LowCmd_cmd_type();
}

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__LOW_CMD__BUILDER_HPP_
