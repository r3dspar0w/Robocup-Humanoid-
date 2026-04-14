// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vision_interface:msg/ImageHeadPosition.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__IMAGE_HEAD_POSITION__BUILDER_HPP_
#define VISION_INTERFACE__MSG__DETAIL__IMAGE_HEAD_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vision_interface/msg/detail/image_head_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vision_interface
{

namespace msg
{

namespace builder
{

class Init_ImageHeadPosition_image
{
public:
  explicit Init_ImageHeadPosition_image(::vision_interface::msg::ImageHeadPosition & msg)
  : msg_(msg)
  {}
  ::vision_interface::msg::ImageHeadPosition image(::vision_interface::msg::ImageHeadPosition::_image_type arg)
  {
    msg_.image = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vision_interface::msg::ImageHeadPosition msg_;
};

class Init_ImageHeadPosition_position
{
public:
  explicit Init_ImageHeadPosition_position(::vision_interface::msg::ImageHeadPosition & msg)
  : msg_(msg)
  {}
  Init_ImageHeadPosition_image position(::vision_interface::msg::ImageHeadPosition::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_ImageHeadPosition_image(msg_);
  }

private:
  ::vision_interface::msg::ImageHeadPosition msg_;
};

class Init_ImageHeadPosition_header
{
public:
  Init_ImageHeadPosition_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImageHeadPosition_position header(::vision_interface::msg::ImageHeadPosition::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ImageHeadPosition_position(msg_);
  }

private:
  ::vision_interface::msg::ImageHeadPosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vision_interface::msg::ImageHeadPosition>()
{
  return vision_interface::msg::builder::Init_ImageHeadPosition_header();
}

}  // namespace vision_interface

#endif  // VISION_INTERFACE__MSG__DETAIL__IMAGE_HEAD_POSITION__BUILDER_HPP_
