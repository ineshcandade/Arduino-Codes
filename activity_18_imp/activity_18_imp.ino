#include <IRremote.h>
#include <LiquidCrystal.h>

#define LCD_RS_PIN A5
#define LCD_E_PIN A4
#define LCD_D4_PIN 6
#define LCD_D5_PIN 7
#define LCD_D6_PIN 8
#define LCD_D7_PIN 9

#define LED_1_PIN 12
#define LED_2_PIN 11
#define LED_3_PIN 10

#define IR_RECEIVE_PIN 5

#define IR_BUTTON_0 22
#define IR_BUTTON_1 12
#define IR_BUTTON_2 24
#define IR_BUTTON_3 94
#define IR_BUTTON_FUNC_STOP 71

#define LED_ARRAY_SIZE 3

byte LEDArray[LED_ARRAY_SIZE] = 
      { LED_1_PIN, LED_2_PIN, LED_3_PIN };
byte LEDStateArray[LED_ARRAY_SIZE] = { LOW, LOW, LOW };

LiquidCrystal lcd(LCD_RS_PIN, LCD_E_PIN, LCD_D4_PIN,
                  LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

void initLEDModes()
{
  for (int i = 0; i < LED_ARRAY_SIZE; i++) {
    pinMode(LEDArray[i], OUTPUT);
  }
}

void powerOffAllLEDs()
{
  for (int i = 0; i < LED_ARRAY_SIZE; i++) {
    LEDStateArray[i] = LOW;
    digitalWrite(LEDArray[i], LOW);
  }
}

void toggleLEDFromIndex(int index)
{
  if (index >= LED_ARRAY_SIZE) {
    return;
  }
  if (LEDStateArray[index] == HIGH) {
    LEDStateArray[index] = LOW;
  }
  else {
    LEDStateArray[index] = HIGH;
  }
  digitalWrite(LEDArray[index], LEDStateArray[index]);
}

void printCommandOnLCD(int command)
{
  lcd.setCursor(0, 0);
  lcd.print(command);
  lcd.print("      ");  
}

void printActionOnLCD(String action)
{
  lcd.setCursor(0, 1);
  lcd.print(action);
}

void setup() {
  IrReceiver.begin(IR_RECEIVE_PIN);
  initLEDModes();
  lcd.begin(16, 2);
}

void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    int command = IrReceiver.decodedIRData.command;
    switch (command) {
      case IR_BUTTON_0: {
        powerOffAllLEDs();
        printCommandOnLCD(command);
        printActionOnLCD("Power off LEDs. ");
        break;
      }
      case IR_BUTTON_1: {
        toggleLEDFromIndex(0);
        printCommandOnLCD(command);
        printActionOnLCD("Toggle LED 1.   ");
        break;
      }
      case IR_BUTTON_2: {
        toggleLEDFromIndex(1);
        printCommandOnLCD(command);
        printActionOnLCD("Toggle LED 2.   ");
        break;
      }
      case IR_BUTTON_3: {
        toggleLEDFromIndex(2);
        printCommandOnLCD(command);
        printActionOnLCD("Toggle LED 3.   ");
        break;
      }
      case IR_BUTTON_FUNC_STOP: {
        lcd.clear();
        break;
      }
      default: {
        printCommandOnLCD(command);
        printActionOnLCD("Not recognized. ");
      }
    }
  }
}
