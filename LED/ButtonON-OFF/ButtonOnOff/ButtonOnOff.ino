//　タクトスイッチはGPIO7とGNDに接続
//  LEDのアノード側はGPIO6に接続

#include "M5AtomS3.h"

const uint8_t LED_PIN = 6;  // LED出力に使用するGPIO PIN番号
const uint8_t Button_PIN = 7;  // Button入力に使用するGPIO PIN番号

void setup() {
  //LED出力ピンを出力モードにする
  pinMode(LED_PIN, OUTPUT); 
  pinMode(Button_PIN, INPUT_PULLUP);
  M5.begin(true, true, false,true);
  digitalWrite(LED_PIN, LOW);       //出力初期化（LED消灯）
}

void loop() {
  if(digitalRead(Button_PIN)==0){ 
    digitalWrite(LED_PIN, HIGH); //タクトスイッチが押されたとき、点灯
  } 
  else{
    digitalWrite(LED_PIN, LOW);  //それ以外は消灯
  }
  delay(100);
  }
