// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from game_controller_interface:msg/RobotInfo.idl
// generated code does not contain a copyright notice

#ifndef GAME_CONTROLLER_INTERFACE__MSG__DETAIL__ROBOT_INFO__STRUCT_HPP_
#define GAME_CONTROLLER_INTERFACE__MSG__DETAIL__ROBOT_INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__game_controller_interface__msg__RobotInfo __attribute__((deprecated))
#else
# define DEPRECATED__game_controller_interface__msg__RobotInfo __declspec(deprecated)
#endif

namespace game_controller_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotInfo_
{
  using Type = RobotInfo_<ContainerAllocator>;

  explicit RobotInfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->penalty = 0;
      this->secs_till_unpenalised = 0;
      this->number_of_warnings = 0;
      this->yellow_card_count = 0;
      this->red_card_count = 0;
      this->goal_keeper = false;
    }
  }

  explicit RobotInfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->penalty = 0;
      this->secs_till_unpenalised = 0;
      this->number_of_warnings = 0;
      this->yellow_card_count = 0;
      this->red_card_count = 0;
      this->goal_keeper = false;
    }
  }

  // field types and members
  using _penalty_type =
    uint8_t;
  _penalty_type penalty;
  using _secs_till_unpenalised_type =
    uint8_t;
  _secs_till_unpenalised_type secs_till_unpenalised;
  using _number_of_warnings_type =
    uint8_t;
  _number_of_warnings_type number_of_warnings;
  using _yellow_card_count_type =
    uint8_t;
  _yellow_card_count_type yellow_card_count;
  using _red_card_count_type =
    uint8_t;
  _red_card_count_type red_card_count;
  using _goal_keeper_type =
    bool;
  _goal_keeper_type goal_keeper;

  // setters for named parameter idiom
  Type & set__penalty(
    const uint8_t & _arg)
  {
    this->penalty = _arg;
    return *this;
  }
  Type & set__secs_till_unpenalised(
    const uint8_t & _arg)
  {
    this->secs_till_unpenalised = _arg;
    return *this;
  }
  Type & set__number_of_warnings(
    const uint8_t & _arg)
  {
    this->number_of_warnings = _arg;
    return *this;
  }
  Type & set__yellow_card_count(
    const uint8_t & _arg)
  {
    this->yellow_card_count = _arg;
    return *this;
  }
  Type & set__red_card_count(
    const uint8_t & _arg)
  {
    this->red_card_count = _arg;
    return *this;
  }
  Type & set__goal_keeper(
    const bool & _arg)
  {
    this->goal_keeper = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    game_controller_interface::msg::RobotInfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const game_controller_interface::msg::RobotInfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<game_controller_interface::msg::RobotInfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<game_controller_interface::msg::RobotInfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      game_controller_interface::msg::RobotInfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<game_controller_interface::msg::RobotInfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      game_controller_interface::msg::RobotInfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<game_controller_interface::msg::RobotInfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<game_controller_interface::msg::RobotInfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<game_controller_interface::msg::RobotInfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__game_controller_interface__msg__RobotInfo
    std::shared_ptr<game_controller_interface::msg::RobotInfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__game_controller_interface__msg__RobotInfo
    std::shared_ptr<game_controller_interface::msg::RobotInfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotInfo_ & other) const
  {
    if (this->penalty != other.penalty) {
      return false;
    }
    if (this->secs_till_unpenalised != other.secs_till_unpenalised) {
      return false;
    }
    if (this->number_of_warnings != other.number_of_warnings) {
      return false;
    }
    if (this->yellow_card_count != other.yellow_card_count) {
      return false;
    }
    if (this->red_card_count != other.red_card_count) {
      return false;
    }
    if (this->goal_keeper != other.goal_keeper) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotInfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotInfo_

// alias to use template instance with default allocator
using RobotInfo =
  game_controller_interface::msg::RobotInfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace game_controller_interface

#endif  // GAME_CONTROLLER_INTERFACE__MSG__DETAIL__ROBOT_INFO__STRUCT_HPP_
