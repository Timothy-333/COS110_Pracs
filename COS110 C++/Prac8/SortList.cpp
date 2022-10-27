#include <sstream>
#include <iostream>
using namespace std;
template<class T>
SortList<T>::SortList(bool asc)
{
    ascending = asc;
    head = NULL;
    tail = NULL;
}
template<class T>
void SortList<T>::add(SortNode<T>* a)
{
    if(head == NULL)
    {
        head = a;
        tail = a;
    }
    else
    {
        tail->next = a;
        a->prev = tail;
        tail = a;
    }
}
template<class T>
SortNode<T>* SortList<T>::remove(T val)
{
    SortNode<T>* temp = NULL;
    SortNode<T>* nodePtr = NULL;
    if(head != NULL)
    {
        SortNode<T>* nodePtr = head;
        while (val != nodePtr->getValue() && nodePtr->next != NULL)
        {   
            nodePtr->prev = nodePtr;
            nodePtr = nodePtr->next;
        }
        temp = nodePtr;
        nodePtr->prev->next = nodePtr->next;
        nodePtr->next->prev = nodePtr->prev;
        delete nodePtr;
    }

    return temp;
}
template<class T>
void SortList<T>::setAsc(bool a)
{
    if (a != ascending)
    {
        if(head != NULL)
        {   
            SortNode<T>* temp = NULL;
            SortNode<T>* nodePtr = head;
            while (nodePtr->next != NULL)
            {
                temp = nodePtr->next;
                nodePtr->next = nodePtr->prev;
                nodePtr->prev = temp;
                nodePtr = temp;
            }
            temp = head;
            head = tail;
            tail = temp;
        }
    }
}
template<class T>
void SortList<T>::sort()
{
    if(head != NULL && head->next !=NULL)
    {
        SortNode<T>* nodePtr = head;
        SortNode<T>* prevNode = NULL;
        if(ascending)
        {
            for (int i = 0; i < 5; i++)
            {                
                nodePtr = head->next;
                prevNode = head;
                for (int j = 0; j < 5-i-1; j++)
                {           
                    if(prevNode->getValue() > nodePtr->getValue())
                    {
                        nodePtr->next->prev = prevNode;
                        prevNode->prev->next = nodePtr;
                        prevNode->next = nodePtr->next;
                        nodePtr->next = prevNode;
                        nodePtr->prev = prevNode->prev;
                        prevNode->prev = nodePtr;
                        nodePtr = prevNode->next;
                    }
                    else
                    {
                        prevNode = nodePtr;
                        nodePtr = nodePtr->next;
                    }
                    debug();
                }
                debug();
            }
        }
        else
        {
            // while (nodePtr->next != NULL && nodePtr->getValue() > nodePtr->next->getValue())
            // {   
            //     // nodePtr->prev->next = nodePtr->next;
            //     // nodePtr->prev = nodePtr->next;
            //     // nodePtr->next = nodePtr->next->next;
            //     // nodePtr->next->prev = nodePtr->prev;
            //     // nodePtr->next->next = nodePtr->next;
            //     nodePtr = nodePtr->next;
            // }
        }
    }
}
template<class T>
string SortList<T>::print()
{
    string result = "";
    if(head != NULL)
    {
        SortNode<T>* nodePtr = head;
        while (nodePtr->next != NULL)
        {
            result += nodePtr->print() + ",";
            nodePtr = nodePtr->next;
        }
        result += nodePtr->print() + "\n";
    }
    return result;
}
template <class T>
SortNode<T>* SortList<T>::getHead()
{
    return head;
}
template <class T>
string SortList<T>::debug()
{
    cout<<print()<<endl;
    return "aaaaa";
}

