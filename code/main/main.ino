#include <Adafruit_NeoPixel.h>
#include "LedMatrix/Monitor.hpp"
#include "Inputs/Inputs.hpp"

#include "pinLayout.h"

Monitor Screen;
//Cell test[32][32];
Inputs testIn;
int buttonPins[2] = {BUTTON_1_PIN , BUTTON_2_PIN};



void setup() { 
  Serial.begin(9600); 

  Screen.setPin(0,0,TOP_LEFT_PIN);
  Screen.setPin(0,1,TOP_RIGHT_PIN);
  Screen.setPin(1,0,BOT_LEFT_PIN);
  Screen.setPin(1,1,BOT_RIGHT_PIN);
  //Screen.applyMatrix(test);

  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(7, HIGH);
  digitalWrite(9, HIGH); 

  testIn.setButtonPin(buttonPins);  
  testIn.setJoystickPin(2,A0,A1,0);
}

void loop() {
  Serial.println(testIn.getJoystickX(0));
}
