#ifndef NumberTester_h
#define NumberTester_h

static int numAliveObjects = 0;
class NumberTester
{
public:
    NumberTester(/* args */);
    ~NumberTester();
    virtual bool evaluate(int val);
};
#endif