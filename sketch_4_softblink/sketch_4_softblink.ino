int LED = 3;       // Qualquer pino PWM: 3, 5, 6, 9, 10, 11
int brilho = 255;  // Inicia com brilho máximo
int direcao = -1;  // 1 = aumentando, -1 = diminuindo

void setup() {
    pinMode(LED, OUTPUT);  // É opcional com analogWrite
}

void loop() {
    analogWrite(LED, brilho);
    delay(5);
    brilho = brilho + direcao;
    if(brilho <= 0 || brilho >= 255) {
        direcao = -direcao;
    }
}

