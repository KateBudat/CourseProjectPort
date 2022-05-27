#include "CargoShip.h"

CargoShip::CargoShip(const std::string &name, const std::string &homePort, int enginePower, int displacement,
                     int numberOfCrew, int loadCapacity) : BasicShip(name, homePort, enginePower, displacement, numberOfCrew),
                     loadCapacity(loadCapacity) {
    if (loadCapacity <= 0)
        throw std::invalid_argument("Вантажопідйомність не може бути від’ємною або нульовою!");
}

std::string CargoShip::Info() const {
    return (BasicShip::Info() + "Вантажопідйомність в тонах: " + std::to_string(loadCapacity) + ";\n");
}


