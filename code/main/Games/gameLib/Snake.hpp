#pragma once
#include<vector>
class Snake{
    public:
        Snake();
    private:
        struct snakeSegment{
            char segX;
            char segY;
        }
        Cell matrix[32][32];
        std::vector<snakeSegment> allSnake;
        char terrain[16][16];
        int snakeX = 7, snakeY= 7;
        char direction;
        bool shoudEnd = false;
        
        int size = 1;

        void generateWalls();
        void getDirection();
        bool colisionCheck();
        void moveSnake();
        void gameOver();
        void convertTerainToMatrix();
        void loop();
};
void Snake::loop(){
    getDirection();
    moveSnake();
    convertTerainToMatrix();
    Arcade.show(matrix);

    if( !shoudEnd ){
        delay(100);
        loop();
    }
}

Snake::Snake(){
    generateWalls();
    loop();
}
void Snake::generateWalls(){
    for(int x = 0; x<16; x++){
        for(int y=0; y<16;y++){
            terrain[x][y] = '.';
        }
    }
    for(int x = 0; x< 16; x++){
        terrain[x][0] = '#';
        terrain[x][15] = '#';
        terrain[0][x] = '#';
        terrain[15][x] = '#';
    }
}
void Snake::convertTerainToMatrix(){
    for(int x=0; x<16; x++){
        for(int y=0; y<16; y++){
            String color;
            if(terrain[x][y] == '#'){
                color = "blue";
            }else if(terrain[x][y] == '.'){
                color = "black";
            }
            matrix[2*x][2*y].set(color);
            matrix[2*x][2*y+1].set(color);
            matrix[2*x+1][2*y].set(color);
            matrix[2*x+1][2*y+1].set(color);
        }
    }
    matrix[2*snakeX][2*snakeY].set("green");
    matrix[2*snakeX][2*snakeY+1].set("green");
    matrix[2*snakeX+1][2*snakeY].set("green");
    matrix[2*snakeX+1][2*snakeY+1].set("green");
}
void Snake::getDirection(){
    if( Arcade.joystickX(0) > 700 ){
        if(direction != 'F'){
            direction = 'B';
        }
    }else if( Arcade.joystickX(0) < 300 ){
        if(direction != 'B'){
            direction = 'F';
        }
    }else if( Arcade.joystickY(0) > 700 ){
        if(direction != 'R'){
            direction = 'L';
        }
    }else if( Arcade.joystickY(0) < 300 ){
        if(direction != 'L'){
            direction = 'R';
        }
    }
}
bool Snake::colisionCheck(){
    if(direction == 'F'){
        return terrain[snakeX-1][snakeY] != '.';
    }else if(direction == 'B'){
        return terrain[snakeX+1][snakeY] != '.';
    }else if(direction == 'L'){
        return terrain[snakeX][snakeY-1] != '.';
    }else if(direction == 'R'){
        return terrain[snakeX][snakeY+1] != '.';
    }
    return false;
}
void Snake::moveSnake(){
    if(colisionCheck()){
        gameOver();
        return;
    }

    if(direction == 'F'){
        snakeX--;
    }else if(direction == 'B'){
        snakeX++;
    }else if(direction == 'L'){
        snakeY--;
    }else if(direction == 'R'){
        snakeY++;
    }
    
}
void Snake::gameOver(){
    shoudEnd = true;
}
