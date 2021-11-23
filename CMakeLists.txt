cmake_minimum_required(VERSION 3.0.2)
project(simple_walker)

find_package(catkin REQUIRED COMPONENTS
  gazebo_ros
  geometry_msgs
  rosbag
  roscpp
)

catkin_package(
 INCLUDE_DIRS include
 LIBRARIES simple_walker
 CATKIN_DEPENDS gazebo_ros geometry_msgs rosbag roscpp
 DEPENDS
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${CMAKE_SOURCE_DIR}/include
)

add_executable(simple-walker src/simple_walker.cpp src/walker_node.cpp)
target_link_libraries(simple-walker ${catkin_LIBRARIES})