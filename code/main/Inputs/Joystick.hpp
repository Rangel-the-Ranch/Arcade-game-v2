#pragma once

class Joystick{
    public:
        Joystick();
        Joystick(int newPin,int newX,int newY);
        void setPin(int newPin, int newX, int newY);

        int getD()const;
        int getX()const;
        int getY()const;

    private:
        int m_PinD = -1;
        int m_PinX = -1;
        int m_PinY = -1;

        void declarePinmode()const;
};
int Joystick::getD()const{
    if(m_PinD == -1){
        return -1;
    }
    return digitalRead(m_PinD);
}
int Joystick::getX()const{
    if(m_PinX == -1){
        return -1;
    }
    return analogRead(m_PinX);
}
int Joystick::getY()const{
    if(m_PinY == -1){
        return -1;
    }
    return analogRead(m_PinY);
}


Joystick::Joystick(){
    m_PinD = -1;
    m_PinX = -1;
    m_PinY = -1;
}
Joystick::Joystick(int newPin, int newX, int newY){
    setPin(newPin,newX,newY);
}

void Joystick::setPin(int newPin, int newX, int newY){
    m_PinD = newPin;
    m_PinX = newX;
    m_PinY = newY;
    declarePinmode();
}
void Joystick::declarePinmode()const{
    pinMode(m_PinD, INPUT);
    pinMode(m_PinX, INPUT);
    pinMode(m_PinY, INPUT);
}