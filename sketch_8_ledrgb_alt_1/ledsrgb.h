int pino_R;
int pino_G;
int pino_B;

void configurarRGB(int pr, int pg, int pb) {
  pino_R = pr;
  pino_G = pg;
  pino_B = pb;
}

void cor(int r, int g, int b) {
  analogWrite(pino_R, 255 - r);
  analogWrite(pino_G, 255 - g);
  analogWrite(pino_B, 255 - b);
}

void piscar(int r, int g, int b, int intervalo) {
  cor(r, g, b);
  delay(intervalo);
}
