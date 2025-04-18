int doubleNumber(int number)
{
  return number * 2;
 
}

void printDoubleNumber(int number)
{
 Serial.println(doubleNumber(number));
}

int number1 = 3;
int number2 = 5;

void setup() {
  Serial.begin(9600);
  int a = doubleNumber(number1);
  int b = doubleNumber(number2);

  printDoubleNumber(number1);
  printDoubleNumber(number2);

}

void loop() {
  

}
