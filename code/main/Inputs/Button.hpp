#pragma once

class Button{
    public:
        Button();
        Button(int newPin);
        void setPin(int newPin);

        int get()const;

    private:
        int m_PinOut = -1;

        void declarePinMode()const;
};

int Button::get()const{
    if(m_PinOut == -1){
        return -1;
    }
    return digitalRead(m_PinOut);
}

void Button::setPin(int newPin){
    m_PinOut = newPin;
    declarePinMode();
}
Button::Button(){
    m_PinOut = -1;
}
Button::Button(int newPin){
    setPin(newPin);
}
void Button::declarePinMode()const{
    pinMode(m_PinOut, INPUT);
}