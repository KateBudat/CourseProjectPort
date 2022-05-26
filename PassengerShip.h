#ifndef COURSEPROJECTPORT_PASSENGERSHIP_H
#define COURSEPROJECTPORT_PASSENGERSHIP_H

#include "BasicShip.h"

class PassengerShip : public BasicShip {

public:
    PassengerShip(const std::string& name, const std::string& homePort, int enginePower, int displacement,
                  int numberOfCrew, int numberOfPassengers, int numberOfBoats, int boatCapacity);
    int GetFullBoatsCapacity() const;
    int GetFullNumberOfPeople() const;
    bool isBoatsEnough() const;
    std::string Info() const override;
    void addBoats();

private:
    int numberOfPassengers;
    int numberOfBoats;
    int boatCapacity;

};



#endif //COURSEPROJECTPORT_PASSENGERSHIP_H
