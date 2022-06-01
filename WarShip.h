#ifndef COURSEPROJECTPORT_WARSHIP_H
#define COURSEPROJECTPORT_WARSHIP_H

#include <string>
#include "BasicShip.h"

enum class WeaponType { missile, artillery, torpedo, mine, antiSubmarine };

// військовий корабель
class WarShip : public BasicShip {
public:
    WarShip(const std::string& name, const std::string& homePort, int enginePower, int displacement, int numberOfCrew,
            WeaponType weaponType);

    std::string Info() const override; // інформація про військовий корабель

    //модифікація кораблів
    void ChangeWeaponType(const WeaponType &weaponType);

private:
    WeaponType weaponType; // тип зброї
};



#endif //COURSEPROJECTPORT_WARSHIP_H
