#define DEBUG 0
#include <LedControl.h>
int DIN = 10;
int CS =  9;
int CLK = 8;

LedControl lc=LedControl(DIN,CLK,CS,0);
unsigned int delaytime = 1000;

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


void loop() {
  #ifdef DEBUG
  Serial.println("Debug testing");
  #endif

  display();
  delay(delaytime);
}
