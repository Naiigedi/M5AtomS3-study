//  LEDのアノード側はGPIO6に接続

#include "M5AtomS3.h"

const uint8_t LED_PIN = 6;  // LED出力に使用するGPIO PIN番号

void setup() {
  //LED出力ピンを出力モードにする
  pinMode(LED_PIN, OUTPUT); 
  M5.begin(true, true, false,true);

  // PWM出力初期設定
  ledcSetup(1, 1000, 10);   // PWM初期設定（ﾁｬﾝﾈﾙ, 周波数Hz, bit数）
  ledcAttachPin(LED_PIN, 1); // PWMﾁｬﾝﾈﾙ割り当て（端子番号, ﾁｬﾝﾈﾙ)
  ledcWrite(1, 512);        // PWM出力開始（ﾁｬﾝﾈﾙ、Duty比：MAXはbit数の分解能）
//  digitalWrite(LED_PIN, LOW);       //出力初期化（LED消灯）
}

void loop() {
  ledcWrite(1, 512);        // PWM出力開始（ﾁｬﾝﾈﾙ、Duty比：MAXはbit数の分解能）
  delay(500);
  ledcWrite(1, 100);        // PWM出力開始（ﾁｬﾝﾈﾙ、Duty比：MAXはbit数の分解能）
  delay(500);
  }
