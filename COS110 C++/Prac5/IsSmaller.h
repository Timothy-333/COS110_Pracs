#ifndef IsSmaller_h
#define IsSmaller_h
#include "ValueDependantTester.h"
static int numAliveObjects = 0;
class IsSmaller: public ValueDependantTester
{
public:
    IsSmaller(int);
    ~IsSmaller();
    virtual bool evaluate(int);
    virtual NumberTester* clone();
    static int getNumAliveObjects();
};
#endif