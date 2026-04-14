// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vision_interface:msg/SegmentationPoint.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_POINT__STRUCT_HPP_
#define VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_POINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__vision_interface__msg__SegmentationPoint __attribute__((deprecated))
#else
# define DEPRECATED__vision_interface__msg__SegmentationPoint __declspec(deprecated)
#endif

namespace vision_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SegmentationPoint_
{
  using Type = SegmentationPoint_<ContainerAllocator>;

  explicit SegmentationPoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->label = "";
      this->x = 0.0;
      this->y = 0.0;
      this->u = 0.0;
      this->v = 0.0;
    }
  }

  explicit SegmentationPoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : label(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->label = "";
      this->x = 0.0;
      this->y = 0.0;
      this->u = 0.0;
      this->v = 0.0;
    }
  }

  // field types and members
  using _label_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _label_type label;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _u_type =
    double;
  _u_type u;
  using _v_type =
    double;
  _v_type v;

  // setters for named parameter idiom
  Type & set__label(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->label = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__u(
    const double & _arg)
  {
    this->u = _arg;
    return *this;
  }
  Type & set__v(
    const double & _arg)
  {
    this->v = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vision_interface::msg::SegmentationPoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const vision_interface::msg::SegmentationPoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vision_interface::msg::SegmentationPoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vision_interface::msg::SegmentationPoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vision_interface::msg::SegmentationPoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vision_interface::msg::SegmentationPoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vision_interface::msg::SegmentationPoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vision_interface::msg::SegmentationPoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vision_interface::msg::SegmentationPoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vision_interface::msg::SegmentationPoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vision_interface__msg__SegmentationPoint
    std::shared_ptr<vision_interface::msg::SegmentationPoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vision_interface__msg__SegmentationPoint
    std::shared_ptr<vision_interface::msg::SegmentationPoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SegmentationPoint_ & other) const
  {
    if (this->label != other.label) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->u != other.u) {
      return false;
    }
    if (this->v != other.v) {
      return false;
    }
    return true;
  }
  bool operator!=(const SegmentationPoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SegmentationPoint_

// alias to use template instance with default allocator
using SegmentationPoint =
  vision_interface::msg::SegmentationPoint_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vision_interface

#endif  // VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_POINT__STRUCT_HPP_
