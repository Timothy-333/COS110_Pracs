#include "Stack.h"
#include <cstddef>

template <class T>
Stack<T>::Stack()
{
    top = NULL;
}
template <class T>
Stack<T>::~Stack()
{
    while (!isEmpty())
    {
        pop();
    }
}
template <class T>
void Stack<T>::push(T data)
{
    Node<T>* newNode = new Node<T>(data);
    newNode->setNext(top);
    top = newNode;
}
template <class T>
Node<T>* Stack<T>::pop()
{
    if (isEmpty())
    {
        return NULL;
    }
    else
    {
        Node<T>* temp = top;
        top = top->getNext();
        return temp;
    }
}
template <class T>
bool Stack<T>::isEmpty()
{
    return top == NULL;
}
template <class T>
Node<T>* Stack<T>::getTop()
{
    if(isEmpty())
    {
        return NULL;
    }
    else
    {
        return top;
    }
}
template <class T>
int Stack<T>::size()
{
    int count = 0;
    Node<T>* temp = top;
    while (temp != NULL)
    {
        count++;
        temp = temp->getNext();
    }
    return count;
}
template <class T>
Stack<T>* Stack<T>::reverse()
{
    Stack<T>* newStack = new Stack<T>();
    if (!isEmpty())
    {
        Node<T>* temp = top;
        while (temp != NULL)
        {
            newStack->push(temp->getData());
            temp = temp->getNext();
        }
    }
    return newStack;
}
template <class T>
bool Stack<T>::contains(T data)
{
    Node<T>* temp = top;
    while (temp != NULL)
    {
        if (temp->getData() == data)
        {
            return true;
        }
        temp = temp->getNext();
    }
    return false;
}