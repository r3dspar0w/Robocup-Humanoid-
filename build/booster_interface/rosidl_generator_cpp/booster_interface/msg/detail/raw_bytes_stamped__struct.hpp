// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from booster_interface:msg/RawBytesStamped.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__RAW_BYTES_STAMPED__STRUCT_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__RAW_BYTES_STAMPED__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__booster_interface__msg__RawBytesStamped __attribute__((deprecated))
#else
# define DEPRECATED__booster_interface__msg__RawBytesStamped __declspec(deprecated)
#endif

namespace booster_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RawBytesStamped_
{
  using Type = RawBytesStamped_<ContainerAllocator>;

  explicit RawBytesStamped_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit RawBytesStamped_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _msg_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _msg_type msg;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__msg(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->msg = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    booster_interface::msg::RawBytesStamped_<ContainerAllocator> *;
  using ConstRawPtr =
    const booster_interface::msg::RawBytesStamped_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<booster_interface::msg::RawBytesStamped_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<booster_interface::msg::RawBytesStamped_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::RawBytesStamped_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::RawBytesStamped_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::RawBytesStamped_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::RawBytesStamped_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<booster_interface::msg::RawBytesStamped_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<booster_interface::msg::RawBytesStamped_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__booster_interface__msg__RawBytesStamped
    std::shared_ptr<booster_interface::msg::RawBytesStamped_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__booster_interface__msg__RawBytesStamped
    std::shared_ptr<booster_interface::msg::RawBytesStamped_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RawBytesStamped_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->msg != other.msg) {
      return false;
    }
    return true;
  }
  bool operator!=(const RawBytesStamped_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RawBytesStamped_

// alias to use template instance with default allocator
using RawBytesStamped =
  booster_interface::msg::RawBytesStamped_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__RAW_BYTES_STAMPED__STRUCT_HPP_
