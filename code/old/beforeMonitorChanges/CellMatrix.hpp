#pragma once

#include "Adafruit_NeoPixel/Adafruit_NeoPixel.h"
#include "Cell.hpp"

class CellMatrix{
    public:
        static const unsigned int MAX_SIZE_X = 16;
        static const unsigned int MAX_SIZE_Y = 16;
        Cell m_Matrix[MAX_SIZE_X][MAX_SIZE_Y];

        CellMatrix();
        CellMatrix(int newPin);
        
        void setPin(int newPin);
        void applyMatrix();
        void resetMatrix();
        void getMatrix(Cell newMatrix[MAX_SIZE_X][MAX_SIZE_Y]);
        void setAll(int newRed, int newGreen, int newBlue);

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

void CellMatrix::getMatrix(Cell newMatrix[MAX_SIZE_X][MAX_SIZE_Y]){
    for(int x=0; x<MAX_SIZE_X; x++){
        for(int y=0; y<MAX_SIZE_Y; y++){
            m_Matrix[x][y] = newMatrix[x][y];
        }
    }
}

CellMatrix::CellMatrix(int newPin){
    setPin(newPin);
}

void CellMatrix::setAll(int newRed, int newGreen, int newBlue){
  for(int x=0; x< MAX_SIZE_X; x++){
    for(int y =0; y < MAX_SIZE_Y; y++){
      m_Matrix[x][y].set(newRed,newGreen,newBlue);
    }
  }
}

void CellMatrix::applyMatrix(){
    if(m_Pin == -1){
        return;
    }
    Adafruit_NeoPixel temp(PIXEL_COUNT , m_Pin , NEO_GRB + NEO_KHZ800);

    temp.begin();
    temp.clear();
    int currPixel = 0;
    for (int x = 0; x < MAX_SIZE_X; x++) {
        if (x%2){
            for (int y = 0; y < MAX_SIZE_Y; y++){
                temp.setPixelColor(currPixel, temp.Color(m_Matrix[x][y].getRed(), m_Matrix[x][y].getGreen(), m_Matrix[x][y].getBlue()));
                currPixel++;
            }
        }else{
            for (int y = MAX_SIZE_Y - 1; y >= 0; y--){
                temp.setPixelColor(currPixel, temp.Color(m_Matrix[x][y].getRed(), m_Matrix[x][y].getGreen(), m_Matrix[x][y].getBlue()));
                currPixel++;
            }
        }
    }
    
    temp.show();
}

void CellMatrix::resetMatrix(){
    
    for(int x = 0; x<MAX_SIZE_X; x++){
        for(int y = 0; y<MAX_SIZE_Y; y++){
            m_Matrix[x][y].clear();
        }
    }
}

