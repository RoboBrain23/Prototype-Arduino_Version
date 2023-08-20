# IMU Sensor Readings using MPU6050

This code reads the Pitch, Roll and Yaw values from an MPU6050 IMU sensor and outputs them to the serial monitor.

## Requirements

- Arduino Uno
- MPU6050 IMU Sensor
- Wires to connect the sensor to the Arduino

## Wiring

| IMU Pin | Arduino Pin |
| ------- | ----------- |
| VCC     | 5V          |
| GND     | GND         |
| SDA     | A4          |
| SCL     | A5          |

## Dependencies

This code requires the following libraries to be installed in the Arduino IDE:

- Wire.h
- MPU6050.h

## Installation

1. Connect the MPU6050 sensor to the Arduino board following the wiring diagram above.
2. Install the required libraries if they are not already installed.
3. Upload the code to the Arduino board.

## Usage

1. Open the serial monitor in the Arduino IDE or any other serial monitor program.
2. Observe the output values for Pitch, Roll and Yaw.
3. The code also includes a timer that outputs the latency between readings.

## Configuration

The `MPU6050_SCALE_2000DPS` and `MPU6050_RANGE_2G` parameters in the `mpu.begin()` function can be modified to change the scale and range of the sensor readings.

The `timeStep` variable can be modified to change the time interval between readings.

The `mpu.setThreshold(3)` function sets the sensitivity threshold for the sensor readings. If you don't want to use this feature, you can comment out this line or set the value to 0.

## Credits

This code is based on the example code provided in the MPU6050 library for Arduino by Jeff Rowberg (https://github.com/jrowberg/i2cdevlib).


