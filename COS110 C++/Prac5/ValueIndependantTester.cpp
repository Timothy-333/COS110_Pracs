#include "ValueIndependantTester.h"

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
    return getNumAliveObjects();
}

