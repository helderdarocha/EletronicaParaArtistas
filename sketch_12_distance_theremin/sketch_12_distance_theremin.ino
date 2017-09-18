#include "notas.h"

const int TRIGGER = 3;
const int ECHO = 4;
const int SPEAKER = 5;
const int LED_R = 6,
          LED_Y = 7,
          LED_G = 8,
          LED_B = 9,
          LED_W = 10;

//const int notas[] = {ZZ, C4, D4, E4, F4, G4};
const int notas[] = {ZZ, C4, D4, E4, F4, G4, A4, B4, C5, D5, F5, G5, A5, B5, C6, D6, F6, G6, A6, B6};
int num_notas = sizeof(notas);

void setup() {
  pinMode(TRIGGER, OUTPUT);
  pinMode(SPEAKER, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_Y, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_W, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
}

void luz(boolean acender, int led) {
  if (acender) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}

void loop() {
  float distance = pulse();
  Serial.println(distance);

  // Som: idx = indice do array notas[] (0 a num_notas-1)
  int idx = (int)(distance/4);
  if(idx > num_notas) { // se idx resultar em numero > num_notas, faça idx = num_notas
    idx = num_notas;
  }
  // soar um tom na nota correspondente por 500ms
  tone(SPEAKER, notas[ idx ], 200);

  // Luz(condição para acender, led)
  luz( distance >= 10,  LED_R);
  luz( distance >= 30, LED_Y);
  luz( distance >= 50, LED_G);
  luz( distance >= 70, LED_B);
  luz( distance >= 90, LED_W);

  delay(200);
}

float pulse() {
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);

  long duration = pulseIn(ECHO, HIGH, 50000);
  return duration / 58.0;
}

