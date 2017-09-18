#include <SimpleDHT.h>

#define DHT22  8

SimpleDHT22 dht;

int leds[] = {2, 3, 4, 5, 6, 7, 9, 14};
int ledCount = 8;

void setup() {
  Serial.begin(9600);
  for (int led = 0; led < ledCount; led++) {
    pinMode(leds[led], OUTPUT);
  }
}

void loop() {
  float temperature = 0;
  float humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht.read2(DHT22, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT22 failed, err=");
    Serial.println(err);
    delay(2000);
    return;
  }

  // humidity meter 
  int ledLevel = map((int)humidity, 0, 100, 0, ledCount + 1);
  for (int led = 0; led < ledCount; led++) {
    if (led >= ledLevel) {
      digitalWrite(leds[led], HIGH);
    } else {
      digitalWrite(leds[led], LOW);
    }
  }

  Serial.print("Temperature(C): ");
  Serial.println(temperature);
  Serial.print("Humidity(%): ");
  Serial.println(humidity);

  delay(2000);
}
