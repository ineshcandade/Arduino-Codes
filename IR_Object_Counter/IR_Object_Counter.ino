// Define the IR sensor pin
const int irSensorPin = 2;

// Counter variable
int objectCount = 0;

// Variable to store the last state of the sensor
bool lastSensorState = LOW;

void setup() {
  // Set the IR sensor pin as input
  pinMode(irSensorPin, INPUT);

  // Start Serial communication
  Serial.begin(9600);

  // Print initial message
  Serial.println("Touchless Counter Started!");
}

void loop() {
  // Read the current state of the IR sensor
  bool currentSensorState = digitalRead(irSensorPin);

  // Check for a rising edge (object detected)
  if (currentSensorState == HIGH && lastSensorState == LOW) {
    objectCount++; // Increment the counter
    Serial.print("Object Count: ");
    Serial.println(objectCount);
  }

  // Update the last sensor state
  lastSensorState = currentSensorState;

  // Small delay to debounce
   delay(50);
}