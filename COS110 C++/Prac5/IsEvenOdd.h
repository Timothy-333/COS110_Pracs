#ifndef IsEvenOdd_h
#define IsEvenOdd_h
#include "ValueIndependantTester.h"
static int numAliveObjects = 0;
class IsEvenOdd: public ValueIndependantTester
{
public:
    IsEvenOdd();
    ~IsEvenOdd();
    virtual bool evaluate(int);
    virtual NumberTester* clone();
    static int getNumAliveObjects();
};
#endif