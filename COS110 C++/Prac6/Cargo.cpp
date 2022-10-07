//The Cargo implementation file
#include "Cargo.h"
using namespace std;
Cargo::Cargo(double w, double ppw)
{
    this->weight = w;
    value = w * ppw;
}
string Cargo::describe()
{
    string a, b;
    string output;
    stringstream ss1,ss2;
    ss1 << value;
    ss2 << weight;
    ss1 >> a;
    ss2 >> b;
    output = "Generic cargo <" + a + "> (" + b + ")";
    return output;
}
double Cargo::getWeight() const
{
    return weight;
}
double Cargo::getValue() const
{
    return value;
}