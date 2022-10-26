#include <sstream>
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
        while (val != nodePtr->value && nodePtr->next != NULL)
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
    if(head != NULL)
    {
        SortNode<T>* nodePtr = head;
        int size = 0;
        while (nodePtr->next != NULL)
        {
            nodePtr = nodePtr->next;
            size++;
        }
        
        if(ascending)
        {
            for (int i = 0; i < size; i++)
            {
                while (nodePtr->getValue() < nodePtr->next->getValue() && nodePtr->next != NULL)
                {   
                    SortNode<T>* temp1 = new SortNode<T>(nodePtr->next->getValue());
                    SortNode<T>* temp2 = new SortNode<T>(nodePtr->getValue());
                    temp1->next = temp2;
                    temp1->prev = nodePtr->prev;
                    nodePtr->prev->next = temp1;
                    temp2->next = nodePtr->next->next;
                    temp2->prev = temp1;
                    nodePtr = temp2;
                }
            }
        }
        else
        {
            for (int i = 0; i < size; i++)
                {
                    while (nodePtr->getValue() > nodePtr->next->getValue() && nodePtr->next != NULL)
                {   
                    SortNode<T>* temp1 = new SortNode<T>(nodePtr->next->getValue());
                    SortNode<T>* temp2 = new SortNode<T>(nodePtr->getValue());
                    temp1->next = temp2;
                    temp1->prev = nodePtr->prev;
                    nodePtr->prev->next = temp1;
                    temp2->next = nodePtr->next->next;
                    temp2->prev = temp1;
                    nodePtr = temp2;
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
    return "";
}

