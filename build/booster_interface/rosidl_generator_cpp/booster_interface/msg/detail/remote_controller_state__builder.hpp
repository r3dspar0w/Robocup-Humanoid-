// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from booster_interface:msg/RemoteControllerState.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__REMOTE_CONTROLLER_STATE__BUILDER_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__REMOTE_CONTROLLER_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "booster_interface/msg/detail/remote_controller_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace booster_interface
{

namespace msg
{

namespace builder
{

class Init_RemoteControllerState_hat_pos
{
public:
  explicit Init_RemoteControllerState_hat_pos(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  ::booster_interface::msg::RemoteControllerState hat_pos(::booster_interface::msg::RemoteControllerState::_hat_pos_type arg)
  {
    msg_.hat_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_hat_rd
{
public:
  explicit Init_RemoteControllerState_hat_rd(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_hat_pos hat_rd(::booster_interface::msg::RemoteControllerState::_hat_rd_type arg)
  {
    msg_.hat_rd = std::move(arg);
    return Init_RemoteControllerState_hat_pos(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_hat_ru
{
public:
  explicit Init_RemoteControllerState_hat_ru(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_hat_rd hat_ru(::booster_interface::msg::RemoteControllerState::_hat_ru_type arg)
  {
    msg_.hat_ru = std::move(arg);
    return Init_RemoteControllerState_hat_rd(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_hat_ld
{
public:
  explicit Init_RemoteControllerState_hat_ld(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_hat_ru hat_ld(::booster_interface::msg::RemoteControllerState::_hat_ld_type arg)
  {
    msg_.hat_ld = std::move(arg);
    return Init_RemoteControllerState_hat_ru(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_hat_lu
{
public:
  explicit Init_RemoteControllerState_hat_lu(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_hat_ld hat_lu(::booster_interface::msg::RemoteControllerState::_hat_lu_type arg)
  {
    msg_.hat_lu = std::move(arg);
    return Init_RemoteControllerState_hat_ld(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_hat_r
{
public:
  explicit Init_RemoteControllerState_hat_r(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_hat_lu hat_r(::booster_interface::msg::RemoteControllerState::_hat_r_type arg)
  {
    msg_.hat_r = std::move(arg);
    return Init_RemoteControllerState_hat_lu(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_hat_l
{
public:
  explicit Init_RemoteControllerState_hat_l(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_hat_r hat_l(::booster_interface::msg::RemoteControllerState::_hat_l_type arg)
  {
    msg_.hat_l = std::move(arg);
    return Init_RemoteControllerState_hat_r(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_hat_d
{
public:
  explicit Init_RemoteControllerState_hat_d(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_hat_l hat_d(::booster_interface::msg::RemoteControllerState::_hat_d_type arg)
  {
    msg_.hat_d = std::move(arg);
    return Init_RemoteControllerState_hat_l(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_hat_u
{
public:
  explicit Init_RemoteControllerState_hat_u(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_hat_d hat_u(::booster_interface::msg::RemoteControllerState::_hat_u_type arg)
  {
    msg_.hat_u = std::move(arg);
    return Init_RemoteControllerState_hat_d(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_hat_c
{
public:
  explicit Init_RemoteControllerState_hat_c(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_hat_u hat_c(::booster_interface::msg::RemoteControllerState::_hat_c_type arg)
  {
    msg_.hat_c = std::move(arg);
    return Init_RemoteControllerState_hat_u(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_start
{
public:
  explicit Init_RemoteControllerState_start(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_hat_c start(::booster_interface::msg::RemoteControllerState::_start_type arg)
  {
    msg_.start = std::move(arg);
    return Init_RemoteControllerState_hat_c(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_back
{
public:
  explicit Init_RemoteControllerState_back(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_start back(::booster_interface::msg::RemoteControllerState::_back_type arg)
  {
    msg_.back = std::move(arg);
    return Init_RemoteControllerState_start(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_rs
{
public:
  explicit Init_RemoteControllerState_rs(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_back rs(::booster_interface::msg::RemoteControllerState::_rs_type arg)
  {
    msg_.rs = std::move(arg);
    return Init_RemoteControllerState_back(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_ls
{
public:
  explicit Init_RemoteControllerState_ls(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_rs ls(::booster_interface::msg::RemoteControllerState::_ls_type arg)
  {
    msg_.ls = std::move(arg);
    return Init_RemoteControllerState_rs(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_rt
{
public:
  explicit Init_RemoteControllerState_rt(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_ls rt(::booster_interface::msg::RemoteControllerState::_rt_type arg)
  {
    msg_.rt = std::move(arg);
    return Init_RemoteControllerState_ls(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_lt
{
public:
  explicit Init_RemoteControllerState_lt(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_rt lt(::booster_interface::msg::RemoteControllerState::_lt_type arg)
  {
    msg_.lt = std::move(arg);
    return Init_RemoteControllerState_rt(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_rb
{
public:
  explicit Init_RemoteControllerState_rb(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_lt rb(::booster_interface::msg::RemoteControllerState::_rb_type arg)
  {
    msg_.rb = std::move(arg);
    return Init_RemoteControllerState_lt(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_lb
{
public:
  explicit Init_RemoteControllerState_lb(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_rb lb(::booster_interface::msg::RemoteControllerState::_lb_type arg)
  {
    msg_.lb = std::move(arg);
    return Init_RemoteControllerState_rb(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_y
{
public:
  explicit Init_RemoteControllerState_y(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_lb y(::booster_interface::msg::RemoteControllerState::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_RemoteControllerState_lb(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_x
{
public:
  explicit Init_RemoteControllerState_x(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_y x(::booster_interface::msg::RemoteControllerState::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_RemoteControllerState_y(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_b
{
public:
  explicit Init_RemoteControllerState_b(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_x b(::booster_interface::msg::RemoteControllerState::_b_type arg)
  {
    msg_.b = std::move(arg);
    return Init_RemoteControllerState_x(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_a
{
public:
  explicit Init_RemoteControllerState_a(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_b a(::booster_interface::msg::RemoteControllerState::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_RemoteControllerState_b(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_ry
{
public:
  explicit Init_RemoteControllerState_ry(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_a ry(::booster_interface::msg::RemoteControllerState::_ry_type arg)
  {
    msg_.ry = std::move(arg);
    return Init_RemoteControllerState_a(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_rx
{
public:
  explicit Init_RemoteControllerState_rx(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_ry rx(::booster_interface::msg::RemoteControllerState::_rx_type arg)
  {
    msg_.rx = std::move(arg);
    return Init_RemoteControllerState_ry(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_ly
{
public:
  explicit Init_RemoteControllerState_ly(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_rx ly(::booster_interface::msg::RemoteControllerState::_ly_type arg)
  {
    msg_.ly = std::move(arg);
    return Init_RemoteControllerState_rx(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_lx
{
public:
  explicit Init_RemoteControllerState_lx(::booster_interface::msg::RemoteControllerState & msg)
  : msg_(msg)
  {}
  Init_RemoteControllerState_ly lx(::booster_interface::msg::RemoteControllerState::_lx_type arg)
  {
    msg_.lx = std::move(arg);
    return Init_RemoteControllerState_ly(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

class Init_RemoteControllerState_event
{
public:
  Init_RemoteControllerState_event()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RemoteControllerState_lx event(::booster_interface::msg::RemoteControllerState::_event_type arg)
  {
    msg_.event = std::move(arg);
    return Init_RemoteControllerState_lx(msg_);
  }

private:
  ::booster_interface::msg::RemoteControllerState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::booster_interface::msg::RemoteControllerState>()
{
  return booster_interface::msg::builder::Init_RemoteControllerState_event();
}

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__REMOTE_CONTROLLER_STATE__BUILDER_HPP_
