#include "ValueDependantTester.h"
ValueDependantTester::ValueDependantTester(int val)
{
    this->value = val;
    numAliveObjects++;
}
ValueDependantTester::~ValueDependantTester()
{
    numAliveObjects--;
}
int ValueDependantTester::getNumAliveObjects()
{
    return numAliveObjects;
}