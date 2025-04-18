#define LED_pin1 12
#define LED_pin2 11
#define LED_pin3 10

#define BUTTON_pin 2

int LEDblinkState = 1;

void setup(){
 
  pinMode(LED_pin1, OUTPUT);
  pinMode(LED_pin3, OUTPUT);
  pinMode(LED_pin2, OUTPUT);
  
  pinMode(BUTTON_pin, INPUT_PULLUP);
}

void loop(){
  
  if (digitalRead(BUTTON_pin) == HIGH){
    if (LEDblinkState == 1){
      digitalWrite(LED_pin2, LOW);
      digitalWrite(LED_pin1, HIGH);
      digitalWrite(LED_pin3, HIGH);
      LEDblinkState = 2;
      
    }
    else{
  
      digitalWrite(LED_pin1, LOW);
      digitalWrite(LED_pin3, LOW);
      digitalWrite(LED_pin2, HIGH);
      LEDblinkState = 1;
    }
    delay(300);
  }
}

  
 

   


