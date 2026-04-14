// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vision_interface:msg/DetectedObject.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__DETECTED_OBJECT__BUILDER_HPP_
#define VISION_INTERFACE__MSG__DETAIL__DETECTED_OBJECT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vision_interface/msg/detail/detected_object__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vision_interface
{

namespace msg
{

namespace builder
{

class Init_DetectedObject_position_confidence
{
public:
  explicit Init_DetectedObject_position_confidence(::vision_interface::msg::DetectedObject & msg)
  : msg_(msg)
  {}
  ::vision_interface::msg::DetectedObject position_confidence(::vision_interface::msg::DetectedObject::_position_confidence_type arg)
  {
    msg_.position_confidence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vision_interface::msg::DetectedObject msg_;
};

class Init_DetectedObject_position_cam
{
public:
  explicit Init_DetectedObject_position_cam(::vision_interface::msg::DetectedObject & msg)
  : msg_(msg)
  {}
  Init_DetectedObject_position_confidence position_cam(::vision_interface::msg::DetectedObject::_position_cam_type arg)
  {
    msg_.position_cam = std::move(arg);
    return Init_DetectedObject_position_confidence(msg_);
  }

private:
  ::vision_interface::msg::DetectedObject msg_;
};

class Init_DetectedObject_position_projection
{
public:
  explicit Init_DetectedObject_position_projection(::vision_interface::msg::DetectedObject & msg)
  : msg_(msg)
  {}
  Init_DetectedObject_position_cam position_projection(::vision_interface::msg::DetectedObject::_position_projection_type arg)
  {
    msg_.position_projection = std::move(arg);
    return Init_DetectedObject_position_cam(msg_);
  }

private:
  ::vision_interface::msg::DetectedObject msg_;
};

class Init_DetectedObject_position
{
public:
  explicit Init_DetectedObject_position(::vision_interface::msg::DetectedObject & msg)
  : msg_(msg)
  {}
  Init_DetectedObject_position_projection position(::vision_interface::msg::DetectedObject::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_DetectedObject_position_projection(msg_);
  }

private:
  ::vision_interface::msg::DetectedObject msg_;
};

class Init_DetectedObject_received_pos
{
public:
  explicit Init_DetectedObject_received_pos(::vision_interface::msg::DetectedObject & msg)
  : msg_(msg)
  {}
  Init_DetectedObject_position received_pos(::vision_interface::msg::DetectedObject::_received_pos_type arg)
  {
    msg_.received_pos = std::move(arg);
    return Init_DetectedObject_position(msg_);
  }

private:
  ::vision_interface::msg::DetectedObject msg_;
};

class Init_DetectedObject_target_uv
{
public:
  explicit Init_DetectedObject_target_uv(::vision_interface::msg::DetectedObject & msg)
  : msg_(msg)
  {}
  Init_DetectedObject_received_pos target_uv(::vision_interface::msg::DetectedObject::_target_uv_type arg)
  {
    msg_.target_uv = std::move(arg);
    return Init_DetectedObject_received_pos(msg_);
  }

private:
  ::vision_interface::msg::DetectedObject msg_;
};

class Init_DetectedObject_ymax
{
public:
  explicit Init_DetectedObject_ymax(::vision_interface::msg::DetectedObject & msg)
  : msg_(msg)
  {}
  Init_DetectedObject_target_uv ymax(::vision_interface::msg::DetectedObject::_ymax_type arg)
  {
    msg_.ymax = std::move(arg);
    return Init_DetectedObject_target_uv(msg_);
  }

private:
  ::vision_interface::msg::DetectedObject msg_;
};

class Init_DetectedObject_xmax
{
public:
  explicit Init_DetectedObject_xmax(::vision_interface::msg::DetectedObject & msg)
  : msg_(msg)
  {}
  Init_DetectedObject_ymax xmax(::vision_interface::msg::DetectedObject::_xmax_type arg)
  {
    msg_.xmax = std::move(arg);
    return Init_DetectedObject_ymax(msg_);
  }

private:
  ::vision_interface::msg::DetectedObject msg_;
};

class Init_DetectedObject_ymin
{
public:
  explicit Init_DetectedObject_ymin(::vision_interface::msg::DetectedObject & msg)
  : msg_(msg)
  {}
  Init_DetectedObject_xmax ymin(::vision_interface::msg::DetectedObject::_ymin_type arg)
  {
    msg_.ymin = std::move(arg);
    return Init_DetectedObject_xmax(msg_);
  }

private:
  ::vision_interface::msg::DetectedObject msg_;
};

class Init_DetectedObject_xmin
{
public:
  explicit Init_DetectedObject_xmin(::vision_interface::msg::DetectedObject & msg)
  : msg_(msg)
  {}
  Init_DetectedObject_ymin xmin(::vision_interface::msg::DetectedObject::_xmin_type arg)
  {
    msg_.xmin = std::move(arg);
    return Init_DetectedObject_ymin(msg_);
  }

private:
  ::vision_interface::msg::DetectedObject msg_;
};

class Init_DetectedObject_confidence
{
public:
  explicit Init_DetectedObject_confidence(::vision_interface::msg::DetectedObject & msg)
  : msg_(msg)
  {}
  Init_DetectedObject_xmin confidence(::vision_interface::msg::DetectedObject::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_DetectedObject_xmin(msg_);
  }

private:
  ::vision_interface::msg::DetectedObject msg_;
};

class Init_DetectedObject_color
{
public:
  explicit Init_DetectedObject_color(::vision_interface::msg::DetectedObject & msg)
  : msg_(msg)
  {}
  Init_DetectedObject_confidence color(::vision_interface::msg::DetectedObject::_color_type arg)
  {
    msg_.color = std::move(arg);
    return Init_DetectedObject_confidence(msg_);
  }

private:
  ::vision_interface::msg::DetectedObject msg_;
};

class Init_DetectedObject_label
{
public:
  Init_DetectedObject_label()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectedObject_color label(::vision_interface::msg::DetectedObject::_label_type arg)
  {
    msg_.label = std::move(arg);
    return Init_DetectedObject_color(msg_);
  }

private:
  ::vision_interface::msg::DetectedObject msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vision_interface::msg::DetectedObject>()
{
  return vision_interface::msg::builder::Init_DetectedObject_label();
}

}  // namespace vision_interface

#endif  // VISION_INTERFACE__MSG__DETAIL__DETECTED_OBJECT__BUILDER_HPP_
