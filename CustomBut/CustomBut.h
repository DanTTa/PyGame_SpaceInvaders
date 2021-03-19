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
    CustomBut(uint8_t pin, unsigned long debounce_time, unsigned long long_press_time);
    void read();
    //Return states:
    //1 - long push (1 sec)
    //2 - less than 1 sec push
    int update();
  private:
    unsigned long _debounce_time;
    unsigned long _long_press_time;
    unsigned long debounce_interval, press_interval;
    uint8_t state;         //state machine for the check
    uint8_t flag;          //return 1 for short press, 2 for long press
    bool button_pressed;   //check to see if the button is pressed or not
    uint8_t _pin;
};

#endif
