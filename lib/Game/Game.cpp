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
  if (IsStarted()) {
    matrix->DisplaySnake(lc);
    matrix->MoveSnake();
  } else {
    StartGameOnFirstMove();
    matrix->PlaceSnake(lc);
  }
}

void Game::StartGameOnFirstMove() {
  if (joystick->WaitForFirstAction())
  {
    StartGame();
  }
}

void Game::StartGame()
{
  gameStarted = true;
}

bool Game::IsStarted()
{
  return gameStarted;
}