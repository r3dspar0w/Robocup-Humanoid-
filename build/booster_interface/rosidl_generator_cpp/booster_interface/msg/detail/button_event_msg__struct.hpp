// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from booster_interface:msg/ButtonEventMsg.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__BUTTON_EVENT_MSG__STRUCT_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__BUTTON_EVENT_MSG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__booster_interface__msg__ButtonEventMsg __attribute__((deprecated))
#else
# define DEPRECATED__booster_interface__msg__ButtonEventMsg __declspec(deprecated)
#endif

namespace booster_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ButtonEventMsg_
{
  using Type = ButtonEventMsg_<ContainerAllocator>;

  explicit ButtonEventMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->event = 0;
      this->button = 0l;
    }
  }

  explicit ButtonEventMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->event = 0;
      this->button = 0l;
    }
  }

  // field types and members
  using _event_type =
    int8_t;
  _event_type event;
  using _button_type =
    int32_t;
  _button_type button;

  // setters for named parameter idiom
  Type & set__event(
    const int8_t & _arg)
  {
    this->event = _arg;
    return *this;
  }
  Type & set__button(
    const int32_t & _arg)
  {
    this->button = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int8_t PRESS_DOWN =
    0;
  static constexpr int8_t PRESS_UP =
    1;
  static constexpr int8_t SINGLE_CLICK =
    0;
  static constexpr int8_t DOUBLE_CLICK =
    1;
  static constexpr int8_t TRIPLE_CLICK =
    0;
  static constexpr int8_t LONG_PRESS_START =
    1;
  static constexpr int8_t LONG_PRESS_HOLD =
    0;
  static constexpr int8_t LONG_PRESS_END =
    1;

  // pointer types
  using RawPtr =
    booster_interface::msg::ButtonEventMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const booster_interface::msg::ButtonEventMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<booster_interface::msg::ButtonEventMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<booster_interface::msg::ButtonEventMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::ButtonEventMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::ButtonEventMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::ButtonEventMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::ButtonEventMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<booster_interface::msg::ButtonEventMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<booster_interface::msg::ButtonEventMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__booster_interface__msg__ButtonEventMsg
    std::shared_ptr<booster_interface::msg::ButtonEventMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__booster_interface__msg__ButtonEventMsg
    std::shared_ptr<booster_interface::msg::ButtonEventMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ButtonEventMsg_ & other) const
  {
    if (this->event != other.event) {
      return false;
    }
    if (this->button != other.button) {
      return false;
    }
    return true;
  }
  bool operator!=(const ButtonEventMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ButtonEventMsg_

// alias to use template instance with default allocator
using ButtonEventMsg =
  booster_interface::msg::ButtonEventMsg_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t ButtonEventMsg_<ContainerAllocator>::PRESS_DOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t ButtonEventMsg_<ContainerAllocator>::PRESS_UP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t ButtonEventMsg_<ContainerAllocator>::SINGLE_CLICK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t ButtonEventMsg_<ContainerAllocator>::DOUBLE_CLICK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t ButtonEventMsg_<ContainerAllocator>::TRIPLE_CLICK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t ButtonEventMsg_<ContainerAllocator>::LONG_PRESS_START;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t ButtonEventMsg_<ContainerAllocator>::LONG_PRESS_HOLD;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t ButtonEventMsg_<ContainerAllocator>::LONG_PRESS_END;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__BUTTON_EVENT_MSG__STRUCT_HPP_
