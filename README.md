# simple-walker
ROS/Gazebo assignment for ENPM808X class. This tutorial contains two nodes. A "walker" node controls the robot's movement and navigation. Another node reads the sensors and publishes to a danger topic if the robot is about to hit an object. The navigation node subscribes to this topic and turns out of harms way. Please see the **Running the Simple Walker** section below. 

## Submission Items
For the static code checks and rosbag, see the branch_results folder inside the repo.

# Run Instructions

## Dependencies
1. **C++11** or greater
2. **ROS Noetic** or **Melodic**. This package was generated on a system with ROS Noetic. However, the code, CMakeLists, package.xml, as well as the running instructions will work on ROS Melodic as well.
3. **catkin build** (i.e. catkin-tools) system. The running instructions use the "catkin build" system rather than the "catkin_make." These two ROS package managers are very similar but catkin build is newer and supposedly better. Since this repo only contains the individual package (i.e. src code), one can still use catkin_make as their manager. Except for replacing `catkin build` to `catkin_make` line in the **Running the Simple Walker**, no other instructions should be affected. See online tutorials for more information.
4. **husky_gazebo** package. 

### Install ROS

Follow the [ROS installation guide](http://wiki.ros.org/ROS/Installation) to install ros on your system.

### Create a catkin workspace

This section only applies if no catkin workspaces have already been installed on your system. If one is available, please skip this section and head to **Running the Simple Walker** section

In a terminal, create a workspace name of your choosing. Generally, the standard is to add a "_ws" to the end of a desired name. For this example we'll use the name `catkin_ws`.

```bash
cd ~
mkdir catkin_ws
cd catkin_ws
mkdir src
```

Type the following command into your terminal to source your new catkin workspace into the bashrc

```bash
echo 'source <path to workspace>/catkin_ws/devel/setup.bash' >> ~/.bashrc
source ~/.bashrc
```

### Running the Simple Walker

Open a terminal and clone the repo into a `src` folder within the desired catkin workspace. Use
```bash
git clone git@github.com:dlerner97/simple_walker.git
```
for an ssh clone and 
```bash
git clone https://github.com/dlerner97/simple_walker.git
```
for an https clone. Then,
```bash
# Download the husky simulator
sudo apt-get install ros-<ros-distro>-husky-simulator

# Go into the catkin_ws folder
cd ..
catkin build
```

Open 2 additional terminals. In one,
```bash
source <path to workspace>/<workspace name>/devel/setup.bash

export HUSKY_REALSENSE_ENABLED=1   
roslaunch simple_walker walker_sim.launch
```

Note the `export...` line. This line is necessary and the system will crash without it. Don't forget this line!

### Recording and Using ROSBag
To record a rosbag, use the same `walker_sim.launch` file but this launch file now has multiple command line arguments. The `record` argument is boolean and tells the program to record a rosbag or not. The `duration:=#` arg controls how long the rosbag will record (default is 15 seconds). Lastly the `bag_directory:=path/to/bagfile` gives the user ability to choose a directory and filename for the bagfile.

```bash
roslaunch simple_walker walker_sim.launch record:=true
```

Once a rosbag is recorded, one can play it back and use the listener as if a publisher was running. Open 2 terminals.

In the first terminal, open a ros master:
```bash
roscore
```

In the last terminal, check some rosbag information and run the rosbag:
```bash
rosbag info <path/to/bag file>
rosbag play <path/to/bag file>
```

Unfortunately we cannot run the walker node because we had to remove the camera data from the rosbag recording. This data is too numerous and the size of the ROSbag is more than github can handle. So, we cannot run the nodes along side the rosbag.
 