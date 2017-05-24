#include "ledsrgb.h"

#define LED_VERMELHO 9
#define LED_VERDE 10
#define LED_AZUL 11

void setup() {
  //pinMode(LED_VERMELHO, OUTPUT);
  //pinMode(LED_VERDE, OUTPUT);
  //pinMode(LED_AZUL, OUTPUT);
  configurarRGB(LED_VERMELHO, LED_VERDE, LED_AZUL);
}

void loop() {
  piscar(255,0,0,1000);    // vermelho
  piscar(0,255,0,1000);    // verde
  piscar(0,0,255,1000);    // azul
  piscar(190,255,0,1000);  // amarelo
  piscar(190,0,255,1000);  // magenta
  piscar(0,255,255,1000);  // ciano
  piscar(190,255,255,1000);  // branco
  piscar(0,0,0,1000);  // preto

  piscar(63,0,0,1000);  // vermelho com 1/4 da intensidade
  piscar(0,63,0,1000);  // verde com 1/4 da intensidade
  piscar(0,0,63,1000);  // azul com 1/4 da intensidade
}

