/*
 * ROBO-01 Ultrasonic Sensor Test
 *
 * Test the HC-SR04 ultrasonic distance sensor
 *
 * Connections (verify with your kit's documentation):
 * - VCC -> 5V
 * - Trig -> Digital Pin (defined below)
 * - Echo -> Digital Pin (defined below)
 * - GND -> GND
 */

// Pin definitions - adjust based on your wiring
// Sensor connected to digital pin 2
const int trigPin = 2;
const int echoPin = 2;  // Single signal pin

void setup() {
  Serial.begin(9600);
  Serial.println("ROBO-01 Ultrasonic Sensor Test");
  Serial.print("Using pin: ");
  Serial.println(trigPin);
}

void loop() {
  long distance = measureDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Warning if object is close
  if (distance < 20) {
    Serial.println("WARNING: Object detected nearby!");
  }

  delay(500);  // Measure twice per second
}

long measureDistance() {
  // For single-pin sensor, switch to OUTPUT mode
  pinMode(trigPin, OUTPUT);

  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Switch to INPUT mode to read echo
  pinMode(echoPin, INPUT);

  // Read echo pulse duration (timeout after 30ms = ~5m max range)
  long duration = pulseIn(echoPin, HIGH, 30000);

  // Calculate distance in cm
  // Speed of sound: 343 m/s = 0.0343 cm/µs
  // Distance = (duration / 2) * 0.0343
  long distance = duration * 0.0343 / 2;

  return distance;
}