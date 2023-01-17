#include <Adafruit_NeoPixel.h>
//#include "LedMatrix/Monitor.hpp"
//#include "Inputs/Inputs.hpp"
#include "Arcade.hpp"


Cell test[32][32];
Arcade All;


void setup() { 
  Serial.begin(9600); 


  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(7, HIGH);
  digitalWrite(9, HIGH);

  test[16][17].set("red");
  All.show(test);
  //All.clear();
}


void loop() {
  

  
}
