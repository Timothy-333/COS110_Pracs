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
        virtual int* operator[](int);
};

#endif