//  LEDのアノード側はGPIO6に接続

#include "M5AtomS3.h"

const uint8_t LED_PIN = 6;  // LED出力に使用するGPIO PIN番号

void setup() {
  //LED出力ピンを出力モードにする
  pinMode(LED_PIN, OUTPUT); 
  M5.begin();
  digitalWrite(LED_PIN, LOW);       //出力初期化（LED消灯）
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
  }
