#include "ValueDependantTester.h"
int ValueDependantTester::numAliveObjects = 0;
ValueDependantTester::ValueDependantTester(int val): NumberTester()
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