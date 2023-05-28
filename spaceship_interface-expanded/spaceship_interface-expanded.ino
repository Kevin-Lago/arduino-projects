int switchState = 0;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  switchState = digitalRead(2);

  if (switchState == LOW) {
    digitalWrite(3, HIGH);
    delay(250);
    digitalWrite(3, LOW);
    delay(250);
  } else {
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);

    delay(250);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    delay(250);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    delay(250);
    digitalWrite(6, LOW);
  }
}
