int ldrpin = A7;  // Analog pin connected to the LDR (Light Dependent Resistor)
int ledpin = 9;   // PWM pin connected to the LED

void setup() {
    // Initialize serial communication at 9600 baud rate for debugging
    Serial.begin(9600);

    // Configure LDR pin as input to read light intensity
    pinMode(ldrpin, INPUT);

    // Configure LED pin as output to control LED brightness
    pinMode(ledpin, OUTPUT);
}

void loop() {
    // Read the current value from the LDR (ranges from 0 to 1023)
    int ldrValue = analogRead(ldrpin);

    // Map the LDR value to an LED brightness value (0 to 255)
    // Bright light (high LDR value) corresponds to low LED intensity, and vice versa
    int ledIntensity = map(ldrValue, 0, 1023, 0, 255);

    // Print the LDR value to the Serial Monitor for debugging
    Serial.print("LDR Value: ");
    Serial.println(ldrValue);

    // Set the LED brightness based on the mapped intensity
    analogWrite(ledpin, ledIntensity);

    // Print the LED intensity to the Serial Monitor for debugging
    Serial.print("LED Intensity: ");
    Serial.println(ledIntensity);

    // delay
    delay(600);
}