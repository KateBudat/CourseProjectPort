#include "WarShip.h"

WarShip::WarShip(const std::string &name, std::string &homePort, int enginePower, int displacement,
                 int numberOfCrew, WeaponType weaponType) : BasicShip(name, homePort, enginePower, displacement, numberOfCrew),
                 weaponType(weaponType) {}

std::string WarShip::Info() const {

    std::string enumToString;
    switch (weaponType)
    {
        case WeaponType::missile:
            enumToString = "ракетний";
            break;
        case WeaponType::artillery:
            enumToString = "артилерійський";
            break;
        case WeaponType::torpedo:
            enumToString = "торпедний";
            break;
        case WeaponType::mine:
            enumToString = "мінний";
            break;
        case WeaponType::antiSubmarine:
            enumToString = "протичовновий";
            break;
    }

    return ("Тип корабля: військовий;\n" + BasicShip::Info() + "Тип зброї: " + enumToString + ";\n");
}

void WarShip::ChangeWeaponType(const WeaponType &weaponType) {
    this->weaponType = weaponType;
}


