#ifndef IsDivisable_h
#define IsDivisable_h
#include "ValueDependantTester.h"
// static int numAliveObjects = 0;
class IsDivisable: public ValueDependantTester
{
public:
    IsDivisable(int);
    virtual ~IsDivisable();
    bool evaluate(int);
    NumberTester* clone();
    static int getNumAliveObjects();
};
#endif