cmake_minimum_required(VERSION 3.0.2)
project(simple_walker)

find_package(catkin REQUIRED COMPONENTS
  gazebo_ros
  geometry_msgs
  rosbag
  roscpp
  sensor_msgs
  std_msgs
)

catkin_package(
 INCLUDE_DIRS include
 LIBRARIES simple_walker
 CATKIN_DEPENDS gazebo_ros geometry_msgs rosbag roscpp sensor_msgs std_msgs
 DEPENDS
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${CMAKE_SOURCE_DIR}/include
)

add_executable(distance-alerter src/danger_node.cpp src/distance_alerter.cpp)
target_link_libraries(distance-alerter ${catkin_LIBRARIES})

add_executable(simple-walker src/simple_walker.cpp src/walker_node.cpp)
target_link_libraries(simple-walker ${catkin_LIBRARIES})