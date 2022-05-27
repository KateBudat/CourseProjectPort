#ifndef COURSEPROJECTPORT_CARGOSHIP_H
#define COURSEPROJECTPORT_CARGOSHIP_H

#include "BasicShip.h"

// вантажний корабель
class CargoShip : public BasicShip {

public:
    CargoShip(const std::string& name, const std::string& homePort, int enginePower, int displacement,
              int numberOfCrew, int loadCapacity);

    std::string Info() const override; // інформація про вантажний корабель

private:
    int loadCapacity; // вантажопідйомність

};




#endif //COURSEPROJECTPORT_CARGOSHIP_H
