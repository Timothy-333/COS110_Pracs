#include "SumArray.h"

SumArray::SumArray(int** a, int* r, int c) : TwoDArray(a,r,c)
{
}
int* SumArray::operator[](int i)
{
    int* sum = new int;
    *sum = 0;
    for (int j = 0; j < getSizes()[i]; j++)
    {
        *sum += getArray()[i][j];
    }
    return sum;
}