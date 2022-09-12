#include "SumArray.h"

SumArray::SumArray(int** a, int* r, int c) : TwoDArray(a,r,c)
{
    array = getArray();
    sizes = getSizes();
    baseSize = getBaseSize();
}
int* SumArray::operator[](int i)
{
    int* sum = new int;
    for (int j = 0; j < sizes[i]; j++)
    {
        *sum += array[i][j];
    }
    
    return sum;
}