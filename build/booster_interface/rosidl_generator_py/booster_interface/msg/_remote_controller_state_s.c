// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from booster_interface:msg/RemoteControllerState.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "booster_interface/msg/detail/remote_controller_state__struct.h"
#include "booster_interface/msg/detail/remote_controller_state__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool booster_interface__msg__remote_controller_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[69];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("booster_interface.msg._remote_controller_state.RemoteControllerState", full_classname_dest, 68) == 0);
  }
  booster_interface__msg__RemoteControllerState * ros_message = _ros_message;
  {  // event
    PyObject * field = PyObject_GetAttrString(_pymsg, "event");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->event = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // lx
    PyObject * field = PyObject_GetAttrString(_pymsg, "lx");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->lx = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ly
    PyObject * field = PyObject_GetAttrString(_pymsg, "ly");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ly = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rx
    PyObject * field = PyObject_GetAttrString(_pymsg, "rx");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rx = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ry
    PyObject * field = PyObject_GetAttrString(_pymsg, "ry");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ry = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a
    PyObject * field = PyObject_GetAttrString(_pymsg, "a");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->a = (Py_True == field);
    Py_DECREF(field);
  }
  {  // b
    PyObject * field = PyObject_GetAttrString(_pymsg, "b");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->b = (Py_True == field);
    Py_DECREF(field);
  }
  {  // x
    PyObject * field = PyObject_GetAttrString(_pymsg, "x");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->x = (Py_True == field);
    Py_DECREF(field);
  }
  {  // y
    PyObject * field = PyObject_GetAttrString(_pymsg, "y");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->y = (Py_True == field);
    Py_DECREF(field);
  }
  {  // lb
    PyObject * field = PyObject_GetAttrString(_pymsg, "lb");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->lb = (Py_True == field);
    Py_DECREF(field);
  }
  {  // rb
    PyObject * field = PyObject_GetAttrString(_pymsg, "rb");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->rb = (Py_True == field);
    Py_DECREF(field);
  }
  {  // lt
    PyObject * field = PyObject_GetAttrString(_pymsg, "lt");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->lt = (Py_True == field);
    Py_DECREF(field);
  }
  {  // rt
    PyObject * field = PyObject_GetAttrString(_pymsg, "rt");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->rt = (Py_True == field);
    Py_DECREF(field);
  }
  {  // ls
    PyObject * field = PyObject_GetAttrString(_pymsg, "ls");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->ls = (Py_True == field);
    Py_DECREF(field);
  }
  {  // rs
    PyObject * field = PyObject_GetAttrString(_pymsg, "rs");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->rs = (Py_True == field);
    Py_DECREF(field);
  }
  {  // back
    PyObject * field = PyObject_GetAttrString(_pymsg, "back");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->back = (Py_True == field);
    Py_DECREF(field);
  }
  {  // start
    PyObject * field = PyObject_GetAttrString(_pymsg, "start");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->start = (Py_True == field);
    Py_DECREF(field);
  }
  {  // hat_c
    PyObject * field = PyObject_GetAttrString(_pymsg, "hat_c");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->hat_c = (Py_True == field);
    Py_DECREF(field);
  }
  {  // hat_u
    PyObject * field = PyObject_GetAttrString(_pymsg, "hat_u");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->hat_u = (Py_True == field);
    Py_DECREF(field);
  }
  {  // hat_d
    PyObject * field = PyObject_GetAttrString(_pymsg, "hat_d");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->hat_d = (Py_True == field);
    Py_DECREF(field);
  }
  {  // hat_l
    PyObject * field = PyObject_GetAttrString(_pymsg, "hat_l");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->hat_l = (Py_True == field);
    Py_DECREF(field);
  }
  {  // hat_r
    PyObject * field = PyObject_GetAttrString(_pymsg, "hat_r");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->hat_r = (Py_True == field);
    Py_DECREF(field);
  }
  {  // hat_lu
    PyObject * field = PyObject_GetAttrString(_pymsg, "hat_lu");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->hat_lu = (Py_True == field);
    Py_DECREF(field);
  }
  {  // hat_ld
    PyObject * field = PyObject_GetAttrString(_pymsg, "hat_ld");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->hat_ld = (Py_True == field);
    Py_DECREF(field);
  }
  {  // hat_ru
    PyObject * field = PyObject_GetAttrString(_pymsg, "hat_ru");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->hat_ru = (Py_True == field);
    Py_DECREF(field);
  }
  {  // hat_rd
    PyObject * field = PyObject_GetAttrString(_pymsg, "hat_rd");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->hat_rd = (Py_True == field);
    Py_DECREF(field);
  }
  {  // hat_pos
    PyObject * field = PyObject_GetAttrString(_pymsg, "hat_pos");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->hat_pos = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * booster_interface__msg__remote_controller_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RemoteControllerState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("booster_interface.msg._remote_controller_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RemoteControllerState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  booster_interface__msg__RemoteControllerState * ros_message = (booster_interface__msg__RemoteControllerState *)raw_ros_message;
  {  // event
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->event);
    {
      int rc = PyObject_SetAttrString(_pymessage, "event", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lx
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->lx);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lx", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ly
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ly);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ly", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rx
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rx);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rx", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ry
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ry);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ry", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->a ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // b
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->b ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "b", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // x
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->x ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->y ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lb
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->lb ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lb", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rb
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->rb ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rb", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lt
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->lt ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lt", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rt
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->rt ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rt", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ls
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->ls ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ls", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rs
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->rs ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rs", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // back
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->back ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "back", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // start
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->start ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "start", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hat_c
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->hat_c ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hat_c", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hat_u
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->hat_u ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hat_u", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hat_d
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->hat_d ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hat_d", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hat_l
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->hat_l ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hat_l", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hat_r
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->hat_r ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hat_r", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hat_lu
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->hat_lu ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hat_lu", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hat_ld
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->hat_ld ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hat_ld", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hat_ru
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->hat_ru ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hat_ru", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hat_rd
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->hat_rd ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hat_rd", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hat_pos
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->hat_pos);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hat_pos", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
