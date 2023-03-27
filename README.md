# Toy Car Robot

This project is a simple toy car robot that can be controlled using a microcontroller. The robot is designed to move forward, backward, left and right using a motor and H-bridge.
This code controls a DC motor with an encoder and uses proximity and temperature sensors to regulate the motor speed and stop the motor when necessary.



## Hardware

The following hardware components were used in this project:

- Microcontroller: Arduino Uno
- Motor: DC motor
- H-bridge: L293D - Datasheet - `https://docs.rs-online.com/90a7/0900766b8135fae0.pdf`
- Proximity sensors: HC-SR04 - Datasheet - `https://components101.com/sites/default/files/component_datasheet/HCSR04%20Datasheet.pdf`
- Temperature sensor: LM35 - Datasheet - `https://www.onsemi.com/pdf/datasheet/lm358-d.pdf`


# Software
The software for this project is written in Arduino IDE. The code can be found in the `car_robot.ino` file.


# Getting Started
- Connect the motor to the Arduino board's digital pins 9 and 10. 
- Connect the encoder to the Arduino board's digital pins 2 and 3. 
- Connect the proximity sensor to the Arduino board's analog pin A0. 
- Connect the temperature sensor to the Arduino board's analog pin A1. 
- Open the Arduino IDE and upload the code to the Arduino board


# Circuit
Connect the H-bridge to the motor and the Arduino board. Connect the encoder module and sensors to the Arduino board as per the pin configuration mentioned in the code
# Usage
The code is designed to regulate the motor speed based on the proximity and temperature readings. The motor will drive forward at a gradually increasing speed until it reaches the maximum speed, and will stop if the temperature exceeds a set threshold or an obstacle is detected by the proximity sensor.

The motor speed can be adjusted by modifying the maxMotorSpeed and minMotorSpeed constants in the code


# Connections

The list of connections to the microcontroller for the toy car robot includes:

- Two DC motors: These are connected to the motor driver module using wires, which are then connected to the PWM pins of the microcontroller.
- Ultrasonic sensors: These are connected to the microcontroller through the GPIO pins.
- Temperature sensor: This is connected to the analog input pin of the microcontroller. 
- H-bridge module: This is connected to the PWM pins of the microcontroller to control the speed and direction of the DC motors.


# How it works
The code sets up the pins for the motor, encoder, proximity sensor, and temperature sensor in the `setup()` function. It also attaches an interrupt to the encoder pin to track the motor's movement.

The `loop()` function reads the proximity and temperature values from the sensors. If the temperature is higher than the desired temperature, the motor is stopped. If the proximity sensor detects an obstacle, the motor is stopped as well. Otherwise, the motor is driven forward based on the proximity sensor value.

The `driveForward()` function controls the direction and speed of the motor using the H-bridge. The `stopMotor()` function stops the motor by setting the speed to 0.

The motor speed is set based on the proximity sensor value using the map() function. The minimum and maximum motor speeds are set using minMotorSpeed and maxMotorSpeed constants in the code.


`Note: Adjust the minMotorSpeed and maxMotorSpeed constants in the code to change the range of the motor speed based on the proximity sensor value.`

