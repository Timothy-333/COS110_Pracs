#include "CountArray.h"

CountArray::CountArray(int** a, int* r, int c) : TwoDArray(a,r,c)
{
}
int* CountArray::operator[](int i)
{
    return &getSizes()[i];
}