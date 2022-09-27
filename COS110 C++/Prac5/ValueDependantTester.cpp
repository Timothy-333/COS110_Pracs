#include "ValueDependantTester.h"
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
    return getNumAliveObjects();
}