#ifndef SUMARRAY_H
#define SUMARRAY_H

#include "TwoDArray.h"

class SumArray : public TwoDArray
{
    private:
        int** array;
        int* sizes;
        int baseSize;
    public:
        SumArray(int**,int*,int);
        ~SumArray();
        int* operator[](int);
};

#endif