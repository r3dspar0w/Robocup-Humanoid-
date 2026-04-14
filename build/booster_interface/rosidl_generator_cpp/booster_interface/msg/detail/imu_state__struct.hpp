// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from booster_interface:msg/ImuState.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__IMU_STATE__STRUCT_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__IMU_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__booster_interface__msg__ImuState __attribute__((deprecated))
#else
# define DEPRECATED__booster_interface__msg__ImuState __declspec(deprecated)
#endif

namespace booster_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ImuState_
{
  using Type = ImuState_<ContainerAllocator>;

  explicit ImuState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 3>::iterator, float>(this->rpy.begin(), this->rpy.end(), 0.0f);
      std::fill<typename std::array<float, 3>::iterator, float>(this->gyro.begin(), this->gyro.end(), 0.0f);
      std::fill<typename std::array<float, 3>::iterator, float>(this->acc.begin(), this->acc.end(), 0.0f);
    }
  }

  explicit ImuState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : rpy(_alloc),
    gyro(_alloc),
    acc(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 3>::iterator, float>(this->rpy.begin(), this->rpy.end(), 0.0f);
      std::fill<typename std::array<float, 3>::iterator, float>(this->gyro.begin(), this->gyro.end(), 0.0f);
      std::fill<typename std::array<float, 3>::iterator, float>(this->acc.begin(), this->acc.end(), 0.0f);
    }
  }

  // field types and members
  using _rpy_type =
    std::array<float, 3>;
  _rpy_type rpy;
  using _gyro_type =
    std::array<float, 3>;
  _gyro_type gyro;
  using _acc_type =
    std::array<float, 3>;
  _acc_type acc;

  // setters for named parameter idiom
  Type & set__rpy(
    const std::array<float, 3> & _arg)
  {
    this->rpy = _arg;
    return *this;
  }
  Type & set__gyro(
    const std::array<float, 3> & _arg)
  {
    this->gyro = _arg;
    return *this;
  }
  Type & set__acc(
    const std::array<float, 3> & _arg)
  {
    this->acc = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    booster_interface::msg::ImuState_<ContainerAllocator> *;
  using ConstRawPtr =
    const booster_interface::msg::ImuState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<booster_interface::msg::ImuState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<booster_interface::msg::ImuState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::ImuState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::ImuState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::ImuState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::ImuState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<booster_interface::msg::ImuState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<booster_interface::msg::ImuState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__booster_interface__msg__ImuState
    std::shared_ptr<booster_interface::msg::ImuState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__booster_interface__msg__ImuState
    std::shared_ptr<booster_interface::msg::ImuState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ImuState_ & other) const
  {
    if (this->rpy != other.rpy) {
      return false;
    }
    if (this->gyro != other.gyro) {
      return false;
    }
    if (this->acc != other.acc) {
      return false;
    }
    return true;
  }
  bool operator!=(const ImuState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ImuState_

// alias to use template instance with default allocator
using ImuState =
  booster_interface::msg::ImuState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__IMU_STATE__STRUCT_HPP_
