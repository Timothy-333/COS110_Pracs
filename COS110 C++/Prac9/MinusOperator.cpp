#include "MinusOperator.h"
template <class T>
T MinusOperator<T>::operator()(T a, T b)
{
    return a - b;
}
template <class T>
Operator<T>* MinusOperator<T>::clone()
{
    return new MinusOperator<T>;
}