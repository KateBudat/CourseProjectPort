#include <stdexcept>
#include <string>
#include "Boat.h"

Boat::Boat(const int boatCapacity) : boatCapacity(boatCapacity) {
    if (boatCapacity <= 0)
        throw std::invalid_argument("̳������ ����� �� ���� ���� ������� ��� ��'�����!!");
    else if (boatCapacity > 150)
        throw std::invalid_argument("̳������ ����� ����� �� 150 ���������� ���������� ��������!");
    else if (boatCapacity < 25)
        throw std::invalid_argument("̳������ ����� ����� �� 25 ���������� ���������� ��������!");
}

int Boat::GetBoatCapacity() const {
    return boatCapacity;
}

std::string Boat::GetBoatInfo() const {
    return ("̳������ �����: " + std::to_string(boatCapacity));
}
