#ifndef ValueIndependantTester_h
#define ValueIndependantTester_h
#include "NumberTester.h"
static int numAliveObjects = 0;
class ValueIndependantTester: public NumberTester
{
public:
    ValueIndependantTester();
    ~ValueIndependantTester();
    virtual bool evaluate(int);
    virtual NumberTester* clone();
    static int getNumAliveObjects();
};
#endif