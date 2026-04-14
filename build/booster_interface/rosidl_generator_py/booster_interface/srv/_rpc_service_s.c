// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from booster_interface:srv/RpcService.idl
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
#include "booster_interface/srv/detail/rpc_service__struct.h"
#include "booster_interface/srv/detail/rpc_service__functions.h"

bool booster_interface__msg__booster_api_req_msg__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * booster_interface__msg__booster_api_req_msg__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool booster_interface__srv__rpc_service__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[54];
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
    assert(strncmp("booster_interface.srv._rpc_service.RpcService_Request", full_classname_dest, 53) == 0);
  }
  booster_interface__srv__RpcService_Request * ros_message = _ros_message;
  {  // msg
    PyObject * field = PyObject_GetAttrString(_pymsg, "msg");
    if (!field) {
      return false;
    }
    if (!booster_interface__msg__booster_api_req_msg__convert_from_py(field, &ros_message->msg)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * booster_interface__srv__rpc_service__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RpcService_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("booster_interface.srv._rpc_service");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RpcService_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  booster_interface__srv__RpcService_Request * ros_message = (booster_interface__srv__RpcService_Request *)raw_ros_message;
  {  // msg
    PyObject * field = NULL;
    field = booster_interface__msg__booster_api_req_msg__convert_to_py(&ros_message->msg);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "msg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "booster_interface/srv/detail/rpc_service__struct.h"
// already included above
// #include "booster_interface/srv/detail/rpc_service__functions.h"

bool booster_interface__msg__booster_api_resp_msg__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * booster_interface__msg__booster_api_resp_msg__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool booster_interface__srv__rpc_service__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[55];
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
    assert(strncmp("booster_interface.srv._rpc_service.RpcService_Response", full_classname_dest, 54) == 0);
  }
  booster_interface__srv__RpcService_Response * ros_message = _ros_message;
  {  // msg
    PyObject * field = PyObject_GetAttrString(_pymsg, "msg");
    if (!field) {
      return false;
    }
    if (!booster_interface__msg__booster_api_resp_msg__convert_from_py(field, &ros_message->msg)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * booster_interface__srv__rpc_service__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RpcService_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("booster_interface.srv._rpc_service");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RpcService_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  booster_interface__srv__RpcService_Response * ros_message = (booster_interface__srv__RpcService_Response *)raw_ros_message;
  {  // msg
    PyObject * field = NULL;
    field = booster_interface__msg__booster_api_resp_msg__convert_to_py(&ros_message->msg);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "msg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
