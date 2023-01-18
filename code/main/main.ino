#include <Adafruit_NeoPixel.h>
#include "Arcade/Arcade.hpp"
#include"Games/Games.hpp"

void setup() { 
  Arcade.clear();
  Serial.begin(9600);
  Games::play("testGame");
  //pinMode(9,OUTPUT);
  //pinMode(10,OUTPUT);
}

void loop() {
  //tone(10,700);
}
