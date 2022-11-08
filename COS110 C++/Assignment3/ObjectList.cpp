#include "ObjectList.h"

using namespace std;

ObjectList::ObjectList(bool dim)
{
    dimension = dim;
    head = NULL;
    current = NULL;
}
void ObjectList::add(Object* obj)
{
    if(head == NULL)
    {
        head = obj;
        current = obj;
    }
    else
    {
        Object* nodePtr = head;
        Object* prevNode = NULL;
        while(nodePtr != NULL && nodePtr->getCoord(dimension) < obj->getCoord(dimension))
        {
            prevNode = nodePtr;
            nodePtr = nodePtr->getNext(dimension);
        }
        if(prevNode == NULL)
        {
            head = obj;
            obj->setNext(nodePtr, dimension);
            nodePtr->setPrev(obj, dimension);
        }
        else
        {
            prevNode->setNext(obj, dimension);
            obj->setNext(nodePtr, dimension);
            obj->setPrev(prevNode,dimension);
            if(nodePtr != NULL)
                nodePtr->setPrev(obj, dimension);
        }
    }
}
Object* ObjectList::getHead()
{
    return head;
}
string ObjectList::print()
{
    string output = "";
    Object* nodePtr = head;
    while(nodePtr != NULL)
    {
        output += nodePtr->getIcon();
        nodePtr = nodePtr->getNext(dimension);
    }
    return output;
}
Object* ObjectList::iterate()
{
    if(current == NULL)
        return NULL;
    Object* temp = current;
    current = current->getNext(dimension);
    return temp;
}
void ObjectList::reset()
{
    current = head;
}
string ObjectList::debug()
{
    stringstream ss;
    ss << "Forward:\n";
    string output = "";
    Object* nodePtr = head;
    Object* lastNode = head;
    while(nodePtr != NULL)
    {
        ss << "<" << nodePtr->getIcon() << "> at (" << nodePtr->getCoord(false) << "," << nodePtr->getCoord(true) << ") ";
        if(nodePtr->above != NULL)
            ss << "Top: N" << endl;
        else
        {
            ss << "Top: Y" << endl;
        }
        if(nodePtr->getNext(dimension) == NULL)
            lastNode = nodePtr;
        nodePtr = nodePtr->getNext(dimension);
    }
    nodePtr = lastNode;
    ss << "Back:\n";
    while (nodePtr != NULL)
    {
        ss << "<" << nodePtr->getIcon() << "> at (" << nodePtr->getCoord(false) << "," << nodePtr->getCoord(true) << ") ";
        if(nodePtr->above != NULL)
            ss << "Top: N" << endl;
        else
        {
            ss << "Top: Y" << endl;
        }
        nodePtr = nodePtr->getPrev(dimension);
    }
    output += ss.str();
    return output;
}