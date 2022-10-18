#pragma once

#include<cstring>

class RGBcell{
    public:
        RGBcell();
        RGBcell(const size_t newRed, const size_t newBlue,const size_t newGreen);

        void setRed(const size_t newRed);
        void setBlue(const size_t newBlue);
        void setGreen(const size_t newBlue);
        void setAll(const size_t newRed, const size_t newBlue,const size_t newGreen)

        unsigned short getRed()const;
        unsigned short getGreen()const;
        unsigned short getBlue()const;

    private:
        unsigned short m_Red;
        unsigned short m_Green;
        unsigned short m_Blue;
}