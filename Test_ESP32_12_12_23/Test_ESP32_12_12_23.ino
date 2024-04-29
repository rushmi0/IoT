#define LED 2


void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  
  delay(3000);
  digitalWrite(LED, HIGH);
  delay(6000);
  digitalWrite(LED, LOW);

}
