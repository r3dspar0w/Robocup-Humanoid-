// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from booster_interface:msg/LowState.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__LOW_STATE__BUILDER_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__LOW_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "booster_interface/msg/detail/low_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace booster_interface
{

namespace msg
{

namespace builder
{

class Init_LowState_motor_state_serial
{
public:
  explicit Init_LowState_motor_state_serial(::booster_interface::msg::LowState & msg)
  : msg_(msg)
  {}
  ::booster_interface::msg::LowState motor_state_serial(::booster_interface::msg::LowState::_motor_state_serial_type arg)
  {
    msg_.motor_state_serial = std::move(arg);
    return std::move(msg_);
  }

private:
  ::booster_interface::msg::LowState msg_;
};

class Init_LowState_motor_state_parallel
{
public:
  explicit Init_LowState_motor_state_parallel(::booster_interface::msg::LowState & msg)
  : msg_(msg)
  {}
  Init_LowState_motor_state_serial motor_state_parallel(::booster_interface::msg::LowState::_motor_state_parallel_type arg)
  {
    msg_.motor_state_parallel = std::move(arg);
    return Init_LowState_motor_state_serial(msg_);
  }

private:
  ::booster_interface::msg::LowState msg_;
};

class Init_LowState_imu_state
{
public:
  Init_LowState_imu_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LowState_motor_state_parallel imu_state(::booster_interface::msg::LowState::_imu_state_type arg)
  {
    msg_.imu_state = std::move(arg);
    return Init_LowState_motor_state_parallel(msg_);
  }

private:
  ::booster_interface::msg::LowState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::booster_interface::msg::LowState>()
{
  return booster_interface::msg::builder::Init_LowState_imu_state();
}

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__LOW_STATE__BUILDER_HPP_
