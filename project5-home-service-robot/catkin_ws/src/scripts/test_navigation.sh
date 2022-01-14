#!/bin/sh

# Define your workspace path
catkin_ws_path="/home/workspace/catkin_ws"

gnome-terminal  -- bash -c "cd ${catkin_ws_path} && source devel/setup.bash && roslaunch turtlebot3_gazebo turtlebot3_stage_4.launch" &
sleep 5
gnome-terminal  -- bash -c "cd ${catkin_ws_path} && source devel/setup.bash && roslaunch turtlebot3_navigation turtlebot3_navigation.launch map_file:=${catkin_ws_path}/src/map/stage_4.yaml"
