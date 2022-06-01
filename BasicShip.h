#ifndef COURSEPROJECTPORT_BASICSHIP_H
#define COURSEPROJECTPORT_BASICSHIP_H

#include <string>

// базовий корабель
class BasicShip {

protected:
    BasicShip(const std::string& name, const std::string& homePort, int enginePower, int displacement, int numberOfCrew);

public:
    int GetNumberOfCrew() const { return numberOfCrew; } // геттер чисельності екіпажу
    virtual std::string Info() const; // інформація про корабель
    virtual ~BasicShip() = default;

    //модифікація кораблів
    void ChangeEnginePower(const int& enginePower);
    void ChangeNumberOfCrew(const int& numberOfCrew);

private:
    const std::string name; // назва
    const std::string homePort; // порт приписки
    int enginePower; // потужність двигуна
    int displacement; // водотоннажність
    int numberOfCrew; // чисельність екіпажу

};


#endif //COURSEPROJECTPORT_BASICSHIP_H
