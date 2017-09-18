const int TRIGGER = 3;
const int ECHO = 4;


void setup() {
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
}

void loop() {
  float distance = pulse();
  Serial.println(distance);
  delay(500); // must be over 60ms
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

