cmake_minimum_required(VERSION 3.0.2)
project(go1-math-motion)

add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  unitree_legged_msgs
)

catkin_package()

message("-- CMAKE_SYSTEM_PROCESSOR: ${CMAKE_SYSTEM_PROCESSOR}")
if("${CMAKE_SYSTEM_PROCESSOR}" MATCHES "x86_64.*")
  set(ARCH amd64)
else()
  set(ARCH arm64)
endif()

link_directories(${CMAKE_SOURCE_DIR}/unitree_legged_sdk/lib/cpp/${ARCH})

set(EXTRA_LIBS -pthread libunitree_legged_sdk.so)

set(CMAKE_CXX_FLAGS "-O3 -fPIC")

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${CMAKE_SOURCE_DIR}/unitree_legged_sdk/include
)

add_executable(circle_walk src/circle_walk.cpp)
target_link_libraries(circle_walk ${EXTRA_LIBS} ${catkin_LIBRARIES})
add_dependencies(circle_walk ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(figure8 src/figure8.cpp)
target_link_libraries(figure8 ${EXTRA_LIBS} ${catkin_LIBRARIES})
add_dependencies(figure8 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(forward_walk src/forward_walk.cpp)
target_link_libraries(forward_walk ${EXTRA_LIBS} ${catkin_LIBRARIES})
add_dependencies(forward_walk ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(twist_sub src/twist_sub.cpp)
target_link_libraries(twist_sub ${EXTRA_LIBS} ${catkin_LIBRARIES})
add_dependencies(twist_sub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})