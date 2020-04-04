#pragma once
#include <Arduino.h>
#include "Matrix.hpp"
#include <Joystick.cpp>

Matrix::Matrix()
{
  randomSeed(analogRead(0));

  x = random(0, 8);
  y = random(0, 8);

  this->joystick = new Joystick();
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
}

void Matrix::MoveSnake()
{
  joystick->ReadAnalog();

  if (joystick->IsDown()) {
    x -= 1;
  }
  if (joystick->IsUp()) {
    x += 1;
  }
  if (joystick->IsLeft()) {
    y -= 1;
  }
  if (joystick->IsRight()) {
    y += 1;
  }

  if (x < MIN) {
    x = MAX;
  }
  if (x > MAX) {
    x = MIN;
  }
  if (y < MIN) {
    y = MAX;
  }
  if (y > MAX) {
    y = MIN;
  }

  ChangeCoordinates(x, y);
}
