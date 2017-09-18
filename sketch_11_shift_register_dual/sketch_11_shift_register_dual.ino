#define DATA  4
#define LATCH 5
#define CLOCK 6

void setup() {
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
}
void loop() {
  byte units = 0, tens = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      bitSet(units, j);
      digitalWrite(LATCH, LOW);
      shiftOut(DATA, CLOCK, MSBFIRST, tens);
      shiftOut(DATA, CLOCK, MSBFIRST, units);
      delay(500);
      digitalWrite(LATCH, HIGH);
    }
    units = 0;
    bitSet(tens, i);
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, tens);
    shiftOut(DATA, CLOCK, MSBFIRST, 0);
    delay(500);
    digitalWrite(LATCH, HIGH);
  }
}
