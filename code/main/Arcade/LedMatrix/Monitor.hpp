#include"CellMatrix.hpp"

class Monitor{
    private:
        static const unsigned int MATRIX_IN_X = 2;
        static const unsigned int MATRIX_IN_Y = 2;
    public:
        static const unsigned int CELLS_IN_X = MATRIX_IN_X * CellMatrix::MAX_SIZE_X;
        static const unsigned int CELLS_IN_Y = MATRIX_IN_Y * CellMatrix::MAX_SIZE_Y;

        void setPin(unsigned int matX,unsigned int matY, int newPin);

        void applyMatrix(const Cell (&newMatrix)[CELLS_IN_X][CELLS_IN_X])const;
        void clear()const;


    private:
        CellMatrix m_Libs[MATRIX_IN_X][MATRIX_IN_Y];

};

void Monitor::setPin(unsigned int matX,unsigned int matY, int newPin){
    if(matX >= MATRIX_IN_X || matY >= MATRIX_IN_Y){
        return;
    }
    m_Libs[matX][matY].setPin(newPin);
}

void Monitor::applyMatrix(const Cell (&newMatrix)[CELLS_IN_X][CELLS_IN_Y])const{
    for(int x=0; x<MATRIX_IN_X; x++){
        for(int y=0; y<MATRIX_IN_Y; y++){
            m_Libs[x][y].applyMatrix(newMatrix, x*CellMatrix::MAX_SIZE_X, y*CellMatrix::MAX_SIZE_Y);
        }
    }
}
void Monitor::clear()const{
    for(int x=0; x<MATRIX_IN_X; x++){
        for(int y=0; y<MATRIX_IN_Y; y++){
            m_Libs[x][y].clear();
        }
    }
}


