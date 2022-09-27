#include "SortArray.h"

SortArray::SortArray(int** a, int* r, int c) : TwoDArray(a,r,c)
{
}
int* SortArray::operator[](int i)
{
    int* temp = new int[getSizes()[i]];
    for (int j = 0; j < getSizes()[i]; j++)
    {
        temp[j] = getArray()[i][j];
    }
    for (int j = 0; j < getSizes()[i]; j++)
    {
        for (int k = 0; k < getSizes()[i] - 1; k++)
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