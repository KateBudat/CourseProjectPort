#ifndef COURSEPROJECTPORT_BASICSHIP_H
#define COURSEPROJECTPORT_BASICSHIP_H

#include <string>


// базовий корабель
class BasicShip {

protected:
    BasicShip(const std::string& name, std::string& homePort, int enginePower, int displacement, int numberOfCrew);

public:
    std::string GetName() const; // геттер назви
    int GetNumberOfCrew() const; // геттер чисельності екіпажу
    virtual std::string Info() const; // інформація про корабель
    virtual ~BasicShip() = default;

    //модифікація кораблів
    void ChangeHomePort(const std::string& homePort); // змінити порт приписки
    void ChangeEnginePower(const int& enginePower); // змінити потужність двигуна
    void ChangeDisplacement(const int& displacement); // змінити водотонажність
    void ChangeNumberOfCrew(const int& numberOfCrew); // змінити кількість екіпажу


private:
    const std::string name; // назва
    std::string homePort; // порт приписки
    int enginePower; // потужність двигуна
    int displacement; // водотоннажність
    int numberOfCrew; // чисельність екіпажу
};


#endif //COURSEPROJECTPORT_BASICSHIP_H
