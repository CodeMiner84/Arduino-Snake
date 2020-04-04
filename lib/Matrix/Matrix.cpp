#pragma once
#include <Arduino.h>
#include "Matrix.hpp"
#include <Joystick.cpp>

Matrix::Matrix()
{
  randomSeed(analogRead(0));
  
  x = random(0, 8);
  y = random(0, 8);
}

Matrix::~Matrix()
{
}

void Matrix::ChangeCoordinates(int x, int y)
{
  this->x = x;
  this->y = y;

  Print();
}

int Matrix::GetX()
{
  return x;
}

int Matrix::GetY()
{
  return y;
}

void Matrix::Print()
{
  Serial.print("Matrix coordinates: [");
  Serial.print(x);
  Serial.print("][");
  Serial.print(y);
  Serial.println("]");
}

void Matrix::AssignJoystick(Joystick* joystick)
{
  this->joystick = joystick;
}

void Matrix::LogMatrix()
{
  joystick->ReadAnalog();

  if (joystick->IsDown() and x > 0) {
    x -= 1;
  }
  if (joystick->IsUp() and x < 7) {
    x += 1;
  }
  if (joystick->IsLeft() and y > 0) {
    y -= 1;
  }
  if (joystick->IsRight() and y < 7) {
    y += 1;
  }

  ChangeCoordinates(x, y);
}