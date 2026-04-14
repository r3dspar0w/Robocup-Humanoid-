// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from booster_interface:msg/LowState.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__LOW_STATE__STRUCT_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__LOW_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'imu_state'
#include "booster_interface/msg/detail/imu_state__struct.hpp"
// Member 'motor_state_parallel'
// Member 'motor_state_serial'
#include "booster_interface/msg/detail/motor_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__booster_interface__msg__LowState __attribute__((deprecated))
#else
# define DEPRECATED__booster_interface__msg__LowState __declspec(deprecated)
#endif

namespace booster_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LowState_
{
  using Type = LowState_<ContainerAllocator>;

  explicit LowState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : imu_state(_init)
  {
    (void)_init;
  }

  explicit LowState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : imu_state(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _imu_state_type =
    booster_interface::msg::ImuState_<ContainerAllocator>;
  _imu_state_type imu_state;
  using _motor_state_parallel_type =
    std::vector<booster_interface::msg::MotorState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<booster_interface::msg::MotorState_<ContainerAllocator>>>;
  _motor_state_parallel_type motor_state_parallel;
  using _motor_state_serial_type =
    std::vector<booster_interface::msg::MotorState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<booster_interface::msg::MotorState_<ContainerAllocator>>>;
  _motor_state_serial_type motor_state_serial;

  // setters for named parameter idiom
  Type & set__imu_state(
    const booster_interface::msg::ImuState_<ContainerAllocator> & _arg)
  {
    this->imu_state = _arg;
    return *this;
  }
  Type & set__motor_state_parallel(
    const std::vector<booster_interface::msg::MotorState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<booster_interface::msg::MotorState_<ContainerAllocator>>> & _arg)
  {
    this->motor_state_parallel = _arg;
    return *this;
  }
  Type & set__motor_state_serial(
    const std::vector<booster_interface::msg::MotorState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<booster_interface::msg::MotorState_<ContainerAllocator>>> & _arg)
  {
    this->motor_state_serial = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    booster_interface::msg::LowState_<ContainerAllocator> *;
  using ConstRawPtr =
    const booster_interface::msg::LowState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<booster_interface::msg::LowState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<booster_interface::msg::LowState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::LowState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::LowState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::LowState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::LowState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<booster_interface::msg::LowState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<booster_interface::msg::LowState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__booster_interface__msg__LowState
    std::shared_ptr<booster_interface::msg::LowState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__booster_interface__msg__LowState
    std::shared_ptr<booster_interface::msg::LowState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LowState_ & other) const
  {
    if (this->imu_state != other.imu_state) {
      return false;
    }
    if (this->motor_state_parallel != other.motor_state_parallel) {
      return false;
    }
    if (this->motor_state_serial != other.motor_state_serial) {
      return false;
    }
    return true;
  }
  bool operator!=(const LowState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LowState_

// alias to use template instance with default allocator
using LowState =
  booster_interface::msg::LowState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__LOW_STATE__STRUCT_HPP_
