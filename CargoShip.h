#ifndef COURSEPROJECTPORT_CARGOSHIP_H
#define COURSEPROJECTPORT_CARGOSHIP_H

#include <string>
#include "BasicShip.h"

// вантажний корабель
class CargoShip : public BasicShip {

public:
    CargoShip(const std::string& name, const std::string& homePort, int enginePower, int displacement,
              int numberOfCrew, int loadCapacity);

    std::string Info() const override; // інформація про вантажний корабель

    //модифікація кораблів
    void ChangeLoadCapacity(const int &loadCapacity);

private:
    int loadCapacity; // вантажопідйомність

};




#endif //COURSEPROJECTPORT_CARGOSHIP_H
