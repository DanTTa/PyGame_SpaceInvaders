/*  * * * * * * * * * * * * * * * * * * * * * * * * * * *
  CustomBut - Library for different types of button push.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Arduino.h"
#include "CustomBut.h"

CustomBut::CustomBut(int pin)
{
  pinMode(pin, INPUT);
  _pin = pin;
}

void CustomBut::debounce()
{
  digitalWrite(_pin, HIGH);
  delay(250);
  digitalWrite(_pin, LOW);
  delay(250);
}

void Morse::dash()
{
  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(250);
}
