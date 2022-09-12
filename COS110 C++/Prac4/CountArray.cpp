#include "CountArray.h"

CountArray::CountArray(int** a, int* r, int c) : TwoDArray(a,r,c)
{
    array = getArray();
    sizes = getSizes();
    baseSize = getBaseSize();
}
int* CountArray::operator[](int i)
{
    return &sizes[i];
}