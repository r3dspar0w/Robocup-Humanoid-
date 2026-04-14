// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from game_controller_interface:msg/RobotInfo.idl
// generated code does not contain a copyright notice

#ifndef GAME_CONTROLLER_INTERFACE__MSG__DETAIL__ROBOT_INFO__BUILDER_HPP_
#define GAME_CONTROLLER_INTERFACE__MSG__DETAIL__ROBOT_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "game_controller_interface/msg/detail/robot_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace game_controller_interface
{

namespace msg
{

namespace builder
{

class Init_RobotInfo_goal_keeper
{
public:
  explicit Init_RobotInfo_goal_keeper(::game_controller_interface::msg::RobotInfo & msg)
  : msg_(msg)
  {}
  ::game_controller_interface::msg::RobotInfo goal_keeper(::game_controller_interface::msg::RobotInfo::_goal_keeper_type arg)
  {
    msg_.goal_keeper = std::move(arg);
    return std::move(msg_);
  }

private:
  ::game_controller_interface::msg::RobotInfo msg_;
};

class Init_RobotInfo_red_card_count
{
public:
  explicit Init_RobotInfo_red_card_count(::game_controller_interface::msg::RobotInfo & msg)
  : msg_(msg)
  {}
  Init_RobotInfo_goal_keeper red_card_count(::game_controller_interface::msg::RobotInfo::_red_card_count_type arg)
  {
    msg_.red_card_count = std::move(arg);
    return Init_RobotInfo_goal_keeper(msg_);
  }

private:
  ::game_controller_interface::msg::RobotInfo msg_;
};

class Init_RobotInfo_yellow_card_count
{
public:
  explicit Init_RobotInfo_yellow_card_count(::game_controller_interface::msg::RobotInfo & msg)
  : msg_(msg)
  {}
  Init_RobotInfo_red_card_count yellow_card_count(::game_controller_interface::msg::RobotInfo::_yellow_card_count_type arg)
  {
    msg_.yellow_card_count = std::move(arg);
    return Init_RobotInfo_red_card_count(msg_);
  }

private:
  ::game_controller_interface::msg::RobotInfo msg_;
};

class Init_RobotInfo_number_of_warnings
{
public:
  explicit Init_RobotInfo_number_of_warnings(::game_controller_interface::msg::RobotInfo & msg)
  : msg_(msg)
  {}
  Init_RobotInfo_yellow_card_count number_of_warnings(::game_controller_interface::msg::RobotInfo::_number_of_warnings_type arg)
  {
    msg_.number_of_warnings = std::move(arg);
    return Init_RobotInfo_yellow_card_count(msg_);
  }

private:
  ::game_controller_interface::msg::RobotInfo msg_;
};

class Init_RobotInfo_secs_till_unpenalised
{
public:
  explicit Init_RobotInfo_secs_till_unpenalised(::game_controller_interface::msg::RobotInfo & msg)
  : msg_(msg)
  {}
  Init_RobotInfo_number_of_warnings secs_till_unpenalised(::game_controller_interface::msg::RobotInfo::_secs_till_unpenalised_type arg)
  {
    msg_.secs_till_unpenalised = std::move(arg);
    return Init_RobotInfo_number_of_warnings(msg_);
  }

private:
  ::game_controller_interface::msg::RobotInfo msg_;
};

class Init_RobotInfo_penalty
{
public:
  Init_RobotInfo_penalty()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotInfo_secs_till_unpenalised penalty(::game_controller_interface::msg::RobotInfo::_penalty_type arg)
  {
    msg_.penalty = std::move(arg);
    return Init_RobotInfo_secs_till_unpenalised(msg_);
  }

private:
  ::game_controller_interface::msg::RobotInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::game_controller_interface::msg::RobotInfo>()
{
  return game_controller_interface::msg::builder::Init_RobotInfo_penalty();
}

}  // namespace game_controller_interface

#endif  // GAME_CONTROLLER_INTERFACE__MSG__DETAIL__ROBOT_INFO__BUILDER_HPP_
