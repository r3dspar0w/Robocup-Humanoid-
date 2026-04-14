// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from booster_interface:srv/RpcService.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__SRV__DETAIL__RPC_SERVICE__STRUCT_HPP_
#define BOOSTER_INTERFACE__SRV__DETAIL__RPC_SERVICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'msg'
#include "booster_interface/msg/detail/booster_api_req_msg__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__booster_interface__srv__RpcService_Request __attribute__((deprecated))
#else
# define DEPRECATED__booster_interface__srv__RpcService_Request __declspec(deprecated)
#endif

namespace booster_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RpcService_Request_
{
  using Type = RpcService_Request_<ContainerAllocator>;

  explicit RpcService_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : msg(_init)
  {
    (void)_init;
  }

  explicit RpcService_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : msg(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _msg_type =
    booster_interface::msg::BoosterApiReqMsg_<ContainerAllocator>;
  _msg_type msg;

  // setters for named parameter idiom
  Type & set__msg(
    const booster_interface::msg::BoosterApiReqMsg_<ContainerAllocator> & _arg)
  {
    this->msg = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    booster_interface::srv::RpcService_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const booster_interface::srv::RpcService_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<booster_interface::srv::RpcService_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<booster_interface::srv::RpcService_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      booster_interface::srv::RpcService_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<booster_interface::srv::RpcService_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      booster_interface::srv::RpcService_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<booster_interface::srv::RpcService_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<booster_interface::srv::RpcService_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<booster_interface::srv::RpcService_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__booster_interface__srv__RpcService_Request
    std::shared_ptr<booster_interface::srv::RpcService_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__booster_interface__srv__RpcService_Request
    std::shared_ptr<booster_interface::srv::RpcService_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RpcService_Request_ & other) const
  {
    if (this->msg != other.msg) {
      return false;
    }
    return true;
  }
  bool operator!=(const RpcService_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RpcService_Request_

// alias to use template instance with default allocator
using RpcService_Request =
  booster_interface::srv::RpcService_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace booster_interface


// Include directives for member types
// Member 'msg'
#include "booster_interface/msg/detail/booster_api_resp_msg__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__booster_interface__srv__RpcService_Response __attribute__((deprecated))
#else
# define DEPRECATED__booster_interface__srv__RpcService_Response __declspec(deprecated)
#endif

namespace booster_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RpcService_Response_
{
  using Type = RpcService_Response_<ContainerAllocator>;

  explicit RpcService_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : msg(_init)
  {
    (void)_init;
  }

  explicit RpcService_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : msg(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _msg_type =
    booster_interface::msg::BoosterApiRespMsg_<ContainerAllocator>;
  _msg_type msg;

  // setters for named parameter idiom
  Type & set__msg(
    const booster_interface::msg::BoosterApiRespMsg_<ContainerAllocator> & _arg)
  {
    this->msg = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    booster_interface::srv::RpcService_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const booster_interface::srv::RpcService_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<booster_interface::srv::RpcService_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<booster_interface::srv::RpcService_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      booster_interface::srv::RpcService_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<booster_interface::srv::RpcService_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      booster_interface::srv::RpcService_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<booster_interface::srv::RpcService_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<booster_interface::srv::RpcService_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<booster_interface::srv::RpcService_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__booster_interface__srv__RpcService_Response
    std::shared_ptr<booster_interface::srv::RpcService_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__booster_interface__srv__RpcService_Response
    std::shared_ptr<booster_interface::srv::RpcService_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RpcService_Response_ & other) const
  {
    if (this->msg != other.msg) {
      return false;
    }
    return true;
  }
  bool operator!=(const RpcService_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RpcService_Response_

// alias to use template instance with default allocator
using RpcService_Response =
  booster_interface::srv::RpcService_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace booster_interface

namespace booster_interface
{

namespace srv
{

struct RpcService
{
  using Request = booster_interface::srv::RpcService_Request;
  using Response = booster_interface::srv::RpcService_Response;
};

}  // namespace srv

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__SRV__DETAIL__RPC_SERVICE__STRUCT_HPP_
