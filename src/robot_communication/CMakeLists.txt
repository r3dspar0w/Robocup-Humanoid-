cmake_minimum_required(VERSION 3.16...3.27)
project(robot_communication)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(game_controller_interface REQUIRED)

add_executable(robot_communication_node src/robot_communication_node.cpp)
target_compile_features(robot_communication_node PUBLIC cxx_std_17)
ament_target_dependencies(robot_communication_node rclcpp game_controller_interface)

install(TARGETS
  robot_communication_node
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
