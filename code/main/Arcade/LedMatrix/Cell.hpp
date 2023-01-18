#pragma once

class Cell{
    public:
        Cell();
        Cell(int newRed, int newGreen, int newBlue);
        Cell(const String& str);
        Cell(const Cell& other);

        void setRed(int newRed);
        void setBlue(int newBlue);
        void setGreen(int newGreen);
        void set(int newRed, int newGreen, int newBlue);
        void set(const Cell& other);
        void set(const String& str);
        void clear();
        void setMax();

        int getRed()const;
        int getBlue()const;
        int getGreen()const;

        Cell& operator=(const Cell& other);
        Cell& operator=(const String& str);

        bool operator==(const String& str);//////////////////

    private:
        static const unsigned int MAX_VALUE = 8;
        
        char m_Red;
        char m_Green;
        char m_Blue;

        
};
bool Cell::operator==(const String& str){
    Cell temp(str);
    return (m_Red == temp.m_Red) && (m_Green == temp.m_Green) && (m_Blue == temp.m_Blue);
}
Cell::Cell(const Cell& other){
    set(other);
}
Cell& Cell::operator=(const Cell& other){
    set(other);
    return *this;
}
Cell& Cell::operator=(const String& str){
    set(str);
    return *this;
}
void Cell::set(const Cell& other){
    m_Blue = other.m_Blue;
    m_Red = other.m_Red;
    m_Green = other.m_Green;
}
void Cell::setMax(){
    set(MAX_VALUE-1,MAX_VALUE-1,MAX_VALUE-1);
}

Cell::Cell(const String& str){
    set(str);
}

void Cell::set(const String& str){
  if(str == "Blue" || str == "blue"){
      set(0,0,MAX_VALUE-1);
  }else if(str == "Red" || str == "red"){
      set(MAX_VALUE-1,0,0);
  }else if(str == "Green" || str == "green"){
    set(0,MAX_VALUE-1,0);
  }else if(str == "White" || str == "white"){
    set(MAX_VALUE-1,MAX_VALUE-1,MAX_VALUE-1);
  }else if(str == "Black" || str == "black"){
    set(0,0,0);
  }else if(str == "Cyan" || str == "cyan"){
    set(0,(MAX_VALUE/5)*3,(MAX_VALUE/5)*3);
  }else{
    set(0,0,0);
  }
}


Cell::Cell(){
    set(0,0,0);
}
Cell::Cell(int newRed, int newGreen, int newBlue){
    set(newRed,newGreen,newBlue);
}
void Cell::setRed(int newRed){
    m_Red = newRed % MAX_VALUE;
}
void Cell::setGreen(int newGreen){
    m_Green = newGreen % MAX_VALUE;
}
void Cell::setBlue(int newBlue){
    m_Blue = newBlue % MAX_VALUE;
}
void Cell::set(int newRed, int newGreen, int newBlue){
    setRed(newRed);
    setGreen(newGreen);
    setBlue(newBlue);
}
void Cell::clear(){
    set(0,0,0);
}

int Cell::getRed()const{
    return m_Red;
}
int Cell::getGreen()const{
    return m_Green;
}
int Cell::getBlue()const{
    return m_Blue;
}

