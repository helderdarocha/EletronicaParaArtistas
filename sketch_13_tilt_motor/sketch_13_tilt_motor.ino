#define POT    A0
#define MOTOR  3
#define TILTSW 4
#define LED    5

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(TILTSW, INPUT_PULLUP);
  pinMode(MOTOR, OUTPUT);
}

void loop() {
  if(digitalRead(TILTSW) == LOW) {
    digitalWrite(LED, LOW);
    analogWrite(MOTOR, 0);
  } else {
    digitalWrite(LED, HIGH);
    int pot = analogRead(POT);
    int speed = map(pot, 0, 1023, 0, 255);
    analogWrite(MOTOR, speed);
  }
  delay(200);
}
