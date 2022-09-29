#ifndef IsEvenOdd_h
#define IsEvenOdd_h
#include "ValueIndependantTester.h"
// static int numAliveObjects = 0;
class IsEvenOdd: public ValueIndependantTester
{
public:
    IsEvenOdd();
    virtual ~IsEvenOdd();
    bool evaluate(int);
    NumberTester* clone();
    static int getNumAliveObjects();
};
#endif