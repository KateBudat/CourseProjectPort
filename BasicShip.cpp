#include <stdexcept>
#include <string>
#include "BasicShip.h"

BasicShip::BasicShip(const std::string& name, std::string& homePort, int enginePower, int displacement, int numberOfCrew):
        name(name), homePort(homePort), enginePower(enginePower),
        displacement(displacement), numberOfCrew(numberOfCrew) {
    if (enginePower <= 0)
        throw std::invalid_argument("Потужність двигуна не може бути від'ємною або нульовою!");
    if (displacement <= 0)
        throw std::invalid_argument("Водотоннажність не може бути негативним або нульовим!");
    if (numberOfCrew <= 0)
        throw std::invalid_argument("Кількість екіпажу не може бути від'ємною або нульовою!");

}

std::string BasicShip::GetName() const {
    return name;
}

int BasicShip::GetNumberOfCrew() const {
    return numberOfCrew;
}

std::string BasicShip::Info() const {
    return ("Назва корабля: " + name + ";\n" + "Порт приписки: " + homePort + ";\n" +
            "Потужність двигуна в кВт: " + std::to_string(enginePower) + ";\n" + "Водотоннажність в тоннах: " + std::to_string(displacement) + ";\n" +
            "Чисельність екіпажу: " + std::to_string(numberOfCrew)  + ";\n");
}

void BasicShip::ChangeHomePort(const std::string& homePort) {
    this->homePort = homePort;
}

void BasicShip::ChangeEnginePower(const int &enginePower) {
    this->enginePower = enginePower;
}

void BasicShip::ChangeDisplacement(const int &displacement) {
    this->displacement = displacement;
}

void BasicShip::ChangeNumberOfCrew(const int &numberOfCrew) {
    this->numberOfCrew = numberOfCrew;
}




