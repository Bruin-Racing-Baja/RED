//---------------------------------------------//
// RED                                         //
// Author: Karen Su and Drew Gautier           //
// Last Updated: 4/28/2021                     //
// Description: Remote pin display             //
//---------------------------------------------//

#include <Arduino.h>
#include <red.h>

#define BACKLIGHT 10
#define BUTTON 2
int listOfPins[8] = {1, 2, 3, 4, 5, 6, 7, 8};
RED red(12, 11, 5, 4, 3, 7, 8, BUTTON, BACKLIGHT, listOfPins);


void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT);
}


void loop() {
  red.displayList();
}