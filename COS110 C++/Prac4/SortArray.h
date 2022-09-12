#ifndef SORTARRAY_H
#define SORTARRAY_H

#include "TwoDArray.h"

class SortArray : public TwoDArray
{
    private:
        int** array;
        int* sizes;
        int baseSize;
    public:
        SortArray(int**,int*,int);
        ~SortArray();
        int* operator[](int);
};

#endif