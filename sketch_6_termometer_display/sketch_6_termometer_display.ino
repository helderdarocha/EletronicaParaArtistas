#include "seven_segment_display.h"

#define  TERMOMETRO A3

int unidades[]  = {14, 15, 2, 3, 4, 5, 6};
int dezenas[]   = {7, 8, 9, 10, 11, 12, 16};
        
void setup() {
  for(int i = 0; i < DISPLAY_LEDS; i++) {
    pinMode(dezenas[i], OUTPUT);
    pinMode(unidades[i], OUTPUT);
  }
  // Para maior precisão usamos a referência interna de 1,1V
  // (conecte também o GND do LM35 a um GND diferente do usado pelos displays)
  analogReference(INTERNAL);
}

void exibir(int numero) {
  showNumber(unidades, numero % 10);
  showNumber(dezenas, numero / 10);
}

void loop() {
  int leitura = analogRead(TERMOMETRO);
  float volts = (leitura / 1024.0) * 1.1;
  float celsius = (volts) * 100.0;
  
  exibir((int)round(celsius));
  
  delay(2000);
}
