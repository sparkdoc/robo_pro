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
const int trigPin = 9;
const int echoPin = 10;

void setup() {
  Serial.begin(9600);
  Serial.println("ROBO-01 Ultrasonic Sensor Test");

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
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
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo pulse duration
  long duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  // Speed of sound: 343 m/s = 0.0343 cm/µs
  // Distance = (duration / 2) * 0.0343
  long distance = duration * 0.0343 / 2;

  return distance;
}