#include "IsEvenOdd.h"

IsEvenOdd::IsEvenOdd(): ValueIndependantTester()
{
    numAliveObjects++;
}
IsEvenOdd::~IsEvenOdd()
{
    numAliveObjects--;
}
bool IsEvenOdd::evaluate(int val)
{
    return val % 2 == 0;
}
NumberTester* IsEvenOdd::clone()
{
    return new IsEvenOdd();
}
int IsEvenOdd::getNumAliveObjects()
{
    return numAliveObjects;
}