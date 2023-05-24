#include <Servo.h>

Servo myServo;
int const sensorPin = A0;
int sensorVal;
int angle;

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Val: ");
  Serial.print(sensorVal);
  angle = map(sensorVal, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(15);
}

