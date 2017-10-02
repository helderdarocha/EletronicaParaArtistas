int R = 3;
int G = 10;
int B = 9;
int POT = A0;

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  delay(100);
  int pot = analogRead(POT);

  if(pot <= 511) {
    analogWrite(R, pot/2);
  } else {
    analogWrite(R, 255);
  }
  
  if(pot > 256 && pot < 768) {
    analogWrite(G, abs(512 - pot));
  } else {
    analogWrite(G, 255);
  }
  
  if(pot >= 512) {
    analogWrite(B, (1023 - pot)/2);
  } else {
    analogWrite(B, 255);
  }
}

