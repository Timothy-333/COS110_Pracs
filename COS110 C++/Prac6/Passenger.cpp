//The Passenger implementation file
#include "Passenger.h"
using namespace std;
Passenger::Passenger(string id, double weight, double ticketPrice)
{
    this->ID = id;
    this->weight = weight;
    this->ticketPrice = ticketPrice;
}
string Passenger::describe()
{
    stringstream ss1,ss2,ss3;
    string id, ticket, w, output;
    ss1 << ID;
    ss2 << ticketPrice;
    ss3 << weight;
    ss1 >> id;
    ss2 >> ticket;
    ss3 >> w;
    output = id + " <" + ticket + "> " + "(" + w + ")";
    return output;
}
double Passenger::getWeight() const
{
    return weight;
}
double Passenger::getValue() const
{
    return ticketPrice;
}