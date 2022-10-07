//The Cargo implementation file
#include "Cargo.h"
Cargo::Cargo(double w, double ppw)
{
    this->weight = w;
    value = w * ppw;
}
std::string Cargo::describe()
{
    std::stringstream ss;
    ss << "Generic Cargo <" << value << "> (" << weight << ")";
    return ss.str();
}
double Cargo::getWeight() const
{
    return weight;
}
double Cargo::getValue() const
{
    return value;
}