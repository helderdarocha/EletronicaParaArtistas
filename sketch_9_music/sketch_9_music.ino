/*
 * Baseado em "Melody" criado por Tom Igoe (Exemplo toneMelody)
 * http://www.arduino.cc/en/Tutorial/Tone
 */

#include "notas.h"

int ALTO_FALANTE = 5; // coloque alto-falante ou buzzer entre pino 5 e GND
int NUM_NOTAS = 44;    // número de notas incluídas em melodia[]

int melodia[] = {
  G4, G4, G4, DS4, AS4, G4, DS4, AS4, G4,
  D5, D5, D5, DS5, AS4, FS4, DS4, AS5, G4,
  G5, G4, G4, G5, FS5, F5, E5, DS5, E5, ZZ, 
  GS4, CS5, C5, B5, AS5, A5, AS5, ZZ, 
  DS4, FS4, DS4, AS4, G4, DS4, AS5, G4
};

// duração: 1 = semibreve, 2 = mínima, 4 = seminima, 8 = colcheia, etc.:
int duracoes[] = { 
  4, 4, 4, 6, 8, 4, 6, 8, 2,
  4, 4, 4, 6, 8, 4, 6, 8, 2,
  4, 6, 8, 4, 6, 8, 16, 16, 8, 8, 
  8, 4, 6, 8, 16, 16, 8, 8, 
  8, 4, 6, 8, 4, 6, 8, 2
};

void setup() {
  for (int nota = 0; nota < NUM_NOTAS; nota++) {
    int duracao = 1000 / duracoes[nota]; // divide 1000 por cada duração
    tone(ALTO_FALANTE, melodia[nota], duracao);
    int pausa = duracao * 1.30;
    delay(pausa);
    noTone(ALTO_FALANTE);
  }
}

void loop() {
  // no need to repeat the melody.
}

