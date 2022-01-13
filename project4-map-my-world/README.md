# P4-Map-My-World
Use ROS package `rtabmap_ros` to create 2D grid map and 3D octomap. [map link](https://drive.google.com/file/d/1Suiqb2uZ1UknJ3flgvB6_2NiaLFu-5I4/view?usp=sharing)
![image](https://github.com/gene-su/udacity-robotics-software-engineer/blob/main/project4-map-my-world/pic.png)

## Environment
Ubuntu 18.04, ROS Melodic.

## Installation
### Install the dependencies.
```bash
sudo apt install ros-melodic-rtabmap-ros
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

### Launch node `rtabmap` for mapping.
```bash
roslaunch my_robot mapping.launch
```

### Move the robot.
```bash
roslaunch my_robot teleop.launch
```
