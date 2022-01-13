#!/bin/sh
gnome-terminal  -- bash -c " gazebo " &
sleep 5
gnome-terminal  -- bash -c " source /opt/ros/melodic/setup.bash; roscore" & 
sleep 5
gnome-terminal  -- bash -c  " rosrun rviz rviz" 
