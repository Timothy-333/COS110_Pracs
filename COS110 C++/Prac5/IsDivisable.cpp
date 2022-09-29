#include "IsDivisable.h"

IsDivisable::IsDivisable(int val): ValueDependantTester(val)
{
    numAliveObjects++;
}
IsDivisable::~IsDivisable()
{
    numAliveObjects--;
}
bool IsDivisable::evaluate(int val)
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
NumberTester* IsDivisable::clone()
{
    return new IsDivisable(value);
}
int IsDivisable::getNumAliveObjects()
{
    return getNumAliveObjects();
}

