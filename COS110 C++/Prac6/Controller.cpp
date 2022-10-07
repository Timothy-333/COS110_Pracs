//The Controller implementation file
#ifndef CONTROLLER_CPP
#define CONTROLLER_CPP
#include <string>
using namespace std;
template <class T>
Controller<T>::Controller(Plane<T>* p)
{
    this->plane = p;
}
template <class T>
string Controller<T>::loadOnPlane(T* item)
{
    try
    {
        plane->add(item);
        return "Success";
    }
    catch (const AboveWeightEx e)
    {
        string a, b;
        stringstream ss;
        ss << e.getDifference();
        ss >> a;
        b = "Could not load item, above max weight by " + a;
        return b;
    }
}
template <class T>
double Controller<T>::getTotalValue()
{
    try
    {
        return plane->calculateValue();
    }
    catch (const UndervaluedEx<T> ua)
    {
        plane->remove(ua.getUndervalued());
        return ua.getSum();
    }
    catch (const UnauthorisedEx e)
    {
        return 0;
    }
    catch(const EmptyEx a)
    {
        return 0;
    } 
}
template <class T>
string Controller<T>::getPlaneContents()
{
    try
    {
        return plane->getDescription();
    }
    catch (const EmptyEx e)
    {
        return "Nothing to report";
    }
    catch (const UnauthorisedEx e)
    {
        return "Not permitted";
    }
}
#endif