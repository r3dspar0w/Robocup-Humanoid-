// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vision_interface:msg/DetectionsTrack.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__DETECTIONS_TRACK__BUILDER_HPP_
#define VISION_INTERFACE__MSG__DETAIL__DETECTIONS_TRACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vision_interface/msg/detail/detections_track__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vision_interface
{

namespace msg
{

namespace builder
{

class Init_DetectionsTrack_corner_pos
{
public:
  explicit Init_DetectionsTrack_corner_pos(::vision_interface::msg::DetectionsTrack & msg)
  : msg_(msg)
  {}
  ::vision_interface::msg::DetectionsTrack corner_pos(::vision_interface::msg::DetectionsTrack::_corner_pos_type arg)
  {
    msg_.corner_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vision_interface::msg::DetectionsTrack msg_;
};

class Init_DetectionsTrack_radar_y
{
public:
  explicit Init_DetectionsTrack_radar_y(::vision_interface::msg::DetectionsTrack & msg)
  : msg_(msg)
  {}
  Init_DetectionsTrack_corner_pos radar_y(::vision_interface::msg::DetectionsTrack::_radar_y_type arg)
  {
    msg_.radar_y = std::move(arg);
    return Init_DetectionsTrack_corner_pos(msg_);
  }

private:
  ::vision_interface::msg::DetectionsTrack msg_;
};

class Init_DetectionsTrack_radar_x
{
public:
  explicit Init_DetectionsTrack_radar_x(::vision_interface::msg::DetectionsTrack & msg)
  : msg_(msg)
  {}
  Init_DetectionsTrack_radar_y radar_x(::vision_interface::msg::DetectionsTrack::_radar_x_type arg)
  {
    msg_.radar_x = std::move(arg);
    return Init_DetectionsTrack_radar_y(msg_);
  }

private:
  ::vision_interface::msg::DetectionsTrack msg_;
};

class Init_DetectionsTrack_detected_objects
{
public:
  explicit Init_DetectionsTrack_detected_objects(::vision_interface::msg::DetectionsTrack & msg)
  : msg_(msg)
  {}
  Init_DetectionsTrack_radar_x detected_objects(::vision_interface::msg::DetectionsTrack::_detected_objects_type arg)
  {
    msg_.detected_objects = std::move(arg);
    return Init_DetectionsTrack_radar_x(msg_);
  }

private:
  ::vision_interface::msg::DetectionsTrack msg_;
};

class Init_DetectionsTrack_ball_type
{
public:
  explicit Init_DetectionsTrack_ball_type(::vision_interface::msg::DetectionsTrack & msg)
  : msg_(msg)
  {}
  Init_DetectionsTrack_detected_objects ball_type(::vision_interface::msg::DetectionsTrack::_ball_type_type arg)
  {
    msg_.ball_type = std::move(arg);
    return Init_DetectionsTrack_detected_objects(msg_);
  }

private:
  ::vision_interface::msg::DetectionsTrack msg_;
};

class Init_DetectionsTrack_header
{
public:
  Init_DetectionsTrack_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectionsTrack_ball_type header(::vision_interface::msg::DetectionsTrack::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_DetectionsTrack_ball_type(msg_);
  }

private:
  ::vision_interface::msg::DetectionsTrack msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vision_interface::msg::DetectionsTrack>()
{
  return vision_interface::msg::builder::Init_DetectionsTrack_header();
}

}  // namespace vision_interface

#endif  // VISION_INTERFACE__MSG__DETAIL__DETECTIONS_TRACK__BUILDER_HPP_
