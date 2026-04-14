// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from game_controller_interface:msg/TeamInfo.idl
// generated code does not contain a copyright notice

#ifndef GAME_CONTROLLER_INTERFACE__MSG__DETAIL__TEAM_INFO__TRAITS_HPP_
#define GAME_CONTROLLER_INTERFACE__MSG__DETAIL__TEAM_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "game_controller_interface/msg/detail/team_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'coach'
// Member 'players'
#include "game_controller_interface/msg/detail/robot_info__traits.hpp"

namespace game_controller_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const TeamInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: team_number
  {
    out << "team_number: ";
    rosidl_generator_traits::value_to_yaml(msg.team_number, out);
    out << ", ";
  }

  // member: field_player_colour
  {
    out << "field_player_colour: ";
    rosidl_generator_traits::value_to_yaml(msg.field_player_colour, out);
    out << ", ";
  }

  // member: score
  {
    out << "score: ";
    rosidl_generator_traits::value_to_yaml(msg.score, out);
    out << ", ";
  }

  // member: penalty_shot
  {
    out << "penalty_shot: ";
    rosidl_generator_traits::value_to_yaml(msg.penalty_shot, out);
    out << ", ";
  }

  // member: single_shots
  {
    out << "single_shots: ";
    rosidl_generator_traits::value_to_yaml(msg.single_shots, out);
    out << ", ";
  }

  // member: coach_sequence
  {
    out << "coach_sequence: ";
    rosidl_generator_traits::value_to_yaml(msg.coach_sequence, out);
    out << ", ";
  }

  // member: coach_message
  {
    if (msg.coach_message.size() == 0) {
      out << "coach_message: []";
    } else {
      out << "coach_message: [";
      size_t pending_items = msg.coach_message.size();
      for (auto item : msg.coach_message) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: coach
  {
    out << "coach: ";
    to_flow_style_yaml(msg.coach, out);
    out << ", ";
  }

  // member: players
  {
    if (msg.players.size() == 0) {
      out << "players: []";
    } else {
      out << "players: [";
      size_t pending_items = msg.players.size();
      for (auto item : msg.players) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TeamInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: team_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "team_number: ";
    rosidl_generator_traits::value_to_yaml(msg.team_number, out);
    out << "\n";
  }

  // member: field_player_colour
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "field_player_colour: ";
    rosidl_generator_traits::value_to_yaml(msg.field_player_colour, out);
    out << "\n";
  }

  // member: score
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "score: ";
    rosidl_generator_traits::value_to_yaml(msg.score, out);
    out << "\n";
  }

  // member: penalty_shot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "penalty_shot: ";
    rosidl_generator_traits::value_to_yaml(msg.penalty_shot, out);
    out << "\n";
  }

  // member: single_shots
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "single_shots: ";
    rosidl_generator_traits::value_to_yaml(msg.single_shots, out);
    out << "\n";
  }

  // member: coach_sequence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "coach_sequence: ";
    rosidl_generator_traits::value_to_yaml(msg.coach_sequence, out);
    out << "\n";
  }

  // member: coach_message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.coach_message.size() == 0) {
      out << "coach_message: []\n";
    } else {
      out << "coach_message:\n";
      for (auto item : msg.coach_message) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: coach
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "coach:\n";
    to_block_style_yaml(msg.coach, out, indentation + 2);
  }

  // member: players
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.players.size() == 0) {
      out << "players: []\n";
    } else {
      out << "players:\n";
      for (auto item : msg.players) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TeamInfo & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace game_controller_interface

namespace rosidl_generator_traits
{

[[deprecated("use game_controller_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const game_controller_interface::msg::TeamInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  game_controller_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use game_controller_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const game_controller_interface::msg::TeamInfo & msg)
{
  return game_controller_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<game_controller_interface::msg::TeamInfo>()
{
  return "game_controller_interface::msg::TeamInfo";
}

template<>
inline const char * name<game_controller_interface::msg::TeamInfo>()
{
  return "game_controller_interface/msg/TeamInfo";
}

template<>
struct has_fixed_size<game_controller_interface::msg::TeamInfo>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<game_controller_interface::msg::TeamInfo>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<game_controller_interface::msg::TeamInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GAME_CONTROLLER_INTERFACE__MSG__DETAIL__TEAM_INFO__TRAITS_HPP_
