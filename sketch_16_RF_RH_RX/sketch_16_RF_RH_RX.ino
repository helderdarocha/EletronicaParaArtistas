#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <RH_ASK.h>

#define RF_RX  11  // receiver pin
#define RF_TX  12  // transmitter pin (not used)
#define RF_PPT 10  // transmitter enable (not used)

#define DISP_LIGHT 9
#define DISP_CLK   6
#define DISP_DIN   5
#define DISP_DC    2
#define DISP_CE    4
#define DISP_RST   3

Adafruit_PCD8544 display = Adafruit_PCD8544(DISP_CLK, DISP_DIN, DISP_DC, DISP_CE, DISP_RST);
RH_ASK receiver(2000, RF_RX, RF_TX, RF_PPT, false);

void setup() {
  Serial.begin(9600);
  
  display.begin(); 
  display.setContrast(50);
  display.clearDisplay();
  
  display.setTextSize(1);
  display.setTextColor(BLACK, WHITE);
  display.setCursor(0,0);

  if(!receiver.init()) {
     Serial.println("Initialization failed.");
     display.println("Init failed.");
  } else {
     Serial.println("Waiting...");
     display.println("Waiting...");
  }
  display.display();
  display.clearDisplay();
}

void loop() {
    uint8_t buf[10];
    uint8_t buflen = sizeof(buf);

    if (receiver.recv(buf, &buflen)) {
       char* text = (char*)buf;

       char temp[5], humi[5];
       memcpy(temp, text, 5*sizeof(char));
       memcpy(humi, &text[5], 5*sizeof(char));

       float temperature = (float)atoi(temp)/100.0;
       float humidity    = (float)atoi(humi)/100.0;
       
       Serial.print("Temperature: ");
       Serial.println(temperature);  
       Serial.print("Humidity: ");
       Serial.println(humidity);  

       display.print("Temp.: "); 
       display.print(temperature);
       display.println(" C");
       display.print("Umid.: ");
       display.print(humidity);
       display.println(" \%"); 
       
       display.display();
       display.clearDisplay();
    }
    delay(5000);
}
