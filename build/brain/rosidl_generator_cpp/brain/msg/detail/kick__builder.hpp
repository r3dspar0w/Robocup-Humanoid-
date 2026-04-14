// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from brain:msg/Kick.idl
// generated code does not contain a copyright notice

#ifndef BRAIN__MSG__DETAIL__KICK__BUILDER_HPP_
#define BRAIN__MSG__DETAIL__KICK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "brain/msg/detail/kick__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace brain
{

namespace msg
{

namespace builder
{

class Init_Kick_power
{
public:
  explicit Init_Kick_power(::brain::msg::Kick & msg)
  : msg_(msg)
  {}
  ::brain::msg::Kick power(::brain::msg::Kick::_power_type arg)
  {
    msg_.power = std::move(arg);
    return std::move(msg_);
  }

private:
  ::brain::msg::Kick msg_;
};

class Init_Kick_robot_theta_to_field
{
public:
  explicit Init_Kick_robot_theta_to_field(::brain::msg::Kick & msg)
  : msg_(msg)
  {}
  Init_Kick_power robot_theta_to_field(::brain::msg::Kick::_robot_theta_to_field_type arg)
  {
    msg_.robot_theta_to_field = std::move(arg);
    return Init_Kick_power(msg_);
  }

private:
  ::brain::msg::Kick msg_;
};

class Init_Kick_goal_y
{
public:
  explicit Init_Kick_goal_y(::brain::msg::Kick & msg)
  : msg_(msg)
  {}
  Init_Kick_robot_theta_to_field goal_y(::brain::msg::Kick::_goal_y_type arg)
  {
    msg_.goal_y = std::move(arg);
    return Init_Kick_robot_theta_to_field(msg_);
  }

private:
  ::brain::msg::Kick msg_;
};

class Init_Kick_goal_x
{
public:
  explicit Init_Kick_goal_x(::brain::msg::Kick & msg)
  : msg_(msg)
  {}
  Init_Kick_goal_y goal_x(::brain::msg::Kick::_goal_x_type arg)
  {
    msg_.goal_x = std::move(arg);
    return Init_Kick_goal_y(msg_);
  }

private:
  ::brain::msg::Kick msg_;
};

class Init_Kick_dir
{
public:
  explicit Init_Kick_dir(::brain::msg::Kick & msg)
  : msg_(msg)
  {}
  Init_Kick_goal_x dir(::brain::msg::Kick::_dir_type arg)
  {
    msg_.dir = std::move(arg);
    return Init_Kick_goal_x(msg_);
  }

private:
  ::brain::msg::Kick msg_;
};

class Init_Kick_y
{
public:
  explicit Init_Kick_y(::brain::msg::Kick & msg)
  : msg_(msg)
  {}
  Init_Kick_dir y(::brain::msg::Kick::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Kick_dir(msg_);
  }

private:
  ::brain::msg::Kick msg_;
};

class Init_Kick_x
{
public:
  explicit Init_Kick_x(::brain::msg::Kick & msg)
  : msg_(msg)
  {}
  Init_Kick_y x(::brain::msg::Kick::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Kick_y(msg_);
  }

private:
  ::brain::msg::Kick msg_;
};

class Init_Kick_header
{
public:
  Init_Kick_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Kick_x header(::brain::msg::Kick::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Kick_x(msg_);
  }

private:
  ::brain::msg::Kick msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::brain::msg::Kick>()
{
  return brain::msg::builder::Init_Kick_header();
}

}  // namespace brain

#endif  // BRAIN__MSG__DETAIL__KICK__BUILDER_HPP_
