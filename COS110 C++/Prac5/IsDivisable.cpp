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
    return val % value == 0;
}
NumberTester* IsDivisable::clone()
{
    return new IsDivisable(value);
}
int IsDivisable::getNumAliveObjects()
{
    return numAliveObjects;
}

