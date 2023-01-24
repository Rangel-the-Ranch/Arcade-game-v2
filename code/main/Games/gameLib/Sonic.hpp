#pragma once

class Sonic{
    public:
        Sonic();
    private:
        Cell screen[32][32];
        char map[16][16];
        int myX=0,myY=0;
        int vX=0, vY=0;
        bool isOut = false;

        int enemyX=4, enemyY=8;
        int enemyVx = 1, enemyVy = 1; 

        void generateTerain();
        void print(); 
        void gameOver();

        void getDirection();
        void playerMove();
        void fillUp();
        void fillRec(int x, int y);
        void loop();
        void enemyMove();
};

Sonic::Sonic(){
    generateTerain();
    print();
    loop();
}
void Sonic::loop(){
    getDirection();
    playerMove();
    enemyMove();
    print();
    loop();

}
void Sonic::playerMove(){
    if(myX + vX >= 16 || myX + vX < 0){
        vX = 0;
    }
    if(myY + vY >= 16 || myY + vY < 0){
        vY = 0;
    }
    
    if(map[myX + vX][myY + vY] == '#'){
        if(isOut){
            fillUp();
        }
        isOut = false;
    }else if(map[myX + vX][myY + vY] == '.'){
        isOut = true;
    }
    myX += vX;
    myY += vY;
    if(isOut){
        map[myX][myY] = 'o';
    }
}
void Sonic::fillUp(){
    for(int x=0; x<16;x++){
        for(int y=0; y<16;y++){
            if(map[x][y] == 'o'){
                map[x][y] = '#';
            }
        }
    }
    fillRec(enemyX,enemyY);
    for(int x=0; x<16; x++){
        for(int y=0; y<16; y++){
            if(map[x][y] == '.'){
                map[x][y] = '#';
            }else if(map[x][y] == 't'){
                map[x][y] = '.';
            }
        }
    }
}
void Sonic::fillRec(int x, int y){
    if(map[x][y] == '.'){
        map[x][y] = 't';
        if( x+1 == 16 || map[x+1][y] == '.'){
            fillRec(x+1,y);
        }
        if( x-1 == 1 || map[x-1][y] == '.'){
            fillRec(x-1,y);
        }
        if( y+1 == 16 || map[x][y+1] == '.'){
            fillRec(x,y+1);
        }
        if( y-1 == -1 || map[x][y-1] == '.'){
            fillRec(x,y-1);
        }
    }
}

void Sonic::print(){
    for(int x=0; x<16; x++){
        for(int y=0; y<16; y++){
            String color;
            switch (map[x][y]){
            case '#':
                color = "blue";
                break;
            case '.':
                color = "black";
                break;
            case 'o':
                color = "cyan";
                break;
            case 'x':
                color = "red";
                break;
            }
            screen[2*x][2*y].set(color);
            screen[2*x][2*y+1].set(color);
            screen[2*x+1][2*y].set(color);
            screen[2*x+1][2*y+1].set(color);
        }
    }
    screen[2*myX][2*myY].set("green");
    screen[2*myX][2*myY+1].set("green");
    screen[2*myX+1][2*myY].set("green");
    screen[2*myX+1][2*myY+1].set("green");

    screen[2*enemyX][2*enemyY].set("red");
    screen[2*enemyX][2*enemyY+1].set("red");
    screen[2*enemyX+1][2*enemyY].set("red");
    screen[2*enemyX+1][2*enemyY+1].set("red");
    Arcade.show(screen);
}
void Sonic::generateTerain(){
    for(int x=0; x<16; x++){
        for(int y=0; y<16; y++){
            map[x][y] = '.';
        }
    }
    for(int x=0; x<16; x++){
        map[x][0] = '#';
        map[x][15] = '#';
        map[0][x] = '#';
        map[15][x] = '#';
    }
}
void Sonic::getDirection(){
    vX = 0;
    vY = 0;
    if( Arcade.joystickX(0) > 700 ){
        vX = 1;
    }else if( Arcade.joystickX(0) < 300 ){
        vX = -1;
    }else if( Arcade.joystickY(0) > 700 ){
        vY = -1;
    }else if( Arcade.joystickY(0) < 300 ){
        vY = 1;
    }
}
void Sonic::enemyMove(){
    if(map[enemyX + enemyVx][enemyY] == '#'){
        enemyVx *= -1;
    }
    if(map[enemyX][enemyY + enemyVy] == '#'){
        enemyVy *= -1;
    }
    Serial.println(enemyX);
    enemyX += enemyVx;
    enemyY += enemyVy;
    if(map[enemyX][enemyY] == 'o'){
        gameOver();
    }
}
void Sonic::gameOver(){
    for(int x=0; x<16; x++){
        for(int y=0; y< 16; y++){
            map[x][y] = 'x';
        }
    }
    print();
    while(true){};
}