#pragma once
#include <Arduino.h>
#include "Joystick.hpp"  

#define xAxis A2
#define yAxis A3
int JOYSTICK_MIN_VALUE = 0;
int JOYSTICK_MAX_VALUE = 1023;

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

bool Joystick::IsUp()
{
  return y == JOYSTICK_MAX_VALUE;
}

bool Joystick::IsDown()
{
  return y == JOYSTICK_MIN_VALUE;
}

bool Joystick::IsLeft()
{
  return x == JOYSTICK_MIN_VALUE;
}

bool Joystick::IsRight()
{
  return x == JOYSTICK_MAX_VALUE;
}