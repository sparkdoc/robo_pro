/*
 * ROBO-01 Motor Test
 *
 * Basic test to verify motor connections and control
 *
 * This example uses the Adafruit Motor Shield library
 * Install via: Arduino Library Manager -> "Adafruit Motor Shield library"
 */

#include <AFMotor.h>

// Create motor objects
// Motor ports depend on your wiring - adjust as needed
AF_DCMotor motorLeft(1);   // Motor on port M1
AF_DCMotor motorRight(2);  // Motor on port M2

// Emergency stop function - checks serial and stops if 'S' received
void checkStop() {
  if (Serial.available() && Serial.read() == 'S') {
    Serial.println("EMERGENCY STOP - Motors disabled");
    motorLeft.setSpeed(0);
    motorRight.setSpeed(0);
    motorLeft.run(RELEASE);
    motorRight.run(RELEASE);
    while(1); // Halt program
  }
}

// Smart delay that checks for stop command
void smartDelay(int ms) {
  unsigned long start = millis();
  while (millis() - start < ms) {
    checkStop();
    delay(10);
  }
}

void setup() {
  Serial.begin(9600);
  Serial.println("ROBO-01 Motor Test");
  Serial.println("Send 'S' to stop motors");

  // Set initial motor speed (0-255)
  motorLeft.setSpeed(150);
  motorRight.setSpeed(150);
}

void loop() {
  // Test sequence
  testForward();
  smartDelay(2000);

  testBackward();
  smartDelay(2000);

  testTurnLeft();
  smartDelay(2000);

  testTurnRight();
  smartDelay(2000);

  testStop();
  smartDelay(2000);
}

void testForward() {
  Serial.println("Moving Forward");
  motorLeft.run(FORWARD);
  motorRight.run(FORWARD);
}

void testBackward() {
  Serial.println("Moving Backward");
  motorLeft.run(BACKWARD);
  motorRight.run(BACKWARD);
}

void testTurnLeft() {
  Serial.println("Turning Left");
  motorLeft.run(BACKWARD);
  motorRight.run(FORWARD);
}

void testTurnRight() {
  Serial.println("Turning Right");
  motorLeft.run(FORWARD);
  motorRight.run(BACKWARD);
}

void testStop() {
  Serial.println("Stopped");
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
}