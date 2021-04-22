#include <Arduino.h>
#include <LiquidCrystal.h>

#ifndef RED_H
#define RED_H
class RED 
{
  private:
  int* list;
  int displayButton;
  static unsigned long timePressed;
  static int pinBeingRead;
  static int numberofPinstoRead;
  LiquidCrystal lcd;

  public:
  RED(int rs, int en, int d4, int d5, int d6, int d7, int dispButton, int* pins8);
  void addPin(int);
  static void toggleDisplay();
  void displayList();
};

RED::RED (int rs, int en, int d4, int d5, int d6, int d7, int dispButton, int* pins8):lcd(rs, en, d4, d5, d6, d7) {
  displayButton = dispButton;
  attachInterrupt(digitalPinToInterrupt(displayButton), this->toggleDisplay, FALLING);
  list = pins8;
  timePressed = 0;
  pinBeingRead = 0;
  numberofPinstoRead = 8;
};

unsigned long RED::timePressed;
int RED::pinBeingRead;
int RED::numberofPinstoRead;

//const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 7;

void RED::toggleDisplay() {
    if (millis() - timePressed > 100) {
        pinBeingRead++;
        
        if (pinBeingRead == numberofPinstoRead) {
            pinBeingRead = 0;
        }
        Serial.print(pinBeingRead);
        Serial.print(" ");
        Serial.print(timePressed);
        Serial.print(" ");
        Serial.print(millis());
        Serial.print(" ");
        Serial.println(millis()-timePressed);
        timePressed = millis();
    }
}


//In constructor have int* pins

void RED::displayList(){
   lcd.clear();
   lcd.print("Pin A1:");
   lcd.setCursor(0,1);
   lcd.print(list[pinBeingRead]);
   delay(1000);
}

//takes in number from the list and display that number to the display 

//define a class red that deals with all things to do with displaying pin data.

//initialize RED:
//pins for display
//pin for button
//pins for what we want to read (all the sensors), the string to relate pin to reading

//save pin values
//(save the public variables to private vairables)


//initialize input pins
//do you need to initialize output pins?

//what does input handling do?

//button function: interupt when button pin updated. Also deal with button debouncing.

//get button index and output corresponding pin name and data
//display function: take in pin name and data update the display

#endif