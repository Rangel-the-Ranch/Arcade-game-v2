#pragma once

#include "LedMatrix/Monitor.hpp"
#include "Inputs/Inputs.hpp"
#include "pinLayout.h"

class Arcade{
    public:
        Arcade();

        static const unsigned int MATRIX_SIZE_X = Monitor::CELLS_IN_X;
        static const unsigned int MATRIX_SIZE_Y = Monitor::CELLS_IN_Y;
        static const unsigned int BUTTON_COUNT = Inputs::BUTTON_COUNT;
        static const unsigned int JOYSTICK_COUNT = Inputs::JOYSTICK_COUNT;

        void show(const Cell (&newMatrix)[MATRIX_SIZE_X][MATRIX_SIZE_Y] )const;
        void clear()const;

        int button(int id)const;
        int joystickX(int id)const;
        int joystickY(int id)const;
        int joystickD(int id)const;

    private:
        Monitor m_Screen;
        Inputs m_Input;

    void pinDeclaration();
};

void Arcade::pinDeclaration(){
    m_Screen.setPin(0,0,TOP_LEFT_PIN);
    m_Screen.setPin(0,1,TOP_RIGHT_PIN);
    m_Screen.setPin(1,0,BOT_LEFT_PIN);
    m_Screen.setPin(1,1,BOT_RIGHT_PIN);

    m_Input.setButtonPin(BUTTON_1_PIN, 0);
    m_Input.setButtonPin(BUTTON_2_PIN, 1);
    m_Input.setButtonPin(BUTTON_3_PIN, 2);

    m_Input.setJoystickPin(JOYSTICK_1_D_PIN,JOYSTICK_1_X_PIN,JOYSTICK_1_Y_PIN, 0);
}

Arcade::Arcade(){
    pinDeclaration();

}
void Arcade::show(const Cell (&newMatrix)[MATRIX_SIZE_X][MATRIX_SIZE_Y])const{
    m_Screen.applyMatrix(newMatrix);
}
void Arcade::clear()const{
    m_Screen.clear();
}

int Arcade::button(int id)const{
    return m_Input.getButton(id);
}
int Arcade::joystickD(int id)const{
    return m_Input.getJoystickD(id);
}
int Arcade::joystickX(int id)const{
    return m_Input.getJoystickX(id);
}
int Arcade::joystickY(int id)const{
    return m_Input.getJoystickY(id);
}