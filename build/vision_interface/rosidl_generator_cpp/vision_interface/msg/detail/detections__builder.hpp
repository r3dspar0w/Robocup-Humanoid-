// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vision_interface:msg/Detections.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__DETECTIONS__BUILDER_HPP_
#define VISION_INTERFACE__MSG__DETAIL__DETECTIONS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vision_interface/msg/detail/detections__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vision_interface
{

namespace msg
{

namespace builder
{

class Init_Detections_corner_pos
{
public:
  explicit Init_Detections_corner_pos(::vision_interface::msg::Detections & msg)
  : msg_(msg)
  {}
  ::vision_interface::msg::Detections corner_pos(::vision_interface::msg::Detections::_corner_pos_type arg)
  {
    msg_.corner_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vision_interface::msg::Detections msg_;
};

class Init_Detections_radar_y
{
public:
  explicit Init_Detections_radar_y(::vision_interface::msg::Detections & msg)
  : msg_(msg)
  {}
  Init_Detections_corner_pos radar_y(::vision_interface::msg::Detections::_radar_y_type arg)
  {
    msg_.radar_y = std::move(arg);
    return Init_Detections_corner_pos(msg_);
  }

private:
  ::vision_interface::msg::Detections msg_;
};

class Init_Detections_radar_x
{
public:
  explicit Init_Detections_radar_x(::vision_interface::msg::Detections & msg)
  : msg_(msg)
  {}
  Init_Detections_radar_y radar_x(::vision_interface::msg::Detections::_radar_x_type arg)
  {
    msg_.radar_x = std::move(arg);
    return Init_Detections_radar_y(msg_);
  }

private:
  ::vision_interface::msg::Detections msg_;
};

class Init_Detections_detected_objects
{
public:
  explicit Init_Detections_detected_objects(::vision_interface::msg::Detections & msg)
  : msg_(msg)
  {}
  Init_Detections_radar_x detected_objects(::vision_interface::msg::Detections::_detected_objects_type arg)
  {
    msg_.detected_objects = std::move(arg);
    return Init_Detections_radar_x(msg_);
  }

private:
  ::vision_interface::msg::Detections msg_;
};

class Init_Detections_header
{
public:
  Init_Detections_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Detections_detected_objects header(::vision_interface::msg::Detections::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Detections_detected_objects(msg_);
  }

private:
  ::vision_interface::msg::Detections msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vision_interface::msg::Detections>()
{
  return vision_interface::msg::builder::Init_Detections_header();
}

}  // namespace vision_interface

#endif  // VISION_INTERFACE__MSG__DETAIL__DETECTIONS__BUILDER_HPP_
