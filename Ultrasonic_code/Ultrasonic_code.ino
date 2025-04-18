#define ECHO_PIN 3
#define TRIGGER_PIN 4

unsigned long lastTimeUltrasonicTrigger = millis();
unsigned long ultrasonicTriggerDelay = 100;

volatile unsigned long pulseInTimeBegin;
volatile unsigned long pulseInTimeEnd;
volatile bool newDistanceAvailable;

void triggerUltrasonicSensor() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
}

double getUltrasonicDistance() {
  double durationMicros = pulseInTimeEnd - pulseInTimeBegin;
  double distance = durationMicros / 58.0; // cm (148.0: inches)
  return distance;
  // return (double)
}

void echoPinInterrupt()
{
  if(digitalRead(ECHO_PIN) == HIGH) {
    pulseInTimeBegin = micros();

  }
  else{
    //falling
    pulseInTimeEnd = micros();
    newDistanceAvailable = true;
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(ECHO_PIN),
                   echoPinInterrupt,
                  CHANGE); 
}

void loop() {
  unsigned long timeNow = millis();
if (timeNow - lastTimeUltrasonicTrigger > ultrasonicTriggerDelay) {
  lastTimeUltrasonicTrigger += ultrasonicTriggerDelay;
  triggerUltrasonicSensor();
 
 }
 if(newDistanceAvailable){
  newDistanceAvailable = false;
  double distance = getUltrasonicDistance();
  Serial.println(distance);

 }
 
}
