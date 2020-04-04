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
Matrix coordinates;
  
void setup() {
  #ifdef DEBUG
  Serial.begin(9600);
  #endif

  randomSeed(analogRead(0));

  randomRow = random(0, 8);
  randomCol = random(0, 8);

  coordinates.ChangeCoordinates(randomRow, randomCol);

  coordinates.Print();
  
 lc.shutdown(0,false);       
 lc.setIntensity(0,1);      //Adjust the brightness maximum is 15
 lc.clearDisplay(0);    
}

/**
 * Display dots function
 */
void display() {  
  for(int row=0;row<8;row++) {
    for(int col=0;col<8;col++) {
      if (row == coordinates.GetX() and col == coordinates.GetY()) {
        lc.setLed(0,row,col,true);
      } else {
        lc.setLed(0,row,col,false);
      }
    }
  }
}

void logMatrix() {
  joystick.ReadAnalog();
  int xValue = joystick.x;
  int yValue = joystick.y;


  if (yValue == 0 and randomRow > 0) {
    randomRow -= 1;
  }
  if (yValue == 1023 and randomRow < 7) {
    randomRow += 1;
  }


  if (xValue == 0 and randomCol > 0) {
    randomCol -= 1;
  }
  if (xValue == 1023 and randomCol < 7) {
    randomCol += 1;
  }

  coordinates.ChangeCoordinates(randomRow, randomCol);

  coordinates.Print();
}


void loop() {
  display();
  logMatrix();
  delay(delaytime);
}
