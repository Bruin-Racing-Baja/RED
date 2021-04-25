#include <Arduino.h>
#include <LiquidCrystal.h>

#ifndef RED_H
#define RED_H

class RED 
{
  private:
  int* m_list;
  int m_displayButton;
  static unsigned long m_timePressed;
  static int m_pinBeingRead;
  static int m_numberofPinstoRead;
  LiquidCrystal lcd;

  public:
  RED(int rs, int en, int d4, int d5, int d6, int d7, int dispButton, int* pins8);
  static void toggleDisplay();
  void displayList();
};

#endif