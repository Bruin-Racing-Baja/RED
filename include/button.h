//---------------------------------------------//
// Button indexer set up and functions
// Author: Karen Su & Drew Gautier
// Date: 4/28/2021
//---------------------------------------------//
// This file contains the declarations for the Button
// class constructor and it's member functions.


#include <Arduino.h>


#ifndef BUTTON_H
#define BUTTON_H


class Button{
    private:
    int m_displayButton;                    //The pin reading the button
    static unsigned long m_timePressed;     //The last time the button was pressed in milliseconds, hense why it's a long
    static int m_numberofPinstoRead;        //The number of indexes there will be

    public:
    Button(int pinsToRead, int dispButton);
    static void toggle();
    static int m_pinBeingRead;              //What index the button class is on 
    static bool buttonPressed();
    static unsigned long m_timeLastPressed;
};


#endif