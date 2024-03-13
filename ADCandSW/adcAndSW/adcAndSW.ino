#include "M5AtomS3.h"

const uint8_t ADC_PIN = 5;    // ADC読み込み用のGPIO PIN番号
const uint8_t LED_PIN = 6;    // LED出力に使用するGPIO PIN番号
const uint8_t Button_PIN = 7;    // SW入力に使用するGPIO PIN番号
const float ADC = 4095;       // ADC分解能
const float ADCV = 3.1;      // ADC時の最大電圧 3.3Vではないことに注意
const float RESISTOR = 10000;  // 10.0kΩ
const float K_val = 2200000;    // 光電流[IuA] vs 照度[Lux] のフィッティングの式から求めた定数

void setup() {
  pinMode(ADC_PIN, INPUT);
  pinMode(Button_PIN, INPUT_PULLUP);
  ledcSetup(1, 1000, 10);   // PWM初期設定（ﾁｬﾝﾈﾙ, 周波数Hz, bit数）
  ledcAttachPin(LED_PIN, 1); // PWMﾁｬﾝﾈﾙ割り当て（端子番号, ﾁｬﾝﾈﾙ)
  ledcWrite(1, 0);        // PWM出力開始（ﾁｬﾝﾈﾙ、Duty比：MAXはbit数の分解能）
  M5.begin();
  Serial.begin(9600);
}

void loop() {
  float sval = 0;
  float analogValue = 0;
  int i;
  // analogRead の値を3回平均
  for(i=0; i < 3; i++ ){
    sval = sval + analogRead(ADC_PIN);
    delay(10);
  }
  sval = sval / 3; 
  float Lux = sval * K_val * ADCV / ADC / RESISTOR;  //ADの値を換算

  char buff[10];
  char buff_all[20];
  M5.Lcd.clear();                       // 画面リセット
  sprintf(buff, "%5.2f", Lux);
  snprintf(buff_all, 15,  "%s%s", buff, "[Lux]" );
  M5.Lcd.drawString(buff_all, 10, 50, 2);
  if(digitalRead(Button_PIN)==0){
    Serial.println(sval);          // debug用としてRawData抽出
  }
  if(Lux < 10){
    ledcWrite(1, 512);        // PWM出力開始（ﾁｬﾝﾈﾙ、Duty比：MAXはbit数の分解能）
  }
  else{
    ledcWrite(1, 0);          // PWM出力停止（ﾁｬﾝﾈﾙ、Duty比：MAXはbit数の分解能）
  }
  delay(200);
}
