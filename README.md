# ROS-Turtlebot-follower
Autonomous person-following system for Turtlebot using ROS and LaserScan. Final project for "Introducció a la Robòtica" (Bachelor's in AI, UPC - FIB). Implements reactive navigation and obstacle avoidance.

It consists of a robotic control system that allows a Turtlebot to identify, track, and follow a person autonomously using laser rangefinder (LiDAR) data.Project DescriptionThe goal of this project is to implement a robust "Follow-Me" behavior. The robot processes environmental data to locate the nearest stimulus (representing a person) and adjusts its movement to maintain a safe following distance while avoiding obstacles.

Key Features:
- Target Identification: Uses sensor_msgs/LaserScan to find the nearest object within a 360-degree radius.
- Reactive Control: Implements a state-based controller that translates angular error into velocity commands (geometry_msgs/Twist).
- Adaptive Behavior: Automatically rotates towards the target and moves forward if the target is within a safe range (>0.6m).
- Quiet Mode: The robot remains stationary if no target is detected or if it is too close, ensuring safety and energy efficiency.
- Obstacle Awareness: The logic is designed to react to the closest stimulus, allowing it to navigate through simple environments.

The project is structured as a standard ROS Catkin package named final_min:
- src/final.cpp: The core node. It contains the scanCallback function for data processing and the main control loop for robot movement.
- launch/launch_file.launch: Automates the node execution within the ROS ecosystem.
- package.xml & CMakeLists.txt: Define dependencies (like roscpp, geometry_msgs, sensor_msgs) and build instructions.
- Informe.pdf: Detailed documentation explaining the mathematical approach, logic diagrams, and experimental results.


How to Run.

Setup Workspace:
Clone this repository into your catkin_ws/src folder.
  Bash
  cd ~/catkin_ws/src
  git clone <repo_url>

Build the Package:
  Bash
  cd ~/catkin_ws
  catkin_make
  source devel/setup.bash
  
Launch the Simulation/Robot:
Ensure your Turtlebot or Gazebo simulation is running, then execute:
  Bash
  roslaunch final_min launch_file.launch
