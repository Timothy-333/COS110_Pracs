#ifndef IsDivisable_h
#define IsDivisable_h
#include "ValueDependantTester.h"
// static int numAliveObjects = 0;
class IsDivisable: public ValueDependantTester
{
public:
    IsDivisable(int);
    virtual ~IsDivisable();
    virtual bool evaluate(int);
    virtual NumberTester* clone();
    static int getNumAliveObjects();
};
#endif