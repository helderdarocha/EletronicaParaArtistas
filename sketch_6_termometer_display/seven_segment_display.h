static int digit[10][7] = {
    {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW},
    {LOW, HIGH,HIGH,LOW, LOW, LOW, LOW},
    {HIGH,HIGH,LOW, HIGH,HIGH,LOW, HIGH},
    {HIGH,HIGH,HIGH,HIGH,LOW, LOW, HIGH},
    {LOW, HIGH,HIGH,LOW, LOW, HIGH,HIGH},
    {HIGH,LOW, HIGH,HIGH,LOW, HIGH,HIGH},
    {HIGH,LOW, HIGH,HIGH,HIGH,HIGH,HIGH}, 
    {HIGH,HIGH,HIGH,LOW, LOW, LOW, LOW}, 
    {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH}, 
    {HIGH,HIGH,HIGH,HIGH,LOW, HIGH,HIGH}
};

const int DISPLAY_LEDS = 7;
const int DISPLAY_DIGITS = 10;

void showNumber(int* disp, int dig) {
  for(int i = 0; i < DISPLAY_LEDS; i++) {
     digitalWrite(disp[i], digit[dig][i]);
  }
}
