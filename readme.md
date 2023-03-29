# Wheelchair Prototype Arduino_Version 

## Description

This project is an electric wheelchair. We started with a simple prototype and used Arduino to implement the code and test the components. We wrote five codes for this project:


1. RC & Motor Driver Testing - This code tests the functionality of the motor driver and controls it using bluetooth module.
2. Encoder Testing - This code reads the counts and calculates the distance using encoders.
3. IMU Testing - This code reads angles and directions from the IMU (MPU6050 sensor) attached to the robot.
4. Obstacle Avoidance Testing - This code uses three ultrasonic sensors to detect obstacles and stop the robot in emergency situations.
5. Arduino & ROS Integration Testing - This code integrates ROS and Arduino to allow communication between the two platforms.


																			

## Requirements

### Hardware

This project requires the following hardware components:

- Robot Chassis with Wheels and Motors
- Arduino Mega board
- Motor driver
- Bluetooth Module (HC-05)
- MPU6050 sensor
- Encoders
- Ultrasonic sensors (3) HC-SR04
- Battery
- Jumbers & Swithces

### Libraries

This project requires the following libraries:

- SoftwareSerial
- A ROS installation
- Wire.h
- MPU6050.h



