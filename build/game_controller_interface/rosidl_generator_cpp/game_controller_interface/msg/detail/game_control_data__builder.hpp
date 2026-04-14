// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from game_controller_interface:msg/GameControlData.idl
// generated code does not contain a copyright notice

#ifndef GAME_CONTROLLER_INTERFACE__MSG__DETAIL__GAME_CONTROL_DATA__BUILDER_HPP_
#define GAME_CONTROLLER_INTERFACE__MSG__DETAIL__GAME_CONTROL_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "game_controller_interface/msg/detail/game_control_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace game_controller_interface
{

namespace msg
{

namespace builder
{

class Init_GameControlData_teams
{
public:
  explicit Init_GameControlData_teams(::game_controller_interface::msg::GameControlData & msg)
  : msg_(msg)
  {}
  ::game_controller_interface::msg::GameControlData teams(::game_controller_interface::msg::GameControlData::_teams_type arg)
  {
    msg_.teams = std::move(arg);
    return std::move(msg_);
  }

private:
  ::game_controller_interface::msg::GameControlData msg_;
};

class Init_GameControlData_secondary_time
{
public:
  explicit Init_GameControlData_secondary_time(::game_controller_interface::msg::GameControlData & msg)
  : msg_(msg)
  {}
  Init_GameControlData_teams secondary_time(::game_controller_interface::msg::GameControlData::_secondary_time_type arg)
  {
    msg_.secondary_time = std::move(arg);
    return Init_GameControlData_teams(msg_);
  }

private:
  ::game_controller_interface::msg::GameControlData msg_;
};

class Init_GameControlData_secs_remaining
{
public:
  explicit Init_GameControlData_secs_remaining(::game_controller_interface::msg::GameControlData & msg)
  : msg_(msg)
  {}
  Init_GameControlData_secondary_time secs_remaining(::game_controller_interface::msg::GameControlData::_secs_remaining_type arg)
  {
    msg_.secs_remaining = std::move(arg);
    return Init_GameControlData_secondary_time(msg_);
  }

private:
  ::game_controller_interface::msg::GameControlData msg_;
};

class Init_GameControlData_drop_in_time
{
public:
  explicit Init_GameControlData_drop_in_time(::game_controller_interface::msg::GameControlData & msg)
  : msg_(msg)
  {}
  Init_GameControlData_secs_remaining drop_in_time(::game_controller_interface::msg::GameControlData::_drop_in_time_type arg)
  {
    msg_.drop_in_time = std::move(arg);
    return Init_GameControlData_secs_remaining(msg_);
  }

private:
  ::game_controller_interface::msg::GameControlData msg_;
};

class Init_GameControlData_drop_in_team
{
public:
  explicit Init_GameControlData_drop_in_team(::game_controller_interface::msg::GameControlData & msg)
  : msg_(msg)
  {}
  Init_GameControlData_drop_in_time drop_in_team(::game_controller_interface::msg::GameControlData::_drop_in_team_type arg)
  {
    msg_.drop_in_team = std::move(arg);
    return Init_GameControlData_drop_in_time(msg_);
  }

private:
  ::game_controller_interface::msg::GameControlData msg_;
};

class Init_GameControlData_secondary_state_info
{
public:
  explicit Init_GameControlData_secondary_state_info(::game_controller_interface::msg::GameControlData & msg)
  : msg_(msg)
  {}
  Init_GameControlData_drop_in_team secondary_state_info(::game_controller_interface::msg::GameControlData::_secondary_state_info_type arg)
  {
    msg_.secondary_state_info = std::move(arg);
    return Init_GameControlData_drop_in_team(msg_);
  }

private:
  ::game_controller_interface::msg::GameControlData msg_;
};

class Init_GameControlData_secondary_state
{
public:
  explicit Init_GameControlData_secondary_state(::game_controller_interface::msg::GameControlData & msg)
  : msg_(msg)
  {}
  Init_GameControlData_secondary_state_info secondary_state(::game_controller_interface::msg::GameControlData::_secondary_state_type arg)
  {
    msg_.secondary_state = std::move(arg);
    return Init_GameControlData_secondary_state_info(msg_);
  }

private:
  ::game_controller_interface::msg::GameControlData msg_;
};

class Init_GameControlData_kick_off_team
{
public:
  explicit Init_GameControlData_kick_off_team(::game_controller_interface::msg::GameControlData & msg)
  : msg_(msg)
  {}
  Init_GameControlData_secondary_state kick_off_team(::game_controller_interface::msg::GameControlData::_kick_off_team_type arg)
  {
    msg_.kick_off_team = std::move(arg);
    return Init_GameControlData_secondary_state(msg_);
  }

private:
  ::game_controller_interface::msg::GameControlData msg_;
};

class Init_GameControlData_first_half
{
public:
  explicit Init_GameControlData_first_half(::game_controller_interface::msg::GameControlData & msg)
  : msg_(msg)
  {}
  Init_GameControlData_kick_off_team first_half(::game_controller_interface::msg::GameControlData::_first_half_type arg)
  {
    msg_.first_half = std::move(arg);
    return Init_GameControlData_kick_off_team(msg_);
  }

private:
  ::game_controller_interface::msg::GameControlData msg_;
};

class Init_GameControlData_state
{
public:
  explicit Init_GameControlData_state(::game_controller_interface::msg::GameControlData & msg)
  : msg_(msg)
  {}
  Init_GameControlData_first_half state(::game_controller_interface::msg::GameControlData::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_GameControlData_first_half(msg_);
  }

private:
  ::game_controller_interface::msg::GameControlData msg_;
};

class Init_GameControlData_game_type
{
public:
  explicit Init_GameControlData_game_type(::game_controller_interface::msg::GameControlData & msg)
  : msg_(msg)
  {}
  Init_GameControlData_state game_type(::game_controller_interface::msg::GameControlData::_game_type_type arg)
  {
    msg_.game_type = std::move(arg);
    return Init_GameControlData_state(msg_);
  }

private:
  ::game_controller_interface::msg::GameControlData msg_;
};

class Init_GameControlData_players_per_team
{
public:
  explicit Init_GameControlData_players_per_team(::game_controller_interface::msg::GameControlData & msg)
  : msg_(msg)
  {}
  Init_GameControlData_game_type players_per_team(::game_controller_interface::msg::GameControlData::_players_per_team_type arg)
  {
    msg_.players_per_team = std::move(arg);
    return Init_GameControlData_game_type(msg_);
  }

private:
  ::game_controller_interface::msg::GameControlData msg_;
};

class Init_GameControlData_packet_number
{
public:
  explicit Init_GameControlData_packet_number(::game_controller_interface::msg::GameControlData & msg)
  : msg_(msg)
  {}
  Init_GameControlData_players_per_team packet_number(::game_controller_interface::msg::GameControlData::_packet_number_type arg)
  {
    msg_.packet_number = std::move(arg);
    return Init_GameControlData_players_per_team(msg_);
  }

private:
  ::game_controller_interface::msg::GameControlData msg_;
};

class Init_GameControlData_version
{
public:
  explicit Init_GameControlData_version(::game_controller_interface::msg::GameControlData & msg)
  : msg_(msg)
  {}
  Init_GameControlData_packet_number version(::game_controller_interface::msg::GameControlData::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_GameControlData_packet_number(msg_);
  }

private:
  ::game_controller_interface::msg::GameControlData msg_;
};

class Init_GameControlData_header
{
public:
  Init_GameControlData_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GameControlData_version header(::game_controller_interface::msg::GameControlData::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_GameControlData_version(msg_);
  }

private:
  ::game_controller_interface::msg::GameControlData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::game_controller_interface::msg::GameControlData>()
{
  return game_controller_interface::msg::builder::Init_GameControlData_header();
}

}  // namespace game_controller_interface

#endif  // GAME_CONTROLLER_INTERFACE__MSG__DETAIL__GAME_CONTROL_DATA__BUILDER_HPP_
