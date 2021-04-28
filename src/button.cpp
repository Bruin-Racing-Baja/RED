//---------------------------------------------//
// Button indexer set up and functions
// Author: Karen Su & Drew Gautier
// Date: 4/28/2021
//---------------------------------------------//
// This file contains the declarations for the Button
// class constructor and it's member functions.


#include <button.h>


Button::Button (int PinsToRead, int dispButton) {
    m_displayButton = dispButton;
    m_timePressed = 0;
    m_pinBeingRead = 0;
    m_numberofPinstoRead = PinsToRead;

    //When button pin voltage falls the toggle display function is called
    attachInterrupt(digitalPinToInterrupt(m_displayButton), this->toggle, FALLING);
}


//Need to declare these variables here to make space in the memory for the interupt to work?
unsigned long Button::m_timePressed;
int Button::m_pinBeingRead;
int Button::m_numberofPinstoRead;


//When called debounce button then increment pinBeingRead member variable if neccesary
void Button::toggle() {
    if (millis() - m_timePressed > 200) {
        m_pinBeingRead++;
        
        if (m_pinBeingRead == m_numberofPinstoRead) {
          m_pinBeingRead = 0;
        }

        m_timePressed = millis();
    }
}