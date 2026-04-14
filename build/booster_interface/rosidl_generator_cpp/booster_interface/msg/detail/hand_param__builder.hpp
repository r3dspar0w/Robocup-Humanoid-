// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from booster_interface:msg/HandParam.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__HAND_PARAM__BUILDER_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__HAND_PARAM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "booster_interface/msg/detail/hand_param__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace booster_interface
{

namespace msg
{

namespace builder
{

class Init_HandParam_seq
{
public:
  explicit Init_HandParam_seq(::booster_interface::msg::HandParam & msg)
  : msg_(msg)
  {}
  ::booster_interface::msg::HandParam seq(::booster_interface::msg::HandParam::_seq_type arg)
  {
    msg_.seq = std::move(arg);
    return std::move(msg_);
  }

private:
  ::booster_interface::msg::HandParam msg_;
};

class Init_HandParam_speed
{
public:
  explicit Init_HandParam_speed(::booster_interface::msg::HandParam & msg)
  : msg_(msg)
  {}
  Init_HandParam_seq speed(::booster_interface::msg::HandParam::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_HandParam_seq(msg_);
  }

private:
  ::booster_interface::msg::HandParam msg_;
};

class Init_HandParam_force
{
public:
  explicit Init_HandParam_force(::booster_interface::msg::HandParam & msg)
  : msg_(msg)
  {}
  Init_HandParam_speed force(::booster_interface::msg::HandParam::_force_type arg)
  {
    msg_.force = std::move(arg);
    return Init_HandParam_speed(msg_);
  }

private:
  ::booster_interface::msg::HandParam msg_;
};

class Init_HandParam_angle
{
public:
  Init_HandParam_angle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HandParam_force angle(::booster_interface::msg::HandParam::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return Init_HandParam_force(msg_);
  }

private:
  ::booster_interface::msg::HandParam msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::booster_interface::msg::HandParam>()
{
  return booster_interface::msg::builder::Init_HandParam_angle();
}

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__HAND_PARAM__BUILDER_HPP_
