#ifndef IsGreater_h
#define IsGreater_h
#include "ValueDependantTester.h"
// static int numAliveObjects = 0;
class IsGreater: public ValueDependantTester
{
private:
    static int numAliveObjects;
public:
    IsGreater(int);
    virtual ~IsGreater();
    bool evaluate(int);
    NumberTester* clone();
    static int getNumAliveObjects();
};
#endif