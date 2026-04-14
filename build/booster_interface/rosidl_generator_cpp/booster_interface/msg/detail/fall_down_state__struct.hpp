// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from booster_interface:msg/FallDownState.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__FALL_DOWN_STATE__STRUCT_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__FALL_DOWN_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__booster_interface__msg__FallDownState __attribute__((deprecated))
#else
# define DEPRECATED__booster_interface__msg__FallDownState __declspec(deprecated)
#endif

namespace booster_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FallDownState_
{
  using Type = FallDownState_<ContainerAllocator>;

  explicit FallDownState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fall_down_state = 0ul;
      this->is_recovery_available = false;
    }
  }

  explicit FallDownState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fall_down_state = 0ul;
      this->is_recovery_available = false;
    }
  }

  // field types and members
  using _fall_down_state_type =
    uint32_t;
  _fall_down_state_type fall_down_state;
  using _is_recovery_available_type =
    bool;
  _is_recovery_available_type is_recovery_available;

  // setters for named parameter idiom
  Type & set__fall_down_state(
    const uint32_t & _arg)
  {
    this->fall_down_state = _arg;
    return *this;
  }
  Type & set__is_recovery_available(
    const bool & _arg)
  {
    this->is_recovery_available = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint32_t IS_READY =
    0u;
  static constexpr uint32_t IS_FALLING =
    1u;
  static constexpr uint32_t HAS_FALLEN =
    2u;
  static constexpr uint32_t IS_GETTING_UP =
    3u;

  // pointer types
  using RawPtr =
    booster_interface::msg::FallDownState_<ContainerAllocator> *;
  using ConstRawPtr =
    const booster_interface::msg::FallDownState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<booster_interface::msg::FallDownState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<booster_interface::msg::FallDownState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::FallDownState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::FallDownState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::FallDownState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::FallDownState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<booster_interface::msg::FallDownState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<booster_interface::msg::FallDownState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__booster_interface__msg__FallDownState
    std::shared_ptr<booster_interface::msg::FallDownState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__booster_interface__msg__FallDownState
    std::shared_ptr<booster_interface::msg::FallDownState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FallDownState_ & other) const
  {
    if (this->fall_down_state != other.fall_down_state) {
      return false;
    }
    if (this->is_recovery_available != other.is_recovery_available) {
      return false;
    }
    return true;
  }
  bool operator!=(const FallDownState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FallDownState_

// alias to use template instance with default allocator
using FallDownState =
  booster_interface::msg::FallDownState_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t FallDownState_<ContainerAllocator>::IS_READY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t FallDownState_<ContainerAllocator>::IS_FALLING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t FallDownState_<ContainerAllocator>::HAS_FALLEN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t FallDownState_<ContainerAllocator>::IS_GETTING_UP;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__FALL_DOWN_STATE__STRUCT_HPP_
