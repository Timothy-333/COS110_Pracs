//The SecretCargo implementation file
#include "SecretCargo.h"
SecretCargo::SecretCargo(double w)
{
    this->weight = w;
}
double SecretCargo::getWeight() const
{
    return weight;
}