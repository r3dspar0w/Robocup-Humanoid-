// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from booster_interface:msg/FallDownState.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__FALL_DOWN_STATE__BUILDER_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__FALL_DOWN_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "booster_interface/msg/detail/fall_down_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace booster_interface
{

namespace msg
{

namespace builder
{

class Init_FallDownState_is_recovery_available
{
public:
  explicit Init_FallDownState_is_recovery_available(::booster_interface::msg::FallDownState & msg)
  : msg_(msg)
  {}
  ::booster_interface::msg::FallDownState is_recovery_available(::booster_interface::msg::FallDownState::_is_recovery_available_type arg)
  {
    msg_.is_recovery_available = std::move(arg);
    return std::move(msg_);
  }

private:
  ::booster_interface::msg::FallDownState msg_;
};

class Init_FallDownState_fall_down_state
{
public:
  Init_FallDownState_fall_down_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FallDownState_is_recovery_available fall_down_state(::booster_interface::msg::FallDownState::_fall_down_state_type arg)
  {
    msg_.fall_down_state = std::move(arg);
    return Init_FallDownState_is_recovery_available(msg_);
  }

private:
  ::booster_interface::msg::FallDownState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::booster_interface::msg::FallDownState>()
{
  return booster_interface::msg::builder::Init_FallDownState_fall_down_state();
}

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__FALL_DOWN_STATE__BUILDER_HPP_
