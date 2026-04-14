// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from booster_interface:msg/HandCommand.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__HAND_COMMAND__STRUCT_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__HAND_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'hand_param'
#include "booster_interface/msg/detail/hand_param__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__booster_interface__msg__HandCommand __attribute__((deprecated))
#else
# define DEPRECATED__booster_interface__msg__HandCommand __declspec(deprecated)
#endif

namespace booster_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HandCommand_
{
  using Type = HandCommand_<ContainerAllocator>;

  explicit HandCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->force_mode = 0l;
      this->hand_index = 0l;
      this->hand_type = 0l;
    }
  }

  explicit HandCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->force_mode = 0l;
      this->hand_index = 0l;
      this->hand_type = 0l;
    }
  }

  // field types and members
  using _hand_param_type =
    std::vector<booster_interface::msg::HandParam_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<booster_interface::msg::HandParam_<ContainerAllocator>>>;
  _hand_param_type hand_param;
  using _force_mode_type =
    int32_t;
  _force_mode_type force_mode;
  using _hand_index_type =
    int32_t;
  _hand_index_type hand_index;
  using _hand_type_type =
    int32_t;
  _hand_type_type hand_type;

  // setters for named parameter idiom
  Type & set__hand_param(
    const std::vector<booster_interface::msg::HandParam_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<booster_interface::msg::HandParam_<ContainerAllocator>>> & _arg)
  {
    this->hand_param = _arg;
    return *this;
  }
  Type & set__force_mode(
    const int32_t & _arg)
  {
    this->force_mode = _arg;
    return *this;
  }
  Type & set__hand_index(
    const int32_t & _arg)
  {
    this->hand_index = _arg;
    return *this;
  }
  Type & set__hand_type(
    const int32_t & _arg)
  {
    this->hand_type = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    booster_interface::msg::HandCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const booster_interface::msg::HandCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<booster_interface::msg::HandCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<booster_interface::msg::HandCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::HandCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::HandCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::HandCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::HandCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<booster_interface::msg::HandCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<booster_interface::msg::HandCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__booster_interface__msg__HandCommand
    std::shared_ptr<booster_interface::msg::HandCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__booster_interface__msg__HandCommand
    std::shared_ptr<booster_interface::msg::HandCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HandCommand_ & other) const
  {
    if (this->hand_param != other.hand_param) {
      return false;
    }
    if (this->force_mode != other.force_mode) {
      return false;
    }
    if (this->hand_index != other.hand_index) {
      return false;
    }
    if (this->hand_type != other.hand_type) {
      return false;
    }
    return true;
  }
  bool operator!=(const HandCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HandCommand_

// alias to use template instance with default allocator
using HandCommand =
  booster_interface::msg::HandCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__HAND_COMMAND__STRUCT_HPP_
