// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vision_interface:msg/CalParam.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__CAL_PARAM__STRUCT_HPP_
#define VISION_INTERFACE__MSG__DETAIL__CAL_PARAM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__vision_interface__msg__CalParam __attribute__((deprecated))
#else
# define DEPRECATED__vision_interface__msg__CalParam __declspec(deprecated)
#endif

namespace vision_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CalParam_
{
  using Type = CalParam_<ContainerAllocator>;

  explicit CalParam_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pitch_compensation = 0.0f;
      this->yaw_compensation = 0.0f;
      this->z_compensation = 0.0f;
    }
  }

  explicit CalParam_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pitch_compensation = 0.0f;
      this->yaw_compensation = 0.0f;
      this->z_compensation = 0.0f;
    }
  }

  // field types and members
  using _pitch_compensation_type =
    float;
  _pitch_compensation_type pitch_compensation;
  using _yaw_compensation_type =
    float;
  _yaw_compensation_type yaw_compensation;
  using _z_compensation_type =
    float;
  _z_compensation_type z_compensation;

  // setters for named parameter idiom
  Type & set__pitch_compensation(
    const float & _arg)
  {
    this->pitch_compensation = _arg;
    return *this;
  }
  Type & set__yaw_compensation(
    const float & _arg)
  {
    this->yaw_compensation = _arg;
    return *this;
  }
  Type & set__z_compensation(
    const float & _arg)
  {
    this->z_compensation = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vision_interface::msg::CalParam_<ContainerAllocator> *;
  using ConstRawPtr =
    const vision_interface::msg::CalParam_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vision_interface::msg::CalParam_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vision_interface::msg::CalParam_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vision_interface::msg::CalParam_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vision_interface::msg::CalParam_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vision_interface::msg::CalParam_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vision_interface::msg::CalParam_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vision_interface::msg::CalParam_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vision_interface::msg::CalParam_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vision_interface__msg__CalParam
    std::shared_ptr<vision_interface::msg::CalParam_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vision_interface__msg__CalParam
    std::shared_ptr<vision_interface::msg::CalParam_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CalParam_ & other) const
  {
    if (this->pitch_compensation != other.pitch_compensation) {
      return false;
    }
    if (this->yaw_compensation != other.yaw_compensation) {
      return false;
    }
    if (this->z_compensation != other.z_compensation) {
      return false;
    }
    return true;
  }
  bool operator!=(const CalParam_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CalParam_

// alias to use template instance with default allocator
using CalParam =
  vision_interface::msg::CalParam_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vision_interface

#endif  // VISION_INTERFACE__MSG__DETAIL__CAL_PARAM__STRUCT_HPP_
