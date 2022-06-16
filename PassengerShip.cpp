#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include "PassengerShip.h"
#include "Boat.h"

PassengerShip::PassengerShip(const std::string& name, std::string& homePort, int enginePower, int displacement,
    int numberOfCrew, int numberOfPassengers, std::vector<Boat*>& boats) : BasicShip(name, homePort, enginePower, displacement, numberOfCrew),
    numberOfPassengers(numberOfPassengers), boats(boats) {
    if (numberOfPassengers < 0)
        throw std::invalid_argument("Кількість пасажирів не може бути від’ємною!");

}

int PassengerShip::GetFullBoatsCapacity() const {
    int bC = 0;
    for (auto boat : boats)
    {
        bC += boat->GetBoatCapacity();
    }
    return bC;
}

int PassengerShip::GetFullNumberOfPeople() const {
    return (numberOfPassengers + GetNumberOfCrew());
}

bool PassengerShip::IsBoatsEnough() const {
    return (GetFullBoatsCapacity() >= GetFullNumberOfPeople());
}

void PassengerShip::AddBoatsToSafeNumber() {
    while (!IsBoatsEnough()) {
        int peopleWithoutBoat = GetFullNumberOfPeople() - GetFullBoatsCapacity();

        if (peopleWithoutBoat > 150) {
            boats.push_back(new Boat(150));
        }
        else if (peopleWithoutBoat < 25) {
            boats.push_back(new Boat(25));
        }
        else {
            boats.push_back(new Boat(peopleWithoutBoat));
        }
    }
}

std::string PassengerShip::Info() const {
    std::string boatInfo, fullBoatsInfo;
    for (int i = 0; i < boats.size(); i++) {
        int nB = 0;

        for (auto boat : boats) {
            if (boats[i]->GetBoatCapacity() == boat->GetBoatCapacity()) {
                nB += 1;
            }
        }
        boatInfo = "Кількість човнів місткістю " + std::to_string(boats[i]->GetBoatCapacity()) + ": " + std::to_string(nB) + ";\n";
        if (fullBoatsInfo.find(boatInfo) == std::string::npos) fullBoatsInfo += boatInfo;
    }

    return ("Тип корабля: пасажирський;\n" + BasicShip::Info() + "Кількість пасажирів: " + std::to_string(numberOfPassengers) + ";\n"
        + "Сумарна кількість човнів: " + std::to_string(boats.size()) + ";\n" + fullBoatsInfo);
}

void PassengerShip::ChangeNumberOfPassengers(const int& numberOfPassengers) {
    this->numberOfPassengers = numberOfPassengers;
}

void PassengerShip::DeleteBoat(int ID) {
    if (ID <= boats.size() && ID >= 0) {
        boats.erase(boats.begin() + ID);
    }
    else {
        throw std::invalid_argument("Такого човна не існує!");
    }
}

void PassengerShip::AddBoats(Boat* b, int n) {
    for (int i = 0; i < n; i++)
        boats.push_back(b);
}

void PassengerShip::PrintBoats() const {
    for (int i = 0; i < boats.size(); i++)
    {
        std::cout << "ID човна: " << i + 1 << std::endl;
        std::cout << boats[i]->GetBoatInfo() << std::endl;
        std::cout << std::endl;
    }
}






