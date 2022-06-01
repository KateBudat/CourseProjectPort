#ifndef COURSEPROJECTPORT_PORT_H
#define COURSEPROJECTPORT_PORT_H

#include "BasicShip.h"
#include <vector>

class Port {
public:
    Port(const int maxNumberOfShips);
    void shipEnteredPort(); // корабель зайшов в порт
    void shipLeftPort(); // корабель залишив порт
private:
    int numberOfShips; // кількість кораблів, які є зараз в порту
    const int maxNumberOfShips; // максимальна кількість кораблів, які може прийняти порт
    std::vector <BasicShip*> ships;
};


#endif //COURSEPROJECTPORT_PORT_H
