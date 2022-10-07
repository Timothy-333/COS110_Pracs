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
    AboveWeightEx(double wd);
    double getDifference() const;

};

class EmptyEx
{

};

class UnauthorisedEx
{

};

template <typename E>
class UndervaluedEx
{
    private:
    E* underVal;
    double sum;

    public:
    UndervaluedEx(E* uv, double s);
    E* getUndervalued() const;
    double getSum() const;

};

template <typename E>
class NotFoundEx
{
    private:
    E* missing;

    public:
    NotFoundEx(E* nf);
    E* getNotFound() const;

};
#include "Exceptions.cpp"
#endif