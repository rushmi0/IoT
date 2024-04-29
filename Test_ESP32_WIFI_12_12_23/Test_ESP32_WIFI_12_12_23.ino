#include<WiFi.h>

void setup() {
  Serial.begin(9600);
  delay(10);
  Serial.println();
  
  WiFi.begin(
    "อ่านหาพ่อง", // "SSID_NAME"
    "Metallica1215" // "SSID_PASS"
  );

  Serial.print("Connecting...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Connected, IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
