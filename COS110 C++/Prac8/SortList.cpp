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
    SortNode<T>* nodePtr = NULL;
    if(head != NULL)
    {
        nodePtr = head;
        while (nodePtr != NULL && val != nodePtr->getValue())
        {   
            nodePtr = nodePtr->next;
        }
        if(nodePtr != NULL)
        {
            if(nodePtr->prev != NULL)
            {
                nodePtr->prev->next = nodePtr->next;
            }
            else
            {
                head = nodePtr->next;
            }
            if(nodePtr->next != NULL)
            {
                nodePtr->next->prev = nodePtr->prev;
            }
            else
            {
                tail = nodePtr->prev;
            }
        }
    }

    return nodePtr;
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
            while (nodePtr != NULL)
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
    ascending = a;
}
template<class T>
void SortList<T>::sort()
{
    if(head != NULL && head->next !=NULL)
    {
        SortNode<T>* nodePtr = head;
        SortNode<T>* prevNode = NULL;
        int size = 0;
        while (nodePtr != NULL)
        {
            size++;
            nodePtr = nodePtr->next;
        }
        if(ascending)
        {
            for (int i = 0; i < size; i++)
            {                
                nodePtr = head->next;
                prevNode = head;
                for(int j = 0; j < size-i-1;j++)
                {           
                    if(prevNode->getValue() > nodePtr->getValue())
                    {
                        if(nodePtr->next != NULL)
                        {
                            nodePtr->next->prev = prevNode;
                            prevNode->next = nodePtr->next;
                        }
                        else
                        {
                            tail = prevNode;
                            prevNode->next = NULL;
                        }
                        nodePtr->next = prevNode;
                        if(prevNode->prev == NULL)
                        {
                            head = nodePtr;
                            nodePtr->prev = NULL;
                        }
                        else
                        {
                            prevNode->prev->next = nodePtr;
                            nodePtr->prev = prevNode->prev;
                        }
                        prevNode->prev = nodePtr;
                        nodePtr = prevNode->next;
                    }
                    else
                    {
                        prevNode = nodePtr;
                        nodePtr = nodePtr->next;
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < size; i++)
            {                
                nodePtr = head->next;
                prevNode = head;
                for(int j = 0; j < size-i-1;j++)
                {           
                    if(prevNode->getValue() <= nodePtr->getValue())
                    {
                        if(nodePtr->next != NULL)
                        {
                            nodePtr->next->prev = prevNode;
                            prevNode->next = nodePtr->next;
                        }
                        else
                        {
                            tail = prevNode;
                            prevNode->next = NULL;
                        }
                        nodePtr->next = prevNode;
                        if(prevNode->prev == NULL)
                        {
                            head = nodePtr;
                            nodePtr->prev = NULL;
                        }
                        else
                        {
                            prevNode->prev->next = nodePtr;
                            nodePtr->prev = prevNode->prev;
                        }
                        prevNode->prev = nodePtr;
                        nodePtr = prevNode->next;
                    }
                    else
                    {
                        prevNode = nodePtr;
                        nodePtr = nodePtr->next;
                    }
                }
            }
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
        result += nodePtr->print();
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

