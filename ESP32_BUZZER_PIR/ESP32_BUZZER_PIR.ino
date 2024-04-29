int buzzer = 22;
int digitalPin = 21;
int val = 0;

#define LED 18 // เพิ่ม เพื่อเปิดไฟ

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(digitalPin, INPUT);
  pinMode(LED, OUTPUT); // เพิ่ม เพื่อเปิดไฟ
  Serial.begin(9600);
}


void loop() {
  val = digitalRead(digitalPin);
  Serial.print("val = ");
  Serial.println(val);
  if (val == 0) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(LED, LOW);
  }
  else {
    digitalWrite(buzzer, LOW);
    digitalWrite(LED, HIGH);

  }
  delay(100);
}
