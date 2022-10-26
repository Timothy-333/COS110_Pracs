#ifndef DLL_H
#define DLL_H

#include "SortNode.h"
template<class T>
class SortList
{
private:
    bool ascending;
    SortNode<T>* head;
    SortNode<T>* tail;
public:
    SortList(bool);
    void add(SortNode<T>*);
    SortNode<T>* remove(T);
    void sort();
    string print();
    SortNode<T>* getHead();
    void setAsc(bool);
    std::string debug();
};



#include "SortList.cpp"

#endif
