#ifndef ValueDpendantTester_h
#define ValueDpendantTester_h
#include "NumberTester.h"
// static int numAliveObjects = 0;
class ValueDependantTester: public NumberTester
{
protected:
    int value;
public:
    ValueDependantTester(int);
    virtual ~ValueDependantTester();
    virtual bool evaluate(int)=0;
    virtual NumberTester* clone()=0;
    static int getNumAliveObjects();
};
#endif