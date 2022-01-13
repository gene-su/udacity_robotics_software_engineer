Build project:
```bash
cd catkin_ws
catkin_make
```

Source environment:
```bash
source devel/setup.bash
```

Launch `world.launch` and `ball_chaser.launch`:
```bash
roslaunch my_robot world.launch          // terminal 1
roslaunch ball_chaser ball_chaser.launch // terminal 2
```

Move the white ball in front of the robot, and the robot will follow it.
