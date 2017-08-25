#include <Servo.h>

#define SERVO     3
#define DIRECAO   A0

Servo servo;

void setup() {
  servo.attach(SERVO);
  servo.write(90); // centraliza o servo-motor
}

void loop() {
  int pot = analogRead(DIRECAO); // 0 a 1023
  int posicao = map(pot, 0, 1023, 0, 180);
  servo.write(posicao);
  delay(100);
}
