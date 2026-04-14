// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from game_controller_interface:msg/TeamInfo.idl
// generated code does not contain a copyright notice

#ifndef GAME_CONTROLLER_INTERFACE__MSG__DETAIL__TEAM_INFO__STRUCT_HPP_
#define GAME_CONTROLLER_INTERFACE__MSG__DETAIL__TEAM_INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'coach'
// Member 'players'
#include "game_controller_interface/msg/detail/robot_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__game_controller_interface__msg__TeamInfo __attribute__((deprecated))
#else
# define DEPRECATED__game_controller_interface__msg__TeamInfo __declspec(deprecated)
#endif

namespace game_controller_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TeamInfo_
{
  using Type = TeamInfo_<ContainerAllocator>;

  explicit TeamInfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : coach(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->team_number = 0;
      this->field_player_colour = 0;
      this->score = 0;
      this->penalty_shot = 0;
      this->single_shots = 0;
      this->coach_sequence = 0;
    }
  }

  explicit TeamInfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : coach(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->team_number = 0;
      this->field_player_colour = 0;
      this->score = 0;
      this->penalty_shot = 0;
      this->single_shots = 0;
      this->coach_sequence = 0;
    }
  }

  // field types and members
  using _team_number_type =
    uint8_t;
  _team_number_type team_number;
  using _field_player_colour_type =
    uint8_t;
  _field_player_colour_type field_player_colour;
  using _score_type =
    uint8_t;
  _score_type score;
  using _penalty_shot_type =
    uint8_t;
  _penalty_shot_type penalty_shot;
  using _single_shots_type =
    uint16_t;
  _single_shots_type single_shots;
  using _coach_sequence_type =
    uint8_t;
  _coach_sequence_type coach_sequence;
  using _coach_message_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _coach_message_type coach_message;
  using _coach_type =
    game_controller_interface::msg::RobotInfo_<ContainerAllocator>;
  _coach_type coach;
  using _players_type =
    std::vector<game_controller_interface::msg::RobotInfo_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<game_controller_interface::msg::RobotInfo_<ContainerAllocator>>>;
  _players_type players;

  // setters for named parameter idiom
  Type & set__team_number(
    const uint8_t & _arg)
  {
    this->team_number = _arg;
    return *this;
  }
  Type & set__field_player_colour(
    const uint8_t & _arg)
  {
    this->field_player_colour = _arg;
    return *this;
  }
  Type & set__score(
    const uint8_t & _arg)
  {
    this->score = _arg;
    return *this;
  }
  Type & set__penalty_shot(
    const uint8_t & _arg)
  {
    this->penalty_shot = _arg;
    return *this;
  }
  Type & set__single_shots(
    const uint16_t & _arg)
  {
    this->single_shots = _arg;
    return *this;
  }
  Type & set__coach_sequence(
    const uint8_t & _arg)
  {
    this->coach_sequence = _arg;
    return *this;
  }
  Type & set__coach_message(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->coach_message = _arg;
    return *this;
  }
  Type & set__coach(
    const game_controller_interface::msg::RobotInfo_<ContainerAllocator> & _arg)
  {
    this->coach = _arg;
    return *this;
  }
  Type & set__players(
    const std::vector<game_controller_interface::msg::RobotInfo_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<game_controller_interface::msg::RobotInfo_<ContainerAllocator>>> & _arg)
  {
    this->players = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    game_controller_interface::msg::TeamInfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const game_controller_interface::msg::TeamInfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<game_controller_interface::msg::TeamInfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<game_controller_interface::msg::TeamInfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      game_controller_interface::msg::TeamInfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<game_controller_interface::msg::TeamInfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      game_controller_interface::msg::TeamInfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<game_controller_interface::msg::TeamInfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<game_controller_interface::msg::TeamInfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<game_controller_interface::msg::TeamInfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__game_controller_interface__msg__TeamInfo
    std::shared_ptr<game_controller_interface::msg::TeamInfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__game_controller_interface__msg__TeamInfo
    std::shared_ptr<game_controller_interface::msg::TeamInfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TeamInfo_ & other) const
  {
    if (this->team_number != other.team_number) {
      return false;
    }
    if (this->field_player_colour != other.field_player_colour) {
      return false;
    }
    if (this->score != other.score) {
      return false;
    }
    if (this->penalty_shot != other.penalty_shot) {
      return false;
    }
    if (this->single_shots != other.single_shots) {
      return false;
    }
    if (this->coach_sequence != other.coach_sequence) {
      return false;
    }
    if (this->coach_message != other.coach_message) {
      return false;
    }
    if (this->coach != other.coach) {
      return false;
    }
    if (this->players != other.players) {
      return false;
    }
    return true;
  }
  bool operator!=(const TeamInfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TeamInfo_

// alias to use template instance with default allocator
using TeamInfo =
  game_controller_interface::msg::TeamInfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace game_controller_interface

#endif  // GAME_CONTROLLER_INTERFACE__MSG__DETAIL__TEAM_INFO__STRUCT_HPP_
