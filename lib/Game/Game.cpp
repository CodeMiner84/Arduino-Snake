#include <Arduino.h>
#include "Game.hpp"
#include "Matrix.hpp"
#include <LedControl.h>

Game::Game() {}
Game::~Game() {}

void Game::Initialize(LedControl* lc)
{
  joystick = new Joystick();
  matrix = new Matrix(joystick, lc);
  Serial.println("GAME IS INITIALIZING");
}

void Game::Display()
{
  if (IsGameOver()) {
    return ;
  }

  if (IsStarted()) {
    matrix->MoveSnake();
    if (matrix->hasEatOwnBody()) {
      GameOver();
      matrix->YouLooseScreen();
    }
  } else {
    StartGameOnFirstMove();
    matrix->PlaceSnake();
  }
}

void Game::StartGameOnFirstMove()
{
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

bool Game::IsGameOver()
{
  return gameOver;
}

void Game::GameOver()
{
  gameOver = true;
}