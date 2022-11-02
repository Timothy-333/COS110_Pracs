#include "Node.h"
#include <cstddef>
template <class T>
Node<T>::Node(T val)
{
    data = val;
    next = NULL;
}
template <class T>
T Node<T>::getData()
{
    return data;
}
template <class T>
Node<T>* Node<T>::getNext()
{
    return next;
}
template <class T>
void Node<T>::setNext(Node<T>* n)
{
    next = n;
}