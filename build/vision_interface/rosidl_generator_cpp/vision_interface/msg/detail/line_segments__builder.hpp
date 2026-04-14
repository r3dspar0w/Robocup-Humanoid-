// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vision_interface:msg/LineSegments.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__LINE_SEGMENTS__BUILDER_HPP_
#define VISION_INTERFACE__MSG__DETAIL__LINE_SEGMENTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vision_interface/msg/detail/line_segments__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vision_interface
{

namespace msg
{

namespace builder
{

class Init_LineSegments_coordinates_uv
{
public:
  explicit Init_LineSegments_coordinates_uv(::vision_interface::msg::LineSegments & msg)
  : msg_(msg)
  {}
  ::vision_interface::msg::LineSegments coordinates_uv(::vision_interface::msg::LineSegments::_coordinates_uv_type arg)
  {
    msg_.coordinates_uv = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vision_interface::msg::LineSegments msg_;
};

class Init_LineSegments_coordinates
{
public:
  explicit Init_LineSegments_coordinates(::vision_interface::msg::LineSegments & msg)
  : msg_(msg)
  {}
  Init_LineSegments_coordinates_uv coordinates(::vision_interface::msg::LineSegments::_coordinates_type arg)
  {
    msg_.coordinates = std::move(arg);
    return Init_LineSegments_coordinates_uv(msg_);
  }

private:
  ::vision_interface::msg::LineSegments msg_;
};

class Init_LineSegments_header
{
public:
  Init_LineSegments_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LineSegments_coordinates header(::vision_interface::msg::LineSegments::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_LineSegments_coordinates(msg_);
  }

private:
  ::vision_interface::msg::LineSegments msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vision_interface::msg::LineSegments>()
{
  return vision_interface::msg::builder::Init_LineSegments_header();
}

}  // namespace vision_interface

#endif  // VISION_INTERFACE__MSG__DETAIL__LINE_SEGMENTS__BUILDER_HPP_
