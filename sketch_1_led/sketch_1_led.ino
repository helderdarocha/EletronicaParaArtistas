void setup() {
    pinMode(8, OUTPUT);     // declara pino 8 como uma saída
}

void loop() {
    digitalWrite(8, HIGH);
    delay(50);
    digitalWrite(8, LOW);
    delay(50);
}

