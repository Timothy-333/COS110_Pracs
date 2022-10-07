//The SecretCargo class
#ifndef SECRETCARGO_H
#define SECRETCARGO_H
#include <string>
#include <sstream>

class SecretCargo
{
    private:
    double weight;
    
    public:
    SecretCargo(double w);
    double getWeight() const;
    
};

#endif