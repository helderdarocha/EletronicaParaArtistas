#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

Adafruit_PCD8544 display = Adafruit_PCD8544(13, 11, 5, 7, 6);

void setup() {
  Serial.begin(9600);
  display.begin(); 
  display.setContrast(50);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK, WHITE);
  display.setCursor(0,0);
  display.println("Hello, world!");
  display.display();
}

void loop() {

}
