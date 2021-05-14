//---------------------------------------------//
// Remote Display set up and functions
// Author: Karen Su & Drew Gautier
// Date: 4/28/2021
//---------------------------------------------//
// This file contains the declaration for the RED class,
// it's member variables, member functions, and it's
// button and lcd sub class.


#include <Arduino.h>
#include <LiquidCrystal.h>
#include <button.h>


#ifndef RED_H
#define RED_H


class RED 
{
  private:
  int* m_list;            //m_list contains all of the pins RED will read
  LiquidCrystal lcd;      //create an object that modifies the 16*2 LCD display
  Button m_button;        //create an object that cycles through an index when a button is pressed
  int m_backLight;
  int m_time_delay;

  public:
  RED(int rs, int en, int d4, int d5, int d6, int d7, int pinsToRead, int dispButton, int backLight, int* pins8);
  void displayList();
};


#endif