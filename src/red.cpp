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
  m_time_delay = 10000; //change 10sec to a minute for real world application
}

//Display the pin and the pin value on the lcd based on what index the button is on
void RED::displayList(){
  if (millis()-m_button.m_timePressed >= m_time_delay ) { 
    digitalWrite(m_backLight, LOW); 
  } else {
    digitalWrite(m_backLight, HIGH);}

  if ((m_list[m_button.m_pinBeingRead] != 8)) {
  //digitalWrite(m_backLight, HIGH);
    lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print("Pin " );
    lcd.setCursor(3,0); 
    lcd.print(m_list[m_button.m_pinBeingRead]);
    lcd.setCursor(10,0); 
    lcd.print(analogRead(m_list[m_button.m_pinBeingRead]));
    //delay(1000);//will want to remove this later and replace with a timer interupt
  } else {
    digitalWrite(m_backLight, LOW); //get to pin8, eight click to turn backlight off
 }
 delay(500);
}