//The Passenger class
#ifndef PASSENGER_H
#define PASSENGER_H
#include <sstream>
#include <string>

using namespace std;

class Passenger
{
    private: 
    string ID; //ID of passenger
    double weight; //weight of passenger
    double ticketPrice; //price paid for ticket

    public: 
    Passenger(string id, double w, double t);
    string describe();
    double getWeight() const;
    double getValue() const;

};

#endif