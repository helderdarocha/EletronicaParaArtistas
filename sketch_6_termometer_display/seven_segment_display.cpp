#include "Arduino.h"
#include "seven_segment_display.h"

void showNumber(int* disp, int dig) {
  for(int i = 0; i < DISPLAY_LEDS; i++) {
     digitalWrite(disp[i], digit[dig][i]);
  }
}
