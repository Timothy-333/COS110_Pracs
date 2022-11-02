#include "Calculator.h"
#include <cstddef>
template <class T>
Calculator<T>::Calculator()
{
    valueStack = new Stack<T>;
    operatorStack = new Stack<Operator<T>*>;
}
template <class T>
Calculator<T>::~Calculator()
{
    delete valueStack;
    delete operatorStack;
}
template <class T>
void Calculator<T>::addOperator(Operator<T>* op)
{
    operatorStack->push(op);
}
template <class T>
void Calculator<T>::addValue(T value)
{
    valueStack->push(value);
}
template <class T>
T Calculator<T>::removeValue()
{
    if (!valueStack->isEmpty())
    {
        return valueStack->pop()->getData();
    }
    else
    {
        return NULL;
    }
}
template <class T>
Operator<T>* Calculator<T>::removeOperator()
{
    if (!operatorStack->isEmpty())
    {
        return operatorStack->pop()->getData();
    }
    else
    {
        return NULL;
    }
}
template <class T>
int Calculator<T>::numValues()
{
    return valueStack->size();
}
template <class T>
int Calculator<T>::numOperators()
{
    return operatorStack->size();
}
template <class T>
T Calculator<T>::calculate()
{
    T result = NULL;
    while (!operatorStack->isEmpty())
    {
        Node<Operator<T>*>* op = operatorStack->pop();
        if (valueStack->getTop()->getNext())
        {
            T a = valueStack->pop()->getData();
            T b = valueStack->pop()->getData();
            result = op->getData()->operator()(a, b);
        }
        else
            return NULL;

        valueStack->push(result);
    }
    return result;
}