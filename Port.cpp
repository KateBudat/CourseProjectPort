#include "Port.h"
#include <stdexcept>

Port::Port(const int maxNumberOfShips) : maxNumberOfShips(maxNumberOfShips) {
    if (numberOfShips > maxNumberOfShips)
        throw std::invalid_argument("Порт не може прийняти більше кораблів!");
    this->numberOfShips = ships.size();
}
