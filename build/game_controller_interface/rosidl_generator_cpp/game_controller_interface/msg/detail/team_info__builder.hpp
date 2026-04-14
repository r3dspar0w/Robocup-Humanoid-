// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from game_controller_interface:msg/TeamInfo.idl
// generated code does not contain a copyright notice

#ifndef GAME_CONTROLLER_INTERFACE__MSG__DETAIL__TEAM_INFO__BUILDER_HPP_
#define GAME_CONTROLLER_INTERFACE__MSG__DETAIL__TEAM_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "game_controller_interface/msg/detail/team_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace game_controller_interface
{

namespace msg
{

namespace builder
{

class Init_TeamInfo_players
{
public:
  explicit Init_TeamInfo_players(::game_controller_interface::msg::TeamInfo & msg)
  : msg_(msg)
  {}
  ::game_controller_interface::msg::TeamInfo players(::game_controller_interface::msg::TeamInfo::_players_type arg)
  {
    msg_.players = std::move(arg);
    return std::move(msg_);
  }

private:
  ::game_controller_interface::msg::TeamInfo msg_;
};

class Init_TeamInfo_coach
{
public:
  explicit Init_TeamInfo_coach(::game_controller_interface::msg::TeamInfo & msg)
  : msg_(msg)
  {}
  Init_TeamInfo_players coach(::game_controller_interface::msg::TeamInfo::_coach_type arg)
  {
    msg_.coach = std::move(arg);
    return Init_TeamInfo_players(msg_);
  }

private:
  ::game_controller_interface::msg::TeamInfo msg_;
};

class Init_TeamInfo_coach_message
{
public:
  explicit Init_TeamInfo_coach_message(::game_controller_interface::msg::TeamInfo & msg)
  : msg_(msg)
  {}
  Init_TeamInfo_coach coach_message(::game_controller_interface::msg::TeamInfo::_coach_message_type arg)
  {
    msg_.coach_message = std::move(arg);
    return Init_TeamInfo_coach(msg_);
  }

private:
  ::game_controller_interface::msg::TeamInfo msg_;
};

class Init_TeamInfo_coach_sequence
{
public:
  explicit Init_TeamInfo_coach_sequence(::game_controller_interface::msg::TeamInfo & msg)
  : msg_(msg)
  {}
  Init_TeamInfo_coach_message coach_sequence(::game_controller_interface::msg::TeamInfo::_coach_sequence_type arg)
  {
    msg_.coach_sequence = std::move(arg);
    return Init_TeamInfo_coach_message(msg_);
  }

private:
  ::game_controller_interface::msg::TeamInfo msg_;
};

class Init_TeamInfo_single_shots
{
public:
  explicit Init_TeamInfo_single_shots(::game_controller_interface::msg::TeamInfo & msg)
  : msg_(msg)
  {}
  Init_TeamInfo_coach_sequence single_shots(::game_controller_interface::msg::TeamInfo::_single_shots_type arg)
  {
    msg_.single_shots = std::move(arg);
    return Init_TeamInfo_coach_sequence(msg_);
  }

private:
  ::game_controller_interface::msg::TeamInfo msg_;
};

class Init_TeamInfo_penalty_shot
{
public:
  explicit Init_TeamInfo_penalty_shot(::game_controller_interface::msg::TeamInfo & msg)
  : msg_(msg)
  {}
  Init_TeamInfo_single_shots penalty_shot(::game_controller_interface::msg::TeamInfo::_penalty_shot_type arg)
  {
    msg_.penalty_shot = std::move(arg);
    return Init_TeamInfo_single_shots(msg_);
  }

private:
  ::game_controller_interface::msg::TeamInfo msg_;
};

class Init_TeamInfo_score
{
public:
  explicit Init_TeamInfo_score(::game_controller_interface::msg::TeamInfo & msg)
  : msg_(msg)
  {}
  Init_TeamInfo_penalty_shot score(::game_controller_interface::msg::TeamInfo::_score_type arg)
  {
    msg_.score = std::move(arg);
    return Init_TeamInfo_penalty_shot(msg_);
  }

private:
  ::game_controller_interface::msg::TeamInfo msg_;
};

class Init_TeamInfo_field_player_colour
{
public:
  explicit Init_TeamInfo_field_player_colour(::game_controller_interface::msg::TeamInfo & msg)
  : msg_(msg)
  {}
  Init_TeamInfo_score field_player_colour(::game_controller_interface::msg::TeamInfo::_field_player_colour_type arg)
  {
    msg_.field_player_colour = std::move(arg);
    return Init_TeamInfo_score(msg_);
  }

private:
  ::game_controller_interface::msg::TeamInfo msg_;
};

class Init_TeamInfo_team_number
{
public:
  Init_TeamInfo_team_number()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TeamInfo_field_player_colour team_number(::game_controller_interface::msg::TeamInfo::_team_number_type arg)
  {
    msg_.team_number = std::move(arg);
    return Init_TeamInfo_field_player_colour(msg_);
  }

private:
  ::game_controller_interface::msg::TeamInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::game_controller_interface::msg::TeamInfo>()
{
  return game_controller_interface::msg::builder::Init_TeamInfo_team_number();
}

}  // namespace game_controller_interface

#endif  // GAME_CONTROLLER_INTERFACE__MSG__DETAIL__TEAM_INFO__BUILDER_HPP_
