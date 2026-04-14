// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vision_interface:msg/SegmentationLine.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_LINE__BUILDER_HPP_
#define VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_LINE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vision_interface/msg/detail/segmentation_line__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vision_interface
{

namespace msg
{

namespace builder
{

class Init_SegmentationLine_v2
{
public:
  explicit Init_SegmentationLine_v2(::vision_interface::msg::SegmentationLine & msg)
  : msg_(msg)
  {}
  ::vision_interface::msg::SegmentationLine v2(::vision_interface::msg::SegmentationLine::_v2_type arg)
  {
    msg_.v2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vision_interface::msg::SegmentationLine msg_;
};

class Init_SegmentationLine_u2
{
public:
  explicit Init_SegmentationLine_u2(::vision_interface::msg::SegmentationLine & msg)
  : msg_(msg)
  {}
  Init_SegmentationLine_v2 u2(::vision_interface::msg::SegmentationLine::_u2_type arg)
  {
    msg_.u2 = std::move(arg);
    return Init_SegmentationLine_v2(msg_);
  }

private:
  ::vision_interface::msg::SegmentationLine msg_;
};

class Init_SegmentationLine_v1
{
public:
  explicit Init_SegmentationLine_v1(::vision_interface::msg::SegmentationLine & msg)
  : msg_(msg)
  {}
  Init_SegmentationLine_u2 v1(::vision_interface::msg::SegmentationLine::_v1_type arg)
  {
    msg_.v1 = std::move(arg);
    return Init_SegmentationLine_u2(msg_);
  }

private:
  ::vision_interface::msg::SegmentationLine msg_;
};

class Init_SegmentationLine_u1
{
public:
  explicit Init_SegmentationLine_u1(::vision_interface::msg::SegmentationLine & msg)
  : msg_(msg)
  {}
  Init_SegmentationLine_v1 u1(::vision_interface::msg::SegmentationLine::_u1_type arg)
  {
    msg_.u1 = std::move(arg);
    return Init_SegmentationLine_v1(msg_);
  }

private:
  ::vision_interface::msg::SegmentationLine msg_;
};

class Init_SegmentationLine_y2
{
public:
  explicit Init_SegmentationLine_y2(::vision_interface::msg::SegmentationLine & msg)
  : msg_(msg)
  {}
  Init_SegmentationLine_u1 y2(::vision_interface::msg::SegmentationLine::_y2_type arg)
  {
    msg_.y2 = std::move(arg);
    return Init_SegmentationLine_u1(msg_);
  }

private:
  ::vision_interface::msg::SegmentationLine msg_;
};

class Init_SegmentationLine_x2
{
public:
  explicit Init_SegmentationLine_x2(::vision_interface::msg::SegmentationLine & msg)
  : msg_(msg)
  {}
  Init_SegmentationLine_y2 x2(::vision_interface::msg::SegmentationLine::_x2_type arg)
  {
    msg_.x2 = std::move(arg);
    return Init_SegmentationLine_y2(msg_);
  }

private:
  ::vision_interface::msg::SegmentationLine msg_;
};

class Init_SegmentationLine_y1
{
public:
  explicit Init_SegmentationLine_y1(::vision_interface::msg::SegmentationLine & msg)
  : msg_(msg)
  {}
  Init_SegmentationLine_x2 y1(::vision_interface::msg::SegmentationLine::_y1_type arg)
  {
    msg_.y1 = std::move(arg);
    return Init_SegmentationLine_x2(msg_);
  }

private:
  ::vision_interface::msg::SegmentationLine msg_;
};

class Init_SegmentationLine_x1
{
public:
  explicit Init_SegmentationLine_x1(::vision_interface::msg::SegmentationLine & msg)
  : msg_(msg)
  {}
  Init_SegmentationLine_y1 x1(::vision_interface::msg::SegmentationLine::_x1_type arg)
  {
    msg_.x1 = std::move(arg);
    return Init_SegmentationLine_y1(msg_);
  }

private:
  ::vision_interface::msg::SegmentationLine msg_;
};

class Init_SegmentationLine_label
{
public:
  Init_SegmentationLine_label()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SegmentationLine_x1 label(::vision_interface::msg::SegmentationLine::_label_type arg)
  {
    msg_.label = std::move(arg);
    return Init_SegmentationLine_x1(msg_);
  }

private:
  ::vision_interface::msg::SegmentationLine msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vision_interface::msg::SegmentationLine>()
{
  return vision_interface::msg::builder::Init_SegmentationLine_label();
}

}  // namespace vision_interface

#endif  // VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_LINE__BUILDER_HPP_
