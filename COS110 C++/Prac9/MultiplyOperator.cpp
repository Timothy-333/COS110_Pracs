#include "MultiplyOperator.h"
template <class T>
T MultiplyOperator<T>::operator()(T a, T b)
{
    return a * b;
}
template <class T>
Operator<T>* MultiplyOperator<T>::clone()
{
    return new MultiplyOperator<T>;
}
