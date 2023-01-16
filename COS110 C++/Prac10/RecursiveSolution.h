#ifndef RS_H
#define RS_H

#include <stack>

#include "TowersOfHanoi.h"
#include "Disk.h"
template <class T>
class RecursiveSolution: public TowersOfHanoi<T>
{
public:
    RecursiveSolution(int,int);
    void solveGame();
    int count(int);
    bool containsLabel(T);
    ~RecursiveSolution();
};



#endif