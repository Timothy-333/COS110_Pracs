#ifndef OPERATOR_H
#define OPERATOR_H
template <class T>
class Operator
{
public:
    Operator(/* args */);
    T operator()(T, T);
    virtual Operator<T>* clone() = 0;
    ~Operator();
};

#endif