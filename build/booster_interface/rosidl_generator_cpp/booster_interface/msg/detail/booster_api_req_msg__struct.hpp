// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from booster_interface:msg/BoosterApiReqMsg.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__BOOSTER_API_REQ_MSG__STRUCT_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__BOOSTER_API_REQ_MSG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__booster_interface__msg__BoosterApiReqMsg __attribute__((deprecated))
#else
# define DEPRECATED__booster_interface__msg__BoosterApiReqMsg __declspec(deprecated)
#endif

namespace booster_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BoosterApiReqMsg_
{
  using Type = BoosterApiReqMsg_<ContainerAllocator>;

  explicit BoosterApiReqMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->api_id = 0ll;
      this->body = "";
    }
  }

  explicit BoosterApiReqMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : body(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->api_id = 0ll;
      this->body = "";
    }
  }

  // field types and members
  using _api_id_type =
    int64_t;
  _api_id_type api_id;
  using _body_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _body_type body;

  // setters for named parameter idiom
  Type & set__api_id(
    const int64_t & _arg)
  {
    this->api_id = _arg;
    return *this;
  }
  Type & set__body(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->body = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    booster_interface::msg::BoosterApiReqMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const booster_interface::msg::BoosterApiReqMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<booster_interface::msg::BoosterApiReqMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<booster_interface::msg::BoosterApiReqMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::BoosterApiReqMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::BoosterApiReqMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::BoosterApiReqMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::BoosterApiReqMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<booster_interface::msg::BoosterApiReqMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<booster_interface::msg::BoosterApiReqMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__booster_interface__msg__BoosterApiReqMsg
    std::shared_ptr<booster_interface::msg::BoosterApiReqMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__booster_interface__msg__BoosterApiReqMsg
    std::shared_ptr<booster_interface::msg::BoosterApiReqMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BoosterApiReqMsg_ & other) const
  {
    if (this->api_id != other.api_id) {
      return false;
    }
    if (this->body != other.body) {
      return false;
    }
    return true;
  }
  bool operator!=(const BoosterApiReqMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BoosterApiReqMsg_

// alias to use template instance with default allocator
using BoosterApiReqMsg =
  booster_interface::msg::BoosterApiReqMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__BOOSTER_API_REQ_MSG__STRUCT_HPP_
