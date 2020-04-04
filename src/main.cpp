#include <Arduino.h>
#define DEBUG 0
#include <LedControl.h>
#include <Matrix.cpp>
#include <Joystick.cpp>

int DIN = A12;
int CS =  A11;
int CLK = A10;

LedControl lc=LedControl(DIN,CLK,CS,0);
unsigned int delaytime = 100;
int randomRow = 0;
int randomCol = 0;

Joystick joystick;
Matrix matrix;
  
void setup() {
  #ifdef DEBUG
  Serial.begin(9600);
  #endif

  matrix.AssignJoystick(&joystick);
  
  lc.shutdown(0,false);       
  lc.setIntensity(0,0);//Adjust the brightness maximum is 15
  lc.clearDisplay(0);    
}

void display() {  
  for(int row=0;row<8;row++) {
    for(int col=0;col<8;col++) {
      if (row == matrix.GetX() and col == matrix.GetY()) {
        lc.setLed(0,row,col,true);
      } else {
        lc.setLed(0,row,col,false);
      }
    }
  }
}


void loop() {
  display();
  matrix.LogMatrix();
  delay(delaytime);
}
