#ifndef COURSEPROJECTPORT_BASICSHIP_H
#define COURSEPROJECTPORT_BASICSHIP_H

#include <string>
#include <utility>
#include <stdexcept>

//базовий корабель
class BasicShip {

public:
    BasicShip(const std::string& name, const std::string& homePort, int enginePower, int displacement, int numberOfCrew);
    int GetNumberOfCrew() const { return numberOfCrew; }
    virtual std::string Info() const;
    virtual ~BasicShip() = default;

private:
    const std::string name; // назва
    const std::string homePort; // порт приписки
    int enginePower; // потужність двигуна
    int displacement; // водотоннажність
    int numberOfCrew; // чисельність екіпажу

};


#endif //COURSEPROJECTPORT_BASICSHIP_H
