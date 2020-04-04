#include <Arduino.h>
#include "Joystick.hpp"  

#define xAxis A2
#define yAxis A3

Joystick::Joystick() {}

Joystick::~Joystick() {}

Joystick* Joystick::ReadAnalog()
{
  x = analogRead(xAxis);
  y = analogRead(yAxis);

  return this;
}

void Joystick::Debug()
{
  Serial.print("Read Joysitck input");
  Serial.print("X: ");
  Serial.print(x);
  Serial.print("   Y:");
  Serial.println(y);
}