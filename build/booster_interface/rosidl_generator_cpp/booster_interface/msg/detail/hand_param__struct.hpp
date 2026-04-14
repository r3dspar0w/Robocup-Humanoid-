// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from booster_interface:msg/HandParam.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__HAND_PARAM__STRUCT_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__HAND_PARAM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__booster_interface__msg__HandParam __attribute__((deprecated))
#else
# define DEPRECATED__booster_interface__msg__HandParam __declspec(deprecated)
#endif

namespace booster_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HandParam_
{
  using Type = HandParam_<ContainerAllocator>;

  explicit HandParam_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->angle = 0l;
      this->force = 0l;
      this->speed = 0l;
      this->seq = 0l;
    }
  }

  explicit HandParam_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->angle = 0l;
      this->force = 0l;
      this->speed = 0l;
      this->seq = 0l;
    }
  }

  // field types and members
  using _angle_type =
    int32_t;
  _angle_type angle;
  using _force_type =
    int32_t;
  _force_type force;
  using _speed_type =
    int32_t;
  _speed_type speed;
  using _seq_type =
    int32_t;
  _seq_type seq;

  // setters for named parameter idiom
  Type & set__angle(
    const int32_t & _arg)
  {
    this->angle = _arg;
    return *this;
  }
  Type & set__force(
    const int32_t & _arg)
  {
    this->force = _arg;
    return *this;
  }
  Type & set__speed(
    const int32_t & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__seq(
    const int32_t & _arg)
  {
    this->seq = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    booster_interface::msg::HandParam_<ContainerAllocator> *;
  using ConstRawPtr =
    const booster_interface::msg::HandParam_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<booster_interface::msg::HandParam_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<booster_interface::msg::HandParam_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::HandParam_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::HandParam_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::HandParam_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::HandParam_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<booster_interface::msg::HandParam_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<booster_interface::msg::HandParam_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__booster_interface__msg__HandParam
    std::shared_ptr<booster_interface::msg::HandParam_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__booster_interface__msg__HandParam
    std::shared_ptr<booster_interface::msg::HandParam_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HandParam_ & other) const
  {
    if (this->angle != other.angle) {
      return false;
    }
    if (this->force != other.force) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    if (this->seq != other.seq) {
      return false;
    }
    return true;
  }
  bool operator!=(const HandParam_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HandParam_

// alias to use template instance with default allocator
using HandParam =
  booster_interface::msg::HandParam_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__HAND_PARAM__STRUCT_HPP_
