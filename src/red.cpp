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
RED::RED (int rs, int en, int d4, int d5, int d6, int d7, int pinsToRead, int dispButton, int backLight, int* pins8): lcd(rs, en, d4, d5, d6, d7), m_button(pinsToRead, dispButton) {
  m_list = pins8; //Assign the user's list of pins to a member variable
  m_backLight = backLight;
  pinMode(m_backLight, OUTPUT);
}


//Display the pin and the pin value on the lcd based on what index the button is on
void RED::displayList(){
  digitalWrite(m_backLight, HIGH);
  lcd.clear();
  lcd.print("Pin A1:");
  lcd.setCursor(0,1);
  lcd.print(m_list[m_button.m_pinBeingRead]);
  delay(1000);//will want to remove this later and replace with a timer interupt
}