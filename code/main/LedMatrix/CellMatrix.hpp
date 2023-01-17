#pragma once

#include "Adafruit_NeoPixel/Adafruit_NeoPixel.h"
#include "Cell.hpp"

class CellMatrix{
    public:
        static const unsigned int MAX_SIZE_X = 16;
        static const unsigned int MAX_SIZE_Y = 16;
        static const unsigned int MAX_SIZE_X_ALL = 32;
        static const unsigned int MAX_SIZE_Y_ALL = 32;      //Magic

        CellMatrix();
        CellMatrix(int newPin);
        
        void setPin(int newPin);
        void applyMatrix(const Cell (&newMatrix)[MAX_SIZE_X_ALL][MAX_SIZE_Y_ALL],int startX,int startY);

    private:

        static const unsigned int PIXEL_COUNT = MAX_SIZE_X * MAX_SIZE_Y;
        unsigned int m_Pin = -1;
};

CellMatrix::CellMatrix(){
    m_Pin = -1;
}
void CellMatrix::setPin(int newPin){
    m_Pin = newPin;
}
CellMatrix::CellMatrix(int newPin){
    setPin(newPin);
}

void CellMatrix::applyMatrix(const Cell (&newMatrix)[MAX_SIZE_X_ALL][MAX_SIZE_Y_ALL],int startX,int startY){
    if(m_Pin == -1){
        return;
    }
    Adafruit_NeoPixel temp(PIXEL_COUNT , m_Pin , NEO_GRB + NEO_KHZ800);
    temp.begin();
    temp.clear();
    if(startX == 0){
        return;
    }
    int currPixel = 0;
    for (int x = startX; x < MAX_SIZE_X + startX; x++) {

        if (x%2){
            for (unsigned int y = startY; y < startY + MAX_SIZE_Y; y++){
                temp.setPixelColor(currPixel, temp.Color(newMatrix[x][y].getRed(), newMatrix[x][y].getGreen(), newMatrix[x][y].getBlue()));
                currPixel++;
            }
        }else{
            for (int y = startY + MAX_SIZE_Y - 1; y >= startY; y--){
                temp.setPixelColor(currPixel, temp.Color(newMatrix[x][y].getRed(), newMatrix[x][y].getGreen(), newMatrix[x][y].getBlue()));
                currPixel++;
            }
        }
    }
    temp.show();
}
