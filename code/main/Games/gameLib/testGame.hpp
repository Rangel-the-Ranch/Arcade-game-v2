#pragma once

class testGame{
    public:
        testGame();
    private:
        const int upLimit = 700;
        const int downLimit = 300;
        const int max = 31;
        int vectorX = 0;
        int vectorY = 0;
        int logoX = 15;
        int logoY = 15;
        String color = "white";
        Cell mat[Arcade::MATRIX_SIZE_X][Arcade::MATRIX_SIZE_Y];

        
        void updateJoystick();
        void updateColor();
        void updateLogo();
        void action();
};
void testGame::updateColor(){
    bool button1 = Arcade.button(0);
    bool button2 = Arcade.button(1);
    bool button3 = Arcade.button(2);
    if(button1 && button2 && button3){
        color = "white";
    }else if(button1){
        color = "green";
    }else if(button2){
        color = "blue";
    }else if(button3){
        color = "red";
    }
}
void testGame::updateJoystick(){
    
    if(Arcade.joystickX(0) > upLimit){
        vectorX = 1;
    }else if(Arcade.joystickX(0) < downLimit){
        vectorX = -1;
    }else{
        vectorX = 0;
    }
    if(Arcade.joystickY(0) > upLimit){
        vectorY = -1;
    }else if(Arcade.joystickY(0) < downLimit){
        vectorY = 1;
    }else{
        vectorY = 0;
    }
    
}
void testGame::updateLogo(){
    logoX += vectorX;
  logoY += vectorY;
  if(logoX >= max){
    logoX = max-1;
  }else if(logoX < 0){
    logoX = 0;
  }
  if(logoY >= max){
    logoY = max-1;
  }else if(logoY < 0){
    logoY = 0;
  }
}
void testGame::action(){
    mat[logoX][logoY].clear();
    mat[logoX][logoY+1].clear();
    mat[logoX+1][logoY].clear();
    mat[logoX+1][logoY+1].clear();

    updateJoystick();
    updateColor();
    updateLogo();
    
    mat[logoX][logoY].set(color);
    mat[logoX][logoY+1].set(color);
    mat[logoX+1][logoY].set(color);
    mat[logoX+1][logoY+1].set(color);
 
    Arcade.show(mat);
    delay(50);
    action();
    
}
testGame::testGame(){
    action();
}
