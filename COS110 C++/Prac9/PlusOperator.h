#ifndef PLUSOPERATOR_H
#define PLUSOPERATOR_H
#include "Operator.h"
template <class T>
class PlusOperator
{
public:
    T operator()(T, T);
    Operator<T>* clone();
};

#endif