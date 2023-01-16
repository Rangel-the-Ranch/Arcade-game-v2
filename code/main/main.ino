#include <Adafruit_NeoPixel.h>
#include "LedMatrix/Monitor.hpp"

#define TOP_LEFT_PIN 5
#define TOP_RIGHT_PIN 4
#define BOT_LEFT_PIN 3
#define BOT_RIGHT_PIN 2

Monitor A;
Cell test[32][32];

void setup() {  
  A.setPin(0,0,TOP_LEFT_PIN);
  A.setPin(0,1,TOP_RIGHT_PIN);
  A.setPin(1,0,BOT_LEFT_PIN);
  A.setPin(1,1,BOT_RIGHT_PIN);
  
  //test[24][13].setMax();
  //test[20][7].set("red");
  //test[16][16].set("green");
  //test[31][31].set(7,0,12);
  
  A.applyMatrix(test);
}

void loop() {

}
