#include <LiquidCrystal.h>

#define LCD_RS_PIN A5
#define LCD_E_PIN A4
#define LCD_04_PIN 6 
#define LCD_05_PIN 7
#define LCD_06_PIN 8
#define LCD_07_PIN 9

LiquidCrystal lcd(LCD_RS_PIN, LCD_E_PIN, LCD_04_PIN,
                  LCD_05_PIN, LCD_06_PIN,  LCD_07_PIN);




void setup() {
  lcd.begin(16,2);
  delay(100);

  lcd.setCursor(0,0); //like this u can mess with the 
  // layouts, use delays and u can use lcd.clear();
  lcd.print("hello world");
  
}

void loop() {
 
}
