#include <Arduino.h>
#include "Matrix.hpp"  

Matrix::Matrix()
{
}

Matrix::~Matrix()
{
}

void Matrix::setX(int x)
{
  this->x = x;
}

void Matrix::setY(int y)
{
  this->y = y;
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