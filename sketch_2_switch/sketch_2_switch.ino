void setup() {
  pinMode(8, OUTPUT);
}

void loop() {
  int estado = digitalRead(3);
  delay(10); // espera 10 ms antes de testar
  if(estado == LOW) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }
}


