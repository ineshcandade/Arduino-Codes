//Define the pin numbers for the IR sensor and the LED
const int irSensorPin = A5; // IR sensor connected to pin A5
const int ledPin = 2;       // LED connected to pin 2

void setup() {
  // Initialize the IR sensor pin as an input
  pinMode(irSensorPin, INPUT);
  
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the state of the IR sensor
  int sensorState = digitalRead(irSensorPin);
  Serial.println(sensorState);

  // Check if the sensor detects an object (assuming LOW means an object is present)
  if (sensorState == HIGH) {
    digitalWrite(ledPin, LOW); // Turn on the LED
    Serial.println("LED : 0");
  } else {
    digitalWrite(ledPin, HIGH);  // Turn off the LED
    Serial.println("LED : 1");
  }
  // Add a small delay to prevent excessive serial output
   delay(100);
}