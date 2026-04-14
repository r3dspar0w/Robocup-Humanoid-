// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from booster_interface:msg/LowCmd.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__LOW_CMD__STRUCT_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__LOW_CMD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'motor_cmd'
#include "booster_interface/msg/detail/motor_cmd__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__booster_interface__msg__LowCmd __attribute__((deprecated))
#else
# define DEPRECATED__booster_interface__msg__LowCmd __declspec(deprecated)
#endif

namespace booster_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LowCmd_
{
  using Type = LowCmd_<ContainerAllocator>;

  explicit LowCmd_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cmd_type = 0;
    }
  }

  explicit LowCmd_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cmd_type = 0;
    }
  }

  // field types and members
  using _cmd_type_type =
    int8_t;
  _cmd_type_type cmd_type;
  using _motor_cmd_type =
    std::vector<booster_interface::msg::MotorCmd_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<booster_interface::msg::MotorCmd_<ContainerAllocator>>>;
  _motor_cmd_type motor_cmd;

  // setters for named parameter idiom
  Type & set__cmd_type(
    const int8_t & _arg)
  {
    this->cmd_type = _arg;
    return *this;
  }
  Type & set__motor_cmd(
    const std::vector<booster_interface::msg::MotorCmd_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<booster_interface::msg::MotorCmd_<ContainerAllocator>>> & _arg)
  {
    this->motor_cmd = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int8_t CMD_TYPE_PARALLEL =
    0;
  static constexpr int8_t CMD_TYPE_SERIAL =
    1;

  // pointer types
  using RawPtr =
    booster_interface::msg::LowCmd_<ContainerAllocator> *;
  using ConstRawPtr =
    const booster_interface::msg::LowCmd_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<booster_interface::msg::LowCmd_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<booster_interface::msg::LowCmd_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::LowCmd_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::LowCmd_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::LowCmd_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::LowCmd_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<booster_interface::msg::LowCmd_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<booster_interface::msg::LowCmd_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__booster_interface__msg__LowCmd
    std::shared_ptr<booster_interface::msg::LowCmd_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__booster_interface__msg__LowCmd
    std::shared_ptr<booster_interface::msg::LowCmd_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LowCmd_ & other) const
  {
    if (this->cmd_type != other.cmd_type) {
      return false;
    }
    if (this->motor_cmd != other.motor_cmd) {
      return false;
    }
    return true;
  }
  bool operator!=(const LowCmd_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LowCmd_

// alias to use template instance with default allocator
using LowCmd =
  booster_interface::msg::LowCmd_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t LowCmd_<ContainerAllocator>::CMD_TYPE_PARALLEL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t LowCmd_<ContainerAllocator>::CMD_TYPE_SERIAL;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__LOW_CMD__STRUCT_HPP_
