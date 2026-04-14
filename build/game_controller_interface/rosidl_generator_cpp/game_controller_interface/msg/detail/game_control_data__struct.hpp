// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from game_controller_interface:msg/GameControlData.idl
// generated code does not contain a copyright notice

#ifndef GAME_CONTROLLER_INTERFACE__MSG__DETAIL__GAME_CONTROL_DATA__STRUCT_HPP_
#define GAME_CONTROLLER_INTERFACE__MSG__DETAIL__GAME_CONTROL_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'teams'
#include "game_controller_interface/msg/detail/team_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__game_controller_interface__msg__GameControlData __attribute__((deprecated))
#else
# define DEPRECATED__game_controller_interface__msg__GameControlData __declspec(deprecated)
#endif

namespace game_controller_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GameControlData_
{
  using Type = GameControlData_<ContainerAllocator>;

  explicit GameControlData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint8_t, 4>::iterator, uint8_t>(this->header.begin(), this->header.end(), 0);
      this->version = 0;
      this->packet_number = 0;
      this->players_per_team = 0;
      this->game_type = 0;
      this->state = 0;
      this->first_half = 0;
      this->kick_off_team = 0;
      this->secondary_state = 0;
      std::fill<typename std::array<uint8_t, 4>::iterator, uint8_t>(this->secondary_state_info.begin(), this->secondary_state_info.end(), 0);
      this->drop_in_team = 0;
      this->drop_in_time = 0;
      this->secs_remaining = 0;
      this->secondary_time = 0;
      this->teams.fill(game_controller_interface::msg::TeamInfo_<ContainerAllocator>{_init});
    }
  }

  explicit GameControlData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc),
    secondary_state_info(_alloc),
    teams(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint8_t, 4>::iterator, uint8_t>(this->header.begin(), this->header.end(), 0);
      this->version = 0;
      this->packet_number = 0;
      this->players_per_team = 0;
      this->game_type = 0;
      this->state = 0;
      this->first_half = 0;
      this->kick_off_team = 0;
      this->secondary_state = 0;
      std::fill<typename std::array<uint8_t, 4>::iterator, uint8_t>(this->secondary_state_info.begin(), this->secondary_state_info.end(), 0);
      this->drop_in_team = 0;
      this->drop_in_time = 0;
      this->secs_remaining = 0;
      this->secondary_time = 0;
      this->teams.fill(game_controller_interface::msg::TeamInfo_<ContainerAllocator>{_alloc, _init});
    }
  }

  // field types and members
  using _header_type =
    std::array<uint8_t, 4>;
  _header_type header;
  using _version_type =
    uint16_t;
  _version_type version;
  using _packet_number_type =
    uint8_t;
  _packet_number_type packet_number;
  using _players_per_team_type =
    uint8_t;
  _players_per_team_type players_per_team;
  using _game_type_type =
    uint8_t;
  _game_type_type game_type;
  using _state_type =
    uint8_t;
  _state_type state;
  using _first_half_type =
    uint8_t;
  _first_half_type first_half;
  using _kick_off_team_type =
    uint8_t;
  _kick_off_team_type kick_off_team;
  using _secondary_state_type =
    uint8_t;
  _secondary_state_type secondary_state;
  using _secondary_state_info_type =
    std::array<uint8_t, 4>;
  _secondary_state_info_type secondary_state_info;
  using _drop_in_team_type =
    uint8_t;
  _drop_in_team_type drop_in_team;
  using _drop_in_time_type =
    uint16_t;
  _drop_in_time_type drop_in_time;
  using _secs_remaining_type =
    uint16_t;
  _secs_remaining_type secs_remaining;
  using _secondary_time_type =
    uint16_t;
  _secondary_time_type secondary_time;
  using _teams_type =
    std::array<game_controller_interface::msg::TeamInfo_<ContainerAllocator>, 2>;
  _teams_type teams;

  // setters for named parameter idiom
  Type & set__header(
    const std::array<uint8_t, 4> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__version(
    const uint16_t & _arg)
  {
    this->version = _arg;
    return *this;
  }
  Type & set__packet_number(
    const uint8_t & _arg)
  {
    this->packet_number = _arg;
    return *this;
  }
  Type & set__players_per_team(
    const uint8_t & _arg)
  {
    this->players_per_team = _arg;
    return *this;
  }
  Type & set__game_type(
    const uint8_t & _arg)
  {
    this->game_type = _arg;
    return *this;
  }
  Type & set__state(
    const uint8_t & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__first_half(
    const uint8_t & _arg)
  {
    this->first_half = _arg;
    return *this;
  }
  Type & set__kick_off_team(
    const uint8_t & _arg)
  {
    this->kick_off_team = _arg;
    return *this;
  }
  Type & set__secondary_state(
    const uint8_t & _arg)
  {
    this->secondary_state = _arg;
    return *this;
  }
  Type & set__secondary_state_info(
    const std::array<uint8_t, 4> & _arg)
  {
    this->secondary_state_info = _arg;
    return *this;
  }
  Type & set__drop_in_team(
    const uint8_t & _arg)
  {
    this->drop_in_team = _arg;
    return *this;
  }
  Type & set__drop_in_time(
    const uint16_t & _arg)
  {
    this->drop_in_time = _arg;
    return *this;
  }
  Type & set__secs_remaining(
    const uint16_t & _arg)
  {
    this->secs_remaining = _arg;
    return *this;
  }
  Type & set__secondary_time(
    const uint16_t & _arg)
  {
    this->secondary_time = _arg;
    return *this;
  }
  Type & set__teams(
    const std::array<game_controller_interface::msg::TeamInfo_<ContainerAllocator>, 2> & _arg)
  {
    this->teams = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    game_controller_interface::msg::GameControlData_<ContainerAllocator> *;
  using ConstRawPtr =
    const game_controller_interface::msg::GameControlData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<game_controller_interface::msg::GameControlData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<game_controller_interface::msg::GameControlData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      game_controller_interface::msg::GameControlData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<game_controller_interface::msg::GameControlData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      game_controller_interface::msg::GameControlData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<game_controller_interface::msg::GameControlData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<game_controller_interface::msg::GameControlData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<game_controller_interface::msg::GameControlData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__game_controller_interface__msg__GameControlData
    std::shared_ptr<game_controller_interface::msg::GameControlData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__game_controller_interface__msg__GameControlData
    std::shared_ptr<game_controller_interface::msg::GameControlData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GameControlData_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->version != other.version) {
      return false;
    }
    if (this->packet_number != other.packet_number) {
      return false;
    }
    if (this->players_per_team != other.players_per_team) {
      return false;
    }
    if (this->game_type != other.game_type) {
      return false;
    }
    if (this->state != other.state) {
      return false;
    }
    if (this->first_half != other.first_half) {
      return false;
    }
    if (this->kick_off_team != other.kick_off_team) {
      return false;
    }
    if (this->secondary_state != other.secondary_state) {
      return false;
    }
    if (this->secondary_state_info != other.secondary_state_info) {
      return false;
    }
    if (this->drop_in_team != other.drop_in_team) {
      return false;
    }
    if (this->drop_in_time != other.drop_in_time) {
      return false;
    }
    if (this->secs_remaining != other.secs_remaining) {
      return false;
    }
    if (this->secondary_time != other.secondary_time) {
      return false;
    }
    if (this->teams != other.teams) {
      return false;
    }
    return true;
  }
  bool operator!=(const GameControlData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GameControlData_

// alias to use template instance with default allocator
using GameControlData =
  game_controller_interface::msg::GameControlData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace game_controller_interface

#endif  // GAME_CONTROLLER_INTERFACE__MSG__DETAIL__GAME_CONTROL_DATA__STRUCT_HPP_
