#include "TwoDArray.h"
TwoDArray::TwoDArray(int** array, int* sizes, int baseSize)
{
    this->array = new int*[baseSize];
    this->sizes = new int[baseSize];
    this->baseSize = baseSize;
    for (int i = 0; i < baseSize; i++)
    {
        this->sizes[i] = sizes[i];
        this->array[i] = new int[sizes[i]];
        for (int j = 0; j < sizes[i]; j++)
        {
            this->array[i][j] = array[i][j];
        }
    }
}
TwoDArray::~TwoDArray()
{
    for (int i = 0; i < baseSize; i++)
    {
        delete[] array[i];
    }
    delete[] array;
    delete[] sizes;
}
std::ostream& operator<<(std::ostream& os, TwoDArray& tda)
{
    for (int i = 0; i < tda.getBaseSize(); i++)
    {
        for (int j = 0; j < tda.getSizes()[i]; j++)
        {
            if (j != tda.getSizes()[i] - 1)
            {
                os << tda.getArray()[i][j] << " ";
            }
            else
            {
                os << tda.getArray()[i][j];
            }
        }
        os << std::endl;
    }
    return os;
}
int** TwoDArray::getArray()
{
    int** temp = new int*[baseSize];
    for (int i = 0; i < baseSize; i++)
    {
        temp[i] = new int[sizes[i]];
        for (int j = 0; j < sizes[i]; j++)
        {
            temp[i][j] = array[i][j];
        }
    }
    return temp;
}
int* TwoDArray::getSizes()
{
    int* temp = new int[baseSize];
    for (int i = 0; i < baseSize; i++)
    {
        temp[i] = sizes[i];
    }
    return temp;
}
int TwoDArray::getBaseSize()  
{
    return baseSize;
}
TwoDArray::operator int**()
{
    return getArray();
}
TwoDArray::operator int*()
{
    return getSizes();
}
TwoDArray::operator int()
{
    return getBaseSize();
}