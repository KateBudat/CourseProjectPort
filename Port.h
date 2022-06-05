#ifndef COURSEPROJECTPORT_PORT_H
#define COURSEPROJECTPORT_PORT_H

#include "BasicShip.h"
#include <vector>

enum class ShipTypes { BasicShip, PassengerShip, CargoShip, WarShip };

class Port {
public:
    Port(const std::string& name, const int maxNumberOfShips);
    void ShipEnteredPort(BasicShip* s); // корабель зайшов в порт
    void ShipLeftPort(int ID); // корабель залишив порт
    void Print(ShipTypes sT = ShipTypes::BasicShip);

    std::string GetPortName() const { return name; }
    int GetMaxNumber() const { return maxNumberOfShips; }
    int GetNumberOfShip() const { return numberOfShips; }
    bool ifShipAlreadyInThePort(BasicShip* bS) const;

    std::string PortInfo() const;

private:
    const std::string name;
    int numberOfShips; // кількість кораблів, які є зараз в порту
    const int maxNumberOfShips; // максимальна кількість кораблів, які може прийняти порт
    std::vector <BasicShip*> ships;
    ShipTypes getShipType(BasicShip* bS);
};


#endif //COURSEPROJECTPORT_PORT_H
