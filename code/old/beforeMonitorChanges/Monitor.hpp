
#include"CellMatrix.hpp"

class Monitor{
    private:
        static const unsigned int MATRIX_IN_X = 2;
        static const unsigned int MATRIX_IN_Y = 2;
        static const unsigned int CELLS_IN_X = MATRIX_IN_X * CellMatrix::MAX_SIZE_X;
        static const unsigned int CELLS_IN_Y = MATRIX_IN_Y * CellMatrix::MAX_SIZE_Y;
    public:
        Cell m_Screen[MATRIX_IN_X][MATRIX_IN_Y];

        void setPin(unsigned int matX,unsigned int matY, int newPin);
        void showAll()const;

    private:
      int m_Pins[MATRIX_IN_X][MATRIX_IN_Y];

};

void Monitor::setPin(unsigned int matX,unsigned int matY, int newPin){
    if(matX >= MATRIX_IN_X || matY >= MATRIX_IN_Y){
        return;
    }
    m_Pins[matX][matY] = newPin;
}

void Monitor::showAll()const{
    
}