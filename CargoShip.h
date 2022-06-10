#ifndef COURSEPROJECTPORT_CARGOSHIP_H
#define COURSEPROJECTPORT_CARGOSHIP_H

#include <string>
#include "BasicShip.h"

// ��������� ��������
class CargoShip : public BasicShip {

public:
    CargoShip(const std::string& name, std::string& homePort, int enginePower, int displacement,
        int numberOfCrew, int loadCapacity);

    std::string Info() const override; // ���������� ��� ��������� ��������

    //����������� �������
    void ChangeLoadCapacity(const int& loadCapacity);

private:
    int loadCapacity; // ����������������

};




#endif //COURSEPROJECTPORT_CARGOSHIP_H
