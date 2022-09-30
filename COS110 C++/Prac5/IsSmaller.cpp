#include "IsSmaller.h"
int IsSmaller::numAliveObjects = 0;
IsSmaller::IsSmaller(int val): ValueDependantTester(val)
{
    numAliveObjects++;
}
IsSmaller::~IsSmaller()
{
    numAliveObjects--;
}
bool IsSmaller::evaluate(int val)
{
    return val < value;
}
NumberTester* IsSmaller::clone()
{
    return new IsSmaller(value);
}
int IsSmaller::getNumAliveObjects()
{
    return numAliveObjects;
}