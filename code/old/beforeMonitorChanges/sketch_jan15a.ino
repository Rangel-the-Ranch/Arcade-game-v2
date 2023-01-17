#include <Adafruit_NeoPixel.h>
#include "CellMatrix.hpp"
#include "Monitor.hpp"

#define PIN 4
#define TOP_LEFT_PIN 6
#define TOP_RIGHT_PIN 7
#define BOT_LEFT_PIN 5
#define BOT_RIGHT_PIN 4

CellMatrix botomRight(PIN);

//Monitor A;


Cell test[16][16];


void setup() {  
  Serial.begin(9600);
  /*
  A.setPin(0,0,TOP_LEFT_PIN);
  A.setPin(0,1,TOP_RIGHT_PIN);
  A.setPin(1,0,BOT_LEFT_PIN);
  A.setPin(1,1,BOT_RIGHT_PIN);
  */
  test[2][3].setMax();
  botomRight.getMatrix(test);

  botomRight.applyMatrix();
  
}
void loop() {

}
