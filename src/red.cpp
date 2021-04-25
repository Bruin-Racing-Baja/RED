#include <red.h>
#include <button.h>

RED::RED (int rs, int en, int d4, int d5, int d6, int d7, int pinsToRead, int dispButton, int* pins8): lcd(rs, en, d4, d5, d6, d7), m_button(pinsToRead, dispButton) {
  m_list = pins8;
}

void RED::displayList(){
   lcd.clear();
   lcd.print("Pin A1:");
   lcd.setCursor(0,1);
   lcd.print(m_list[m_button.m_pinBeingRead]);
   delay(1000);
}



