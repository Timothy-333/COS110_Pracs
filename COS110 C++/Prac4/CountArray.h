#ifndef COUNTARRAY_H
#define COUNTARRAY_H

#include "TwoDArray.h"

class CountArray : public TwoDArray
{
    private:
        int** array;
        int* sizes;
        int baseSize;
    public:
        CountArray(int**,int*,int);
        ~CountArray();
        virtual int* operator[](int);
};

#endif