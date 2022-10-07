//The Controller class
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Plane.h"
#include "Passenger.h"
#include "Cargo.h"
#include <string>

using namespace std;

//See spec for inclusion strategy for templates

template <typename T>
class Controller
{
    private:
    Plane<T>* plane;

    public:
    Controller(Plane<T>* p);
    string loadOnPlane(T* t);
    double getTotalValue();
    string getPlaneContents();

};

#include "Controller.cpp"
#endif