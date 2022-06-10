#ifndef COURSEPROJECTPORT_PASSENGERSHIP_H
#define COURSEPROJECTPORT_PASSENGERSHIP_H

#include <vector>
#include <string>
#include "BasicShip.h"
#include "Boat.h"

// ������������ ��������
class PassengerShip : public BasicShip {

public:
    PassengerShip(const std::string& name, std::string& homePort, int enginePower, int displacement,
        int numberOfCrew, int numberOfPassengers, std::vector<Boat*>& boats);
    int GetFullBoatsCapacity() const; // ������� ��� �����
    int GetFullNumberOfPeople() const; // ���� ��� ����� �� ������ (�������� � ������)
    bool IsBoatsEnough() const; // �� ��������� ����� �� ��� �����
    void PrintBoats() const;
    std::string Info() const override; // ���������� ��� ������������ ��������
    void AddBoatsToSafeNumber();

    //����������� �������
    void ChangeNumberOfPassengers(const int& numberOfPassengers);
    void DeleteBoat(int ID);
    void AddBoats(Boat* b, int n);


private:
    int numberOfPassengers;
    std::vector<Boat*> boats;
};



#endif //COURSEPROJECTPORT_PASSENGERSHIP_H
