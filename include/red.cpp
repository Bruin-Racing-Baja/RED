#include <Arduino.h>
#include <LiquidCrystal.h>
class RED 
{
    public:
    String name; 
    int age;
    String occupation;

    void printdata() {

    };

};

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int pot = A0;

//write ur function that'll display the list 


int list[] = {0,1,2,3,4,5,6,7};
//button function 
int displayButton = 2;
int timePressed = 0;
int pinBeingRead = 0;
int numberofPinstoRead = 8;
void toggleDisplay() {
    if (millis() - timePressed > 1000) {
        pinBeingRead = pinBeingRead + 1;
        if (pinBeingRead == numberofPinstoRead) {
            pinBeingRead = 0;
        }
        Serial.println(pinBeingRead);
    }
    timePressed = millis();
}

void displayList(){

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
//(save the public variables to private vairables)\


//initialize input pins
//do you need to initialize output pins?

//what does input handling do?

//button function: interupt when button pin updated. Also deal with button debouncing.

//get button index and output corresponding pin name and data
//display function: take in pin name and data update the display
