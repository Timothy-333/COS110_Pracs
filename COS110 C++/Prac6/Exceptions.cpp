//Exception implementations
#ifndef EXCEPTIONS_CPP
#define EXCEPTIONS_CPP
AboveWeightEx::AboveWeightEx(double wd)
{
    weightDiff = wd;
}
double AboveWeightEx::getDifference() const
{
    return weightDiff;
}
template <class E>
UndervaluedEx<E>::UndervaluedEx(E* uv, double s)
{
    UnderVal = uv;
    sum = s;
}
template <class E>
E* UndervaluedEx<E>::getUndervalued() const
{
    return UnderVal;
}
template <class E>
double UndervaluedEx<E>::getSum() const
{
    return sum;
}
template <class E>
NotFoundEx<E>::NotFoundEx(E* nf)
{
    missing = nf;
}
template <class E>
E* NotFoundEx<E>::getNotFound() const
{
    return missing;
}
#endif
