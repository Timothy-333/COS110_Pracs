//The Plane class
#ifndef PLANE_H
#define PLANE_H
#include <vector>
#include "Exceptions.h"
#include "SecretCargo.h"

using namespace std;

//See spec on inclusion strategy for templates

template <typename T>
class Plane 
{
    private:
    vector<T*> cargo;
    double maxWeight;

    public:
    Plane(double max);
    ~Plane();
    void add(T* item);
    void remove(T* item);
    string getDescription();
    double calculateValue();

};

#include "Plane.cpp"
#endif