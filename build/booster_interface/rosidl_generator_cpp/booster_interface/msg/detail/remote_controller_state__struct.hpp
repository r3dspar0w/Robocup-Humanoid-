// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from booster_interface:msg/RemoteControllerState.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__REMOTE_CONTROLLER_STATE__STRUCT_HPP_
#define BOOSTER_INTERFACE__MSG__DETAIL__REMOTE_CONTROLLER_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__booster_interface__msg__RemoteControllerState __attribute__((deprecated))
#else
# define DEPRECATED__booster_interface__msg__RemoteControllerState __declspec(deprecated)
#endif

namespace booster_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RemoteControllerState_
{
  using Type = RemoteControllerState_<ContainerAllocator>;

  explicit RemoteControllerState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->event = 0ul;
      this->lx = 0.0f;
      this->ly = 0.0f;
      this->rx = 0.0f;
      this->ry = 0.0f;
      this->a = false;
      this->b = false;
      this->x = false;
      this->y = false;
      this->lb = false;
      this->rb = false;
      this->lt = false;
      this->rt = false;
      this->ls = false;
      this->rs = false;
      this->back = false;
      this->start = false;
      this->hat_c = false;
      this->hat_u = false;
      this->hat_d = false;
      this->hat_l = false;
      this->hat_r = false;
      this->hat_lu = false;
      this->hat_ld = false;
      this->hat_ru = false;
      this->hat_rd = false;
      this->hat_pos = 0;
    }
  }

  explicit RemoteControllerState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->event = 0ul;
      this->lx = 0.0f;
      this->ly = 0.0f;
      this->rx = 0.0f;
      this->ry = 0.0f;
      this->a = false;
      this->b = false;
      this->x = false;
      this->y = false;
      this->lb = false;
      this->rb = false;
      this->lt = false;
      this->rt = false;
      this->ls = false;
      this->rs = false;
      this->back = false;
      this->start = false;
      this->hat_c = false;
      this->hat_u = false;
      this->hat_d = false;
      this->hat_l = false;
      this->hat_r = false;
      this->hat_lu = false;
      this->hat_ld = false;
      this->hat_ru = false;
      this->hat_rd = false;
      this->hat_pos = 0;
    }
  }

  // field types and members
  using _event_type =
    uint32_t;
  _event_type event;
  using _lx_type =
    float;
  _lx_type lx;
  using _ly_type =
    float;
  _ly_type ly;
  using _rx_type =
    float;
  _rx_type rx;
  using _ry_type =
    float;
  _ry_type ry;
  using _a_type =
    bool;
  _a_type a;
  using _b_type =
    bool;
  _b_type b;
  using _x_type =
    bool;
  _x_type x;
  using _y_type =
    bool;
  _y_type y;
  using _lb_type =
    bool;
  _lb_type lb;
  using _rb_type =
    bool;
  _rb_type rb;
  using _lt_type =
    bool;
  _lt_type lt;
  using _rt_type =
    bool;
  _rt_type rt;
  using _ls_type =
    bool;
  _ls_type ls;
  using _rs_type =
    bool;
  _rs_type rs;
  using _back_type =
    bool;
  _back_type back;
  using _start_type =
    bool;
  _start_type start;
  using _hat_c_type =
    bool;
  _hat_c_type hat_c;
  using _hat_u_type =
    bool;
  _hat_u_type hat_u;
  using _hat_d_type =
    bool;
  _hat_d_type hat_d;
  using _hat_l_type =
    bool;
  _hat_l_type hat_l;
  using _hat_r_type =
    bool;
  _hat_r_type hat_r;
  using _hat_lu_type =
    bool;
  _hat_lu_type hat_lu;
  using _hat_ld_type =
    bool;
  _hat_ld_type hat_ld;
  using _hat_ru_type =
    bool;
  _hat_ru_type hat_ru;
  using _hat_rd_type =
    bool;
  _hat_rd_type hat_rd;
  using _hat_pos_type =
    uint8_t;
  _hat_pos_type hat_pos;

  // setters for named parameter idiom
  Type & set__event(
    const uint32_t & _arg)
  {
    this->event = _arg;
    return *this;
  }
  Type & set__lx(
    const float & _arg)
  {
    this->lx = _arg;
    return *this;
  }
  Type & set__ly(
    const float & _arg)
  {
    this->ly = _arg;
    return *this;
  }
  Type & set__rx(
    const float & _arg)
  {
    this->rx = _arg;
    return *this;
  }
  Type & set__ry(
    const float & _arg)
  {
    this->ry = _arg;
    return *this;
  }
  Type & set__a(
    const bool & _arg)
  {
    this->a = _arg;
    return *this;
  }
  Type & set__b(
    const bool & _arg)
  {
    this->b = _arg;
    return *this;
  }
  Type & set__x(
    const bool & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const bool & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__lb(
    const bool & _arg)
  {
    this->lb = _arg;
    return *this;
  }
  Type & set__rb(
    const bool & _arg)
  {
    this->rb = _arg;
    return *this;
  }
  Type & set__lt(
    const bool & _arg)
  {
    this->lt = _arg;
    return *this;
  }
  Type & set__rt(
    const bool & _arg)
  {
    this->rt = _arg;
    return *this;
  }
  Type & set__ls(
    const bool & _arg)
  {
    this->ls = _arg;
    return *this;
  }
  Type & set__rs(
    const bool & _arg)
  {
    this->rs = _arg;
    return *this;
  }
  Type & set__back(
    const bool & _arg)
  {
    this->back = _arg;
    return *this;
  }
  Type & set__start(
    const bool & _arg)
  {
    this->start = _arg;
    return *this;
  }
  Type & set__hat_c(
    const bool & _arg)
  {
    this->hat_c = _arg;
    return *this;
  }
  Type & set__hat_u(
    const bool & _arg)
  {
    this->hat_u = _arg;
    return *this;
  }
  Type & set__hat_d(
    const bool & _arg)
  {
    this->hat_d = _arg;
    return *this;
  }
  Type & set__hat_l(
    const bool & _arg)
  {
    this->hat_l = _arg;
    return *this;
  }
  Type & set__hat_r(
    const bool & _arg)
  {
    this->hat_r = _arg;
    return *this;
  }
  Type & set__hat_lu(
    const bool & _arg)
  {
    this->hat_lu = _arg;
    return *this;
  }
  Type & set__hat_ld(
    const bool & _arg)
  {
    this->hat_ld = _arg;
    return *this;
  }
  Type & set__hat_ru(
    const bool & _arg)
  {
    this->hat_ru = _arg;
    return *this;
  }
  Type & set__hat_rd(
    const bool & _arg)
  {
    this->hat_rd = _arg;
    return *this;
  }
  Type & set__hat_pos(
    const uint8_t & _arg)
  {
    this->hat_pos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    booster_interface::msg::RemoteControllerState_<ContainerAllocator> *;
  using ConstRawPtr =
    const booster_interface::msg::RemoteControllerState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<booster_interface::msg::RemoteControllerState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<booster_interface::msg::RemoteControllerState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::RemoteControllerState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::RemoteControllerState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      booster_interface::msg::RemoteControllerState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<booster_interface::msg::RemoteControllerState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<booster_interface::msg::RemoteControllerState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<booster_interface::msg::RemoteControllerState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__booster_interface__msg__RemoteControllerState
    std::shared_ptr<booster_interface::msg::RemoteControllerState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__booster_interface__msg__RemoteControllerState
    std::shared_ptr<booster_interface::msg::RemoteControllerState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RemoteControllerState_ & other) const
  {
    if (this->event != other.event) {
      return false;
    }
    if (this->lx != other.lx) {
      return false;
    }
    if (this->ly != other.ly) {
      return false;
    }
    if (this->rx != other.rx) {
      return false;
    }
    if (this->ry != other.ry) {
      return false;
    }
    if (this->a != other.a) {
      return false;
    }
    if (this->b != other.b) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->lb != other.lb) {
      return false;
    }
    if (this->rb != other.rb) {
      return false;
    }
    if (this->lt != other.lt) {
      return false;
    }
    if (this->rt != other.rt) {
      return false;
    }
    if (this->ls != other.ls) {
      return false;
    }
    if (this->rs != other.rs) {
      return false;
    }
    if (this->back != other.back) {
      return false;
    }
    if (this->start != other.start) {
      return false;
    }
    if (this->hat_c != other.hat_c) {
      return false;
    }
    if (this->hat_u != other.hat_u) {
      return false;
    }
    if (this->hat_d != other.hat_d) {
      return false;
    }
    if (this->hat_l != other.hat_l) {
      return false;
    }
    if (this->hat_r != other.hat_r) {
      return false;
    }
    if (this->hat_lu != other.hat_lu) {
      return false;
    }
    if (this->hat_ld != other.hat_ld) {
      return false;
    }
    if (this->hat_ru != other.hat_ru) {
      return false;
    }
    if (this->hat_rd != other.hat_rd) {
      return false;
    }
    if (this->hat_pos != other.hat_pos) {
      return false;
    }
    return true;
  }
  bool operator!=(const RemoteControllerState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RemoteControllerState_

// alias to use template instance with default allocator
using RemoteControllerState =
  booster_interface::msg::RemoteControllerState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace booster_interface

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__REMOTE_CONTROLLER_STATE__STRUCT_HPP_
