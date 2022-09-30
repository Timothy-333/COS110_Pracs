#ifndef NumberTester_h
#define NumberTester_h

class NumberTester
{
private:
    static int numAliveObjects;
public:
    NumberTester(/* args */);
    ~NumberTester();
    virtual bool evaluate(int)=0;
    virtual NumberTester* clone()=0;
    static int getNumAliveObjects();
};
#endif