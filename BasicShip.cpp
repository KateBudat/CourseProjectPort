#include "BasicShip.h"

BasicShip::BasicShip(const std::string& name, const std::string& homePort, int enginePower, int displacement, int numberOfCrew):
        name(name), homePort(homePort), enginePower(enginePower),
        displacement(displacement), numberOfCrew(numberOfCrew) {
    if (enginePower <= 0)
        throw std::invalid_argument("Engine power can't be negative or zero!");
    if (displacement <= 0)
        throw std::invalid_argument("Displacement can't be negative or zero!");
    if (numberOfCrew <= 0)
        throw std::invalid_argument("Number of crew can't be negative or zero!");
}

std::string BasicShip::Info() const {
    return ("Назва корабля: " + name + ";\n" + "Назва порту приписки: " + homePort + ";\n" +
            "Потужність двигуна: " + std::to_string(enginePower) + ";\n" + "Водотоннажність: " + std::to_string(displacement) + ";\n" +
            "Чисельність екіпажу: " + std::to_string(numberOfCrew)  + ";\n");
}




