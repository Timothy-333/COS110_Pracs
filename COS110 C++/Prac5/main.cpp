#include <iostream>
#include "TesterInterface.h"
#include "ValueIndependantTester.h"
#include "NumberTester.h"
#include "IsEvenOdd.h"
#include "IsDivisible.h"
#include "IsSmaller.h"
#include "IsGreater.h"
#include "IsPrimeNumber.h"

using namespace std;

int main() 
{
    cout << "Number of alive objects: " << NumberTester::getNumAliveObjects() << endl;
    IsPrimeNumber* tester = new IsPrimeNumber();
    int a = 2;
    int b = 1;
    if(tester->evaluate(a))
    {
        cout << a << " is a prime number" << endl;
    }
    else
    {
        cout << a << " is not a prime number" << endl;
    }

    IsEvenOdd* tester2 = new IsEvenOdd();
    if(tester2->evaluate(a))
    {
        cout << a << " is an even number" << endl;
    }
    else
    {
        cout << a << " is not an even number" << endl;
    }
    IsDivisible* tester3 = new IsDivisible(b);
    if(tester3->evaluate(a))
    {
        cout << a << " is Divisible by " << b << endl;
    }
    else
    {
        cout << a << " is not Divisible by " << b << endl;
    }
    IsSmaller* tester4 = new IsSmaller(b);
    if(tester4->evaluate(a))
    {
        cout << a << " is smaller than " << b << endl;
    }
    else
    {
        cout << a << " is not smaller than " << b << endl;
    }
    IsGreater* tester5 = new IsGreater(b);
    if(tester5->evaluate(a))
    {
        cout << a << " is greater than " << b << endl;
    }
    else
    {
        cout << a << " is not greater than " << b << endl;
    }
    TesterInterface* testerInterface = new TesterInterface(5);
    testerInterface->addTester(tester);
    testerInterface->addTester(tester2);
    testerInterface->addTester(tester3);
    testerInterface->addTester(tester4);
    testerInterface->addTester(tester5);
    if(testerInterface->evaluate(a))
    {
        cout << a << " passed all tests" << endl;
    }
    else
    {
        cout << a << " did not pass all tests" << endl;
    }
    cout << "Failed Tests: " << testerInterface->numberOfFailedTests(a) << endl;
    cout << "Number of alive objects: " << NumberTester::getNumAliveObjects() << endl;
    return 0;
}