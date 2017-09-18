#include <OneWire.h>
#include <DallasTemperature.h>

#define DATA    4
#define LATCH   5
#define CLOCK   6
#define ENABLE  3
#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

static byte digits[] = {
  0b11111100,
  0b01100000,
  0b11011010,
  0b11110010,
  0b01100110,
  0b10110110,
  0b10111110,
  0b11100000,
  0b11111110,
  0b11110110
};

int count = 0;
float temperature = 0;

void setup() {
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(ENABLE, OUTPUT);
  setBrightness(25);
  Serial.begin(9600);
  sensors.begin();
}

void setBrightness(int percent) {
  int brightness = map(percent, 100, 0, 0, 255);
  analogWrite(ENABLE, brightness);
}

void displayNumber(int number) {
  int units = digits[number % 10];
  int tens  = digits[number / 10];

  if (number >= 100 || number < 0) { // error
    units = tens = 0b10011110;
  }

  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, LSBFIRST, tens);
  shiftOut(DATA, CLOCK, LSBFIRST, units);
  digitalWrite(LATCH, HIGH);
}

void loop() {
  sensors.requestTemperatures();
  temperature = sensors.getTempCByIndex(0);
  Serial.print("Temperature: ");
  Serial.println(temperature);
  displayNumber((int)round(temperature));
  count = 0;
  delay(10000); // 10 seconds for each reading
}
