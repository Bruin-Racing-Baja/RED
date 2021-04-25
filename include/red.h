#include <Arduino.h>
#include <LiquidCrystal.h>
#include <button.h>

#ifndef RED_H
#define RED_H

class RED 
{
  private:
  int* m_list;
  LiquidCrystal lcd;
  Button m_button;

  public:
  RED(int rs, int en, int d4, int d5, int d6, int d7, int pinsToRead, int dispButton, int* pins8);
  void displayList();
};

#endif