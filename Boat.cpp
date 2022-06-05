#include <stdexcept>
#include "Boat.h"

Boat::Boat(const int boatCapacity) : boatCapacity(boatCapacity) {
    if (boatCapacity <= 0)
        throw std::invalid_argument("Місткість човна не може бути нульвою або від'ємною!!");
    else if (boatCapacity > 150)
        throw std::invalid_argument("Місткість човна більша за 150 заборонена міжнародним кодексом!");
}

int Boat::GetBoatCapacity() const {
    return boatCapacity;
}

std::string Boat::GetBoatInfo() const {
    return ("Місткість човна: " + std::to_string(boatCapacity));
}
