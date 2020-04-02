#define DEBUG 0

unsigned int delaytime = 1000;

void setup() {
  #ifdef DEBUG
  Serial.begin(9600);
  #endif

}

void loop() {
  #ifdef DEBUG
  Serial.println("Debug testing");
  #endif

  delay(delaytime);

}
