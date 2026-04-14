// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from game_controller_interface:msg/GameControlData.idl
// generated code does not contain a copyright notice

#ifndef GAME_CONTROLLER_INTERFACE__MSG__DETAIL__GAME_CONTROL_DATA__TRAITS_HPP_
#define GAME_CONTROLLER_INTERFACE__MSG__DETAIL__GAME_CONTROL_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "game_controller_interface/msg/detail/game_control_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'teams'
#include "game_controller_interface/msg/detail/team_info__traits.hpp"

namespace game_controller_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const GameControlData & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    if (msg.header.size() == 0) {
      out << "header: []";
    } else {
      out << "header: [";
      size_t pending_items = msg.header.size();
      for (auto item : msg.header) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: version
  {
    out << "version: ";
    rosidl_generator_traits::value_to_yaml(msg.version, out);
    out << ", ";
  }

  // member: packet_number
  {
    out << "packet_number: ";
    rosidl_generator_traits::value_to_yaml(msg.packet_number, out);
    out << ", ";
  }

  // member: players_per_team
  {
    out << "players_per_team: ";
    rosidl_generator_traits::value_to_yaml(msg.players_per_team, out);
    out << ", ";
  }

  // member: game_type
  {
    out << "game_type: ";
    rosidl_generator_traits::value_to_yaml(msg.game_type, out);
    out << ", ";
  }

  // member: state
  {
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << ", ";
  }

  // member: first_half
  {
    out << "first_half: ";
    rosidl_generator_traits::value_to_yaml(msg.first_half, out);
    out << ", ";
  }

  // member: kick_off_team
  {
    out << "kick_off_team: ";
    rosidl_generator_traits::value_to_yaml(msg.kick_off_team, out);
    out << ", ";
  }

  // member: secondary_state
  {
    out << "secondary_state: ";
    rosidl_generator_traits::value_to_yaml(msg.secondary_state, out);
    out << ", ";
  }

  // member: secondary_state_info
  {
    if (msg.secondary_state_info.size() == 0) {
      out << "secondary_state_info: []";
    } else {
      out << "secondary_state_info: [";
      size_t pending_items = msg.secondary_state_info.size();
      for (auto item : msg.secondary_state_info) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: drop_in_team
  {
    out << "drop_in_team: ";
    rosidl_generator_traits::value_to_yaml(msg.drop_in_team, out);
    out << ", ";
  }

  // member: drop_in_time
  {
    out << "drop_in_time: ";
    rosidl_generator_traits::value_to_yaml(msg.drop_in_time, out);
    out << ", ";
  }

  // member: secs_remaining
  {
    out << "secs_remaining: ";
    rosidl_generator_traits::value_to_yaml(msg.secs_remaining, out);
    out << ", ";
  }

  // member: secondary_time
  {
    out << "secondary_time: ";
    rosidl_generator_traits::value_to_yaml(msg.secondary_time, out);
    out << ", ";
  }

  // member: teams
  {
    if (msg.teams.size() == 0) {
      out << "teams: []";
    } else {
      out << "teams: [";
      size_t pending_items = msg.teams.size();
      for (auto item : msg.teams) {
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
  const GameControlData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.header.size() == 0) {
      out << "header: []\n";
    } else {
      out << "header:\n";
      for (auto item : msg.header) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: version
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "version: ";
    rosidl_generator_traits::value_to_yaml(msg.version, out);
    out << "\n";
  }

  // member: packet_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "packet_number: ";
    rosidl_generator_traits::value_to_yaml(msg.packet_number, out);
    out << "\n";
  }

  // member: players_per_team
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "players_per_team: ";
    rosidl_generator_traits::value_to_yaml(msg.players_per_team, out);
    out << "\n";
  }

  // member: game_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "game_type: ";
    rosidl_generator_traits::value_to_yaml(msg.game_type, out);
    out << "\n";
  }

  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << "\n";
  }

  // member: first_half
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "first_half: ";
    rosidl_generator_traits::value_to_yaml(msg.first_half, out);
    out << "\n";
  }

  // member: kick_off_team
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "kick_off_team: ";
    rosidl_generator_traits::value_to_yaml(msg.kick_off_team, out);
    out << "\n";
  }

  // member: secondary_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "secondary_state: ";
    rosidl_generator_traits::value_to_yaml(msg.secondary_state, out);
    out << "\n";
  }

  // member: secondary_state_info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.secondary_state_info.size() == 0) {
      out << "secondary_state_info: []\n";
    } else {
      out << "secondary_state_info:\n";
      for (auto item : msg.secondary_state_info) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: drop_in_team
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "drop_in_team: ";
    rosidl_generator_traits::value_to_yaml(msg.drop_in_team, out);
    out << "\n";
  }

  // member: drop_in_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "drop_in_time: ";
    rosidl_generator_traits::value_to_yaml(msg.drop_in_time, out);
    out << "\n";
  }

  // member: secs_remaining
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "secs_remaining: ";
    rosidl_generator_traits::value_to_yaml(msg.secs_remaining, out);
    out << "\n";
  }

  // member: secondary_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "secondary_time: ";
    rosidl_generator_traits::value_to_yaml(msg.secondary_time, out);
    out << "\n";
  }

  // member: teams
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.teams.size() == 0) {
      out << "teams: []\n";
    } else {
      out << "teams:\n";
      for (auto item : msg.teams) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GameControlData & msg, bool use_flow_style = false)
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
  const game_controller_interface::msg::GameControlData & msg,
  std::ostream & out, size_t indentation = 0)
{
  game_controller_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use game_controller_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const game_controller_interface::msg::GameControlData & msg)
{
  return game_controller_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<game_controller_interface::msg::GameControlData>()
{
  return "game_controller_interface::msg::GameControlData";
}

template<>
inline const char * name<game_controller_interface::msg::GameControlData>()
{
  return "game_controller_interface/msg/GameControlData";
}

template<>
struct has_fixed_size<game_controller_interface::msg::GameControlData>
  : std::integral_constant<bool, has_fixed_size<game_controller_interface::msg::TeamInfo>::value> {};

template<>
struct has_bounded_size<game_controller_interface::msg::GameControlData>
  : std::integral_constant<bool, has_bounded_size<game_controller_interface::msg::TeamInfo>::value> {};

template<>
struct is_message<game_controller_interface::msg::GameControlData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GAME_CONTROLLER_INTERFACE__MSG__DETAIL__GAME_CONTROL_DATA__TRAITS_HPP_
