
#include "TesterInterface.h"
TesterInterface::TesterInterface(int maxNumTests)
{
    if(maxNumTests > 0)
    {
        this->maxNumTesters = maxNumTests;
    }
    else
    {
        this->maxNumTesters = 0;
    }
    testers = new NumberTester*[maxNumTests];
    for (int i = 0; i < maxNumTesters; i++)
    {
        testers[i] = nullptr;
    }
    currNumTesters = 0;
}
TesterInterface::TesterInterface(TesterInterface* other)
{
    if (other != nullptr)
    {
        this->maxNumTesters = other->maxNumTesters;
        this->currNumTesters = other->currNumTesters;
    }
    else
    {
        this->maxNumTesters = 0;
        this->currNumTesters = 0;
    }
    testers = new NumberTester*[maxNumTesters];
    for (int i = 0; i < maxNumTesters; i++)
    {
        this->testers[i] = other->testers[i]->clone();
    }
}
TesterInterface::TesterInterface(TesterInterface& other)
{
    this->maxNumTesters = other.maxNumTesters;
    this->currNumTesters = other.currNumTesters;
    testers = new NumberTester*[maxNumTesters];
    for (int i = 0; i < maxNumTesters; i++)
    {
        this->testers[i] = other.testers[i]->clone();
    }
}
TesterInterface::~TesterInterface()
{
    for (int i = 0; i < maxNumTesters; i++)
    {
        delete testers[i];
    }
    delete[] testers;
}
int TesterInterface::addTester(NumberTester* tester)
{
    if (tester != nullptr)
    {
        bool isFound = false;
        for (int i = 0; i < maxNumTesters; i++)
        {
            if (testers[i] == nullptr)
            {
                testers[i] = tester->clone();
                currNumTesters++;
                return 0;
            }
        }
    }
    return -1;
}
bool TesterInterface::removeTester(int index)
{
    if (index >= 0 && index < maxNumTesters)
    {
        if (testers[index] != nullptr)
        {
            delete testers[index];
            testers[index] = nullptr;
            currNumTesters--;
            return true;
        }
    }
    return false;
}
bool TesterInterface::evaluate(int value)
{
    if (testers == nullptr)
    {
        return false;
    }
    for (int i = 0; i < currNumTesters; i++)
    {
        if (testers[i] != nullptr)
        {
            if (testers[i]->evaluate(value) == false)
            {
                return false;
            }
        }
    }
    return true;
    
}
int* TesterInterface::failedTests(int value)
{
    int* failedTests = new int[currNumTesters];
    int count = 0;
    for (int i = 0; i < currNumTesters; i++)
    {
        if (testers[i] != nullptr)
        {
            if (testers[i]->evaluate(value) == false)
            {
                failedTests[count] = i;
                count++;
            }
        }
    }
    return failedTests;
}
int TesterInterface::numberOfFailedTests(int value)
{
    int count = 0;
    for (int i = 0; i < currNumTesters; i++)
    {
        if (testers[i] != nullptr)
        {
            if (testers[i]->evaluate(value) == false)
            {
                count++;
            }
        }
    }
    return count;
}
NumberTester* TesterInterface::operator[](int index)
{
    if (index >= 0 && index < maxNumTesters)
    {
        if (testers[index] != nullptr)
        {
            return testers[index];
        }
    }
    return nullptr;
}
const int TesterInterface::getCurrNumTesters()
{
    return currNumTesters;
}
const int TesterInterface::getMaxNumTesters()
{
    return maxNumTesters;
}

