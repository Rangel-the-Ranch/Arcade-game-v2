#pragma once

class Button{
    public:
        Button();
        Button(int newPin);
        void setPin(int newPin);

        bool get()const;

    private:
        int m_PinOut = -1;

        void declarePinMode()const;
};

bool Button::get()const{
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