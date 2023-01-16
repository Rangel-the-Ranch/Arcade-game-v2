#pragma once

#include"Button.hpp"

class Inputs{
    private:
        static const unsigned int BUTTON_COUNT = 2;
    public:

        void setButtonPin(int newPin, int id);
        void setButtonPin(int newPins[BUTTON_COUNT]);
        bool getButton(int id)const;

    private:
        Button m_ButtonArr[BUTTON_COUNT];
};


void Inputs::setButtonPin(int newPin, int id){
    if(id >= BUTTON_COUNT){
        return;
    }
    m_ButtonArr[id].setPin(newPin);
}

void Inputs::setButtonPin(int newPins[BUTTON_COUNT]){
    for(int i=0; i<BUTTON_COUNT; i++){
        m_ButtonArr[i].setPin(newPins[i]);
    }
}
bool Inputs::getButton(int id)const{
    if(id >= BUTTON_COUNT){
        return false;
    }
    return m_ButtonArr[id].get();
}

