//The Plane implementation file
#ifndef PLANE_CPP
#define PLANE_CPP
#include <string>
template <class T>
Plane<T>::Plane(double max)
{
    maxWeight = max;
}
template <class T>
Plane<T>::~Plane()
{
    while (!cargo.empty())
    {
        cargo.pop_back();
    }
    cargo.clear();
}
template <class T>
void Plane<T>::add(T* item)
{
    double totalWeight = 0;
    for (int i = 0; i < cargo.size(); i++)
    {
        totalWeight += cargo[i]->getWeight();
    }
    if (totalWeight + item->getWeight() > maxWeight)
    {
        throw AboveWeightEx(totalWeight + item->getWeight() - maxWeight);
    }
    else
    {
        cargo.push_back(item);
    }
}
template <class T>
void Plane<T>::remove(T* item)
{
    bool found = false;
    if(cargo.size() == 0)
    {
        throw EmptyEx();
    }
    else
    {
        for (int i = 0; i < cargo.size(); i++)
        {
            if (cargo[i] == item)
            {
                cargo.erase(cargo.begin() + i);
                found = true;
                break;
            }
        }
    }
    if (!found)
    {
        throw NotFoundEx<T>(item);
    }
}
template <class T>
std::string Plane<T>::getDescription()
{
    if (cargo.size() == 0)
    {
        throw EmptyEx();
    }
    else
    {
        std::stringstream ss;
        for (int i = 0; i < cargo.size()-1; i++)
        {
            ss << cargo[i]->describe() << std::endl;
        }
        ss << cargo[cargo.size()-1]->describe();
        return ss.str();
    }
}
template <>
std::string Plane<SecretCargo>::getDescription()
{
    if (cargo.size() == 0)
    {
        throw EmptyEx();
    }
    else
    {
        throw UnauthorisedEx();
    }
    
}
template <class T>
double Plane<T>::calculateValue()
{
    if (cargo.size() == 0)
    {
        throw EmptyEx();
    }
    else
    {
        double leastValuable = 9999999;
        int leastindex = 0;
        double secondLeastValuable = 9999999;
        double totalValue = 0;
        for (int i = 0; i < cargo.size(); i++)
        {
            if (cargo[i]->getValue() < leastValuable)
            {
                leastValuable = cargo[i]->getValue();
                leastindex = i;
            }
            if (cargo[i]->getValue() < secondLeastValuable && cargo[i]->getValue() > leastValuable)
            {
                secondLeastValuable = cargo[i]->getValue();
            }
            totalValue += cargo[i]->getValue();
        }
        if (leastValuable < secondLeastValuable/2.0)
            throw UndervaluedEx<T>(cargo[leastindex], (totalValue-leastValuable));
        
        return totalValue;
    }
}
template <>
double Plane<SecretCargo>::calculateValue()
{
    if (cargo.size() == 0)
    {
        throw EmptyEx();
    }
    else
    {
        throw UnauthorisedEx();
    }
}
#endif