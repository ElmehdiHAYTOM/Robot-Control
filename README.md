# Arduino Bluetooth Robot Control with Stepper Motors

This repository contains Arduino code for controlling a robot using Bluetooth communication. The robot is equipped with obstacle detection and avoidance capabilities and uses NEMA 17 stepper motors controlled by A4988 drivers for movement.

## Components Used
- Arduino Uno
- HC-05 Bluetooth Module
- Ultrasonic Sensor
- NEMA 17 Stepper Motors
- A4988 Stepper Motor Drivers

## Wiring
- Bluetooth Module: Connected to Arduino's RX and TX pins (pins 0 and 1)
- Ultrasonic Sensor: 
  - Trigger pin: 9
  - Echo pin: 10
- Stepper Motor Drivers:
  - Connect A4988 drivers to control the NEMA 17 stepper motors.
- Buzzer: Connected to pin 11

## Setup
1. Connect the components according to the wiring mentioned above.
2. Upload the provided code to your Arduino Uno board.
3. Connect to the Arduino via Bluetooth from your smartphone or computer using a serial terminal app.
4. Follow the instructions below for controlling the robot.

## Usage
- Once connected via Bluetooth (using the Blueduino app), you can send commands to control the robot's movement:
  - 'w': Move forward
  - 's': Move backward
  - 'a': Move left
  - 'd': Move right
  - 'b': Increase speed
  - 'x': Decrease speed
- The robot will automatically stop and alert if an obstacle is detected within a certain range (configurable).
- Ensure that the ultrasonic sensor is properly calibrated for accurate obstacle detection.

## Note
- Adjust the stepper motor speed and steps as per your requirements.
- Ensure proper calibration of sensors for accurate obstacle detection.
- This code serves as a basic framework and can be expanded upon for more complex behaviors.

