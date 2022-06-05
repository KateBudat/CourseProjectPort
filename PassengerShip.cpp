#include <stdexcept>
#include <iostream>
#include "PassengerShip.h"

PassengerShip::PassengerShip(const std::string &name, const std::string &homePort, int enginePower, int displacement,
                             int numberOfCrew, int numberOfPassengers, std::vector<Boat*> boats) : BasicShip(name, homePort, enginePower, displacement, numberOfCrew),
                             numberOfPassengers(numberOfPassengers), boats(boats) {
    if (numberOfPassengers < 0)
        throw std::invalid_argument("Кількість пасажирів не може бути від’ємною!");

    this->numberOfBoats = boats.size();
}

int PassengerShip::GetFullBoatsCapacity() const {
    int bC = 0;
    for (int i = 0; i < boats.size(); i++)
    {
        bC += boats[i]->GetBoatCapacity();
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
    while(!IsBoatsEnough()) {
        int peopleWithoutBoat = GetFullNumberOfPeople() - GetFullBoatsCapacity();
        if (peopleWithoutBoat <= 150) {
            boats.push_back(new Boat(peopleWithoutBoat));
        }
        else {
            boats.push_back(new Boat(150));
        }
    }
}

std::string PassengerShip::Info() const {
    std::string boatsInfo;
    for (int i = 0; i < boats.size(); i++) {
        int nB = 0;

        for (int j = 0; j < boats.size(); j++) {
            if (boats[i]->GetBoatCapacity() == boats[j]->GetBoatCapacity()) {
                nB += 1;
            }
        }
        boatsInfo += "Кількість човнів місткістю " + std::to_string(boats[i]->GetBoatCapacity()) + ": " + std::to_string(nB) + ";\n";
    }

    return ("Тип корабля: пасажирський;\n" + BasicShip::Info() + "Кількість пасажирів: " + std::to_string(numberOfPassengers) +  ";\n" +
            boatsInfo + "Сумарна кількість човнів: " + std::to_string(numberOfBoats) + ";\n");
}

void PassengerShip::ChangeNumberOfPassengers(const int &numberOfPassengers) {
    this->numberOfPassengers = numberOfPassengers;
}

void PassengerShip::DeleteBoat(int ID) {
    if (ID < boats.size() && ID != 0) {
        boats.erase(boats.begin() + ID - 1);
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
        std::cout << "ID човна: " << std::endl;
        std::cout << boats[i]->GetBoatInfo() << std::endl;
        std::cout << std::endl;
    }
}






