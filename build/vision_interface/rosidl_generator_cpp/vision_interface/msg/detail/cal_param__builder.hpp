// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vision_interface:msg/CalParam.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__CAL_PARAM__BUILDER_HPP_
#define VISION_INTERFACE__MSG__DETAIL__CAL_PARAM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vision_interface/msg/detail/cal_param__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vision_interface
{

namespace msg
{

namespace builder
{

class Init_CalParam_z_compensation
{
public:
  explicit Init_CalParam_z_compensation(::vision_interface::msg::CalParam & msg)
  : msg_(msg)
  {}
  ::vision_interface::msg::CalParam z_compensation(::vision_interface::msg::CalParam::_z_compensation_type arg)
  {
    msg_.z_compensation = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vision_interface::msg::CalParam msg_;
};

class Init_CalParam_yaw_compensation
{
public:
  explicit Init_CalParam_yaw_compensation(::vision_interface::msg::CalParam & msg)
  : msg_(msg)
  {}
  Init_CalParam_z_compensation yaw_compensation(::vision_interface::msg::CalParam::_yaw_compensation_type arg)
  {
    msg_.yaw_compensation = std::move(arg);
    return Init_CalParam_z_compensation(msg_);
  }

private:
  ::vision_interface::msg::CalParam msg_;
};

class Init_CalParam_pitch_compensation
{
public:
  Init_CalParam_pitch_compensation()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CalParam_yaw_compensation pitch_compensation(::vision_interface::msg::CalParam::_pitch_compensation_type arg)
  {
    msg_.pitch_compensation = std::move(arg);
    return Init_CalParam_yaw_compensation(msg_);
  }

private:
  ::vision_interface::msg::CalParam msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vision_interface::msg::CalParam>()
{
  return vision_interface::msg::builder::Init_CalParam_pitch_compensation();
}

}  // namespace vision_interface

#endif  // VISION_INTERFACE__MSG__DETAIL__CAL_PARAM__BUILDER_HPP_
