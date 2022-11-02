#ifndef STACK_H
#define STACK_H
#include "Node.h"
template <class T>
class Stack
{
private:
    Node<T>* top;
public:
    Stack();
    ~Stack();
    void push(T);
    Node<T>* pop();
    bool isEmpty();
    Node<T>* getTop();
    int size();
    Stack<T>* reverse();
    bool contains(T);
};
#endif 