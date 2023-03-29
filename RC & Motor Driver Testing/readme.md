# Arduino Bluetooth Controlled Car

This project is a simple Bluetooth controlled car using an Arduino board and an motor driver. The car can be controlled via Bluetooth using a mobile app that sends commands to the Arduino board. 

### Prerequisites

To run this project, you will need the following components:

- Arduino UNO or similar board
- Motor driver
- HC-06 Bluetooth module
- DC motors (2)
- Chassis for the car

### Installing

To install this project, follow these steps:

1. Connect the motor driver to the Arduino board and to the DC motors.
2. Connect the HC-05 Bluetooth module to the Arduino board.
3. Download and install the mobile app from the app store.
4. Upload the code to the Arduino board.

## Running the Tests

To run the tests, connect the power supply to the car and the Arduino board, and open the mobile app. Pair the mobile device with the HC-06 Bluetooth module and start sending commands. The car should respond accordingly.

## Usage

The car can be controlled using the following commands:

- F: move forward
- B: move backward
- R: turn right
- L: turn left
- S: stop

The car's speed can also be adjusted using the numbers 1-8 on the mobile app. Each number corresponds to a different speed, with 1 being the slowest and 8 being the fastest.

