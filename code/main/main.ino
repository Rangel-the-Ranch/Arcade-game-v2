#include <Adafruit_NeoPixel.h>
#include "LedMatrix/Monitor.hpp"
#include "Inputs/Inputs.hpp"

#include "pinLayout.h"

Monitor A;
Cell test[32][32];
Inputs testIn;
int buttonPins[2] = {BUTTON_1_PIN , BUTTON_2_PIN};

void setup() { 
  Serial.begin(9600); 

  A.setPin(0,0,TOP_LEFT_PIN);
  A.setPin(0,1,TOP_RIGHT_PIN);
  A.setPin(1,0,BOT_LEFT_PIN);
  A.setPin(1,1,BOT_RIGHT_PIN);
  //test[24][13].setMax();
  //test[20][7].set("red");
  //test[16][16].set("green");
  //test[31][31].set(7,0,12);
  A.applyMatrix(test);

  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(7, HIGH);
  digitalWrite(9, HIGH);

  testIn.setButtonPin(buttonPins);  
}

void loop() {
  Serial.println(testIn.getButton(1));
}
