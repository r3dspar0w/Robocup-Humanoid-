// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from brain:msg/Kick.idl
// generated code does not contain a copyright notice

#ifndef BRAIN__MSG__DETAIL__KICK__STRUCT_HPP_
#define BRAIN__MSG__DETAIL__KICK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__brain__msg__Kick __attribute__((deprecated))
#else
# define DEPRECATED__brain__msg__Kick __declspec(deprecated)
#endif

namespace brain
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Kick_
{
  using Type = Kick_<ContainerAllocator>;

  explicit Kick_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->dir = 0.0;
      this->goal_x = 0.0;
      this->goal_y = 0.0;
      this->robot_theta_to_field = 0.0;
      this->power = 0.0;
    }
  }

  explicit Kick_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->dir = 0.0;
      this->goal_x = 0.0;
      this->goal_y = 0.0;
      this->robot_theta_to_field = 0.0;
      this->power = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _dir_type =
    double;
  _dir_type dir;
  using _goal_x_type =
    double;
  _goal_x_type goal_x;
  using _goal_y_type =
    double;
  _goal_y_type goal_y;
  using _robot_theta_to_field_type =
    double;
  _robot_theta_to_field_type robot_theta_to_field;
  using _power_type =
    double;
  _power_type power;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__dir(
    const double & _arg)
  {
    this->dir = _arg;
    return *this;
  }
  Type & set__goal_x(
    const double & _arg)
  {
    this->goal_x = _arg;
    return *this;
  }
  Type & set__goal_y(
    const double & _arg)
  {
    this->goal_y = _arg;
    return *this;
  }
  Type & set__robot_theta_to_field(
    const double & _arg)
  {
    this->robot_theta_to_field = _arg;
    return *this;
  }
  Type & set__power(
    const double & _arg)
  {
    this->power = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    brain::msg::Kick_<ContainerAllocator> *;
  using ConstRawPtr =
    const brain::msg::Kick_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<brain::msg::Kick_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<brain::msg::Kick_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      brain::msg::Kick_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<brain::msg::Kick_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      brain::msg::Kick_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<brain::msg::Kick_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<brain::msg::Kick_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<brain::msg::Kick_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__brain__msg__Kick
    std::shared_ptr<brain::msg::Kick_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__brain__msg__Kick
    std::shared_ptr<brain::msg::Kick_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Kick_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->dir != other.dir) {
      return false;
    }
    if (this->goal_x != other.goal_x) {
      return false;
    }
    if (this->goal_y != other.goal_y) {
      return false;
    }
    if (this->robot_theta_to_field != other.robot_theta_to_field) {
      return false;
    }
    if (this->power != other.power) {
      return false;
    }
    return true;
  }
  bool operator!=(const Kick_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Kick_

// alias to use template instance with default allocator
using Kick =
  brain::msg::Kick_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace brain

#endif  // BRAIN__MSG__DETAIL__KICK__STRUCT_HPP_
