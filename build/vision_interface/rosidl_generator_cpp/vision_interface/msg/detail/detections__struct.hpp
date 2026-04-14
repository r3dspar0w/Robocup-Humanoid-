// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vision_interface:msg/Detections.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__DETECTIONS__STRUCT_HPP_
#define VISION_INTERFACE__MSG__DETAIL__DETECTIONS__STRUCT_HPP_

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
// Member 'detected_objects'
#include "vision_interface/msg/detail/detected_object__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vision_interface__msg__Detections __attribute__((deprecated))
#else
# define DEPRECATED__vision_interface__msg__Detections __declspec(deprecated)
#endif

namespace vision_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Detections_
{
  using Type = Detections_<ContainerAllocator>;

  explicit Detections_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit Detections_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _detected_objects_type =
    std::vector<vision_interface::msg::DetectedObject_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vision_interface::msg::DetectedObject_<ContainerAllocator>>>;
  _detected_objects_type detected_objects;
  using _radar_x_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _radar_x_type radar_x;
  using _radar_y_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _radar_y_type radar_y;
  using _corner_pos_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _corner_pos_type corner_pos;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__detected_objects(
    const std::vector<vision_interface::msg::DetectedObject_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vision_interface::msg::DetectedObject_<ContainerAllocator>>> & _arg)
  {
    this->detected_objects = _arg;
    return *this;
  }
  Type & set__radar_x(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->radar_x = _arg;
    return *this;
  }
  Type & set__radar_y(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->radar_y = _arg;
    return *this;
  }
  Type & set__corner_pos(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->corner_pos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vision_interface::msg::Detections_<ContainerAllocator> *;
  using ConstRawPtr =
    const vision_interface::msg::Detections_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vision_interface::msg::Detections_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vision_interface::msg::Detections_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vision_interface::msg::Detections_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vision_interface::msg::Detections_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vision_interface::msg::Detections_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vision_interface::msg::Detections_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vision_interface::msg::Detections_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vision_interface::msg::Detections_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vision_interface__msg__Detections
    std::shared_ptr<vision_interface::msg::Detections_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vision_interface__msg__Detections
    std::shared_ptr<vision_interface::msg::Detections_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Detections_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->detected_objects != other.detected_objects) {
      return false;
    }
    if (this->radar_x != other.radar_x) {
      return false;
    }
    if (this->radar_y != other.radar_y) {
      return false;
    }
    if (this->corner_pos != other.corner_pos) {
      return false;
    }
    return true;
  }
  bool operator!=(const Detections_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Detections_

// alias to use template instance with default allocator
using Detections =
  vision_interface::msg::Detections_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vision_interface

#endif  // VISION_INTERFACE__MSG__DETAIL__DETECTIONS__STRUCT_HPP_
