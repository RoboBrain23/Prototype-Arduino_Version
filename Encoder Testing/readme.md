# Encoder Code 

This code is designed to work with an encoder to read the counts and calculate the distance. The following code sets up the necessary parameters and interrupts for the encoder:

## Installation

1. Connect the encoder to the Arduino board.
2. Copy and paste the code into the Arduino IDE.
3. Upload the code to the Arduino board.

## Usage

1. Connect the motors to the motor driver.
2. Connect the motor driver to the Arduino board.
3. Connect the ultrasonic sensors to the Arduino board.
4. Connect the MPU6050 sensor to the Arduino board.
5. Turn on the robot.
6. Wait for the robot to start moving.
7. Observe the output in the Serial Monitor.

## Parameters

- PPR: Pulses Per Revolution of the encoder.
- WCFC: Wheel circumference in cm.
- distance_test: The distance in cm.
- RM_Int: Right Motor Mixed interrupt at pin 2 INT 0.
- LM_Int: Left Motor Mixed interrupt at pin 3 INT 1.
- R_DIR: Right motor direction pin.
- L_DIR: Left motor direction pin.
- R_speed: Right motor speed pin.
- L_speed: Left motor speed pin.
- forward: Set motor direction forward.
- backward: Set motor direction backward.
- Speed: Set the motor speed.

## Interrupt Handlers

- RM_Int_Handler(): Handles the interrupt for the right motor.
- LM_Int_Handler(): Handles the interrupt for the left motor.

## Output

- RM_Int_current: The current number of counts for the right motor.
- LM_Int_current: The current number of counts for the left motor.
- distance_in_pulses: The calculated distance in pulses.

## Notes

- The delay in the loop is set to 5 seconds to allow time for the robot to start moving before it begins to measure distance.
- The Stop variable is used to stop the robot when it reaches the desired distance.
