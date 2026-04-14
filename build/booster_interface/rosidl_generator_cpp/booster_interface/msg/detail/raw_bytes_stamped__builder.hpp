// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from booster_interface:msg/RawBytesStamped.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__RAW_BYTES_STAMPED__BUILDER_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__RAW_BYTES_STAMPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "booster_interface/msg/detail/raw_bytes_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace booster_interface
{

namespace msg
{

namespace builder
{

class Init_RawBytesStamped_msg
{
public:
  explicit Init_RawBytesStamped_msg(::booster_interface::msg::RawBytesStamped & msg)
  : msg_(msg)
  {}
  ::booster_interface::msg::RawBytesStamped msg(::booster_interface::msg::RawBytesStamped::_msg_type arg)
  {
    msg_.msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::booster_interface::msg::RawBytesStamped msg_;
};

class Init_RawBytesStamped_header
{
public:
  Init_RawBytesStamped_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RawBytesStamped_msg header(::booster_interface::msg::RawBytesStamped::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RawBytesStamped_msg(msg_);
  }

private:
  ::booster_interface::msg::RawBytesStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::booster_interface::msg::RawBytesStamped>()
{
  return booster_interface::msg::builder::Init_RawBytesStamped_header();
}

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__RAW_BYTES_STAMPED__BUILDER_HPP_
