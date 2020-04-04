#include <Arduino.h>
#include "Game.hpp"
#include "Matrix.hpp"
#include <LedControl.h>

Game::Game()
{

}


Game::~Game()
{

}


void Game::Initialize()
{
  joystick = new Joystick();
  matrix = new Matrix(joystick);
  Serial.println("GAME IS INITIALIZING");
}


void Game::Display(LedControl lc) {
  matrix->DisplaySnake(lc);

  matrix->MoveSnake();
}