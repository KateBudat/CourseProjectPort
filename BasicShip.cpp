#include <stdexcept>
#include <string>
#include "BasicShip.h"

BasicShip::BasicShip(const std::string& name, std::string& homePort, int enginePower, int displacement, int numberOfCrew) :
    name(name), homePort(homePort), enginePower(enginePower),
    displacement(displacement), numberOfCrew(numberOfCrew) {
    if (enginePower <= 0)
        throw std::invalid_argument("��������� ������� �� ���� ���� ��'����� ��� ��������!");
    if (displacement <= 0)
        throw std::invalid_argument("�������������� �� ���� ���� ���������� ��� ��������!");
    if (numberOfCrew <= 0)
        throw std::invalid_argument("ʳ������ ������ �� ���� ���� ��'����� ��� ��������!");

}

std::string BasicShip::GetName() const {
    return name;
}

int BasicShip::GetNumberOfCrew() const {
    return numberOfCrew;
}

std::string BasicShip::Info() const {
    return ("����� �������: " + name + ";\n" + "���� ��������: " + homePort + ";\n" +
        "��������� ������� � ���: " + std::to_string(enginePower) + ";\n" + "�������������� � ������: " + std::to_string(displacement) + ";\n" +
        "���������� ������: " + std::to_string(numberOfCrew) + ";\n");
}

void BasicShip::ChangeHomePort(const std::string& homePort) {
    this->homePort = homePort;
}

void BasicShip::ChangeEnginePower(const int& enginePower) {
    this->enginePower = enginePower;
}

void BasicShip::ChangeDisplacement(const int& displacement) {
    this->displacement = displacement;
}

void BasicShip::ChangeNumberOfCrew(const int& numberOfCrew) {
    this->numberOfCrew = numberOfCrew;
}




