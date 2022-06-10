#ifndef COURSEPROJECTPORT_PASSENGERSHIP_H
#define COURSEPROJECTPORT_PASSENGERSHIP_H

#include <vector>
#include <string>
#include "BasicShip.h"
#include "Boat.h"

// пасажирський корабель
class PassengerShip : public BasicShip {

public:
    PassengerShip(const std::string& name, std::string& homePort, int enginePower, int displacement,
        int numberOfCrew, int numberOfPassengers, std::vector<Boat*>& boats);
    int GetFullBoatsCapacity() const; // місткість усіх човнів
    int GetFullNumberOfPeople() const; // сума всіх людей на кораблі (пасажирів і екіпажу)
    bool IsBoatsEnough() const; // чи достатньо човнів на усіх людей
    void PrintBoats() const;
    std::string Info() const override; // інформація про пасажирський корабель
    void AddBoatsToSafeNumber();

    //модифікація кораблів
    void ChangeNumberOfPassengers(const int& numberOfPassengers);
    void DeleteBoat(int ID);
    void AddBoats(Boat* b, int n);


private:
    int numberOfPassengers;
    std::vector<Boat*> boats;
};



#endif //COURSEPROJECTPORT_PASSENGERSHIP_H
