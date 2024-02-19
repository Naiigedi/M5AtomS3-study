#include "M5AtomS3.h"

const uint8_t ADC_PIN = 6;  // LED出力に使用するGPIO PIN番号
const uint8_t RESO = 4095;  // ADCの分解能12bit

void setup() {
  pinMode(ADC_PIN, INPUT);
  M5.begin();
  // put your setup code here, to run once:

}

void loop() {
  int analogValue = analogRead(ADC_PIN);
  M5.Lcd.println(analogValue);
  delay(2000);
}
