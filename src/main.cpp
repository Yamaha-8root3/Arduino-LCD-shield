#include <Arduino.h>
#include <LiquidCrystal.h>

// LCD pin define
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  //(rs, en, d4, d5, d6, d7)

void setup() {
  pinMode(A0, INPUT);

  // boot message
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("hello, world!");
}

void loop() {
  int buttonValue = analogRead(A0);

  // read buttons analog value
  if (buttonValue >= 700 && buttonValue < 1000) {
    lcd.clear();
    lcd.print("SELECT");
    lcd.blink();  // blink 2

    delay(30);
  } else if (buttonValue >= 500 && buttonValue < 700) {
    lcd.clear();
    lcd.print("LEFT");
    delay(30);
  } else if (buttonValue >= 300 && buttonValue < 500) {
    lcd.clear();
    lcd.print("DOWN");
    delay(30);
  } else if (buttonValue >= 50 && buttonValue < 300) {
    lcd.clear();
    lcd.print("UP");
    delay(30);
  } else if (buttonValue < 50) {
    lcd.clear();
    lcd.print("RIGHT");
    delay(30);
  }
}