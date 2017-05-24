#define CHAVE 3
#define LED   8

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  int estado = digitalRead(CHAVE);
  delay(10); // espera 10 milissegundos antes de testar
  if(estado == LOW) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}

