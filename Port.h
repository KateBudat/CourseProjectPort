#ifndef COURSEPROJECTPORT_PORT_H
#define COURSEPROJECTPORT_PORT_H

#include <vector>
#include <string>
#include "BasicShip.h"

class Port {
public:
    Port(const std::string& name, const int maxNumberOfShips);
    void ShipEnteredPort(BasicShip* bS); // корабель зайшов в порт
    void ShipLeftPort(BasicShip* bS); // корабель залишив порт
    void Print();

    std::string GetPortName() const { return name; }
    int GetMaxNumber() const { return maxNumberOfShips; }
    int GetNumberOfShips() const { return ships.size(); }
    bool ifShipAlreadyInThePort(BasicShip* bS) const;

    std::string PortInfo() const;

private:
    const std::string name;
    const int maxNumberOfShips; // максимальна кількість кораблів, які може прийняти порт
    std::vector <BasicShip*> ships;
};


#endif //COURSEPROJECTPORT_PORT_H
