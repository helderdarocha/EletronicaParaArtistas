#define TERMOMETRO A1

void setup() {
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(TERMOMETRO);
  float volts = (leitura / 1024.0) * 5.0;
  float celsius = (volts) * 100.0;
  
  Serial.print("Temperatura: ");
  Serial.println(celsius);
  
  delay(2000);
}

