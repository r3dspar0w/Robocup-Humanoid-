// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vision_interface:msg/Ball.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__BALL__BUILDER_HPP_
#define VISION_INTERFACE__MSG__DETAIL__BALL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vision_interface/msg/detail/ball__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vision_interface
{

namespace msg
{

namespace builder
{

class Init_Ball_confidence
{
public:
  explicit Init_Ball_confidence(::vision_interface::msg::Ball & msg)
  : msg_(msg)
  {}
  ::vision_interface::msg::Ball confidence(::vision_interface::msg::Ball::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vision_interface::msg::Ball msg_;
};

class Init_Ball_y
{
public:
  explicit Init_Ball_y(::vision_interface::msg::Ball & msg)
  : msg_(msg)
  {}
  Init_Ball_confidence y(::vision_interface::msg::Ball::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Ball_confidence(msg_);
  }

private:
  ::vision_interface::msg::Ball msg_;
};

class Init_Ball_x
{
public:
  explicit Init_Ball_x(::vision_interface::msg::Ball & msg)
  : msg_(msg)
  {}
  Init_Ball_y x(::vision_interface::msg::Ball::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Ball_y(msg_);
  }

private:
  ::vision_interface::msg::Ball msg_;
};

class Init_Ball_header
{
public:
  Init_Ball_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Ball_x header(::vision_interface::msg::Ball::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Ball_x(msg_);
  }

private:
  ::vision_interface::msg::Ball msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vision_interface::msg::Ball>()
{
  return vision_interface::msg::builder::Init_Ball_header();
}

}  // namespace vision_interface

#endif  // VISION_INTERFACE__MSG__DETAIL__BALL__BUILDER_HPP_
