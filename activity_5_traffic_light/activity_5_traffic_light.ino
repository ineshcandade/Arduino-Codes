#define LED_4_PIN 12
#define LED_2_PIN 11
#define LED_3_PIN 10
#define LED_1_PIN 13
#define BUTTON_pin 2

void setup() {
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
  pinMode(LED_4_PIN, OUTPUT);


  digitalWrite(LED_1_PIN, LOW);
  digitalWrite(LED_2_PIN, LOW);
  digitalWrite(LED_3_PIN, LOW);
  digitalWrite(LED_4_PIN, LOW);
}

void loop() {
  digitalWrite(LED_1_PIN, HIGH);
  digitalWrite(LED_2_PIN, LOW);
  digitalWrite(LED_3_PIN, LOW);
  digitalWrite(LED_4_PIN, LOW);
  delay(500);
  digitalWrite(LED_1_PIN, LOW);
  digitalWrite(LED_3_PIN, LOW);
  digitalWrite(LED_2_PIN, HIGH);
  digitalWrite(LED_4_PIN, LOW);
  delay(500);
  digitalWrite(LED_1_PIN, LOW);
  digitalWrite(LED_3_PIN, HIGH);
  digitalWrite(LED_2_PIN, LOW);
  digitalWrite(LED_4_PIN, LOW);
  delay(500);
  digitalWrite(LED_1_PIN, LOW);
  digitalWrite(LED_4_PIN, HIGH);
  digitalWrite(LED_2_PIN, LOW);
  digitalWrite(LED_3_PIN, LOW);
  delay(500);
}







  
