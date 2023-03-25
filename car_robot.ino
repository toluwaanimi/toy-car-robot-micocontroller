// Define pin numbers for motor control, encoder, proximity sensor, and temperature sensor
const int motorPin1 = 9;
const int motorPin2 = 10;
const int encoderPinA = 2;
const int encoderPinB = 3;
const int proximityPin = A0;
const int temperaturePin = A1;

// Define variables for encoder readings
volatile int encoderTicks = 0;
volatile bool encoderDirection = false;

// Define constants for desired temperature and motor speed
const int desiredTemperature = 35;
const int maxMotorSpeed = 255;
const int minMotorSpeed = 50;
int motorSpeed = minMotorSpeed;

void setup() {
// Set pin modes for all the pins
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);
  pinMode(proximityPin, INPUT);
  pinMode(temperaturePin, INPUT);

// Attach interrupt to encoder pin A for detecting changes in encoder readings
  attachInterrupt(digitalPinToInterrupt(encoderPinA), handleEncoderInterrupt, CHANGE);
}

void loop() {
// Read values from proximity and temperature sensors
  int proximityValue = analogRead(proximityPin);
  int temperatureValue = analogRead(temperaturePin);

// Check if temperature is too hot and stop the motor if it is

  if (temperatureValue > desiredTemperature) {
      Serial.println("Temperature too hot! Stopping motor...");
    stopMotor();
  } else if (proximityValue < 500) {
  // Check if there is an obstacle and drive the motor forward if there isn't
    driveForward();
  } else {
  // Stop the motor if there is an obstacle
    stopMotor();
    Serial.println("Obstacle detected! Stopping motor...");
  }
}

void handleEncoderInterrupt() {
// Determine the direction of the encoder reading based on the A and B pins
  if (digitalRead(encoderPinA) == digitalRead(encoderPinB)) {
    encoderDirection = true;
  } else {
    encoderDirection = false;
  }
// Increment or decrement encoder ticks based on the direction of rotation
  encoderTicks += encoderDirection ? 1 : -1;
}

void driveForward() {
// Set motor direction to forward and set motor speed
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  analogWrite(motorPin1, motorSpeed);

// Increase motor speed gradually up to the maximum speed
  if (motorSpeed < maxMotorSpeed) {
    motorSpeed += 5;
  }
}

void stopMotor() {
// Stop the motor and reset the motor speed to the minimum value
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  analogWrite(motorPin1, 0);
  motorSpeed = minMotorSpeed;
}
