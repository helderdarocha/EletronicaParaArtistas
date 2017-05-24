#define PINO_LIGAR    3
#define PINO_DESLIGAR 4
#define LED 8

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(PINO_LIGAR, INPUT_PULLUP);
  pinMode(PINO_DESLIGAR, INPUT_PULLUP);
}

void loop() {
  int acender = digitalRead(PINO_LIGAR);  
  int apagar  = digitalRead(PINO_DESLIGAR);  
   
  if(acender == LOW) {
    digitalWrite(LED, HIGH);
  }
  if(apagar  == LOW) {
    digitalWrite(LED, LOW);
  }
}

