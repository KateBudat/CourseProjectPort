#include "Port.h"
#include <stdexcept>
#include <iostream>
#include <algorithm>

Port::Port(const std::string& name, const int maxNumberOfShips) : name(name), maxNumberOfShips(maxNumberOfShips) {
    if (maxNumberOfShips <= 0)
        throw std::invalid_argument("Порт не може приймати нульову чи негативну кількість кораблі!");
}

bool Port::ifShipAlreadyInThePort(BasicShip* bS) const {
    return std::find(ships.begin(), ships.end(), bS) != ships.end();
}

ShipTypes Port::getShipType(BasicShip* bS) {
    std::string str = bS->Info();
    if (str.find("пасажирський") != std::string::npos) return ShipTypes::PassengerShip;
    else if (str.find("вантажний") != std::string::npos) return ShipTypes::CargoShip;
    else return ShipTypes::WarShip;
}

void Port::ShipEnteredPort(BasicShip* bS) {
    if (ifShipAlreadyInThePort(bS))
        throw std::invalid_argument("Цей корабель вже в порту!");
    else if (ships.size() + 1 > maxNumberOfShips)
        throw std::invalid_argument("Порт не може прийняти більше кораблів!");
    else ships.push_back(bS);
}

void Port::ShipLeftPort(int ID) {

    if (ID < ships.size() && ID != 0) {
        ships.erase(ships.begin() + ID - 1);
    }

    else {
        throw std::invalid_argument("Такий корабель відсутній в порту!");
    }

}

void Port::Print(ShipTypes sT) {
    if (sT == ShipTypes::BasicShip) {
        std::cout << "Кораблі, які зараз знаходяться в порту: " << std::endl;
        for (int i = 0; i < ships.size(); i++) {
            std::cout << "ID: " << i + 1 << ";" << std::endl;
            std::cout << ships[i]->Info() << std::endl;
            }
        }

    else {
        std::cout << "Кораблі, які зараз знаходяться в порту: " << std::endl;
            for (int i = 0; i < ships.size(); i++) {
                if (getShipType(ships[i]) == sT) {
                    std::cout << "ID: " << i + 1 << ";" << std::endl;
                    std::cout << ships[i]->Info() << std::endl;
                }
            }
    }
}


std::string Port::PortInfo() const {
    return ("Назва порту: " + name + ";\n" + "Кількість кораблів зараз в порту: " + std::to_string(ships.size()) + ";\n" +
            "Максимальна кількість кораблів, які може прийняти порт: " + std::to_string(maxNumberOfShips) + ";\n");
}



