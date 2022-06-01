#ifndef COURSEPROJECTPORT_PASSENGERSHIP_H
#define COURSEPROJECTPORT_PASSENGERSHIP_H

#include <string>
#include "BasicShip.h"

// пасажирський корабель
class PassengerShip : public BasicShip {

public:
    PassengerShip(const std::string& name, const std::string& homePort, int enginePower, int displacement,
                  int numberOfCrew, int numberOfPassengers, int numberOfBoats, int boatCapacity);
    int GetFullBoatsCapacity() const; // місткість усіх човнів
    int GetFullNumberOfPeople() const; // сума всіх людей на кораблі (пасажирів і екіпажу)
    bool isBoatsEnough() const; // чи достатньо човнів на усіх людей
    std::string Info() const override; // інформація про пасажирський корабель
    void addBoats();

    //модифікація кораблів
    void ChangeNumberOfPassengers(const int& numberOfPassengers);
    void ChangeNumberOfBoats(const int& numberOfBoats);
    void ChangeBoatCapacity(const int& boatCapacity);


private:
    int numberOfPassengers;
    int numberOfBoats;
    int boatCapacity;

};



#endif //COURSEPROJECTPORT_PASSENGERSHIP_H
