// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from booster_msgs:msg/BinaryData.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_MSGS__MSG__DETAIL__BINARY_DATA__BUILDER_HPP_
#define BOOSTER_MSGS__MSG__DETAIL__BINARY_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "booster_msgs/msg/detail/binary_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace booster_msgs
{

namespace msg
{

namespace builder
{

class Init_BinaryData_data
{
public:
  Init_BinaryData_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::booster_msgs::msg::BinaryData data(::booster_msgs::msg::BinaryData::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::booster_msgs::msg::BinaryData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::booster_msgs::msg::BinaryData>()
{
  return booster_msgs::msg::builder::Init_BinaryData_data();
}

}  // namespace booster_msgs

#endif  // BOOSTER_MSGS__MSG__DETAIL__BINARY_DATA__BUILDER_HPP_
