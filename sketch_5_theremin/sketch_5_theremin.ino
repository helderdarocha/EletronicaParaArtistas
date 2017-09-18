#define FTE 10
#define LDR A2 
#define POT A3 

void setup() {}  // pinMode é opcional com analogRead

void loop() {
  int luz    = analogRead(LDR);
  int pausa  = analogRead(POT);
  delay(pausa * .25);
  int tom = luz * luz * luz / 16;  // experimente outros valores
  tone(FTE, tom);
}

