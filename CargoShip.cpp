#include "CargoShip.h"
#include <stdexcept>
#include <string>
#include "CargoShip.h"

CargoShip::CargoShip(const std::string& name, std::string& homePort, int enginePower, int displacement,
    int numberOfCrew, int loadCapacity) : BasicShip(name, homePort, enginePower, displacement, numberOfCrew),
    loadCapacity(loadCapacity) {
    if (loadCapacity <= 0)
        throw std::invalid_argument("���������������� �� ���� ���� �䒺���� ��� ��������!");
}

std::string CargoShip::Info() const {
    return ("��� �������: ���������;\n" + BasicShip::Info() + "���������������� � �����: " + std::to_string(loadCapacity) + ";\n");
}

void CargoShip::ChangeLoadCapacity(const int& loadCapacity) {
    this->loadCapacity = loadCapacity;
}


