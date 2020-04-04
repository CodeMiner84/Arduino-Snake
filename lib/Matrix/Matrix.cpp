#pragma once
#include <Arduino.h>
#include <LedControl.h>
#include "Matrix.hpp"
#include <Joystick.cpp>
#include "Point.hpp"

Matrix::Matrix(Joystick* joystick, LedControl* lc)
{
  this->lc = lc;
  randomSeed(analogRead(0));

  x = 2, y = 3;
  Snake[0] = Point { 2, 3 };
  Snake[1] = Point { 3, 3 };
  Snake[2] = Point { 4, 3 };
  SnakeSize = 3;

  this->joystick = joystick;

  Serial.print("SNAKE COORDS: ");
	for(int i=0;i<SnakeSize;i++)
	{
    Serial.print("[");
    Serial.print(Snake[i].x);
    Serial.print("][");
    Serial.print(Snake[i].y);
    Serial.print("]");
	}

  Serial.println("");
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
  // Serial.print("Matrix coordinates: [");
  // Serial.print(x);
  // Serial.print("][");
  // Serial.print(y);
  // Serial.println("]");
}


void Matrix::MoveSnake()
{
  joystick->ReadAnalog();

  if (currentDirection != directions::up and joystick->IsDown()) {
    currentDirection=directions::down;
  }
  if (currentDirection != directions::down and joystick->IsUp()) {
    currentDirection=directions::up;
  }
  if (currentDirection != directions::right and joystick->IsLeft()) {
    currentDirection=directions::left;
  }
  if (currentDirection != directions::left and joystick->IsRight()) {
    currentDirection=directions::right;
  }

  if (currentDirection==directions::down) {
    x -= 1;
  }
  if (currentDirection==directions::up) {
    x += 1;
  }
  if (currentDirection==directions::left) {
    y -= 1;
  }
  if (currentDirection==directions::right) {
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

  // Serial.print("Direction of game: ");
  // Serial.println(currentDirection);
}

void Matrix::PlaceSnake()
{
  for(int i=0;i<SnakeSize;i++)
	{
    lc->setLed(0,Snake[i].x ,Snake[i].y, true);
	}
}

void Matrix::DisplaySnake()
{
  lc->clearDisplay(0);

	for(int i=0; i<SnakeSize; i++)
	{
    TmpSnake[i] = Snake[i];
	}

	for(int i=0;i<SnakeSize;i++)
	{
    Serial.print("[");
    Serial.print(TmpSnake[i].x);
    Serial.print("][");
    Serial.print(TmpSnake[i].y);
    Serial.print("]   ");
	}
  for(int i=0; i<SnakeSize; i++)
	{
    if ( i==0 ) {
      lc->setLed(0,x ,y, true);

      Snake[i] = Point { x, y };
    } else {
      Snake[i] = Point { TmpSnake[i-1].x, TmpSnake[i-1].y };
      lc->setLed(0,TmpSnake[i-1].x ,TmpSnake[i-1].y, true);
    }
	}


  Serial.println("...");

  // for(int row=0;row<SIZE;row++) {
  //   for(int col=0;col<SIZE;col++) {
  //     if (row == GetX() and col == GetY()) {
  //       lc->setLed(0,row,col,true);
  //     } else {
  //       lc->setLed(0,row,col,false);
  //     }
  //   }
  // }
}