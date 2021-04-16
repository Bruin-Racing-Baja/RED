#include <Arduino.h>
#include <red.cpp>

#define BUTTON 2
RED red(12, 11, 5, 4, 3, 7, BUTTON);

void ra() {
  red.toggleDisplay();
}


void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON), ra, FALLING);
  //lcd.begin(16, 2);
  //lcd.print("Cheryl, Emma, and");
  //lcd.setCursor(0,1);
  //lcd.print("Jake are cool");
}

void loop() {
//RED.displayList();
}