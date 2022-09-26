#ifndef ValueDpendantTester_h
#define ValueDpendantTester_h
#include "NumberTester.h"
static int numAliveObjects = 0;
class ValueDependantTester: public NumberTester
{
protected:
    int value;
public:
    ValueDependantTester(int);
    ~ValueDependantTester();
    virtual bool evaluate(int);
    virtual NumberTester* clone();
    static int getNumAliveObjects();
};
#endif