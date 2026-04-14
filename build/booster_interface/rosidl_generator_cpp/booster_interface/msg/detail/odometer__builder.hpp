// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from booster_interface:msg/Odometer.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__ODOMETER__BUILDER_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__ODOMETER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "booster_interface/msg/detail/odometer__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace booster_interface
{

namespace msg
{

namespace builder
{

class Init_Odometer_theta
{
public:
  explicit Init_Odometer_theta(::booster_interface::msg::Odometer & msg)
  : msg_(msg)
  {}
  ::booster_interface::msg::Odometer theta(::booster_interface::msg::Odometer::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::booster_interface::msg::Odometer msg_;
};

class Init_Odometer_y
{
public:
  explicit Init_Odometer_y(::booster_interface::msg::Odometer & msg)
  : msg_(msg)
  {}
  Init_Odometer_theta y(::booster_interface::msg::Odometer::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Odometer_theta(msg_);
  }

private:
  ::booster_interface::msg::Odometer msg_;
};

class Init_Odometer_x
{
public:
  Init_Odometer_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Odometer_y x(::booster_interface::msg::Odometer::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Odometer_y(msg_);
  }

private:
  ::booster_interface::msg::Odometer msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::booster_interface::msg::Odometer>()
{
  return booster_interface::msg::builder::Init_Odometer_x();
}

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__ODOMETER__BUILDER_HPP_
