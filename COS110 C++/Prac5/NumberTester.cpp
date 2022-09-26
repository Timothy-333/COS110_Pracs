#include "NumberTester.h"
NumberTester::NumberTester()
{
    numAliveObjects++;
}
NumberTester::~NumberTester()
{
    numAliveObjects--;
}