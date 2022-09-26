#include "SortArray.h"

SortArray::SortArray(int** a, int* r, int c) : TwoDArray(a,r,c)
{
    array = getArray();
    sizes = getSizes();
    baseSize = getBaseSize();
}
SortArray::~SortArray()
{
    for (int i = 0; i < baseSize; i++)
    {
        delete[] array[i];
    }
    delete[] array;
    delete[] sizes;
}
int* SortArray::operator[](int i)
{
    int* temp = new int[sizes[i]];
    for (int j = 0; j < sizes[i]; j++)
    {
        temp[j] = array[i][j];
    }
    for (int j = 0; j < sizes[i]; j++)
    {
        for (int k = 0; k < sizes[i] - 1; k++)
        {
            if (temp[k] > temp[k + 1])
            {
                int temp2 = temp[k];
                temp[k] = temp[k + 1];
                temp[k + 1] = temp2;
            }
        }
    }
    return temp;
}