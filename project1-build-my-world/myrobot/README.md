Build project:
```bash
mkdir build && cd build
cmake ..
make
```

Export environmental variable `GAZEBO_PLUGIN_PATH`:
```bash
export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/home/username/udacity-robotics-software-engineer/project1-build-my-world/myrobot/build
```

Launch the world file in Gazebo:
```bash
cd /home/username/udacity-robotics-software-engineer/project1-build-my-world/myrobot/world
gazebo world
```
