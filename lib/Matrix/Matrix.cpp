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
  Snake[0] = Point { x, y };
  Snake[1] = Point { 3, 3 };
  Snake[2] = Point { 4, 3 };
  SnakeSize = 3;
  GenerateFood();

  this->joystick = joystick;
}


Matrix::~Matrix()
{
}


void Matrix::GenerateFood()
{
  bool created = false;
  do {
    int foodX = random(0, 8);
    int foodY = random(0, 8);

    int sameCoords = false;
    for (int i = 0; i < SnakeSize; i++) {
      if (foodX == Snake[i].x and foodY == Snake[i].y) {
        sameCoords = sameCoords;
      }
    }

    if (!sameCoords) {
      created = false;

      Food = Point { foodX, foodY };
    }

  } while (created);
}

void Matrix::ChangeHeadCoordinates(int x, int y)
{
  this->x = x;
  this->y = y;
}

void Matrix::MoveSnake()
{
  joystick->ReadAnalog();

  if (currentDirection != directions::down and joystick->IsUp()) {
    currentDirection=directions::up;
  }
  if (currentDirection != directions::up and joystick->IsDown()) {
    currentDirection=directions::down;
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

  ChangeHeadCoordinates(x, y);

  DisplaySnake();
}

void Matrix::PlaceSnake()
{
  for (int i = 0; i < SnakeSize; i++)
	{
    lc->setLed(0,Snake[i].x ,Snake[i].y, true);
	}
  lc->setLed(0,Food.x ,Food.y, true);
}

void Matrix::DisplaySnake()
{
	for (int i = 0; i < SnakeSize; i++)
	{
    TmpSnake[i] = Snake[i];
	}

  for (int i = 0; i < SnakeSize; i++)
	{
    if ( i==0 ) {
      lc->setLed(0,x ,y, true); 
      Snake[i] = Point { x, y };
    } else {
      Snake[i] = Point { TmpSnake[i-1].x, TmpSnake[i-1].y };
      lc->setLed(0, TmpSnake[i-1].x, TmpSnake[i-1].y, true);
    }
	}
  lc->setLed(0, TmpSnake[SnakeSize-1].x , TmpSnake[SnakeSize-1].y, false);

  lc->setLed(0, Food.x, Food.y, true);

  if (Food.x == x and Food.y == y) {
    SnakeSize += 1;
    Snake[SnakeSize] = Point {TmpSnake[SnakeSize-2].x, TmpSnake[SnakeSize-2].y };
    GenerateFood();
  }
}

bool Matrix::hasEatOwnBody()
{
  for (int i = 1; i < SnakeSize; i++)
	{
    if (Snake[0].x == Snake[i].x and Snake[0].y == Snake[i].y) {
      Serial.print("YOU EAT OWN BODY");
      return true;
    }
	}

  return false;
}

void Matrix::YouLooseScreen()
{
  lc->clearDisplay(0);
  byte IMAGES[8] =
  {
    B00000000,
    B01100110,
    B01100110,
    B00000000,
    B00000000,
    B00111100,
    B01000010,
    B00000000
  };

  DisplayImage(IMAGES);

  delay(10000000);
}

void Matrix::DisplayImage(const byte* image) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      lc->setLed(0, i, j, bitRead(image[i], 7 - j));
    }
  }
}