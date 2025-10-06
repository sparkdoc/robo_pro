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

void setup() {
  Serial.begin(9600);
  Serial.println("ROBO-01 Motor Test");

  // Set initial motor speed (0-255)
  motorLeft.setSpeed(150);
  motorRight.setSpeed(150);
}

void loop() {
  // Test sequence
  testForward();
  delay(2000);

  testBackward();
  delay(2000);

  testTurnLeft();
  delay(2000);

  testTurnRight();
  delay(2000);

  testStop();
  delay(2000);
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