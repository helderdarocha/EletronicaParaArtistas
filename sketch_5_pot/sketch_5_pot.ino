/*
 * Conecte um potenciometro de 10k da sequinte forma:
 * Terminal 1: GND
 * Terminal 2 (central): A0
 * Terminal 3: VCC
 * 
 * Abra o monitor serial para ver os resultados
 */

void setup() {
    Serial.begin(9600);
}

void loop() {
  int pot = analogRead(A0);
  Serial.println(pot);
}
