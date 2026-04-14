// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vision_interface:msg/SegmentationPoint.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_POINT__BUILDER_HPP_
#define VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_POINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vision_interface/msg/detail/segmentation_point__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vision_interface
{

namespace msg
{

namespace builder
{

class Init_SegmentationPoint_v
{
public:
  explicit Init_SegmentationPoint_v(::vision_interface::msg::SegmentationPoint & msg)
  : msg_(msg)
  {}
  ::vision_interface::msg::SegmentationPoint v(::vision_interface::msg::SegmentationPoint::_v_type arg)
  {
    msg_.v = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vision_interface::msg::SegmentationPoint msg_;
};

class Init_SegmentationPoint_u
{
public:
  explicit Init_SegmentationPoint_u(::vision_interface::msg::SegmentationPoint & msg)
  : msg_(msg)
  {}
  Init_SegmentationPoint_v u(::vision_interface::msg::SegmentationPoint::_u_type arg)
  {
    msg_.u = std::move(arg);
    return Init_SegmentationPoint_v(msg_);
  }

private:
  ::vision_interface::msg::SegmentationPoint msg_;
};

class Init_SegmentationPoint_y
{
public:
  explicit Init_SegmentationPoint_y(::vision_interface::msg::SegmentationPoint & msg)
  : msg_(msg)
  {}
  Init_SegmentationPoint_u y(::vision_interface::msg::SegmentationPoint::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_SegmentationPoint_u(msg_);
  }

private:
  ::vision_interface::msg::SegmentationPoint msg_;
};

class Init_SegmentationPoint_x
{
public:
  explicit Init_SegmentationPoint_x(::vision_interface::msg::SegmentationPoint & msg)
  : msg_(msg)
  {}
  Init_SegmentationPoint_y x(::vision_interface::msg::SegmentationPoint::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_SegmentationPoint_y(msg_);
  }

private:
  ::vision_interface::msg::SegmentationPoint msg_;
};

class Init_SegmentationPoint_label
{
public:
  Init_SegmentationPoint_label()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SegmentationPoint_x label(::vision_interface::msg::SegmentationPoint::_label_type arg)
  {
    msg_.label = std::move(arg);
    return Init_SegmentationPoint_x(msg_);
  }

private:
  ::vision_interface::msg::SegmentationPoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vision_interface::msg::SegmentationPoint>()
{
  return vision_interface::msg::builder::Init_SegmentationPoint_label();
}

}  // namespace vision_interface

#endif  // VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_POINT__BUILDER_HPP_
