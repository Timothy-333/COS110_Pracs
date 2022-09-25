#ifndef COUNTARRAY_H
#define COUNTARRAY_H

#include "TwoDArray.h"

class CountArray : TwoDArray
{
    public:
        CountArray(int**,int*,int);
        int* operator[](int);
};

#endif