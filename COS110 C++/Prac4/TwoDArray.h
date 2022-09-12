//The base 2D array class

//# directives....
#ifndef TWODARRAY_H
#define TWODARRAY_H
//Do not add any more #includes
#include <iostream>
#include <string>

class TwoDArray;
std::ostream& operator<<(std::ostream& os, TwoDArray& tda);
//Define class below
class TwoDArray
{
private:
    int** array;
    int* sizes;
    int baseSize;
protected:
    int** getArray();
    int* getSizes();
    int getBaseSize();
public:
    TwoDArray(int**,int*,int);
    ~TwoDArray();
    friend std::ostream& operator<<(std::ostream& os, TwoDArray& tda);
    operator int**();
    operator int*();
    operator int();
    virtual int* operator[](int) = 0;
};
#endif