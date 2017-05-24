#define FTE 12
#define LDR A0 
#define POT A1 

void setup() {}  // pinMode é opcional com analogRead

void loop() {
  int luz    = analogRead(LDR);
  int pausa  = analogRead(POT);
  delay(pausa * .25);
  int tom = luz * luz * luz / 16;  // experimente outros valores
  tone(FTE, tom);
}

