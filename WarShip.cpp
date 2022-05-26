#include "WarShip.h"

WarShip::WarShip(const std::string &name, const std::string &homePort, int enginePower, int displacement,
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
            enumToString = "артилерійська";
            break;
        case WeaponType::torpedo:
            enumToString = "торпедна";
            break;
        case WeaponType::mine:
            enumToString = "мінна";
            break;
        case WeaponType::antiSubmarine:
            enumToString = "протичовновий";
            break;
    }

    return BasicShip::Info() + "Тип зброї: " + enumToString + ";/n";
}


