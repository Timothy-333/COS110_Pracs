//The SecretCargo implementation file
#include "SecretCargo.h"
using namespace std;
SecretCargo::SecretCargo(double w)
{
    this->weight = w;
}
double SecretCargo::getWeight() const
{
    return weight;
}