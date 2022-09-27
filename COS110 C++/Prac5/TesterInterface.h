#ifndef TesterInterface_h
#define TesterInterface_h
#include "NumberTester.h"
#include <cstddef>
class TesterInterface
{
private:
    int maxNumTesters;
    int currNumTesters;
    NumberTester** testers;
public:
    TesterInterface(int);
    TesterInterface(TesterInterface*);
    TesterInterface(TesterInterface&);
    int addTester(NumberTester*);
    bool removeTester(int);
    bool evaluate(int);
    int* failedTests(int);
    int numberOfFailedTests(int);
    NumberTester* operator[](int);
    const int getCurrNumTesters();
    const int getMaxNumTesters();
    ~TesterInterface();
};
#endif
