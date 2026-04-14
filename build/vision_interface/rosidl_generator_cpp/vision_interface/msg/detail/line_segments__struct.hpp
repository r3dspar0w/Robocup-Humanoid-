// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vision_interface:msg/LineSegments.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__LINE_SEGMENTS__STRUCT_HPP_
#define VISION_INTERFACE__MSG__DETAIL__LINE_SEGMENTS__STRUCT_HPP_

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
# define DEPRECATED__vision_interface__msg__LineSegments __attribute__((deprecated))
#else
# define DEPRECATED__vision_interface__msg__LineSegments __declspec(deprecated)
#endif

namespace vision_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LineSegments_
{
  using Type = LineSegments_<ContainerAllocator>;

  explicit LineSegments_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit LineSegments_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _coordinates_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _coordinates_type coordinates;
  using _coordinates_uv_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _coordinates_uv_type coordinates_uv;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__coordinates(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->coordinates = _arg;
    return *this;
  }
  Type & set__coordinates_uv(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->coordinates_uv = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vision_interface::msg::LineSegments_<ContainerAllocator> *;
  using ConstRawPtr =
    const vision_interface::msg::LineSegments_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vision_interface::msg::LineSegments_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vision_interface::msg::LineSegments_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vision_interface::msg::LineSegments_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vision_interface::msg::LineSegments_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vision_interface::msg::LineSegments_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vision_interface::msg::LineSegments_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vision_interface::msg::LineSegments_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vision_interface::msg::LineSegments_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vision_interface__msg__LineSegments
    std::shared_ptr<vision_interface::msg::LineSegments_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vision_interface__msg__LineSegments
    std::shared_ptr<vision_interface::msg::LineSegments_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LineSegments_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->coordinates != other.coordinates) {
      return false;
    }
    if (this->coordinates_uv != other.coordinates_uv) {
      return false;
    }
    return true;
  }
  bool operator!=(const LineSegments_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LineSegments_

// alias to use template instance with default allocator
using LineSegments =
  vision_interface::msg::LineSegments_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vision_interface

#endif  // VISION_INTERFACE__MSG__DETAIL__LINE_SEGMENTS__STRUCT_HPP_
