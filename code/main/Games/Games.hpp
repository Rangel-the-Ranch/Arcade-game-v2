#pragma once
#include "gameLib/testGame.hpp"
#include "gameLib/Sonic.hpp"
#include "gameLib/Pong.hpp"
//#include "gameLib/Snake.hpp"

#include"../Arcade/LedMatrix/Cell.hpp"
#define Arcade Arcade
class Games{
    public:
        static void play(const String& name);
};  

static void Games::play(const String& name){
    if(name == "testGame"){
        testGame p;
    }else if(name == "snake"){
        //Snake p;                    ///todo
    }else if(name == "sonic"){
        Sonic p;
    }
    else if(name == "pong"){
        //Pong p;
    }
}
#undef Arcade
