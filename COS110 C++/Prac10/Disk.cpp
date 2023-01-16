#include "Disk.h"
template <class T>
Disk<T>::Disk(T label)
{
    this->label = label;
}
template <class T>
const T Disk<T>::getLabel()
{
    return label;
}