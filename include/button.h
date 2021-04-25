#include <Arduino.h>

#ifndef BUTTON_H
#define BUTTON_H

class Button{
    private:
    int m_displayButton;
    static unsigned long m_timePressed;
    
    static int m_numberofPinstoRead;
    public:
    Button(int dispButton);
    static void toggleDisplay();
    static int m_pinBeingRead;
};


#endif