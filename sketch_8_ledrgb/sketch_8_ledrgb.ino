#define LED_VERMELHO 9
#define LED_VERDE 10
#define LED_AZUL 11

void setup() {}

void cor(int r, int g, int b) {
  analogWrite(LED_VERMELHO, 255 - r);
  analogWrite(LED_VERDE, 255 - g);
  analogWrite(LED_AZUL, 255 - b);
}

void acender(int r, int g, int b, int intervalo) {
  cor(r, g, b);
  delay(intervalo);
}

void loop() {
  acender(255,0,0,1000);      // vermelho
  acender(0,255,0,1000);      // verde
  acender(0,0,255,1000);      // azul
  acender(190,255,0,1000);    // amarelo
  acender(190,0,255,1000);    // magenta
  acender(0,255,255,1000);    // ciano
  acender(255,255,255,1000);  // branco
  acender(0,0,0,1000);        // apagado

  acender(63,0,0,1000);  // vermelho com 1/4 da intensidade
  acender(0,63,0,1000);  // verde com 1/4 da intensidade
  acender(0,0,63,1000);  // azul com 1/4 da intensidade
}

