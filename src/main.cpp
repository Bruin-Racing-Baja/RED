#include <Arduino.h>
#include <red.h>

#define BUTTON 2
int listOfPins[8] = {1, 2, 3, 4, 5, 6, 7, 8};
RED red(12, 11, 5, 4, 3, 7, BUTTON, listOfPins);

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT);
  //lcd.begin(16, 2);
  //lcd.print("Cheryl, Emma, and");
  //lcd.setCursor(0,1);
  //lcd.print("Jake are cool");
}

void loop() {
//RED.displayList();
}