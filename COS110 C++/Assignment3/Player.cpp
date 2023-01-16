#include "Player.h"

using namespace std;

Player::Player(int x, int y): Object(x, y)
{
    icon = '&';
}
void Player::move(int x, int y)
{
    if(x != 0 || y != 0)
    {
        Object* floorPtr = this;
        Object* temp = this->below;
        
        while(floorPtr->below != NULL)
            floorPtr = floorPtr->below;
        
        if(x == 1)
        {
            if(y == -1)
            {
                if(floorPtr->getNext(false) != NULL && floorPtr->getNext(false)->getPrev(true) != NULL)
                {
                    if (floorPtr->getNext(false)->getPrev(true)->isSolid())
                        {
                            string out = "Walked into something";
                            throw out;
                        }
                    floorPtr = floorPtr->getNext(false)->getPrev(true);
                    while(floorPtr->above != NULL)
                        floorPtr = floorPtr->above;
                    this->below = floorPtr;
                    floorPtr->above = this;
                }
                else if(floorPtr->getPrev(true) != NULL && floorPtr->getPrev(true)->getNext(false) != NULL)
                {
                    if (floorPtr->getPrev(true)->getNext(false)->isSolid())
                        throw "Walked into something";
                    floorPtr = floorPtr->getPrev(true)->getNext(false);
                    while(floorPtr->above != NULL)
                        floorPtr = floorPtr->above;
                    this->below = floorPtr;
                    floorPtr->above = this;
                }
                else
                {
                    string message = "Out of bounds";
                    throw message;
                }
                
            }
            else if(y == 1)
            {
                if (floorPtr->getNext(false) != NULL && floorPtr->getNext(false)->getNext(true) != NULL)
                {
                    if (floorPtr->getNext(false)->getNext(true)->isSolid())
                        throw "Walked into something";
                    floorPtr = floorPtr->getNext(false)->getNext(true);
                    while(floorPtr->above != NULL)
                        floorPtr = floorPtr->above;
                    this->below = floorPtr;
                    floorPtr->above = this;
                }
                else if (floorPtr->getNext(true) != NULL && floorPtr->getNext(true)->getNext(false) != NULL)
                {
                    if (floorPtr->getNext(true)->getNext(false)->isSolid())
                        throw "Walked into something";
                    floorPtr = floorPtr->getNext(true)->getNext(false);
                    while(floorPtr->above != NULL)
                        floorPtr = floorPtr->above;
                    this->below = floorPtr;
                    floorPtr->above = this;
                }
                else
                {
                    string message = "Out of bounds";
                    throw message;
                }
            }
            else
            {
                if (floorPtr->getNext(false) != NULL)
                {
                    if (floorPtr->getNext(false)->isSolid())
                        throw "Walked into something";
                    floorPtr = floorPtr->getNext(false);
                    while(floorPtr->above != NULL)
                        floorPtr = floorPtr->above;
                    this->below = floorPtr;
                    floorPtr->above = this;
                }
                else
                {
                    string message = "Out of bounds";
                    throw message;
                }
            }
        }
        else if(x == -1)
        {
            if(y == -1)
            {
                if (floorPtr->getPrev(false) != NULL && floorPtr->getPrev(false)->getPrev(true) != NULL)
                {
                    if (floorPtr->getPrev(false)->getPrev(true)->isSolid())
                        throw "Walked into something";
                    floorPtr = floorPtr->getPrev(false)->getPrev(true);
                    while(floorPtr->above != NULL)
                        floorPtr = floorPtr->above;
                    this->below = floorPtr;
                    floorPtr->above = this;
                }
                else if (floorPtr->getPrev(true) != NULL && floorPtr->getPrev(true)->getPrev(false) != NULL)
                {
                    if (floorPtr->getPrev(true)->getPrev(false)->isSolid())
                        throw "Walked into something";
                    floorPtr = floorPtr->getPrev(true)->getPrev(false);
                    while(floorPtr->above != NULL)
                        floorPtr = floorPtr->above;
                    this->below = floorPtr;
                    floorPtr->above = this;
                }
                else
                {
                    string message = "Out of bounds";
                    throw message;
                }
            }
            else if(y == 1)
            {
                if (floorPtr->getPrev(false) != NULL && floorPtr->getPrev(false)->getNext(true) != NULL)
                {
                    if (floorPtr->getPrev(false)->getNext(true)->isSolid())
                        throw "Walked into something";
                    floorPtr = floorPtr->getPrev(false)->getNext(true);
                    while(floorPtr->above != NULL)
                        floorPtr = floorPtr->above;
                    this->below = floorPtr;
                    floorPtr->above = this;
                }
                else if (floorPtr->getNext(true) != NULL && floorPtr->getNext(true)->getPrev(false) != NULL)
                {
                    if (floorPtr->getNext(true)->getPrev(false)->isSolid())
                        throw "Walked into something";
                    floorPtr = floorPtr->getNext(true)->getPrev(false);
                    while(floorPtr->above != NULL)
                        floorPtr = floorPtr->above;
                    this->below = floorPtr;
                    floorPtr->above = this;
                }
                else
                {
                    string message = "Out of bounds";
                    throw message;
                }
            }
            else
            {
                if (floorPtr->getPrev(false) != NULL)
                {
                    if (floorPtr->getPrev(false)->isSolid())
                        throw "Walked into something";
                    floorPtr = floorPtr->getPrev(false);
                    while(floorPtr->above != NULL)
                        floorPtr = floorPtr->above;
                    this->below = floorPtr;
                    floorPtr->above = this;
                }
                else
                {
                    string message = "Out of bounds";
                    throw message;
                }
            }
        }
        else
        {
            if(y == -1)
            {
                if (floorPtr->getPrev(true) != NULL)
                {
                    if (floorPtr->getPrev(true)->isSolid())
                        throw "Walked into something";
                    floorPtr = floorPtr->getPrev(true);
                    while(floorPtr->above != NULL)
                        floorPtr = floorPtr->above;
                    this->below = floorPtr;
                    floorPtr->above = this;
                }
                else
                {
                    string message = "Out of bounds";
                    throw message;
                }
            }
            else if(y == 1)
            {
                if (floorPtr->getNext(true) != NULL)
                {
                    if (floorPtr->getNext(true)->isSolid())
                        throw "Walked into something";
                    floorPtr = floorPtr->getNext(true);
                    while(floorPtr->above != NULL)
                        floorPtr = floorPtr->above;
                    this->below = floorPtr;
                    floorPtr->above = this;
                }
                else
                {
                    string message = "Out of bounds";
                    throw message;
                }
            }
        }
        if(this->below != temp)
            temp->above = NULL;
    }
}