#!/bin/sh
gnome-terminal  -- bash -c "source /home/$USER/project5-home-service-robot/catkin_ws/devel/setup.bash && roslaunch turtlebot3_gazebo turtlebot3_stage_4.launch" &
sleep 5
gnome-terminal  -- bash -c "source /home/$USER/project5-home-service-robot/catkin_ws/devel/setup.bash && roslaunch turtlebot3_navigation turtlebot3_navigation.launch map_file:=/home/$USER/project5-home-service-robot/catkin_ws/src/map/stage_4.yaml"
