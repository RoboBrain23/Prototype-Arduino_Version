# ROS Motor Controller

This code controls a two-wheeled robot using ROS (Robot Operating System) on an Arduino board. It subscribes to a `cmd_vel` topic for receiving movement commands and publishes the encoder readings on an `encoder` topic.

## Requirement 

To use this code, you will need:

- An Arduino board
- A motor driver circuit
- Two DC motors
- Two encoders
- A ROS installation

## Usage

1. Connect the motor driver circuit to the Arduino board, and the motors and encoders to the circuit.
2. Compile and upload the code to the Arduino board.
3. Run the ROS node using the command `rosrun <package_name> <node_name>`.
4. Send movement commands to the `cmd_vel` topic using a ROS client, such as `rostopic pub`.
5. View the encoder readings on the `encoder` topic using a ROS client, such as `rostopic echo`.

