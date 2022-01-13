# P3-Where-Am-I
Use ROS package `amcl` to localize the robot. The particles would converge while the robot is moving around.
![image](https://github.com/gene-su/udacity-robotics-software-engineer/blob/main/project3-where-am-i/video.gif)

## Environment
Ubuntu 18.04, ROS Melodic.

## Installation
### Install the dependencies.
```bash
sudo apt-get install ros-melodic-navigation
sudo apt-get install ros-melodic-map-server
sudo apt-get install ros-melodic-move-base
sudo apt-get install ros-melodic-amcl
```

### Build the catkin workspace.
```bash
cd catkin_ws
catkin_make
```

## Usage
### Spawn the robot model and the Gazebo world.
```bash
roslaunch my_robot world.launch
```

### Launch node `amcl` for localization.
```bash
roslaunch my_robot amcl.launch
```

### Move the robot.
1. Use node `teleop_twist_keyboard`
```bash
rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```

2. Use `2D Nav Goal` button in the RViz toolbar.
