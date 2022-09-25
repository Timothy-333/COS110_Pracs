#ifndef SORTARRAY_H
#define SORTARRAY_H

#include "TwoDArray.h"

class SortArray : TwoDArray
{
    public:
        SortArray(int**,int*,int);
        int* operator[](int);
};

#endif