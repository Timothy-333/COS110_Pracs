#ifndef ValueIndependantTester_h
#define ValueIndependantTester_h
#include "NumberTester.h"
// static int numAliveObjects = 0;
class ValueIndependantTester: public NumberTester
{
public:
    ValueIndependantTester();
    virtual ~ValueIndependantTester();
    virtual bool evaluate(int)=0;
    virtual NumberTester* clone()=0;
    static int getNumAliveObjects();
};
#endif