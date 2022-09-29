#include "IsDivisible.h"

IsDivisible::IsDivisible(int val): ValueDependantTester(val)
{
    numAliveObjects++;
}
IsDivisible::~IsDivisible()
{
    numAliveObjects--;
}
bool IsDivisible::evaluate(int val)
{
    if (value != 0)
    {
        return val % value == 0; 
    }   
    else
    {
        return false;
    }
}
NumberTester* IsDivisible::clone()
{
    return new IsDivisible(value);
}
int IsDivisible::getNumAliveObjects()
{
    return getNumAliveObjects();
}

