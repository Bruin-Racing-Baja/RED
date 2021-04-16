#include <Arduino.h>
#include <LiquidCrystal.h>
class RED 
{
  private:
  int list[8] = {0,1,2,3,4,5,6,7};
  int displayButton;
  int timePressed = 0;
  int pinBeingRead = 0;
  int numberofPinstoRead = 8;

  public:
  RED(int, int, int, int, int, int, int);
  void addPin(int);
  void toggleDisplay();
  void displayList();
};

RED::RED (int rs, int en, int d4, int d5, int d6, int d7, int dispButton) {
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  displayButton = dispButton;
};

//const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 7;

void RED::toggleDisplay() {
    if (millis() - timePressed > 1000) {
        pinBeingRead = pinBeingRead + 1;
        if (pinBeingRead == numberofPinstoRead) {
            pinBeingRead = 0;
        }
        Serial.println(pinBeingRead);
    }
    timePressed = millis();
}

// void RED::displayList(){
//   lcd.clear();
//   lcd.print("Pin A1:");
//   lcd.setCursor(0,1);
//   lcd.print(list[pinBeingRead]);
//   delay(1000);

//takes in number from the list and display that number to the display 

//define a class red that deals with all things to do with displaying pin data.

//initialize RED:
//pins for display
//pin for button
//pins for what we want to read (all the sensors), the string to relate pin to reading

//save pin values
//(save the public variables to private vairables)\


//initialize input pins
//do you need to initialize output pins?

//what does input handling do?

//button function: interupt when button pin updated. Also deal with button debouncing.

//get button index and output corresponding pin name and data
//display function: take in pin name and data update the display

void help() {

}