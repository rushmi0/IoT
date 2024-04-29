#include <WiFi.h>
#define SSID_AP_NAME "ESPino32 ap mode"
#define SSID_AP_PASS "root"

#define SSID_NAME "อ่านหาพ่อง"
#define SSID_PASS "Metallica1215"


void setup() {
  Serial.begin(115200);
  delay(100);
  WiFi.softAP(SSID_NAME, SSID_PASS);
  Serial.print("AP IP Address: ");
  Serial.println(WiFi.softAPIP());
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(SSID_NAME);
  WiFi.begin(SSID_NAME, SSID_PASS);

  while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print("+");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("STA IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}

void loop() {
 
}
