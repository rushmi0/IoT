#include "DHTesp.h"


// ตรวจสอบว่าโค้ดนี้ถูกคอมไพล์บน ESP32 เท่านั้น
#ifndef ESP32
#pragma message(THIS EXAMPLE IS FOR ESP32 ONLY!)
#error Select ESP32 board.
#endif


// นำเข้าไลบรารี TridentTD_LineNotify
#include <TridentTD_LineNotify.h>


// กำหนดค่าของเครือข่าย
#define SSID     "อ่านหาพ่อง"         // ชื่อเครือข่าย (network-name)
#define PASSWORD "Metallica1215"    // รหัสผ่านเครือข่าย (pass-to-network)


// กำหนด Line Token
#define LINE_TOKEN "wipP7AoXo0Hy3mLIObX37mgOMwZSnrrOuoOSseIV0tu"


// กำหนดหมายเลขขาของเซ็นเซอร์ DHT
#define dhtPin 27


// สร้างอ็อบเจ็กต์ DHT
DHTesp dht;


// ฟังก์ชัน setup ที่จะทำงานครั้งแรกเมื่อเริ่มต้นโปรแกรม
void setup() {
  // เริ่มต้น Serial communication
  Serial.begin(115200);
  Serial.println();


  // แสดงเวอร์ชันของไลบรารี LINE Notify ที่ใช้
  Serial.println(LINE.getVersion());


  // เริ่มต้นการเชื่อมต่อ WiFi
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n", SSID);


  // รอจนกว่าจะเชื่อมต่อ WiFi สำเร็จ
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(400);
  }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());


  // เริ่มต้นการใช้งานเซ็นเซอร์ DHT
  dht.setup(dhtPin, DHTesp::DHT11);
  Serial.println("DHT initiated");


  // กำหนด Line Token
  LINE.setToken(LINE_TOKEN);
}


void loop() {
  delay(5000);
  float temperature = dht.getTemperature();
  float humidity = dht.getHumidity();
  Serial.println(" T:" + String(temperature) + " H:" + String(humidity) );
  if (isnan(temperature) || isnan(humidity))
  {
    LINE.notify("อ่านค่าความชื้นไม่ได้");
  }
  else if (humidity >= 25) {
   
    

    // ตัวอย่างส่งข้อความ
	  LINE.notify ("วัชรพล");
    LINE.notify ("2013111089");
    LINE.notify("ความชื้นเกินกำหนด : ");
    LINE.notify(humidity);
    LINE.notify("อุณหภูมิ : ");
    LINE.notify(temperature);
    Serial.println("send line");
  }
}
