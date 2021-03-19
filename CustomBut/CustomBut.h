/*  * * * * * * * * * * * * * * * * * * * * * * * * * * *
  CustomBut - Library for different types of button push.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef CustomBut_h
#define CustomBut_h

#include "Arduino.h"
#include <inttypes.h>

class CustomBut
{
  public:
    CustomBut(uint8_t pin);
    //Return states:
    //1 - long push (1 sec)
    //2 - less than 1 sec push
    int push();
    //debounce: tactile of the button
    void debounce();
  private:
    unsigned long debounce_time;
    unsigned long timer_millis;
    uint8_t pin;
};

#endif
