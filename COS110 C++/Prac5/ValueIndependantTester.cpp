#include "ValueIndependantTester.h"
int ValueIndependantTester::numAliveObjects = 0;
ValueIndependantTester::ValueIndependantTester(): NumberTester()
{
    numAliveObjects++;
}
ValueIndependantTester::~ValueIndependantTester()
{
    numAliveObjects--;
}
int ValueIndependantTester::getNumAliveObjects()
{
    return numAliveObjects;
}

