//The Controller implementation file
#ifndef CONTROLLER_CPP
#define CONTROLLER_CPP
#include <string>
template <class T>
Controller<T>::Controller(Plane<T>* p)
{
    this->plane = p;
}
template <class T>
std::string Controller<T>::loadOnPlane(T* item)
{
    try
    {
        plane->add(item);
        return "Success";
    }
    catch (const AboveWeightEx e)
    {
        std::stringstream ss;
        ss << "Could not load item, above max weight by " << e.getDifference();
        return ss.str();
    }
}
template <class T>
double Controller<T>::getTotalValue()
{
    try
    {
        return plane->calculateValue();
    }
    catch (const UnauthorisedEx e)
    {
        return 0;
    }
    catch(const EmptyEx a)
    {
        return 0;
    } 
    catch (const UndervaluedEx<T> ua)
    {

        plane->remove(ua.getUndervalued());
        return ua.getSum();
    }
}
template <class T>
std::string Controller<T>::getPlaneContents()
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