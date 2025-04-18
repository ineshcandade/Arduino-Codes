#define LED_1_PIN 12
#define LED_2_PIN 11

unsigned long previousTimeLED1Blink = millis();
unsigned long timeIntervalLED1Blink = 470;

unsigned long previousTimeLED2Blink = millis();
unsigned long timeIntervalLED2Blink = 1300;


int LED1State = LOW;
int LED2State = LOW;

void setup() {
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);

 
}

void loop() {
  unsigned long timeNow = millis();
  if (timeNow - previousTimeLED1Blink > timeIntervalLED1Blink) {
    if (LED1State == LOW) {
      LED1State = HIGH; 
    }
    else {
      LED1State = LOW;
    }
    digitalWrite(LED_1_PIN, LED1State);
    previousTimeLED1Blink += timeIntervalLED1Blink;
  }
  if (timeNow - previousTimeLED2Blink > timeIntervalLED2Blink) {
    if (LED2State == LOW) {
      LED2State = HIGH; 
    }
    else {
      LED2State = LOW;
    }
    digitalWrite(LED_2_PIN, LED2State);
    previousTimeLED2Blink += timeIntervalLED2Blink;
  }

   

  
}
