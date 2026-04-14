// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from booster_interface:msg/HandDdsMsg.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__HAND_DDS_MSG__BUILDER_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__HAND_DDS_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "booster_interface/msg/detail/hand_dds_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace booster_interface
{

namespace msg
{

namespace builder
{

class Init_HandDdsMsg_hands_vec
{
public:
  Init_HandDdsMsg_hands_vec()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::booster_interface::msg::HandDdsMsg hands_vec(::booster_interface::msg::HandDdsMsg::_hands_vec_type arg)
  {
    msg_.hands_vec = std::move(arg);
    return std::move(msg_);
  }

private:
  ::booster_interface::msg::HandDdsMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::booster_interface::msg::HandDdsMsg>()
{
  return booster_interface::msg::builder::Init_HandDdsMsg_hands_vec();
}

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__HAND_DDS_MSG__BUILDER_HPP_
