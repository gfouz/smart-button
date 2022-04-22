#ifndef VARIABLES_H
#define VARIABLES_H

//configuration for Button
#define BUTTON_PIN A0 // The pin that the Button is attached to.
#define LEDPIN 13
const unsigned long interval;//to Review.
int buttonState = 0;
int lastButtonState = 0;
int buttonPushCounter = -1;
bool isButton=true;

//Booleans and variables relating to SevSeg Library.
bool isBlank=false;
bool isDisplay=false;

//Configuration for reseting the Watchdog software.
bool isReset=false;

//variable for countDown counter.
 static int result=0;
 static int countdownNumber;
 static int minutes;
 static uint32_t mycounter = 0;
#endif
