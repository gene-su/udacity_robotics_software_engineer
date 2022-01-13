#!/bin/sh
gnome-terminal  -- bash -c "source /home/$USER/project5-home-service-robot/catkin_ws/devel/setup.bash && roslaunch turtlebot3_gazebo turtlebot3_stage_4.launch" &
sleep 5
gnome-terminal  -- bash -c "source /home/$USER/project5-home-service-robot/catkin_ws/devel/setup.bash && roslaunch turtlebot3_slam turtlebot3_slam.launch slam_methods:=gmapping" &
sleep 5
gnome-terminal  -- bash -c "source /home/$USER/project5-home-service-robot/catkin_ws/devel/setup.bash && roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch" 
