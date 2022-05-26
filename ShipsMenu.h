#ifndef COURSEPROJECTPORT_SHIPSMENU_H
#define COURSEPROJECTPORT_SHIPSMENU_H

#include "BasicShip.h"
#include "PassengerShip.h"
#include "CargoShip.h"
#include "WarShip.h"
#include <vector>

class ShipsMenu {
private:
    std::vector <BasicShip*> ships;
public:
    ~ShipsMenu();
    void menu();
};


#endif //COURSEPROJECTPORT_SHIPSMENU_H
