const int TRIGGER = 3;
const int ECHO = 4;
const int MOTOR = 5;


void setup() {
  pinMode(TRIGGER, OUTPUT);
  pinMode(MOTOR, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
}

void loop() {
  float distance = pulse();
  int velocidade = 0;
  if(distance > 20) {
    velocidade = 255;
  } 
  Serial.println(distance);
  analogWrite(MOTOR, velocidade);
  delay(200); // must be over 60ms
}

float pulse() {
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);

  long duration = pulseIn(ECHO, HIGH);
  return duration / 58.0;
}

