#include <button.h>

Button::Button (int PinsToRead, int dispButton) {
    m_displayButton = dispButton;
    m_timePressed = 0;
    m_pinBeingRead = 0;
    m_numberofPinstoRead = PinsToRead;
    attachInterrupt(digitalPinToInterrupt(m_displayButton), this->toggleDisplay, FALLING);
}

unsigned long Button::m_timePressed;
int Button::m_pinBeingRead;
int Button::m_numberofPinstoRead;

void Button::toggleDisplay() {
    if (millis() - m_timePressed > 200) {
        m_pinBeingRead++;
        
        if (m_pinBeingRead == m_numberofPinstoRead) {
          m_pinBeingRead = 0;
        }
        Serial.print(m_pinBeingRead);
        Serial.print(" ");
        Serial.print(m_timePressed);
        Serial.print(" ");
        Serial.print(millis());
        Serial.print(" ");
        Serial.println(millis()-m_timePressed);
        m_timePressed = millis();
    }
}