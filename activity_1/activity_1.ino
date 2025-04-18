void setup() {
  // initialize serial communication
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hello Arduino");

}

void loop() {
  digitalWrite(13, HIGH);
  delay(2000);
  Serial.println("in the loop");
  delay(500);
  digitalWrite(13, LOW);
  delay(1000);
  
}
