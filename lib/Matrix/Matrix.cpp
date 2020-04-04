#include <Arduino.h>
#include "Matrix.hpp"  

Matrix::Matrix()
{
}

Matrix::~Matrix()
{
}

void Matrix::changeCoordinates(int x, int y)
{
  this->x = x;
  this->y =y;
}

int Matrix::getX()
{
  return x;
}

int Matrix::getY()
{
  return y;
}

void Matrix::print()
{
  Serial.print("Matrix coordinates: [");
  Serial.print(x);
  Serial.print("][");
  Serial.print(y);
  Serial.println("]");
}