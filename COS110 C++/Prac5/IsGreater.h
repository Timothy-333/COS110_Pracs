#ifndef IsGreater_h
#define IsGreater_h
#include "ValueDependantTester.h"
static int numAliveObjects = 0;
class IsGreater: public ValueDependantTester
{
public:
    IsGreater(int);
    ~IsGreater();
    virtual bool evaluate(int);
    virtual NumberTester* clone();
    static int getNumAliveObjects();
};
#endif