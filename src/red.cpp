#include <red.h>


RED::RED (int rs, int en, int d4, int d5, int d6, int d7, int dispButton, int* pins8):lcd(rs, en, d4, d5, d6, d7) {
  m_displayButton = dispButton;
  attachInterrupt(digitalPinToInterrupt(m_displayButton), this->toggleDisplay, FALLING);
  m_list = pins8;
  m_timePressed = 0;
  m_pinBeingRead = 0;
  m_numberofPinstoRead = 8;
}

void RED::displayList(){
   lcd.clear();
   lcd.print("Pin A1:");
   lcd.setCursor(0,1);
   lcd.print(m_list[m_pinBeingRead]);
   delay(1000);
}

unsigned long RED::m_timePressed;
int RED::m_pinBeingRead;
int RED::m_numberofPinstoRead;

void RED::toggleDisplay() {
    if (millis() - m_timePressed > 100) {
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