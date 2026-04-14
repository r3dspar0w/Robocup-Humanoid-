// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vision_interface:msg/SegmentationResult.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_RESULT__BUILDER_HPP_
#define VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vision_interface/msg/detail/segmentation_result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vision_interface
{

namespace msg
{

namespace builder
{

class Init_SegmentationResult_points
{
public:
  explicit Init_SegmentationResult_points(::vision_interface::msg::SegmentationResult & msg)
  : msg_(msg)
  {}
  ::vision_interface::msg::SegmentationResult points(::vision_interface::msg::SegmentationResult::_points_type arg)
  {
    msg_.points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vision_interface::msg::SegmentationResult msg_;
};

class Init_SegmentationResult_lines
{
public:
  explicit Init_SegmentationResult_lines(::vision_interface::msg::SegmentationResult & msg)
  : msg_(msg)
  {}
  Init_SegmentationResult_points lines(::vision_interface::msg::SegmentationResult::_lines_type arg)
  {
    msg_.lines = std::move(arg);
    return Init_SegmentationResult_points(msg_);
  }

private:
  ::vision_interface::msg::SegmentationResult msg_;
};

class Init_SegmentationResult_header
{
public:
  Init_SegmentationResult_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SegmentationResult_lines header(::vision_interface::msg::SegmentationResult::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_SegmentationResult_lines(msg_);
  }

private:
  ::vision_interface::msg::SegmentationResult msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vision_interface::msg::SegmentationResult>()
{
  return vision_interface::msg::builder::Init_SegmentationResult_header();
}

}  // namespace vision_interface

#endif  // VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_RESULT__BUILDER_HPP_
