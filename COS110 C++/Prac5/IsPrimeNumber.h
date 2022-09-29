#ifndef IsPrimeNumber_h
#define IsPrimeNumber_h
#include "ValueIndependantTester.h"
// static int numAliveObjects = 0;
class IsPrimeNumber: public ValueIndependantTester
{
public:
    IsPrimeNumber();
    virtual ~IsPrimeNumber();
    bool evaluate(int);
    NumberTester* clone();
    static int getNumAliveObjects();
};
#endif