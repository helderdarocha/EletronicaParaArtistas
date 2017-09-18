#define TILT 12
#define LED  8

void setup() {
  pinMode(TILT, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
  int tilt = digitalRead(TILT);
  if(tilt == LOW) {
    digitalWrite(LED, LOW);
  } else {
    digitalWrite(LED, HIGH);
  }
}
