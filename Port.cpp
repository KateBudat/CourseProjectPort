#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include "Port.h"
#include "BasicShip.h"


Port::Port(const std::string& name, const int maxNumberOfShips) : name(name), maxNumberOfShips(maxNumberOfShips) {
    if (maxNumberOfShips <= 0)
        throw std::invalid_argument("Порт не може приймати нульову чи негативну кількість кораблі!");
}

bool Port::ifShipAlreadyInThePort(BasicShip* bS) const {
    return std::find(ships.begin(), ships.end(), bS) != ships.end();
}


void Port::ShipEnteredPort(BasicShip* bS) {
    if (ifShipAlreadyInThePort(bS))
        throw std::invalid_argument("Цей корабель вже в порту!");
    else if (ships.size() + 1 > maxNumberOfShips)
        throw std::invalid_argument("Порт не може прийняти більше кораблів!");
    else ships.push_back(bS);
}

void Port::ShipLeftPort(BasicShip* bS) {

    if (!ifShipAlreadyInThePort(bS))
        throw std::invalid_argument("Такий корабель відсутній в порту!");

    else {
        ships.erase(std::find(ships.begin(), ships.end(), bS));
    }
}

void Port::Print() {
    if (!ships.empty()) {
        std::cout << "--Кораблі, які зараз знаходяться в порту--" << std::endl;
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
    return ("Назва порту: " + name + ";\n" + "Кількість кораблів зараз в порту: " + std::to_string(ships.size()) + ";\n" +
        "Максимальна кількість кораблів, які може прийняти порт: " + std::to_string(maxNumberOfShips) + ";\n");
}



