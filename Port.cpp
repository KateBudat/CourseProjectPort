#include "Port.h"
#include <stdexcept>
#include <iostream>
#include <algorithm>

Port::Port(const std::string& name, const int maxNumberOfShips) : name(name), maxNumberOfShips(maxNumberOfShips) {
    if (numberOfShips > maxNumberOfShips)
        throw std::invalid_argument("Порт не може прийняти більше кораблів!");
    this->numberOfShips = ships.size();
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

void Port::ShipEnteredPort(BasicShip* s) {
    if (ifShipAlreadyInThePort(s))
        throw std::invalid_argument("Цей корабель вже в порту!");
    else ships.push_back(s);
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
    if (ships.empty()) {
        std::cout << "В порту нема кораблів." << std::endl;
    }

    else {
        if (sT == ShipTypes::BasicShip) {
            std::cout << "Кораблі, які зараз знаходяться в порту: " << std::endl;
            for (int i = 0; i < ships.size(); i++) {
                std::cout << "ID: " << i + 1 << ";" << std::endl;
                std::cout << ships[i]->Info() << std::endl;
            }
        }

        else {
            std::string enumToString;
            switch(sT) {
                case ShipTypes::PassengerShip:
                    enumToString = "Пасажирські кораблі";
                    break;

                case ShipTypes::CargoShip:
                    enumToString = "Вантажні кораблі";
                    break;

                case ShipTypes::WarShip:
                    enumToString = "Військові кораблі";
                    break;
            }

            for (int i = 0; i < ships.size(); i++) {
                std::cout << enumToString << ", які зараз знаходяться в порту: " << std::endl;
                if (getShipType(ships[i]) == sT) {
                    std::cout << "ID: " << i + 1 << ";" << std::endl;
                    std::cout << ships[i]->Info() << std::endl;
                }
            }
        }
    }
}


std::string Port::PortInfo() const {
    return ("Назва порту: " + name + ";\n" + "Кількість кораблів зараз в порту: " + std::to_string(numberOfShips) + ";\n" +
            "Максимальна кількість кораблів, які може прийняти порт: " + std::to_string(maxNumberOfShips) + ";\n");
}



