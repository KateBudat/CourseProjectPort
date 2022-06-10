#ifndef COURSEPROJECTPORT_BASICSHIP_H
#define COURSEPROJECTPORT_BASICSHIP_H

#include <string>


// ������� ��������
class BasicShip {

protected:
    BasicShip(const std::string& name, std::string& homePort, int enginePower, int displacement, int numberOfCrew);

public:
    std::string GetName() const; // ������ �����
    int GetNumberOfCrew() const; // ������ ���������� ������
    virtual std::string Info() const; // ���������� ��� ��������
    virtual ~BasicShip() = default;

    //����������� �������
    void ChangeHomePort(const std::string& homePort); // ������ ���� ��������
    void ChangeEnginePower(const int& enginePower); // ������ ��������� �������
    void ChangeDisplacement(const int& displacement); // ������ �������������
    void ChangeNumberOfCrew(const int& numberOfCrew); // ������ ������� ������


private:
    const std::string name; // �����
    std::string homePort; // ���� ��������
    int enginePower; // ��������� �������
    int displacement; // ��������������
    int numberOfCrew; // ���������� ������
};


#endif //COURSEPROJECTPORT_BASICSHIP_H
