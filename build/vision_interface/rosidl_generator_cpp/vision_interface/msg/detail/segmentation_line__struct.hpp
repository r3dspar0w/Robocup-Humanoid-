// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vision_interface:msg/SegmentationLine.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_LINE__STRUCT_HPP_
#define VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_LINE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__vision_interface__msg__SegmentationLine __attribute__((deprecated))
#else
# define DEPRECATED__vision_interface__msg__SegmentationLine __declspec(deprecated)
#endif

namespace vision_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SegmentationLine_
{
  using Type = SegmentationLine_<ContainerAllocator>;

  explicit SegmentationLine_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->label = "";
      this->x1 = 0.0;
      this->y1 = 0.0;
      this->x2 = 0.0;
      this->y2 = 0.0;
      this->u1 = 0.0;
      this->v1 = 0.0;
      this->u2 = 0.0;
      this->v2 = 0.0;
    }
  }

  explicit SegmentationLine_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : label(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->label = "";
      this->x1 = 0.0;
      this->y1 = 0.0;
      this->x2 = 0.0;
      this->y2 = 0.0;
      this->u1 = 0.0;
      this->v1 = 0.0;
      this->u2 = 0.0;
      this->v2 = 0.0;
    }
  }

  // field types and members
  using _label_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _label_type label;
  using _x1_type =
    double;
  _x1_type x1;
  using _y1_type =
    double;
  _y1_type y1;
  using _x2_type =
    double;
  _x2_type x2;
  using _y2_type =
    double;
  _y2_type y2;
  using _u1_type =
    double;
  _u1_type u1;
  using _v1_type =
    double;
  _v1_type v1;
  using _u2_type =
    double;
  _u2_type u2;
  using _v2_type =
    double;
  _v2_type v2;

  // setters for named parameter idiom
  Type & set__label(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->label = _arg;
    return *this;
  }
  Type & set__x1(
    const double & _arg)
  {
    this->x1 = _arg;
    return *this;
  }
  Type & set__y1(
    const double & _arg)
  {
    this->y1 = _arg;
    return *this;
  }
  Type & set__x2(
    const double & _arg)
  {
    this->x2 = _arg;
    return *this;
  }
  Type & set__y2(
    const double & _arg)
  {
    this->y2 = _arg;
    return *this;
  }
  Type & set__u1(
    const double & _arg)
  {
    this->u1 = _arg;
    return *this;
  }
  Type & set__v1(
    const double & _arg)
  {
    this->v1 = _arg;
    return *this;
  }
  Type & set__u2(
    const double & _arg)
  {
    this->u2 = _arg;
    return *this;
  }
  Type & set__v2(
    const double & _arg)
  {
    this->v2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vision_interface::msg::SegmentationLine_<ContainerAllocator> *;
  using ConstRawPtr =
    const vision_interface::msg::SegmentationLine_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vision_interface::msg::SegmentationLine_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vision_interface::msg::SegmentationLine_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vision_interface::msg::SegmentationLine_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vision_interface::msg::SegmentationLine_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vision_interface::msg::SegmentationLine_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vision_interface::msg::SegmentationLine_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vision_interface::msg::SegmentationLine_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vision_interface::msg::SegmentationLine_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vision_interface__msg__SegmentationLine
    std::shared_ptr<vision_interface::msg::SegmentationLine_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vision_interface__msg__SegmentationLine
    std::shared_ptr<vision_interface::msg::SegmentationLine_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SegmentationLine_ & other) const
  {
    if (this->label != other.label) {
      return false;
    }
    if (this->x1 != other.x1) {
      return false;
    }
    if (this->y1 != other.y1) {
      return false;
    }
    if (this->x2 != other.x2) {
      return false;
    }
    if (this->y2 != other.y2) {
      return false;
    }
    if (this->u1 != other.u1) {
      return false;
    }
    if (this->v1 != other.v1) {
      return false;
    }
    if (this->u2 != other.u2) {
      return false;
    }
    if (this->v2 != other.v2) {
      return false;
    }
    return true;
  }
  bool operator!=(const SegmentationLine_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SegmentationLine_

// alias to use template instance with default allocator
using SegmentationLine =
  vision_interface::msg::SegmentationLine_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vision_interface

#endif  // VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_LINE__STRUCT_HPP_
