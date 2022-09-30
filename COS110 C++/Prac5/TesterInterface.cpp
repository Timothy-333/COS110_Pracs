#include "TesterInterface.h"
TesterInterface::TesterInterface(int maxNumTests)
{
    if(maxNumTests >= 1)
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
        testers[i] = NULL;
    }
    currNumTesters = 0;
}
TesterInterface::TesterInterface(TesterInterface* other)
{
    if (other != NULL)
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
        if (other->testers[i] != NULL)
        {
            this->testers[i] = other->testers[i]->clone();
        }
        else
            this->testers[i] = NULL;
    }
}
TesterInterface::TesterInterface(TesterInterface& other)
{
    if (&other != NULL)
    {
        this->maxNumTesters = other.maxNumTesters;
        this->currNumTesters = other.currNumTesters;
    }
    else
    {
        this->maxNumTesters = 0;
        this->currNumTesters = 0;
    }
    testers = new NumberTester*[maxNumTesters];
    for (int i = 0; i < maxNumTesters; i++)
    {
        if (other.testers[i] != NULL)
        {
            this->testers[i] = other.testers[i]->clone();
        }
        else
            this->testers[i] = NULL;
    }
}
TesterInterface::~TesterInterface()
{
    for (int i = 0; i < maxNumTesters; i++)
    {
        if (testers[i] != NULL)
        {
            delete testers[i];
        }
    }
    delete[] testers;
}
int TesterInterface::addTester(NumberTester* tester)
{
    if (tester == NULL || currNumTesters >= maxNumTesters)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < maxNumTesters; i++)
        {
            if (testers[i] == NULL)
            {
                testers[i] = tester->clone();
                currNumTesters++;
                return i;
            }
        }
    }
    return -1;
}
bool TesterInterface::removeTester(int index)
{
    if (index >= 0 && index < maxNumTesters)
    {
        if (testers[index] != NULL)
        {
            delete testers[index];
            testers[index] = NULL;
            currNumTesters--;
            return true;
        }
    }
    return false;
}
bool TesterInterface::evaluate(int value)
{
    if (testers == NULL || currNumTesters == 0)
    {
        return false;
    }
    for (int i = 0; i < maxNumTesters; i++)
    {
        if (testers[i] != NULL)
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
    int count = 0;
    for (int i = 0; i < maxNumTesters; i++)
    {
        if (testers[i] != NULL)
        {
            if (testers[i]->evaluate(value) == false)
            {
                count++;
            }
        }
    }
    int* failedTests = new int[count];
    count = 0;
    for (int i = 0; i < maxNumTesters; i++)
    {
        if (testers[i] != NULL)
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
    for (int i = 0; i < maxNumTesters; i++)
    {
        if (testers[i] != NULL)
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
        if (testers[index] != NULL)
        {
            return testers[index];
        }
    }
    return NULL;
}
int TesterInterface::getCurrNumTesters()const
{
    return currNumTesters;
}
int TesterInterface::getMaxNumTesters()const 
{
    return maxNumTesters;
}

