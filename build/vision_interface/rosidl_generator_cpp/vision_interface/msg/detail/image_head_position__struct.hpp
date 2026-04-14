// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vision_interface:msg/ImageHeadPosition.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__IMAGE_HEAD_POSITION__STRUCT_HPP_
#define VISION_INTERFACE__MSG__DETAIL__IMAGE_HEAD_POSITION__STRUCT_HPP_

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
// Member 'position'
#include "geometry_msgs/msg/detail/pose__struct.hpp"
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vision_interface__msg__ImageHeadPosition __attribute__((deprecated))
#else
# define DEPRECATED__vision_interface__msg__ImageHeadPosition __declspec(deprecated)
#endif

namespace vision_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ImageHeadPosition_
{
  using Type = ImageHeadPosition_<ContainerAllocator>;

  explicit ImageHeadPosition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    position(_init),
    image(_init)
  {
    (void)_init;
  }

  explicit ImageHeadPosition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    position(_alloc, _init),
    image(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _position_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _position_type position;
  using _image_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _image_type image;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__position(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__image(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->image = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vision_interface::msg::ImageHeadPosition_<ContainerAllocator> *;
  using ConstRawPtr =
    const vision_interface::msg::ImageHeadPosition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vision_interface::msg::ImageHeadPosition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vision_interface::msg::ImageHeadPosition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vision_interface::msg::ImageHeadPosition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vision_interface::msg::ImageHeadPosition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vision_interface::msg::ImageHeadPosition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vision_interface::msg::ImageHeadPosition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vision_interface::msg::ImageHeadPosition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vision_interface::msg::ImageHeadPosition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vision_interface__msg__ImageHeadPosition
    std::shared_ptr<vision_interface::msg::ImageHeadPosition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vision_interface__msg__ImageHeadPosition
    std::shared_ptr<vision_interface::msg::ImageHeadPosition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ImageHeadPosition_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->image != other.image) {
      return false;
    }
    return true;
  }
  bool operator!=(const ImageHeadPosition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ImageHeadPosition_

// alias to use template instance with default allocator
using ImageHeadPosition =
  vision_interface::msg::ImageHeadPosition_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vision_interface

#endif  // VISION_INTERFACE__MSG__DETAIL__IMAGE_HEAD_POSITION__STRUCT_HPP_
