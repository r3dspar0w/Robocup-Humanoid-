// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from booster_msgs:msg/BinaryData.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_MSGS__MSG__DETAIL__BINARY_DATA__STRUCT_HPP_
#define BOOSTER_MSGS__MSG__DETAIL__BINARY_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__booster_msgs__msg__BinaryData __attribute__((deprecated))
#else
# define DEPRECATED__booster_msgs__msg__BinaryData __declspec(deprecated)
#endif

namespace booster_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BinaryData_
{
  using Type = BinaryData_<ContainerAllocator>;

  explicit BinaryData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit BinaryData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _data_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__data(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    booster_msgs::msg::BinaryData_<ContainerAllocator> *;
  using ConstRawPtr =
    const booster_msgs::msg::BinaryData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<booster_msgs::msg::BinaryData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<booster_msgs::msg::BinaryData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      booster_msgs::msg::BinaryData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<booster_msgs::msg::BinaryData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      booster_msgs::msg::BinaryData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<booster_msgs::msg::BinaryData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<booster_msgs::msg::BinaryData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<booster_msgs::msg::BinaryData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__booster_msgs__msg__BinaryData
    std::shared_ptr<booster_msgs::msg::BinaryData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__booster_msgs__msg__BinaryData
    std::shared_ptr<booster_msgs::msg::BinaryData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BinaryData_ & other) const
  {
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const BinaryData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BinaryData_

// alias to use template instance with default allocator
using BinaryData =
  booster_msgs::msg::BinaryData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace booster_msgs

#endif  // BOOSTER_MSGS__MSG__DETAIL__BINARY_DATA__STRUCT_HPP_
