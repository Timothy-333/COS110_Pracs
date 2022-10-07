//The Plane class
#ifndef PLANE_H
#define PLANE_H
#include <vector>
#include <string>
#include "Exceptions.h"
#include "SecretCargo.h"

//See spec on inclusion strategy for templates
template <class T>
class  Plane
{
private:
    std::vector<T*> cargo;
    double maxWeight;
public:
    Plane(double);
    ~Plane();
    void add(T*);
    void remove(T*);
    std::string getDescription();
    double calculateValue();
};
#include "Plane.cpp"
#endif
