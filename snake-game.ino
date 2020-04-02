#define DEBUG 0
#include <LedControl.h>
int DIN = A12;
int CS =  A11;
int CLK = A10;

#define joyX A0
#define joyY A1

LedControl lc=LedControl(DIN,CLK,CS,0);
unsigned int delaytime = 100;
  
void setup() {
  #ifdef DEBUG
  Serial.begin(9600);
  #endif

 lc.shutdown(0,false);       
 lc.setIntensity(0,1);      //Adjust the brightness maximum is 15
 lc.clearDisplay(0);    
}

/**
 * Display dots function
 */
void display() {  
  delay(delaytime);
  for(int row=0;row<8;row++) {
    for(int col=0;col<8;col++) {
      delay(50);
      lc.setLed(0,row,col,true);
    }
  }
  
  for(int row=0;row<8;row++) {
    for(int col=0;col<8;col++) {
      delay(50);
      lc.setLed(0,row,col,false);
    }
  }
}

void logJoystick() {  
  int xValue = analogRead(A2);
  int yValue = analogRead(A3);
  

  //print the values with to plot or view
  Serial.print(xValue);
  Serial.print("\t");
  Serial.println(yValue);
}


void loop() {
  //display();
  logJoystick();
  delay(delaytime);
}
