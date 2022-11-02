#include "PlusOperator.h"
template <class T>
T PlusOperator<T>::operator()(T a, T b)
{
    return a + b;
}
template <class T>
Operator<T>* PlusOperator<T>::clone()
{
    return new PlusOperator<T>;
}