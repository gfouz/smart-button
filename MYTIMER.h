#ifndef MYTIMER_H
#define MYTIMER_H

#include<Chrono.h>
#include<SevSeg.h>
#include<avr/wdt.h>
#define POWER_PIN A5

//variables will change.



extern "C"
{
  typedef int (*callback_t)();

}


class Timers
{
  private:
    callback_t onButtonEvent;
    bool power = false;
  public:

    Timers() {};


    int timeout;



    void timeSelector(callback_t newFunction, bool & isButton, bool & isDisplay, bool & isBlank, bool & isReset ,int & countdownNumber, uint32_t & mycounter)
    {
      int push;
      static int counter = 0;
      onButtonEvent = newFunction;
      push = onButtonEvent();//This function returns an integer.
      if (push == 1 && counter == 0)
      {
        countdownNumber=100;
        isDisplay=true;
        counter++;
        timeout = 5000;
        power = true;
        

      }
      if (push == 2 && counter == 1)
      { 
        countdownNumber=300;
        mycounter = 0;
        counter++;
        timeout = 10000;
        power = true;
        

      }
      if (push == 3 && counter == 2)
      {
        countdownNumber= 400;
        mycounter=0;
        counter++;
        timeout = 10000;
        power = true;
        
        
      }
      if (push == 4 )
      {

        isReset = true;
        isButton = false;
        power = false;
        //digitalWrite(POWER_PIN, LOW);

      }
    }


void onPowerPin()
{

  
  
}

};

#endif
