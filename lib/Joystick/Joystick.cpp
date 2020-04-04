#include <Arduino.h>
#include "Joystick.hpp"  

Joystick::Joystick()
{
}

Joystick::~Joystick()
{
}

void Joystick::setX(int x)
{
  this->x = x;
}

void Joystick::setY(int y)
{
  this->y = y;
}

int Joystick::getX()
{
  return x;
}

int Joystick::getY()
{
  return y;
}

void Joystick::print()
{
  Serial.print("Joystick coordinates: [");
  Serial.print(x);
  Serial.print("][");
  Serial.print(y);
  Serial.println("]");
}