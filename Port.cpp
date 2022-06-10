#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include "Port.h"
#include "BasicShip.h"


Port::Port(const std::string& name, const int maxNumberOfShips) : name(name), maxNumberOfShips(maxNumberOfShips) {
    if (maxNumberOfShips <= 0)
        throw std::invalid_argument("���� �� ���� �������� ������� �� ��������� ������� ������!");
}

bool Port::ifShipAlreadyInThePort(BasicShip* bS) const {
    return std::find(ships.begin(), ships.end(), bS) != ships.end();
}


void Port::ShipEnteredPort(BasicShip* bS) {
    if (ifShipAlreadyInThePort(bS))
        throw std::invalid_argument("��� �������� ��� � �����!");
    else if (ships.size() + 1 > maxNumberOfShips)
        throw std::invalid_argument("���� �� ���� �������� ����� �������!");
    else ships.push_back(bS);
}

void Port::ShipLeftPort(BasicShip* bS) {

    if (!ifShipAlreadyInThePort(bS))
        throw std::invalid_argument("����� �������� ������� � �����!");

    else {
        ships.erase(std::find(ships.begin(), ships.end(), bS));
    }
}

void Port::Print() {
    if (!ships.empty()) {
        std::cout << "--������, �� ����� ����������� � �����--" << std::endl;
        for (int i = 0; i < ships.size(); i++) {
            std::cout << "ID: " << i + 1 << ";" << std::endl;
            std::cout << ships[i]->Info() << std::endl;
        }
    }

    else {
        std::cout << std::endl;
    }
}


std::string Port::PortInfo() const {
    return ("����� �����: " + name + ";\n" + "ʳ������ ������� ����� � �����: " + std::to_string(ships.size()) + ";\n" +
        "����������� ������� �������, �� ���� �������� ����: " + std::to_string(maxNumberOfShips) + ";\n");
}



