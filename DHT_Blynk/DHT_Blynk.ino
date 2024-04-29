#define BLYNK_TEMPLATE_ID "TMPL68P2NOeI6"
#define BLYNK_TEMPLATE_NAME "TestDHT11"
#define BLYNK_AUTH_TOKEN "Mqx-ar80dNLaxh0N90t9JNto_MTlBirC"
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


#include <DHT.h>
#define DHTPIN 27
#define DHTTYPE DHT11


DHT dht (DHTPIN, DHTTYPE);


const char ssid [] = "อ่านหาพ่อง";
const char pass [] = "Metallica1215";
const char auth [] = BLYNK_AUTH_TOKEN;


BlynkTimer timer;


void timerEvent();
void pushHumidity();
void pushTemp();


void setup() {
  Serial.begin(115200);
  Blynk.begin (auth, ssid, pass);
  timer.setInterval(1000L, timerEvent);


  dht.begin();
    delay(2000);
}


void loop() {
  Blynk.run();
  timer.run();
}


void timerEvent(){
  pushTemp();
  pushHumidity();
}


void pushTemp(){
  float t = dht.readTemperature();
  Blynk.virtualWrite (V0,t);
  Serial.print("Temperature is :   ");
  Serial.print(t);
  Serial.println("    ํC");
}


void pushHumidity(){
  float h = dht.readHumidity();
  Blynk.virtualWrite (V1,h);
  Serial.print("Humidity is :   ");
  Serial.print(h);
  Serial.println("   %");
}
