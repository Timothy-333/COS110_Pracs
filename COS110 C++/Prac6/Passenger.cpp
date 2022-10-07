//The Passenger implementation file
#include "Passenger.h"
Passenger::Passenger(std::string id, double weight, double ticketPrice)
{
    this->ID = id;
    this->weight = weight;
    this->ticketPrice = ticketPrice;
}
std::string Passenger::describe()
{
    std::stringstream ss;
    ss << ID << " <" << ticketPrice << "> (" << weight << ")";
    return ss.str();
}
double Passenger::getWeight() const
{
    return weight;
}
double Passenger::getValue() const
{
    return ticketPrice;
}