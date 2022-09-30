#ifndef IsSmaller_h
#define IsSmaller_h
#include "ValueDependantTester.h"
// static int numAliveObjects = 0;
class IsSmaller: public ValueDependantTester
{
private:
    static int numAliveObjects;
public:
    IsSmaller(int);
    virtual ~IsSmaller();
    bool evaluate(int);
    NumberTester* clone();
    static int getNumAliveObjects();
};
#endif