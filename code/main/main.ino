#include <Adafruit_NeoPixel.h>
#include "Arcade/Arcade.hpp"

Arcade All;
Cell test[32][32];

int logoX=11, logoY=5;
int vX=1,vY=1;
const int max = 16;
String color[3] = {"red","green","blue"};
int counter = 0;
void updateLogo(){
  if(logoX== 0 || logoX== max-1){
    vX *= 0;
    counter++;
  }
  if(logoY== 0 || logoY == max-1){
    vY *= 0;
    counter++;
  }
  logoX += vX;
  logoY += vY;
}
void updateJoystick(){
  vX =0;
  vY = 0;
  if(All.joystickX(0) > 700){
    vX = 1;
  }
  if(All.joystickX(0) < 300){
    vX = -1;
  }
  if(All.joystickY(0) > 700){
    vY = -1;
  }
  if(All.joystickY(0) < 300){
    vY = 1;
  }
}
void setColor(const Cell (&matr)[32][32], String color){
  for(int x=0; x< 32; x++){
    for(int y=0; y<32; y++){
      matr[x][y].set(color);
    }
  }
}

void setup() { 
  Serial.begin(9600);
  //pinMode(7, OUTPUT);
  //pinMode(9, OUTPUT);
  //pinMode(11, OUTPUT);
  //digitalWrite(7, HIGH);
  //digitalWrite(9, HIGH);
  //digitalWrite(11, HIGH);

  All.clear();  
  
}

bool count;
void loop() {
  /*
  bool b1,b2,b3;
  b1 = All.button(0);
  b2 = All.button(1);
  b3 = All.button(2);
  if(b1 && b2 && b3){
    setColor(test,"white");
  }else if(b1){
    setColor(test,"green");
  }else if(b2){
    setColor(test,"blue");
  }else if(b3){
    setColor(test,"red");
  }else{
    setColor(test,"black");
  }
  All.show(test);
  */
  updateJoystick();
  test[2*logoX][2*logoY].clear();
  test[2*logoX][2*logoY+1].clear();
  test[2*logoX+1][2*logoY].clear();
  test[2*logoX+1][2*logoY+1].clear();
  updateLogo();
  test[2*logoX][2*logoY].set(color[counter%3]);
  test[2*logoX][2*logoY+1].set(color[counter%3]);
  test[2*logoX+1][2*logoY].set(color[counter%3]);
  test[2*logoX+1][2*logoY+1].set(color[counter%3]);
  All.show(test);
  Serial.println(All.joystickY(0));
  delay(50);
  
  
}
