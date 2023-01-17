#pragma once

#include"Button.hpp"
#include"Joystick.hpp"

class Inputs{
    private:
        static const unsigned int BUTTON_COUNT = 2;
        static const unsigned int JOYSTICK_COUNT = 1;
    public:

        void setButtonPin(int newPin, int id);
        void setButtonPin(const int (&newPins)[BUTTON_COUNT]);
        void setJoystickPin(int newPin, int newX, int newY, int id);

        int getButton(int id)const;
        int getJoystickX(int id)const;
        int getJoystickY(int id)const;
        int getJoystickD(int id)const;

    private:
        Button m_ButtonArr[BUTTON_COUNT];
        Joystick m_JoystickArr[JOYSTICK_COUNT];
};

int Inputs::getJoystickX(int id)const{
    if(id >= JOYSTICK_COUNT){
        return -1;
    }
    return m_JoystickArr[id].getX();
}
int Inputs::getJoystickY(int id)const{
    if(id >= JOYSTICK_COUNT){
        return -1;
    }
    return m_JoystickArr[id].getY();
}
int Inputs::getJoystickD(int id)const{
    if(id >= JOYSTICK_COUNT){
        return -1;
    }
    return m_JoystickArr[id].getD();
}

void Inputs::setButtonPin(int newPin, int id){
    if(id >= BUTTON_COUNT){
        return;
    }
    m_ButtonArr[id].setPin(newPin);
}
void Inputs::setJoystickPin(int newPin, int newX, int newY, int id){
    if(id >= JOYSTICK_COUNT){
        return;
    }
    m_JoystickArr[id].setPin(newPin,newX,newY);
}

void Inputs::setButtonPin(const int (&newPins)[BUTTON_COUNT]){
    for(int i=0; i<BUTTON_COUNT; i++){
        m_ButtonArr[i].setPin(newPins[i]);
    }
}
int Inputs::getButton(int id)const{
    if(id >= BUTTON_COUNT){
        return -1;
    }
    return m_ButtonArr[id].get();
}

