#include <WiFi.h>
#include <WiFiClientSecure.h>
#include "DHT.h"

#define analog_pin 34
#define LED 27


// ตรวจสอบว่าโค้ดนี้ถูกคอมไพล์บน ESP32 เท่านั้น
#ifndef ESP32
#pragma message(THIS EXAMPLE IS FOR ESP32 ONLY!)
#error Select ESP32 board.
#endif


// นำเข้าไลบรารี TridentTD_LineNotify
#include <TridentTD_LineNotify.h>

// กำหนด Line Token
#define LINE_TOKEN "g86GEgYWCgCBjwQZSvJPips9GDrxH0gWprtcblz8L51"

const char* ssid = "อ่านหาพ่อง";
const char* password = "Metallica1215";

const char* host = "script.google.com";
const int httpsPort = 443;


// *********************************************************

int ldr_value = 0;
String led_state = "LOW";


void setup() {

  WiFi.begin(ssid, password);

  // แสดงเวอร์ชันของไลบรารี LINE Notify ที่ใช้
  Serial.println(LINE.getVersion());

  // กำหนด Line Token
  LINE.setToken(LINE_TOKEN);

  //กำหนด mode ให้กับ pin
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);//ส่งสัญญาณ LOW ไปที่ LED
  Serial.begin(9600);
}
void loop() {
  ldr_value = analogRead(analog_pin);
  if(ldr_value > 700){//เช็คค่าของ ldr_value ว่ามีค่ามากกว่า 700 หรือไม่
    digitalWrite(LED, LOW);//ส่งสัญญาณ LOW ไปที่ LED
    led_state = "LOW";
  }
  else{
    digitalWrite(LED, HIGH);//ส่งสัญญาณ HIGH ไปที่ LED
    led_state = "HIGH";
  }  
  Serial.print("LDR value: ");
  Serial.print(ldr_value); // เเสดงค่าของ ldr_value
  Serial.print("\t");
  Serial.print("LED state: ");
  Serial.println(led_state); // เเสดงสถานะของ led_state

  String value = "LED value : " + String(ldr_value);
  LINE.notify(value);

  String state = "LED state : " + String(led_state);
  LINE.notify(state);

  delay(1000);
}
