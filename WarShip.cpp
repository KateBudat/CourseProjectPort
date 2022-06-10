#include "WarShip.h"

WarShip::WarShip(const std::string& name, std::string& homePort, int enginePower, int displacement,
    int numberOfCrew, WeaponType weaponType) : BasicShip(name, homePort, enginePower, displacement, numberOfCrew),
    weaponType(weaponType) {}

std::string WarShip::Info() const {

    std::string enumToString;
    switch (weaponType)
    {
    case WeaponType::missile:
        enumToString = "��������";
        break;
    case WeaponType::artillery:
        enumToString = "�������������";
        break;
    case WeaponType::torpedo:
        enumToString = "���������";
        break;
    case WeaponType::mine:
        enumToString = "�����";
        break;
    case WeaponType::antiSubmarine:
        enumToString = "�������������";
        break;
    }

    return ("��� �������: ���������;\n" + BasicShip::Info() + "��� ����: " + enumToString + ";\n");
}

void WarShip::ChangeWeaponType(const WeaponType& weaponType) {
    this->weaponType = weaponType;
}


