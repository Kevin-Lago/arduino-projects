const int sensorPin1 = A0;
const int sensorPin2 = A1;
const float baselineTemp = 22.0;

void setup() {
  Serial.begin(9600);

  for (int pinNumber = 2; pinNumber < 6; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal1 = analogRead(sensorPin1);
  float voltage1 = (sensorVal1 / 1024.0) * 5.0;
  float temperature1 = (voltage1 - .5) * 100;
  print(1, sensorVal1, voltage1, temperature1);

  int sensorVal2 = analogRead(sensorPin2);
  float voltage2 = (sensorVal2 / 1024.0) * 5.0;
  float temperature2 = (voltage2 - .5) * 100;
  print(2, sensorVal2, voltage2, temperature2);

  if (temperature1 < baselineTemp + 2) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature1 >= baselineTemp + 2 && temperature1 < baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature1 >= baselineTemp + 4 && temperature1 < baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temperature1 >= baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  if (abs(sensorVal1 - sensorVal2) <= 2) {
    digitalWrite(5, HIGH);
  } else {
    digitalWrite(5, LOW);
  }

  delay(1);
}

void print(int sensor, int sensorVal, float voltage, float temperature) {
  Serial.print("Sensor Value ");
  Serial.print(sensor);
  Serial.print(": ");
  Serial.print(sensorVal);
  Serial.print(", Voltage: ");
  Serial.print(voltage);
  Serial.print(", degrees1 C: ");
  Serial.println(temperature);
}
