#include <Arduino.h>
#include <red.cpp>

void setup() {
  Serial.begin(9600);
  pinMode(displayButton, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(displayButton), toggleDisplay, FALLING);
  pinMode(pot, INPUT);
  lcd.begin(16, 2);
  lcd.print("Cheryl, Emma, and");
  lcd.setCursor(0,1);
  lcd.print("Jake are cool");
}

void loop() {
displayList();
}