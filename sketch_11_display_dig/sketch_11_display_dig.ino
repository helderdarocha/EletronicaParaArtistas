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

int unidades[]  = {14, 15, 2, 3, 4, 5, 6};
int dezenas[]   = {7, 8, 9, 10, 11, 12, 16};

static int digito[10][7] = {
    {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW},
    {LOW,HIGH,HIGH,LOW,LOW,LOW,LOW},
    {HIGH,HIGH,LOW,HIGH,HIGH,LOW,HIGH},
    {HIGH,HIGH,HIGH,HIGH,LOW,LOW,HIGH},
    {LOW,HIGH,HIGH,LOW,LOW,HIGH,HIGH},
    {HIGH,LOW,HIGH,HIGH,LOW,HIGH,HIGH},
    {HIGH,LOW,HIGH,HIGH,HIGH,HIGH,HIGH}, 
    {HIGH,HIGH,HIGH,LOW,LOW,LOW,LOW}, 
    {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH}, 
    {HIGH,HIGH,HIGH,HIGH,LOW,HIGH,HIGH}
};

const int DISPLAY_LEDS = 7;
const int DISPLAY_DIGITS = 10;
        
void setup() {
  for(int i = 0; i < DISPLAY_LEDS; i++) {
    pinMode(dezenas[i], OUTPUT);
    pinMode(unidades[i], OUTPUT);
  }
}

void acende(int* disp, int dig) {
  for(int i = 0; i < DISPLAY_LEDS; i++) {
     digitalWrite(disp[i], digito[dig][i]);
  }
}

void loop() {
  for(int j = 0; j < DISPLAY_DIGITS; j++) {
     acende(dezenas, j);
     for(int i = 0; i < DISPLAY_DIGITS; i++) {
         acende(unidades, i);
         delay(500);
     } 
  }
}
