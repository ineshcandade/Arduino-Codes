
#define LED_1_pin  12
#define LED_2_pin  11

unsigned long previousTimeLED1Blink = millis();
unsigned long timeintervalLED1Blink = 470;

unsigned long previousTimeLED2Blink = millis();
unsigned long timeintervalLED2Blink = 1300;

int LED1State = LOW;
int LED2State = LOW;

void setup() {
  pinMode(LED_1_pin , OUTPUT);
  pinMode(LED_2_pin , OUTPUT);

}

void loop() {
  unsigned long timeNow = millis();
  if (timeNow - previousTimeLED1Blink > timeintervalLED1Blink) {
    if (LED1State == LOW) {
    LED1State == HIGH;
   }
   else {
    LED1State = LOW;
   }
   digitalWrite(LED_1_pin, LED1State);
   previousTimeLED1Blink += timeintervalLED1Blink;

  }
   if (timeNow - previousTimeLED2Blink > timeintervalLED2Blink) {
    if (LED2State == LOW) {
    LED2State == HIGH;
   }
   else {
    LED2State = LOW;
    }
    digitalWrite(LED_2_pin, LED2State);
   previousTimeLED2Blink += timeintervalLED2Blink;
   }
}

