#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(3);
  servo.write(90); // centraliza
}

void loop() {
  int pot = analogRead(A0); // 0 a 1023
  int posicao = map(pot, 0, 1023, 0, 179);
  servo.write(posicao);
  delay(100);
}


