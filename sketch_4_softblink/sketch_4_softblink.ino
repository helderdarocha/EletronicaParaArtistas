int LED = 3;
int brilho = 255; // inicia com brilho máximo
int direcao = -1;  // 1 = aumentando, -1 = diminuindo

void setup() {
    pinMode(LED, OUTPUT);  // opcional com analogWrite (mas é boa prática)
}

void loop() {
    analogWrite(LED, brilho);
    delay(2);
    brilho = brilho + direcao;
    if(brilho <= 0 || brilho >= 255) {
        direcao = -direcao;
    }
}

