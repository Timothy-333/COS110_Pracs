#ifndef IsDivisible_h
#define IsDivisible_h
#include "ValueDependantTester.h"
// static int numAliveObjects = 0;
class IsDivisible: public ValueDependantTester
{
public:
    IsDivisible(int);
    virtual ~IsDivisible();
    bool evaluate(int);
    NumberTester* clone();
    static int getNumAliveObjects();
};
#endif