/* Normalmente deve-se evitar usar os pinos: 0 (atrapalha o upload e acende led),
 * 1 (interfere na saída serial e acende led) e 13 (acende led).
 * 
 * Como estamos usando o pino digital 0, deslique o fio conectado ao pino 0 
 * (ou o GND do Arduino - o que for mais fácil) durante o upload, 
 * e depois conecte o fio de volta para iniciar o programa.
 * 
 * Alternativa: substitua os pinos 0, 1 e 13 pelos pinos analógicos A0, A1 e A2
 * referenciando-os pelos números 14 (A0), 15 (A1) e 16 (A2).
 */
    
void setup() {
  // Define cada pino como saida
  for(int i = 3; i < 16; i++) {
    pinMode(i, OUTPUT);
  }
  teste();
}

// testa os leds acendendo-os e depois apagando-os
void teste() {
  for(int i = 3; i < 16; i++) {
    digitalWrite(i, HIGH);
    delay(500);
  }
  for(int i = 3; i < 16; i++) {
    digitalWrite(i, LOW);
    delay(500);
  }
}

void loop() {}
