int sensor=A0;
int  LED=4;

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  bool value = digitalRead(sensor);
  Serial.println(value);

  if (value == 0) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED,LOW);
  }
}
