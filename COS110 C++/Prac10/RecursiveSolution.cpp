#include "RecursiveSolution.h"
template <class T>
RecursiveSolution<T>::RecursiveSolution(int startTower, int goalTower):TowersOfHanoi<T>(startTower, goalTower)
{
    
}
template <class T>
void RecursiveSolution<T>::solveGame()
{
    int n = count(startTower);
    moves(n, startTower, goalTower, spareTower);
}
template <class T>
int RecursiveSolution<T>::count(int tower)
{
    int n = 0;
    return n;
}
template <class T>
void RecursiveSolution<T>::solveGame()
{
    int n = count(startTower);
    moves(n, startTower, goalTower, spareTower);
}
template <class T>
bool RecursiveSolution<T>::containsLabel(T label)
{
    bool contains = false;
    if(t1->top().getLabel() == label)
        contains = true;
    else if(t2->top().getLabel() == label)
        contains = true;
    else if(t3->top().getLabel() == label)
        contains = true;
    return contains;
}