#define BLYNK_TEMPLATE_ID "TMPL6ryFDzw66"
#define BLYNK_TEMPLATE_NAME "RED"
#define BLYNK_AUTH_TOKEN "lCOfDQbCDyXCwFpKmee58YfhpGwA8GvG"
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


const char ssid [] = "อ่านหาพ่อง";
const char pass [] = "Metallica1215";
const char auth [] = BLYNK_AUTH_TOKEN;


BlynkTimer timer;


void timerEvent();


void setup() {
  Serial.begin(115200);
  Blynk.begin (auth, ssid, pass);
  timer.setInterval(1000L, timerEvent);


  pinMode(32, OUTPUT);
  digitalWrite(32, LOW);
}


void loop() {
  Blynk.run();
  timer.run();
}


BLYNK_WRITE(V1){
  if(param.asInt()){
    digitalWrite(32, HIGH);}
  else{
    digitalWrite(32, LOW);}
  }
  void timerEvent(){
  }
