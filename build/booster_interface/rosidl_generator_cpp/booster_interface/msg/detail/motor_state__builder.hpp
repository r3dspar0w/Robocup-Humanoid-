// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from booster_interface:msg/MotorState.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__MOTOR_STATE__BUILDER_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__MOTOR_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "booster_interface/msg/detail/motor_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace booster_interface
{

namespace msg
{

namespace builder
{

class Init_MotorState_reserve
{
public:
  explicit Init_MotorState_reserve(::booster_interface::msg::MotorState & msg)
  : msg_(msg)
  {}
  ::booster_interface::msg::MotorState reserve(::booster_interface::msg::MotorState::_reserve_type arg)
  {
    msg_.reserve = std::move(arg);
    return std::move(msg_);
  }

private:
  ::booster_interface::msg::MotorState msg_;
};

class Init_MotorState_lost
{
public:
  explicit Init_MotorState_lost(::booster_interface::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_reserve lost(::booster_interface::msg::MotorState::_lost_type arg)
  {
    msg_.lost = std::move(arg);
    return Init_MotorState_reserve(msg_);
  }

private:
  ::booster_interface::msg::MotorState msg_;
};

class Init_MotorState_temperature
{
public:
  explicit Init_MotorState_temperature(::booster_interface::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_lost temperature(::booster_interface::msg::MotorState::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return Init_MotorState_lost(msg_);
  }

private:
  ::booster_interface::msg::MotorState msg_;
};

class Init_MotorState_tau_est
{
public:
  explicit Init_MotorState_tau_est(::booster_interface::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_temperature tau_est(::booster_interface::msg::MotorState::_tau_est_type arg)
  {
    msg_.tau_est = std::move(arg);
    return Init_MotorState_temperature(msg_);
  }

private:
  ::booster_interface::msg::MotorState msg_;
};

class Init_MotorState_ddq
{
public:
  explicit Init_MotorState_ddq(::booster_interface::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_tau_est ddq(::booster_interface::msg::MotorState::_ddq_type arg)
  {
    msg_.ddq = std::move(arg);
    return Init_MotorState_tau_est(msg_);
  }

private:
  ::booster_interface::msg::MotorState msg_;
};

class Init_MotorState_dq
{
public:
  explicit Init_MotorState_dq(::booster_interface::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_ddq dq(::booster_interface::msg::MotorState::_dq_type arg)
  {
    msg_.dq = std::move(arg);
    return Init_MotorState_ddq(msg_);
  }

private:
  ::booster_interface::msg::MotorState msg_;
};

class Init_MotorState_q
{
public:
  explicit Init_MotorState_q(::booster_interface::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_dq q(::booster_interface::msg::MotorState::_q_type arg)
  {
    msg_.q = std::move(arg);
    return Init_MotorState_dq(msg_);
  }

private:
  ::booster_interface::msg::MotorState msg_;
};

class Init_MotorState_mode
{
public:
  Init_MotorState_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorState_q mode(::booster_interface::msg::MotorState::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_MotorState_q(msg_);
  }

private:
  ::booster_interface::msg::MotorState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::booster_interface::msg::MotorState>()
{
  return booster_interface::msg::builder::Init_MotorState_mode();
}

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__MOTOR_STATE__BUILDER_HPP_
