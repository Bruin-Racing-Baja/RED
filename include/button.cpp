#include <Arduino.h>
int displayButton = 2;
int timePressed = 0;
int pinBeingRead = 0;
int numberofPinstoRead = 8;
void toggleDisplay() {
    if (millis() - timePressed > 750) {
        pinBeingRead = pinBeingRead + 1;
        if (pinBeingRead == numberofPinstoRead) {
            pinBeingRead = 0;
        }
        Serial.println(pinBeingRead);
    }
    timePressed = millis();
}