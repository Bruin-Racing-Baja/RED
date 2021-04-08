#include <Arduino.h>
#include <button.cpp>



void setup() {
  Serial.begin(9600);
  pinMode(displayButton, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(displayButton), toggleDisplay, FALLING);
}

void loop() {
  //Karen is stinky
}