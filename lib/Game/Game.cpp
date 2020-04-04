#include <Arduino.h>
#include "Game.hpp"
#include "Matrix.hpp"  

Game::Game()
{

}

Game::~Game()
{

}

void Game::Initialize(Matrix* matrix)
{
  this->matrix = matrix;
  Serial.println("GAME IS INITIALIZING");
}