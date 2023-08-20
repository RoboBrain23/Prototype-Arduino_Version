# Obstacle Avoidance Code

This code controls a robot that avoids obstacles using ultrasonic sensors and can be remotely controlled using Bluetooth.

## Dependencies

This code uses the following libraries:
- SoftwareSerial

## Hardware Requirements
- Arduino Board
- HC-SR04 Ultrasonic Sensors (3)
- L298N Motor Driver
- Robot Chassis with Wheels and Motors
- Bluetooth Module (HC-05)

## Pin Configuration

### Motor Driver Pins
- R_DIR   -> Pin 5
- L_DIR   -> Pin 8
- R_speed -> Pin 6
- L_speed -> Pin 9

### Ultrasonic Sensor Pins
- Front Sensor
    - trig_f -> Pin 14
    - echo_f -> Pin 15
- Right Sensor
    - trig_r -> Pin 16
    - echo_r -> Pin 17
- Left Sensor
    - trig_l -> Pin 23
    - echo_l -> Pin 24

### Bluetooth Module Pins
- RX -> Pin 10
- TX -> Pin 11

## Usage

1. Upload the code to the Arduino board.
2. Connect the hardware components as per the pin configuration.
3. Power up the Arduino board and the robot.
4. Pair the Bluetooth module with a device that can send commands (e.g. smartphone).
5. Open a serial communication program (e.g. Arduino Serial Monitor) and connect to the Arduino board.
6. Send the following commands over Bluetooth to control the robot:
    - `F` - Go Forward
    - `B` - Go Backward
    - `R` - Turn Right
    - `L` - Turn Left
    - `S` - Stop
    - `1` to `8` - Set Speed (1 is slowest, 8 is fastest)

## Functions

- `forward_distance()` - Measures the distance of the front sensor and stops the robot if an obstacle is detected.
- `right_distance()` - Measures the distance of the right sensor and stops the robot if an obstacle is detected.
- `left_distance()` - Measures the distance of the left sensor and stops the robot if an obstacle is detected.
- `GO_forward()` - Makes the robot go forward.
- `GO_backward()` - Makes the robot go backward.
- `turn_right()` - Makes the robot turn right.
- `turn_left()` - Makes the robot turn left.
- `Stop()` - Stops the robot.
- `set_speed(int in)` - Sets the speed of the robot (input range: 1 to 8).

