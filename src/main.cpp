#include <Arduino.h>
#define DEBUG 0
#include <LedControl.h>
#include <Matrix.cpp>
#include <Joystick.cpp>
#include <Game.cpp>

int DIN = A12;
int CS =  A11;
int CLK = A10;

LedControl lc=LedControl(DIN,CLK,CS,0);
unsigned int delaytime = 100;
int randomRow = 0;
int randomCol = 0;

Game game;
Joystick joystick;
Matrix matrix;
  
void setup() {
  #ifdef DEBUG
  Serial.begin(9600);
  #endif

  game.Initialize();
  
  lc.shutdown(0,false);       
  lc.setIntensity(0,0);//Adjust the brightness maximum is 15
  lc.clearDisplay(0);    
}


void loop() {
  game.Display(lc);
  delay(delaytime);
}
