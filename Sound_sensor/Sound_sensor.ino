// Pin definitions
int soundSensorPin = A0; // Sound sensor digital output pin
int ledpin1= 12;
int ledpin2= 11;
int ledpin3=10;

      // LED pin

void setup() {
  pinMode(soundSensorPin, INPUT); // Set sound sensor as input
  pinMode(ledpin1, OUTPUT);        // Set LED as output
  digitalWrite(ledpin1, LOW);    
    pinMode(ledpin2, OUTPUT);        // Set LED as output
  digitalWrite(ledpin2, LOW); 
    pinMode(ledpin3, OUTPUT);        // Set LED as output
  digitalWrite(ledpin3, LOW);   // Ensure LED is off initially
}

void loop() {
  int soundDetected = digitalRead(soundSensorPin); // Read sound sensor output

  if (soundDetected == HIGH) {
    digitalWrite(ledpin1, HIGH);
    digitalWrite(ledpin2, HIGH);
    digitalWrite(ledpin3, HIGH);
     // Turn on the LED when sound is detected
  } else {
    digitalWrite(ledpin1, LOW);
     digitalWrite(ledpin2, LOW);
      digitalWrite(ledpin3, LOW); // Turn off the LED when no sound is detected
   }
}