#include "M5AtomS3.h"

const uint8_t ADC_PIN = 6;    // LED出力に使用するGPIO PIN番号
const float ADC = 4095;       // ADC分解能
const float ADCV = 3.1;      // ADC時の最大電圧 3.3Vではないことに注意
const float RESISTOR = 10000;  // 10.0kΩ
const float K_val = 2200000;    // 光電流[IuA] vs 照度[Lux] のフィッティングの式から求めた定数

void setup() {
  pinMode(ADC_PIN, INPUT);
  M5.begin();
  Serial.begin(9600);
}

void loop() {
  float analogValue = analogRead(ADC_PIN);    // ADの値を取得
  float Lux = analogValue * K_val * ADCV / ADC / RESISTOR;  //ADの値を換算
  M5.Lcd.clear();                       // 画面リセット
  //M5.Lcd.printf("%f [Lux]", Lux);
  M5.Lcd.drawFloat(Lux, 3, 10, 50, 4);  // (数値, 小数点以下の個数,  x座標, y座標, フォント)
  Serial.println(analogValue);          // debug用としてRawData抽出
  delay(1000);
}
