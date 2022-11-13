#include "IterativeSolution.h"
template <class T>
IterativeSolution<T>::IterativeSolution(int startTower, int goalTower): TowersOfHanoi<T>(startTower, goalTower)
{
}
template <class T>
void IterativeSolution<T>::solveGame()
{
    int n = 0;
    if(startTower == 1)
        n = t1->size();
    else if(startTower == 2)
        n = t2->size();
    else if(startTower == 3)
        n = t3->size();

    int start = this->startTower;
    int goal = this->goalTower;
    int temp = 6 - start - goal;
    int moves = n*n - 1;
    for (int i = 1; i <= moves; i++)
    {
        if (i % 3 == 1)
        {
            try
            {
                this->moveDisk(start, goal);
            }
            catch (Exception<T> e)
            {
                throw e;
            }
        }
        else if (i % 3 == 2)
        {
            try
            {
                this->moveDisk(start, temp);
            }
            catch (Exception<T> e)
            {
                throw e;
            }
        }
        else if (i % 3 == 0)
        {
            try
            {
                this->moveDisk(temp, goal);
            }
            catch (Exception<T> e)
            {
                throw e;
            }
        }
    }
    if(!this->validateGame())
    {
        Extention<T>::invalidGame();
    }
}
template <class T>
void IterativeSolution<T>::moves(int numMoves)
{
    if(numMoves < 0)
    {
        throw Exception<T>::InvalidMoves(numMoves);
    }
    int start = this->startTower;
    int goal = this->goalTower;
    int temp = 6 - start - goal;
    int moves = numMoves;
    for (int i = 1; i <= moves; i++)
    {
        if (i % 3 == 1)
        {
            this->moveDisk(start, goal);
        }
        else if (i % 3 == 2)
        {
            this->moveDisk(start, temp);
        }
        else if (i % 3 == 0)
        {
            this->moveDisk(temp, goal);
        }
    }
    if(!this->validateGame())
    {
        throw Exception<T>::invalidGame();
    }
}