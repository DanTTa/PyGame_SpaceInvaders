/*  * * * * * * * * * * * * * * * * * * * * * * * * * * *
  CustomBut - Library for different types of button push.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Arduino.h"
#include "CustomBut.h"

CustomBut::CustomBut(uint8_t pin, unsigned long debounce_time, unsigned long long_press_time)
{
  pinMode(pin, INPUT);
  _pin = pin;
  _debounce_time = debounce_time;               //in millis
  _long_press_time = long_press_time;           //long press is 1s
  flag = 0;
  state = 0;
}

void CustomBut::read()
{
  int button_state = digitalRead(_pin);  //HI not push, LO is push (inverting scheme)
  button_pressed = !button_state;        //check to see if the button is pressed or not
}

int CustomBut::update(){
  flag = 0;
  read();
  switch (state){
    case 0:                         //unpress state
      if (button_pressed){
        debounce_interval = millis();
        state = 1;
      }
      break;
    case 1:                         //make sure that the button is debounce correctly
      if (!button_pressed){
        state = 0;
      }
      else if (millis() - debounce_interval >= _debounce_time){
        press_interval = millis();
        state = 2;
      }
      break;
    case 2:
      if (!button_pressed){           //short press
        state = 4;
        debounce_interval = millis();
      }
      else if (millis() - press_interval >= _long_press_time) {
        state = 3;
      }
      break;
    case 3:                           //long press
      if (!button_pressed){
        state = 4;
        debounce_interval = millis();
      }
      break;
    case 4:           //the button press check here is to confirm your push
      if (button_pressed && (millis() - press_interval < _long_press_time)){
        state = 2;           //go back to short press state
        debounce_interval = millis();
      }
      else if (button_pressed && (millis() - press_interval >= _long_press_time)){
        state = 3;
        debounce_interval = millis();
      }
      else if (millis() - debounce_interval >= _debounce_time){   //final; steady state
        state = 0;
        if (millis() - press_interval < _long_press_time){
          flag = 1;           //indicate short press
        }
        else{
          flag = 2;           //indicate long press
        }
      }
      break;
  }

  return flag;
}
