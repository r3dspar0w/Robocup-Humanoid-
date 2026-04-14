// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from booster_interface:msg/ImuState.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__IMU_STATE__BUILDER_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__IMU_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "booster_interface/msg/detail/imu_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace booster_interface
{

namespace msg
{

namespace builder
{

class Init_ImuState_acc
{
public:
  explicit Init_ImuState_acc(::booster_interface::msg::ImuState & msg)
  : msg_(msg)
  {}
  ::booster_interface::msg::ImuState acc(::booster_interface::msg::ImuState::_acc_type arg)
  {
    msg_.acc = std::move(arg);
    return std::move(msg_);
  }

private:
  ::booster_interface::msg::ImuState msg_;
};

class Init_ImuState_gyro
{
public:
  explicit Init_ImuState_gyro(::booster_interface::msg::ImuState & msg)
  : msg_(msg)
  {}
  Init_ImuState_acc gyro(::booster_interface::msg::ImuState::_gyro_type arg)
  {
    msg_.gyro = std::move(arg);
    return Init_ImuState_acc(msg_);
  }

private:
  ::booster_interface::msg::ImuState msg_;
};

class Init_ImuState_rpy
{
public:
  Init_ImuState_rpy()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImuState_gyro rpy(::booster_interface::msg::ImuState::_rpy_type arg)
  {
    msg_.rpy = std::move(arg);
    return Init_ImuState_gyro(msg_);
  }

private:
  ::booster_interface::msg::ImuState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::booster_interface::msg::ImuState>()
{
  return booster_interface::msg::builder::Init_ImuState_rpy();
}

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__IMU_STATE__BUILDER_HPP_
