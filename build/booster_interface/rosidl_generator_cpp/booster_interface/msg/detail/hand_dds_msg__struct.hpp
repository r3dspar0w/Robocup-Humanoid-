// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from booster_interface:msg/HandDdsMsg.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__HAND_DDS_MSG__STRUCT_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__HAND_DDS_MSG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'hands_vec'
#include "booster_interface/msg/detail/hand_command__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__booster_interface__msg__HandDdsMsg __attribute__((deprecated))
#else
# define DEPRECATED__booster_interface__msg__HandDdsMsg __declspec(deprecated)
#endif

namespace booster_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HandDdsMsg_
{
  using Type = HandDdsMsg_<ContainerAllocator>;

  explicit HandDdsMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit HandDdsMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _hands_vec_type =
    std::vector<booster_interface::msg::HandCommand_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<booster_interface::msg::HandCommand_<ContainerAllocator>>>;
  _hands_vec_type hands_vec;

  // setters for named parameter idiom
  Type & set__hands_vec(
    const std::vector<booster_interface::msg::HandCommand_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<booster_interface::msg::HandCommand_<ContainerAllocator>>> & _arg)
  {
    this->hands_vec = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    booster_interface::msg::HandDdsMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const booster_interface::msg::HandDdsMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<booster_interface::msg::HandDdsMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<booster_interface::msg::HandDdsMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::HandDdsMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::HandDdsMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::HandDdsMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::HandDdsMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<booster_interface::msg::HandDdsMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<booster_interface::msg::HandDdsMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__booster_interface__msg__HandDdsMsg
    std::shared_ptr<booster_interface::msg::HandDdsMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__booster_interface__msg__HandDdsMsg
    std::shared_ptr<booster_interface::msg::HandDdsMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HandDdsMsg_ & other) const
  {
    if (this->hands_vec != other.hands_vec) {
      return false;
    }
    return true;
  }
  bool operator!=(const HandDdsMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HandDdsMsg_

// alias to use template instance with default allocator
using HandDdsMsg =
  booster_interface::msg::HandDdsMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__HAND_DDS_MSG__STRUCT_HPP_
