cmake_minimum_required(VERSION 3.16...3.27)
project(motion_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -Wno-unused-parameter)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(booster_interface REQUIRED)

option(ENABLE_MOTION_CONTROL_ONNX "Enable ONNX Runtime backend for locomotion policy" ON)
if(ENABLE_MOTION_CONTROL_ONNX)
  find_path(MOTION_CONTROL_ONNX_INCLUDE_DIRS onnxruntime_cxx_api.h
    HINTS
    /usr/include/onnxruntime
    /usr/local/include/onnxruntime
    /opt/onnxruntime/include
    PATH_SUFFIXES onnxruntime core/session)

  find_library(MOTION_CONTROL_ONNX_LIBRARIES
    NAMES onnxruntime
    HINTS
    /usr/lib
    /usr/local/lib
    /opt/onnxruntime/lib)
endif()

if(MOTION_CONTROL_ONNX_INCLUDE_DIRS AND MOTION_CONTROL_ONNX_LIBRARIES)
  message(STATUS "motion_control: ONNX Runtime enabled")
  set(MOTION_CONTROL_HAVE_ONNX TRUE)
else()
  message(WARNING "motion_control: ONNX Runtime not found, the node will hold stance until ONNX is available.")
  set(MOTION_CONTROL_HAVE_ONNX FALSE)
endif()

add_executable(custom_motion_node
  src/custom_motion_node.cpp
)

target_include_directories(custom_motion_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

if(MOTION_CONTROL_HAVE_ONNX)
  target_include_directories(custom_motion_node PRIVATE ${MOTION_CONTROL_ONNX_INCLUDE_DIRS})
  target_link_libraries(custom_motion_node ${MOTION_CONTROL_ONNX_LIBRARIES})
  target_compile_definitions(custom_motion_node PRIVATE MOTION_CONTROL_HAVE_ONNX_RUNTIME=1)
endif()

ament_target_dependencies(custom_motion_node
  rclcpp
  geometry_msgs
  booster_interface
)

target_compile_features(custom_motion_node PUBLIC c_std_99 cxx_std_17)

install(TARGETS
  custom_motion_node
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

install(DIRECTORY config
  DESTINATION share/${PROJECT_NAME})

install(DIRECTORY model
  DESTINATION share/${PROJECT_NAME})

ament_package()
