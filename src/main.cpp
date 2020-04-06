#pragma once
#include <Arduino.h>
#include <LedControl.h>
#include <Game.cpp>

int DIN = A12;
int CS =  A11;
int CLK = A10;

LedControl lc=LedControl(DIN,CLK,CS,0);
unsigned int delaytime = 100;
Game game;

void setup() {
  Serial.begin(9600);

  lc.shutdown(0,false);       
  lc.setIntensity(0, 15);
  lc.clearDisplay(0);

  game.Initialize(&lc);
}


void loop() {
  game.Display();
  delay(delaytime);
}
