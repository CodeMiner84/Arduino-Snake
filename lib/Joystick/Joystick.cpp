#pragma once
#include <Arduino.h>
#include "Joystick.hpp"  

#define xAxis A3
#define yAxis A1
int JOYSTICK_MIN_TOLERANCE = 100;
int JOYSTICK_MAX_TOLERANCE = 900;

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
  return y >= JOYSTICK_MAX_TOLERANCE;
}

bool Joystick::IsDown()
{
  return y <= JOYSTICK_MIN_TOLERANCE;
}

bool Joystick::IsLeft()
{
  return x <= JOYSTICK_MIN_TOLERANCE;
}

bool Joystick::IsRight()
{
  return x >= JOYSTICK_MAX_TOLERANCE;
}

bool Joystick::WaitForFirstAction()
{
  int startingX = analogRead(xAxis);
  int startingY = analogRead(yAxis);

  if (
    startingX <= JOYSTICK_MIN_TOLERANCE or
    startingX >= JOYSTICK_MAX_TOLERANCE or
    startingY <= JOYSTICK_MIN_TOLERANCE or
    startingY >= JOYSTICK_MAX_TOLERANCE
  ) {
    return true;
  }

  return false;
}