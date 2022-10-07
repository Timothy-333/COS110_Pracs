//The Plane implementation file
#ifndef PLANE_CPP
#define PLANE_CPP
#include <string>
#include <iostream>
using namespace std;
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
    int pos = 0;
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
                pos = i;
                found = true;
                break;
            }
        }
    }
    if (!found)
    {
        throw NotFoundEx<T>(item);
    }
    else
    {
        cargo.erase(cargo.begin() + pos);
    }
}
template <class T>
string Plane<T>::getDescription()
{
    if (cargo.size() == 0)
    {
        throw EmptyEx();
    }
    else
    {
        string output;
        for (int i = 0; i < cargo.size(); i++)
        {
            output += cargo[i]->describe();
            if (i+1 != cargo.size())
            {
                output += "\n";
            }
        }
    return output;
    }
}
template <>
string Plane<SecretCargo>::getDescription()
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
    // else
    // {
    //     double leastValuable = 99999;
    //     int leastindex = 0;
    //     double secondLeastValuable = 9999999;
    //     double totalValue = 0;
    //     for (int i = 0; i < cargo.size(); i++)
    //     {
    //         if (cargo[i]->getValue() < leastValuable)
    //         {
    //             leastValuable = cargo[i]->getValue();
    //             leastindex = i;
    //         }
    //         if (cargo[i]->getValue() < secondLeastValuable && cargo[i]->getValue() > leastValuable)
    //         {
    //             secondLeastValuable = cargo[i]->getValue();
    //         }
    //         totalValue += cargo[i]->getValue();
    //     }
    //     if (leastValuable < secondLeastValuable/2.0)
    //         throw UndervaluedEx<T>(cargo[leastindex], (totalValue-leastValuable));
        
    //     return totalValue;
    // }
    double totalVal = 0;
    vector<double> temp;
    for(int i = 0; i < cargo.size(); i++)
    {
        temp.push_back(cargo[i]->getValue());
        totalVal += cargo[i]->getValue();
    }  
    int index;
    for (int i = 0; i < cargo.size()-1; i++)
    {
        for (int j = 0; j < cargo.size() - i - 1; j++)
        {   
            if (temp[j] > temp[j + 1])
            {
                double smallest = temp[j+1];
                temp[j+1] = temp[j];
                temp[j] = smallest;
            }
        }
    }
    for (int i = 0; i < cargo.size(); i++)
    {
        if (temp[0] == cargo[i]->getValue())
        {
            index = i;
        }
    }
    if (temp[0] < temp[1]/2)
    {
        throw UndervaluedEx<T>(cargo[index], totalVal - cargo[index]->getValue());
    }
    else
    {
        return totalVal;
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