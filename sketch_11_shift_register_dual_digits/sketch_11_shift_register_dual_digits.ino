#define DATA  4
#define LATCH 5
#define CLOCK 6

void setup() {
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
}

byte digits[] = {
  0b11111100,
  0b01100000,
  0b11011010,
  0b11110010,
  0b01100110,
  0b10110110,
  0b10111110, 
  0b11100000,
  0b11111110, 
  0b11110110
};
  
void loop() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {;
      digitalWrite(LATCH, LOW);
      shiftOut(DATA, CLOCK, LSBFIRST, digits[i]);
      shiftOut(DATA, CLOCK, LSBFIRST, digits[j]);
      delay(500);
      digitalWrite(LATCH, HIGH);
    }
  }
}
