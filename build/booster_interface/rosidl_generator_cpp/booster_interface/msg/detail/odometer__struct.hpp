// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from booster_interface:msg/Odometer.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__ODOMETER__STRUCT_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__ODOMETER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__booster_interface__msg__Odometer __attribute__((deprecated))
#else
# define DEPRECATED__booster_interface__msg__Odometer __declspec(deprecated)
#endif

namespace booster_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Odometer_
{
  using Type = Odometer_<ContainerAllocator>;

  explicit Odometer_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->theta = 0.0f;
    }
  }

  explicit Odometer_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->theta = 0.0f;
    }
  }

  // field types and members
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _theta_type =
    float;
  _theta_type theta;

  // setters for named parameter idiom
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__theta(
    const float & _arg)
  {
    this->theta = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    booster_interface::msg::Odometer_<ContainerAllocator> *;
  using ConstRawPtr =
    const booster_interface::msg::Odometer_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<booster_interface::msg::Odometer_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<booster_interface::msg::Odometer_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::Odometer_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::Odometer_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::Odometer_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::Odometer_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<booster_interface::msg::Odometer_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<booster_interface::msg::Odometer_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__booster_interface__msg__Odometer
    std::shared_ptr<booster_interface::msg::Odometer_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__booster_interface__msg__Odometer
    std::shared_ptr<booster_interface::msg::Odometer_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Odometer_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->theta != other.theta) {
      return false;
    }
    return true;
  }
  bool operator!=(const Odometer_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Odometer_

// alias to use template instance with default allocator
using Odometer =
  booster_interface::msg::Odometer_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__ODOMETER__STRUCT_HPP_
