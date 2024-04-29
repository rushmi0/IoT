#define AOUT_PIN 34 
#define LED1 33
#define LED2 32

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}


void loop() {
  int value = analogRead(AOUT_PIN); // read the analog value from sensor


  Serial.print("Moisture value: ");
  Serial.println(value); 

  if(value > 4000) {
    Serial.println("น้ำกูอยู่ไหน!!");
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
  } else {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
  }


  delay(500);
}
