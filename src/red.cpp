//---------------------------------------------//
// Remote Display set up and functions
// Author: Karen Su & Drew Gautier
// Date: 4/28/2021
//---------------------------------------------//
// This file contains the definitions for the RED
// class constructor and it's member functions.


#include <red.h>
#include <button.h>


//Constructor creates RED object with button and lcd subobjects
RED::RED (int rs, int en, int d4, int d5, int d6, int d7, int pinsToRead, int dispButton, int* pins8): lcd(rs, en, d4, d5, d6, d7), m_button(pinsToRead, dispButton) {
  m_list = pins8; //Assign the user's list of pins to a member variable
  m_numPins = pinsToRead;
  m_index = 0;
  m_displayButton = dispButton;
  attachInterrupt(digitalPinToInterrupt(m_displayButton), this->toggleDisplay, FALLING);
}

//Need to declare these variables here to make space in the memory for the interupt to work?
int RED::m_numPins;
int RED::m_index;

//Is called when the dispButton falls. Uses button object to figure out if the button has been pressed, then index over list.
void RED::toggleDisplay(){
  if (Button::buttonPressed()) {
    m_index++;
    if (m_index == m_numPins) m_index = 0;
  }
  Serial.println("button hit");
}

//Display the pin and the pin value on the lcd based on what index the button is on
void RED::displayList(){
   lcd.clear();
   lcd.print("Pin A1:");
   lcd.setCursor(0,1);
   lcd.print(m_list[m_index]);
   delay(1000);//will want to remove this later and replace with a timer interupt
}