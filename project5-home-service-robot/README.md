# P5-Home-Service-Robot

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
### test_slam.sh
```bash
cd catkin_ws/src/scripts
./test_slam.sh
```
Select the terminal which launches teleop package, control the robot, map the environment.

### test_navigation.sh
```bash
cd catkin_ws/src/scripts
./test_navigation.sh
```
Use `2D Nav Goal` button in the RViz toolbar to select goal, and the robot will navigate to the goal.

### pick_objects.sh
```bash
cd catkin_ws/src/scripts
./pick_objects.sh
```
The robot will travel to the pick up zone and the drop off zone.

### add_marker.sh
```bash
cd catkin_ws/src/scripts
./add_marker.sh
```
The visual object will show in the pick up zone for 5s, and after another 5s it will show in the drop off zone.

### home_service.sh
```bash
cd catkin_ws/src/scripts
./add_marker.sh
```
The robot will travel to the pick up zone and pick up the visual object and drop it in the drop off zone.
