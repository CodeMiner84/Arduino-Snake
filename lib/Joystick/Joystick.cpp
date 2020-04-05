#pragma once
#include <Arduino.h>
#include "Joystick.hpp"  

#define xAxis A2
#define yAxis A3
int JOYSTICK_MIN_VALUE = 100;
int JOYSTICK_MAX_VALUE = 900;

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
  return y >= JOYSTICK_MAX_VALUE;
}

bool Joystick::IsDown()
{
  return y <= JOYSTICK_MIN_VALUE;
}

bool Joystick::IsLeft()
{
  return x <= JOYSTICK_MIN_VALUE;
}

bool Joystick::IsRight()
{
  return x >= JOYSTICK_MAX_VALUE;
}

bool Joystick::WaitForFirstAction()
{
  int startingX = analogRead(xAxis);
  int startingY = analogRead(yAxis);

  if (
    startingX <= JOYSTICK_MIN_VALUE or
    startingX >= JOYSTICK_MAX_VALUE or
    startingY <= JOYSTICK_MIN_VALUE or
    startingY >= JOYSTICK_MAX_VALUE
  ) {
    return true;
  }

  return false;
}