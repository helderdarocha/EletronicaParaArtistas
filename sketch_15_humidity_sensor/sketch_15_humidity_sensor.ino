#include <SimpleDHT.h>

#define DHT22  8

SimpleDHT22 dht;

void setup() {
  Serial.begin(9600);
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

  Serial.print("Temperature(C): ");
  Serial.println(temperature);
  Serial.print("Humidity(%): ");
  Serial.println(humidity);

  delay(2000);
}
