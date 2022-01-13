cmake_minimum_required(VERSION 3.0.2)
project(pick_objects)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  actionlib
  move_base_msgs
)

catkin_package(
  INCLUDE_DIRS
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS roscpp std_msgs actionlib move_base_msgs
  DEPENDS
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(pick_objects src/pick_objects.cpp)
target_link_libraries(pick_objects ${catkin_LIBRARIES})