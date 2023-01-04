# go1-math-motion

Go1 high level control with ROS

- git clone https://github.com/dbaldwin/go1-math-motion
- cd go1-math-motion
- docker run -p 6080:80 -v ${PWD}:/home/ubuntu/catkin_ws/src --shm-size=512m --name go1-ros-testing -d tiryoh/ros-desktop-vnc:melodic
- http://localhost:6080
- Open terminal and cd ~/catkin_ws/src
- git clone -b v3.8.0 https://github.com/unitreerobotics/unitree_legged_sdk
- cd ~/catkin_ws
- catkin_make
- source ~/catkin_ws/devel/setup.bash
- roslaunch go1-math-motion circle.launch
