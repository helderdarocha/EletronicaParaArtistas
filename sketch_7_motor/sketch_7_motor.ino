#define PINO_MOTOR 3;
#define PINO_LDR A0;

void setup() { 
  pinMode(PINO_MOTOR, OUTPUT);
} 
 
void loop() { 
    int velocidade = analogRead(PINO_LDR) / 4; 
    analogWrite(PINO_MOTOR, velocidade);
}

