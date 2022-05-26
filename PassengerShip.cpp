#include "PassengerShip.h"

PassengerShip::PassengerShip(const std::string &name, const std::string &homePort, int enginePower, int displacement,
                             int numberOfCrew, int numberOfPassengers, int numberOfBoats, int boatCapacity) :
        BasicShip(name, homePort, enginePower, displacement, numberOfCrew),
        numberOfPassengers(numberOfPassengers), numberOfBoats(numberOfBoats), boatCapacity(boatCapacity) {
    if (numberOfPassengers < 0)
        throw std::invalid_argument("numberOfPassengers can't be negative!");
    if (numberOfBoats < 0)
        throw std::invalid_argument("Number of boats can't be negative!");
    if (boatCapacity <= 0)
        throw std::invalid_argument("Boat capacity can't be negative or zero!");
}

int PassengerShip::GetFullBoatsCapacity() const {
    return (numberOfBoats * boatCapacity);
}

int PassengerShip::GetFullNumberOfPeople() const {
    return (numberOfPassengers + BasicShip::GetNumberOfCrew());
}

bool PassengerShip::isBoatsEnough() const {
    if (GetFullBoatsCapacity() < GetFullNumberOfPeople()) return false;
    return true;
}

void PassengerShip::addBoats() {
    while(!isBoatsEnough())
        numberOfBoats++;
}

std::string PassengerShip::Info() const {
    return (BasicShip::Info() + "Number of passengers: " + std::to_string(numberOfPassengers) +  ";\n" +
            "Number of boats: " + std::to_string(numberOfBoats) + ";\n" +
            "Boat's capacity: " + std::to_string(boatCapacity) + ";\n");
}


