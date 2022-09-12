#include "CountArray.h"

CountArray::CountArray(int** a, int* r, int c) : TwoDArray(a,r,c)
{
    array = getArray();
    sizes = getSizes();
    baseSize = getBaseSize();
}
CountArray::~CountArray()
{
    for (int i = 0; i < baseSize; i++)
    {
        delete[] array[i];
    }
    delete[] array;
    delete[] sizes;
}
int* CountArray::operator[](int i)
{
    return &sizes[i];
}