#include "ValueIndependantTester.h"

ValueIndependantTester::ValueIndependantTester()
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

