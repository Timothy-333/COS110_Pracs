//File for all exception definitions
//See spec for inclusion strategy
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <sstream>
class AboveWeightEx
{
private:
    double weightDiff;
public:
    AboveWeightEx(double);
    double getDifference() const;
};

class EmptyEx
{
};

class UnauthorisedEx
{
};

template <class E>
class UndervaluedEx
{
private:
    E* UnderVal;
    double sum;
public:
    UndervaluedEx(E*, double);
    E* getUndervalued() const;
    double getSum() const;
};

template <class E>
class NotFoundEx
{
private:
    E* missing;
public:
    NotFoundEx(E*);
    E* getNotFound() const;
};
#include "Exceptions.cpp"
#endif