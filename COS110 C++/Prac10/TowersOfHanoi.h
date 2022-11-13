#ifndef TOH_H
#define TOH_H

#include <stack>

#include "Exception.h"
#include "Disk.h"
template <class T>
class TowersOfHanoi
{
private:
    std::stack<Disk<T>>* t1;
    std::stack<Disk<T>>* t2;
    std::stack<Disk<T>>* t3;
    int startTower;
    int goalTower;
public:
    TowersOfHanoi();
    TowersOfHanoi(int, int);
    ~TowersOfHanoi();
    void addDisk(T, int);
    void moveDisk(int, int);
    bool validateGame();
    std::stack<Disk<T>> getTower(int);
    virtual void solveGame() = 0;
};

#endif