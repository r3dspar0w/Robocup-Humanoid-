// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from booster_interface:srv/AgentService.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__SRV__DETAIL__AGENT_SERVICE__STRUCT_HPP_
#define BOOSTER_INTERFACE__SRV__DETAIL__AGENT_SERVICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__booster_interface__srv__AgentService_Request __attribute__((deprecated))
#else
# define DEPRECATED__booster_interface__srv__AgentService_Request __declspec(deprecated)
#endif

namespace booster_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AgentService_Request_
{
  using Type = AgentService_Request_<ContainerAllocator>;

  explicit AgentService_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->body = "";
    }
  }

  explicit AgentService_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : body(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->body = "";
    }
  }

  // field types and members
  using _body_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _body_type body;

  // setters for named parameter idiom
  Type & set__body(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->body = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    booster_interface::srv::AgentService_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const booster_interface::srv::AgentService_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<booster_interface::srv::AgentService_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<booster_interface::srv::AgentService_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      booster_interface::srv::AgentService_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<booster_interface::srv::AgentService_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      booster_interface::srv::AgentService_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<booster_interface::srv::AgentService_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<booster_interface::srv::AgentService_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<booster_interface::srv::AgentService_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__booster_interface__srv__AgentService_Request
    std::shared_ptr<booster_interface::srv::AgentService_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__booster_interface__srv__AgentService_Request
    std::shared_ptr<booster_interface::srv::AgentService_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AgentService_Request_ & other) const
  {
    if (this->body != other.body) {
      return false;
    }
    return true;
  }
  bool operator!=(const AgentService_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AgentService_Request_

// alias to use template instance with default allocator
using AgentService_Request =
  booster_interface::srv::AgentService_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace booster_interface


#ifndef _WIN32
# define DEPRECATED__booster_interface__srv__AgentService_Response __attribute__((deprecated))
#else
# define DEPRECATED__booster_interface__srv__AgentService_Response __declspec(deprecated)
#endif

namespace booster_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AgentService_Response_
{
  using Type = AgentService_Response_<ContainerAllocator>;

  explicit AgentService_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->body = "";
    }
  }

  explicit AgentService_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : body(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->body = "";
    }
  }

  // field types and members
  using _body_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _body_type body;

  // setters for named parameter idiom
  Type & set__body(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->body = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    booster_interface::srv::AgentService_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const booster_interface::srv::AgentService_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<booster_interface::srv::AgentService_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<booster_interface::srv::AgentService_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      booster_interface::srv::AgentService_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<booster_interface::srv::AgentService_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      booster_interface::srv::AgentService_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<booster_interface::srv::AgentService_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<booster_interface::srv::AgentService_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<booster_interface::srv::AgentService_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__booster_interface__srv__AgentService_Response
    std::shared_ptr<booster_interface::srv::AgentService_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__booster_interface__srv__AgentService_Response
    std::shared_ptr<booster_interface::srv::AgentService_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AgentService_Response_ & other) const
  {
    if (this->body != other.body) {
      return false;
    }
    return true;
  }
  bool operator!=(const AgentService_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AgentService_Response_

// alias to use template instance with default allocator
using AgentService_Response =
  booster_interface::srv::AgentService_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace booster_interface

namespace booster_interface
{

namespace srv
{

struct AgentService
{
  using Request = booster_interface::srv::AgentService_Request;
  using Response = booster_interface::srv::AgentService_Response;
};

}  // namespace srv

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__SRV__DETAIL__AGENT_SERVICE__STRUCT_HPP_
