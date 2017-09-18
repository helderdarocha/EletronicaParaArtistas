#include <RH_ASK.h>
#include <SimpleDHT.h>

#define RF_RX  11  // receiver pin (not used)
#define RF_TX  12  // transmitter pin
#define RF_PPT 10  // transmitter enable (not used)
#define DHT22  8

RH_ASK transmitter(2000, RF_RX, RF_TX, RF_PPT, false);
SimpleDHT22 dht;

int leds[] = {2, 3, 4, 5, 6, 7, 9, 14};
int ledCount = 8;

void setup() {
  Serial.begin(9600);
  if (!transmitter.init()) {
    Serial.println("Initialization failed.");
  }
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

  int temp100 = (int)(temperature * 100);
  int humi100 = (int)(humidity * 100);

  // humidity meter 
  int ledLevel = map(humi100, 0, 10000, 0, ledCount + 1);
  for (int led = 0; led < ledCount; led++) {
    if (led >= ledLevel) {
      digitalWrite(leds[led], HIGH);
    } else {
      digitalWrite(leds[led], LOW);
    }
  }

  int msglen = 10;

  char message[msglen];
  sprintf(message, "%5d%5d", temp100, humi100);

  Serial.print("Sending: ");
  Serial.println(message);

  transmitter.send((uint8_t *)message, msglen);
  transmitter.waitPacketSent();

  delay(2500);
}
