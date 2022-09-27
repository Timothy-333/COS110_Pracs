//The base 2D array class

//# directives....
#ifndef TwoDArray_H
#define TwoDArray_H
//Do not add any more #includes
#include <iostream>
#include <string>

//Define class below
class TwoDArray
{
private:
    int** array;
    int* sizes;
    int baseSize;
public:
    TwoDArray(int**,int*,int);
    ~TwoDArray();
    friend std::ostream& operator<<(std::ostream& os, TwoDArray& tda);
    operator int**();
    operator int*();
    operator int();
protected:
    int** getArray();
    int* getSizes();
    int getBaseSize();
};
#endif