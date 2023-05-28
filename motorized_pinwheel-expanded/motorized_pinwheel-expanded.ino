const int switchPin = 2;
const int motorPin = 9;
int switchState = 0;
const int analogPin = A0;
int analogValue = 0;
int motorSpeed = 0;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  analogValue = analogRead(analogPin);
  Serial.print("Analog Value: ");
  Serial.println(analogValue);
  motorSpeed = map(analogValue, 0, 1023, 0, 255);
  Serial.print("Motor Speed: ");
  Serial.println(motorSpeed);
  switchState = digitalRead(switchPin);

  if (switchState == HIGH) {
    analogWrite(motorPin, motorSpeed);
  } else {
    analogWrite(motorPin, 0);
  }
}
