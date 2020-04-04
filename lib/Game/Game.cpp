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
  this->matrix = new Matrix();
  Serial.println("GAME IS INITIALIZING");
}


void Game::Display(LedControl lc) {
  for(int row=0;row<matrix->SIZE;row++) {
    for(int col=0;col<matrix->SIZE;col++) {
      if (row == matrix->GetX() and col == matrix->GetY()) {
        lc.setLed(0,row,col,true);
      } else {
        lc.setLed(0,row,col,false);
      }
    }
  }

  matrix->LogMatrix();
}