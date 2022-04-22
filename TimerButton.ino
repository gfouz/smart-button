#include"MYTIMER.h"
#include"VARIABLES.h"
#include<avr/wdt.h>
#include<Chrono.h>
SevSeg sevseg;
Chrono chrono;
Timers timers;


void setup() {
  //configuration belonging to Button.
  Serial.begin(9600);
  Serial.println("The program has started");
  pinMode(POWER_PIN, OUTPUT);


  //configuration according to SevSeg library.
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_ANODE; // See README.md for options
  bool updateWithDelays = false; // Default. Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros);
  sevseg.setBrightness(90);


}

void loop() {
  timers.timeSelector(buttonCounter, isButton, isDisplay, isBlank, isReset, countdownNumber,mycounter);
  countdownCounter();
  resetWatchDog();
 
}




int buttonCounter()
{
  if (isButton)
  {
    buttonState = digitalRead(BUTTON_PIN);
    if (buttonState != lastButtonState)
    {
      if (buttonState == HIGH)
      {
        buttonPushCounter++;
        Serial.println(buttonPushCounter);
      }
      else {
        Serial.println("OFF");

      }
      delay(200);
    }
    lastButtonState = buttonState;
    return buttonPushCounter;
  }
}






int countdownCounter()
{
  sevseg.refreshDisplay();
  
  static uint32_t lastTime = 0;
  uint32_t now = millis();
  result = countdownNumber - mycounter;
  if (isDisplay)
  {

    if (now - lastTime > 1000)
    {
      lastTime = now;

     mycounter++;


      if (result > -1)
      {
        sevseg.setNumber(result, 2);
        if (result == 0)
        {
          sevseg.setChars("OFF");
        }
      }
    }

  } else {
    mycounter = 0;
  }


}






void toBlank()
{
  if (isBlank)
  {
    sevseg.blank();
    isBlank = false;
  }

}

void resetWatchDog()
{
  if (isReset)
  {
    wdt_disable();
    wdt_enable(WDTO_1S);
    wdt_reset();
    isReset = false;
  }

}



