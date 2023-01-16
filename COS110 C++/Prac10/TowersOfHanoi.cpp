#include "TowersOfHanoi.h"
template <class T>
TowersOfHanoi<T>::TowersOfHanoi()
{
}
template <class T>
TowersOfHanoi<T>::TowersOfHanoi(int startTower, int goalTower)
{
    this->startTower = startTower;
    this->goalTower = goalTower;
    t1 = new std::stack<Disk<T>>();
    t2 = new std::stack<Disk<T>>();
    t3 = new std::stack<Disk<T>>();
}
template <class T>
TowersOfHanoi<T>::~TowersOfHanoi()
{
}
template <class T>
void TowersOfHanoi<T>::moveDisk(int dep, int dest)
{
    if(dep > 3 || dest > 3 || dep < 1 || dest < 1 || dep == dest)
    {
        throw Exception<T>::incorrectDiskMove(dep, dest);
    }
    if (dep == 1)
    {
        if(t1->top() == NULL)
        {
            throw Exception<T>::emptyStack(dep);
        }
        if (dest == 2 &&)
        {
            if (t1->top().getLabel() < t2->top().getLabel())
            {
                t2->push(t1->top());
                t1->pop();
            }
            else
            {
                throw Exception<T>::incorrectDiskMove(dep, dest);
            }
        }
        else if (dest == 3)
        {
            if (t1->top().getLabel() < t3->top().getLabel())
            {
                t3->push(t1->top());
                t1->pop();
            }
            else
            {
                throw Exception<T>::incorrectDiskMove(dep, dest);
            }
        }
    }
    else if (dep == 2)
    {
        if(t2->top() == NULL)
        {
            throw Exception<T>::emptyStack(dep);
        }
        if (dest == 1)
        {
            if (t2->top().getLabel() < t1->top().getLabel())
            {
                t1->push(t2->top());
                t2->pop();
            }
            else
            {
                throw Exception<T>::incorrectDiskMove(dep, dest);
            }
        }
        else if (dest == 3)
        {
            if (t2->top().getLabel() < t3->top().getLabel())
            {
                t3->push(t2->top());
                t2->pop();
            }
            else
            {
                throw Exception<T>::incorrectDiskMove(dep, dest);
            }
        }
    }
    else if (dep == 3)
    {
        if(t3->top() == NULL)
        {
            throw Exception<T>::emptyStack(dep);
        }
        if (dest == 1)
        {
            if (t3->top().getLabel() < t1->top().getLabel())
            {
                t1->push(t3->top());
                t3->pop();
            }
            else
            {
                throw Exception<T>::incorrectDiskMove(dep, dest);
            }
        }
        else if (dest == 2)
        {
            if (t3->top().getLabel() < t2->top().getLabel())
            {
                t2->push(t3->top());
                t3->pop();
            }
            else
            {
                throw Exception<T>::incorrectDiskMove(dep, dest);
            }
        }
    }
    Exception<T>::movePlan(dest->top(), dep, dest);
}
template <class T>
void TowersOfHanoi<T>::addDisk(T diskData, int tower)
{
    Disk<T> disk(diskData);
    switch (tower)
    {
    case 1:
        if(disk.getLabel < t1->top().getLabel())
        {
            t1->push(disk);
        }
        else
        {
            Exception<T>::invalidTower(tower);
        }
        break;
    case 2:
        if(disk.getLabel < t2->top().getLabel())
        {
            t2->push(disk);
        }
        else
        {
            Exception<T>::invalidTower(tower);
        }
        break;
    case 3:
        if(disk.getLabel < t3->top().getLabel())
        {
            t3->push(disk);
        }
        else
        {
            Exception<T>::invalidTower(tower);
        }
        break;
    default:
        break;
    }
}
template <class T>
bool TowersOfHanoi<T>::validateGame()
{
    if(!t1->empty() && goalTower == 1 && t2->empty() && t3->empty())
    {
        return true;
    }
    else if(!t2->empty() && goalTower == 2 && t1->empty() && t3->empty())
    {
        return true;
    }
    else if(!t3->empty() && goalTower == 3 && t1->empty() && t2->empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <class T>
std::stack<Disk<T>> TowersOfHanoi<T>::getTower(int tower)
{
    switch (tower)
    {
    case 1:
        return *t1;
    case 2:
        return *t2;
    case 3:
        return *t3;
    default:
        throw Exception<T>::invalidTower(tower);
    }
}