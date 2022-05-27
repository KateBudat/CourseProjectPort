#include "PassengerShip.h"

PassengerShip::PassengerShip(const std::string &name, const std::string &homePort, int enginePower, int displacement,
                             int numberOfCrew, int numberOfPassengers, int numberOfBoats, int boatCapacity) :
        BasicShip(name, homePort, enginePower, displacement, numberOfCrew),
        numberOfPassengers(numberOfPassengers), numberOfBoats(numberOfBoats), boatCapacity(boatCapacity) {
    if (numberOfPassengers < 0)
        throw std::invalid_argument("Кількість пасажирів не може бути від’ємною!");
    if (numberOfBoats < 0)
        throw std::invalid_argument("Кількість човнів не може бути від’ємною!");
    if (boatCapacity <= 0)
        throw std::invalid_argument("Місткість човна не може бути від’ємною або нульовою!");
}

int PassengerShip::GetFullBoatsCapacity() const {
    return (numberOfBoats * boatCapacity);
}

int PassengerShip::GetFullNumberOfPeople() const {
    return (numberOfPassengers + GetNumberOfCrew());
}

bool PassengerShip::isBoatsEnough() const {
    return (GetFullBoatsCapacity() > GetFullNumberOfPeople());
}

void PassengerShip::addBoats() {
    while(!isBoatsEnough())
        numberOfBoats++;
}

std::string PassengerShip::Info() const {
    return (BasicShip::Info() + "Кількість пасажирів: " + std::to_string(numberOfPassengers) +  ";\n" +
            "Кількість човнів: " + std::to_string(numberOfBoats) + ";\n" +
            "Місткість човна: " + std::to_string(boatCapacity) + ";\n");
}


