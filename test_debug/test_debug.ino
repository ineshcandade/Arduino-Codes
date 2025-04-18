void setup() {
  // initialize serial communication
  Serial.begin(9600);
  Serial.println("Hello Arduino");

}

void loop() {
  Serial.println("in the loop");
  delay(500);
}
