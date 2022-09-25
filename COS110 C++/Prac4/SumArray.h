#ifndef SUMARRAY_H
#define SUMARRAY_H

#include "TwoDArray.h"

class SumArray : TwoDArray
{
    public:
        SumArray(int**,int*,int);
        int* operator[](int);
};

#endif