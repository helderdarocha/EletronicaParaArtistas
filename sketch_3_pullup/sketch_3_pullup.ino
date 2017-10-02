void setup() {
  pinMode(8, OUTPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
}

void loop() {
  int acender = digitalRead(3);  
  int apagar  = digitalRead(4);  
   
  if(acender == LOW) {
    digitalWrite(8, HIGH);
  }
  if(apagar  == LOW) {
    digitalWrite(8, LOW);
  }
}

