cmake_minimum_required(VERSION 3.8)
project(motion_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)

if(DEFINED ENV{BOOSTER_SDK_ROOT})
  set(DEFAULT_BOOSTER_SDK_ROOT "$ENV{BOOSTER_SDK_ROOT}")
else()
  get_filename_component(DEFAULT_BOOSTER_SDK_ROOT
    "${CMAKE_CURRENT_LIST_DIR}/../../../sdk_release/sdk_release" ABSOLUTE)
endif()

set(BOOSTER_SDK_ROOT "${DEFAULT_BOOSTER_SDK_ROOT}" CACHE PATH
  "Path to the Booster firmware 1.4 sdk_release/sdk_release directory")

if(NOT EXISTS "${BOOSTER_SDK_ROOT}/include/booster/robot/b1/b1_api_const.hpp")
  message(FATAL_ERROR
    "BOOSTER_SDK_ROOT does not look like sdk_release/sdk_release: ${BOOSTER_SDK_ROOT}\n"
    "Set it before building, for example:\n"
    "  export BOOSTER_SDK_ROOT=/path/on/robot/to/sdk_release/sdk_release")
endif()

if(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64|arm64")
  set(BOOSTER_SDK_ARCH "aarch64")
else()
  set(BOOSTER_SDK_ARCH "x86_64")
endif()

set(BOOSTER_SDK_LIB_DIR "${BOOSTER_SDK_ROOT}/lib/${BOOSTER_SDK_ARCH}")
set(BOOSTER_SDK_THIRD_PARTY_LIB_DIR "${BOOSTER_SDK_ROOT}/third_party/lib/${BOOSTER_SDK_ARCH}")

add_library(booster_robotics_sdk STATIC IMPORTED)
set_target_properties(booster_robotics_sdk PROPERTIES
  IMPORTED_LOCATION "${BOOSTER_SDK_LIB_DIR}/libbooster_robotics_sdk.a")

find_library(BOOSTER_FASTRTPS_LIB fastrtps
  PATHS "${BOOSTER_SDK_THIRD_PARTY_LIB_DIR}" NO_DEFAULT_PATH REQUIRED)
find_library(BOOSTER_FASTCDR_LIB fastcdr
  PATHS "${BOOSTER_SDK_THIRD_PARTY_LIB_DIR}" NO_DEFAULT_PATH REQUIRED)
find_library(BOOSTER_FOONATHAN_LIB foonathan_memory-0.7.3
  PATHS "${BOOSTER_SDK_THIRD_PARTY_LIB_DIR}" NO_DEFAULT_PATH REQUIRED)

add_executable(motion_control_node src/motion_control_node.cpp)
target_compile_features(motion_control_node PUBLIC cxx_std_17)
target_include_directories(motion_control_node PRIVATE
  "${BOOSTER_SDK_ROOT}/include"
  "${BOOSTER_SDK_ROOT}/third_party/include")
ament_target_dependencies(motion_control_node
  geometry_msgs
  rclcpp
  std_msgs
  std_srvs)
target_link_libraries(motion_control_node
  booster_robotics_sdk
  "${BOOSTER_FASTRTPS_LIB}"
  "${BOOSTER_FASTCDR_LIB}"
  "${BOOSTER_FOONATHAN_LIB}"
  pthread
  dl)

set_target_properties(motion_control_node PROPERTIES
  INSTALL_RPATH "${BOOSTER_SDK_THIRD_PARTY_LIB_DIR}")

install(TARGETS motion_control_node
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch models
  DESTINATION share/${PROJECT_NAME})

ament_package()
