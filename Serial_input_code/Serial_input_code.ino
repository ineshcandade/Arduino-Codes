void setup() {
  Serial.begin(115200);
  Serial.setTimeout(10);
  // becomes faster
}

void loop() {
  if (Serial.available() > 0) {
    int var = Serial.parseInt();
    Serial.println(var);
  }
}

//  u can use long var, double var = parseFloat
// use String var for words
  
