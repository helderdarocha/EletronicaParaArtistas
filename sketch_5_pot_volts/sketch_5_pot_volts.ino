/*
 * Conecte um potenciometro de 10k da sequinte forma:
 * Terminal 1: GND
 * Terminal 2 (central): A0
 * Terminal 3: VCC
 * 
 * Abra o monitor serial para ver os resultados.
 * 
 * Troque por:
 * LDR entre A0 e GND, 10k entre A0 e VCC
 * Termistor entre A0 e GND, 10k entre A0 e VCC
 */

void setup() {
    Serial.begin(9600);
}

void loop() {
  int pot = analogRead(A0);
  float volts = (pot / 1023.0) * 5.0;
  Serial.println(volts);
}
