#include <Adafruit_NeoPixel.h>
#include "Arcade/Arcade.hpp"


Cell test[32][32];
Arcade All;

void setColor(Cell (&mat)[32][32],String word){
  for(int x =0; x<32; x++){
    for(int y=0; y<32;y++){
      test[x][y].set(word);
    }
  }
}
void setup() { 
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(7, HIGH);
  digitalWrite(9, HIGH);

  setColor(test,"blue");
  All.clear();
  
}


void loop() {

}
