/*
 * ROBO-01 Line Sensor Test
 *
 * Test the line following sensor
 * Typically uses IR sensors to detect contrast between line and surface
 *
 * Connections (verify with your kit's documentation):
 * Adjust pin numbers based on your actual wiring
 */

// Pin definitions - adjust based on your wiring
const int leftSensorPin = A0;
const int rightSensorPin = A1;

// Threshold values - adjust based on your surface and sensor
int threshold = 500;  // Analog value threshold

void setup() {
  Serial.begin(9600);
  Serial.println("ROBO-01 Line Sensor Test");

  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);

  Serial.println("Place robot on test surface");
  Serial.println("Readings: > threshold = dark/line, < threshold = light/surface");
  delay(2000);
}

void loop() {
  int leftValue = analogRead(leftSensorPin);
  int rightValue = analogRead(rightSensorPin);

  Serial.print("Left: ");
  Serial.print(leftValue);
  Serial.print(" (");
  Serial.print(leftValue > threshold ? "LINE" : "SURFACE");
  Serial.print(") | Right: ");
  Serial.print(rightValue);
  Serial.print(" (");
  Serial.print(rightValue > threshold ? "LINE" : "SURFACE");
  Serial.println(")");

  // Line position indication
  if (leftValue > threshold && rightValue > threshold) {
    Serial.println("  -> Both on line");
  } else if (leftValue > threshold) {
    Serial.println("  -> Line on LEFT");
  } else if (rightValue > threshold) {
    Serial.println("  -> Line on RIGHT");
  } else {
    Serial.println("  -> No line detected");
  }

  delay(250);
}