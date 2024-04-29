#include<WiFi.h>
#define SSIP_NAME "อ่านหาพ่อง"
#define SSIP_PASS "Metallica1215"

IPAddress local_ip = {(192, 168, 1150)};
IPAddress gateway = {(192, 168, 1, 1)};
IPAddress subnet = {(255, 255, 255, 0)};

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  WiFi.softAP(SSIP_NAME, SSIP_PASS);
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());
  delay(5000);
  WiFi.softAPdisconnect();
  Serial.print("SoftAPdisconnect!!!");
}

void loop() {

}
