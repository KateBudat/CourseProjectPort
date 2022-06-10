#ifndef COURSEPROJECTPORT_WARSHIP_H
#define COURSEPROJECTPORT_WARSHIP_H

#include <string>
#include "BasicShip.h"

enum class WeaponType { missile, artillery, torpedo, mine, antiSubmarine };

// ��������� ��������
class WarShip : public BasicShip {
public:
    WarShip(const std::string& name, std::string& homePort, int enginePower, int displacement, int numberOfCrew,
        WeaponType weaponType);

    std::string Info() const override; // ���������� ��� ��������� ��������

    //����������� �������
    void ChangeWeaponType(const WeaponType& weaponType);

private:
    WeaponType weaponType; // ��� ����
};



#endif //COURSEPROJECTPORT_WARSHIP_H
