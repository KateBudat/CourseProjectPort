#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include "BasicShip.h"
#include "PassengerShip.h"
#include "CargoShip.h"
#include "WarShip.h"
#include "Port.h"

void showPorts(std::vector<Port>& ports);

void showPassengerShips(std::vector<PassengerShip*>& ships);
void showCargoShips(std::vector<CargoShip*>& ships);
void showWarShips(std::vector<WarShip*>& ships);

void createPassengerShip(std::vector<PassengerShip*>& ships);
void createCargoShip(std::vector<CargoShip*>& ships);
void createWarShip(std::vector<WarShip*>& ships);

void modifyPassengerShip(int choice, int ID, std::vector<PassengerShip*>& ships);
void modifyCargoShip(int choice, int ID, std::vector<CargoShip*>& ships);
void modifyWarShip(int choice, int ID, std::vector<WarShip*>& ships);


int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::vector<PassengerShip*> passengerShips;
    std::vector<CargoShip*> cargoShips;
    std::vector<WarShip*> warShips;

    std::vector<Port> ports = {
            Port("ϳ�������", 20),
            Port("��������", 50),
            Port("�������������", 15),
            Port("���������", 20),
            Port("������������", 20),
            Port("Test", 1)
    };

    int choice;
    do {
        try {
            std::cout << "----------------------------------------" << std::endl;
            std::cout << "0. �����" << std::endl;
            std::cout << "1. �������� ��������" << std::endl;
            std::cout << "2. ������������ ��������" << std::endl;
            std::cout << "3. �������� ��������" << std::endl;
            std::cout << "4. �������� ����� ���������� ��� ������" << std::endl;
            std::cout << "5. �������� ��������" << std::endl;
            std::cout << "6. �������� ���������� ��� ������� �����" << std::endl;
            std::cout << "----------------------------------------" << std::endl;
            std::cin >> choice;
            std::cout << std::endl;

            switch (choice) {
                case 1:
                    std::cout << "���� ��� ������� ��������?" << std::endl;
                    std::cout << "1. ������������ ��������" << std::endl;
                    std::cout << "2. �������� �����" << std::endl;
                    std::cout << "3. ³�������� ��������" << std::endl;
                    int choiceCreate;
                    std::cin >> choiceCreate;
                    std::cout << std::endl;
                    switch (choiceCreate) {
                        case 1:
                            createPassengerShip(passengerShips);
                            break;
                        case 2:
                            createCargoShip(cargoShips);
                            break;
                        case 3:
                            createWarShip(warShips);
                            break;
                    }
                    break;
                case 2:
                    if (passengerShips.empty() && cargoShips.empty() && warShips.empty()) {
                        std::cout << "� ��� ���� �������!" << std::endl;
                        std::cout << std::endl;
                        break;
                    }
                    else {
                        std::cout << "���� ��� ������� ������� ������������?" << std::endl;
                        std::cout << "1. ������������ ��������" << std::endl;
                        std::cout << "2. �������� �����" << std::endl;
                        std::cout << "3. ³�������� ��������" << std::endl;
                        int choiceMod;
                        std::cin >> choiceMod;
                        std::cout << std::endl;
                        switch (choiceMod) {
                            case 1:
                                if (passengerShips.empty()) {
                                    std::cout << "� ��� ���� ������������ �������!" << std::endl;
                                    std::cout << std::endl;
                                    break;
                                }
                                else {
                                    showPassengerShips(passengerShips);
                                    std::cout << "������ ID �������, ���� ����� ������������: ";
                                    int pSID;
                                    std::cin >> pSID;
                                    std::cout << std::endl;
                                    std::cout << "�� ���� ������� ������������?" << std::endl;
                                    std::cout << "1. ������ ���� ��������" << std::endl;
                                    std::cout << "2. ������ ��������� �������" << std::endl;
                                    std::cout << "3. ������ �������������" << std::endl;
                                    std::cout << "4. ������ ������� ������" << std::endl;
                                    std::cout << "5. ������ ������� ��������" << std::endl;
                                    std::cout << "6. �������� ������� �����" << std::endl;
                                    std::cout << "7. �������� ������� �����" << std::endl;
                                    int choiceModPS;
                                    std::cin >> choiceModPS;
                                    std::cout << std::endl;
                                    modifyPassengerShip(choiceModPS, pSID, passengerShips);
                                    break;
                                }
                            case 2:
                                if (cargoShips.empty()) {
                                    std::cout << "� ��� ���� ��������� �������!" << std::endl;
                                    std::cout << std::endl;
                                    break;
                                }
                                else {
                                    showCargoShips(cargoShips);
                                    std::cout << "������ ID �������, ���� ����� ������������: ";
                                    int cSID;
                                    std::cin >> cSID;
                                    std::cout << std::endl;
                                    std::cout << "�� ���� ������� ������������?" << std::endl;
                                    std::cout << "1. ������ ���� ��������" << std::endl;
                                    std::cout << "2. ������ ��������� �������" << std::endl;
                                    std::cout << "3. ������ �������������" << std::endl;
                                    std::cout << "4. ������ ������� ������" << std::endl;
                                    std::cout << "5. ������ ����������������" << std::endl;
                                    int choiceModCS;
                                    std::cin >> choiceModCS;
                                    std::cout << std::endl;
                                    modifyCargoShip(choiceModCS, cSID, cargoShips);
                                    break;
                                }
                            case 3:
                                if (warShips.empty()) {
                                    std::cout << "� ��� ���� ��������� �������!" << std::endl;
                                    std::cout << std::endl;
                                    break;
                                }
                                else {
                                    showWarShips(warShips);
                                    std::cout << "������ ID �������, ���� ����� ������������: ";
                                    int wSID;
                                    std::cin >> wSID;
                                    std::cout << std::endl;
                                    std::cout << "1. ������ ���� ��������" << std::endl;
                                    std::cout << "2. ������ ��������� �������" << std::endl;
                                    std::cout << "3. ������ �������������" << std::endl;
                                    std::cout << "4. ������ ������� ������" << std::endl;
                                    std::cout << "5. ������ ��� ����" << std::endl;
                                    int choiceModWS;
                                    std::cin >> choiceModWS;
                                    std::cout << std::endl;
                                    modifyWarShip(choiceModWS, wSID, warShips);
                                    break;
                                }
                        }
                        break;
                    }
                case 3:
                    if (passengerShips.empty() && cargoShips.empty() && warShips.empty()) {
                        std::cout << "� ��� ���� �������!" << std::endl;
                        std::cout << std::endl;
                        break;
                    }
                    else {
                        int choiceToDelete;
                        std::cout << "�������� ����� ���� �� ������ ��������?" << std::endl;
                        std::cout << "1. ������������ ��������" << std::endl;
                        std::cout << "2. �������� �����" << std::endl;
                        std::cout << "3. ³�������� ��������" << std::endl;
                        std::cin >> choiceToDelete;
                        std::cout << std::endl;
                        switch (choiceToDelete) {
                            case 1:
                                if (passengerShips.empty()) {
                                    std::cout << "� ��� ���� ������������ �������!" << std::endl;
                                    std::cout << std::endl;
                                    break;
                                }
                                else {
                                    showPassengerShips(passengerShips);
                                    std::cout << "������ ID �������, ���� ����� ��������: ";
                                    int pSID;
                                    std::cin >> pSID;
                                    std::cout << std::endl;
                                    bool checkIfShipInPort = false;
                                    for (int i = 0; i < ports.size(); i++) {
                                        if (ports[i].ifShipAlreadyInThePort(passengerShips[pSID - 1])) {
                                            checkIfShipInPort = true;
                                            std::cout << "�������� ����������� � ����� " << "\"" << ports[i].GetPortName() << "\". " << std::endl;
                                            std::cout << "�������� ���� � �������� ��������?" << std::endl;
                                            std::cout << "1. ���" << std::endl;
                                            std::cout << "2. ͳ" << std::endl;
                                            int choiceMove;
                                            std::cin >> choiceMove;
                                            if (choiceMove == 1) {
                                                ports[i].ShipLeftPort(passengerShips[pSID - 1]);
                                                delete passengerShips[pSID - 1];
                                                passengerShips.erase(passengerShips.begin() + pSID - 1);
                                                break;
                                            }
                                            else {
                                                break;
                                            }
                                        }
                                    }

                                    if (!checkIfShipInPort) {
                                        delete passengerShips[pSID - 1];
                                        passengerShips.erase(passengerShips.begin() + pSID - 1);
                                        break;
                                    }
                                    else {
                                        break;
                                    }
                                }
                            case 2:
                                if (cargoShips.empty()) {
                                    std::cout << "� ��� ���� ��������� �������!" << std::endl;
                                    std::cout << std::endl;
                                    break;
                                }
                                else {
                                    showCargoShips(cargoShips);
                                    std::cout << "������ ID �������, ���� ����� ��������: ";
                                    int cSID;
                                    std::cin >> cSID;
                                    std::cout << std::endl;
                                    bool checkIfShipInPort = false;
                                    for (int i = 0; i < ports.size(); i++) {
                                        if (ports[i].ifShipAlreadyInThePort(cargoShips[cSID - 1])) {
                                            checkIfShipInPort = true;
                                            std::cout << "�������� ����������� � ����� " << "\"" << ports[i].GetPortName() << "\". " << std::endl;
                                            std::cout << "�������� ���� � �������� ��������?" << std::endl;
                                            std::cout << "1. ���" << std::endl;
                                            std::cout << "2. ͳ" << std::endl;
                                            int choiceMove;
                                            std::cin >> choiceMove;
                                            if (choiceMove == 1) {
                                                ports[i].ShipLeftPort(cargoShips[cSID - 1]);
                                                delete cargoShips[cSID - 1];
                                                cargoShips.erase(cargoShips.begin() + cSID - 1);
                                                break;
                                            }
                                            else {
                                                break;
                                            }
                                        }
                                    }

                                    if (!checkIfShipInPort) {
                                        delete cargoShips[cSID - 1];
                                        cargoShips.erase(cargoShips.begin() + cSID - 1);
                                        break;
                                    }
                                    else {
                                        break;
                                    }
                                }
                            case 3:
                                if (warShips.empty()) {
                                    std::cout << "� ��� ���� ��������� �������!" << std::endl;
                                    std::cout << std::endl;
                                    break;
                                }
                                else {
                                    showWarShips(warShips);
                                    std::cout << "������ ID �������, ���� ����� ��������: ";
                                    int wSID;
                                    std::cin >> wSID;
                                    std::cout << std::endl;
                                    bool checkIfShipInPort = false;
                                    for (int i = 0; i < ports.size(); i++) {
                                        if (ports[i].ifShipAlreadyInThePort(warShips[wSID - 1])) {
                                            checkIfShipInPort = true;
                                            std::cout << "�������� ����������� � ����� " << "\"" << ports[i].GetPortName() << "\". " << std::endl;
                                            std::cout << "�������� ���� � �������� ��������?" << std::endl;
                                            std::cout << "1. ���" << std::endl;
                                            std::cout << "2. ͳ" << std::endl;
                                            int choiceMove;
                                            std::cin >> choiceMove;
                                            if (choiceMove == 1) {
                                                ports[i].ShipLeftPort(warShips[wSID - 1]);
                                                delete warShips[wSID - 1];
                                                warShips.erase(warShips.begin() + wSID - 1);
                                                break;
                                            }
                                            else {
                                                break;
                                            }
                                        }
                                    }

                                    if (!checkIfShipInPort) {
                                        delete warShips[wSID - 1];
                                        warShips.erase(warShips.begin() + wSID - 1);
                                        break;
                                    }
                                    else {
                                        break;
                                    }
                                }
                        }
                        break;
                    }
                case 4:
                    if (passengerShips.empty() && cargoShips.empty() && warShips.empty()) {
                        std::cout << "� ��� ���� �������!" << std::endl;
                        std::cout << std::endl;
                    }
                    else {

                        if (passengerShips.empty()) {
                            std::cout << "� ��� ���� ������������ �������!" << std::endl;
                            std::cout << std::endl;
                        }
                        else {
                            showPassengerShips(passengerShips);
                        }

                        if (cargoShips.empty()) {
                            std::cout << "� ��� ���� ��������� �������!" << std::endl;
                            std::cout << std::endl;
                        }
                        else {
                            showCargoShips(cargoShips);
                        }

                        if (warShips.empty()) {
                            std::cout << "� ��� ���� ��������� �������!" << std::endl;
                            std::cout << std::endl;
                        }
                        else {
                            showWarShips(warShips);
                        }
                    }
                    break;
                case 5:
                    if (passengerShips.empty() && cargoShips.empty() && warShips.empty()) {
                        std::cout << "� ��� ���� �������!" << std::endl;
                        std::cout << std::endl;
                    }
                    else {
                        std::cout << "�������� ����� ���� �� ������ ��������?" << std::endl;
                        std::cout << "1. ������������" << std::endl;
                        std::cout << "2. ���������" << std::endl;
                        std::cout << "3. ³���������" << std::endl;
                        int choiceDrive;
                        std::cin >> choiceDrive;
                        std::cout << std::endl;
                        int portsID;
                        switch (choiceDrive) {
                            case 1:
                                if (passengerShips.empty()) {
                                    std::cout << "� ��� ���� ������������ �������!" << std::endl;
                                    std::cout << std::endl;
                                }
                                else {
                                    showPassengerShips(passengerShips);
                                    std::cout << "������ ID �������, ���� �� ������ ��������: ";
                                    int pSID;
                                    std::cin >> pSID;
                                    std::cout << std::endl;
                                    bool checkIfShipInPort = false;
                                    for (int i = 0; i < ports.size(); i++) {
                                        if (ports[i].ifShipAlreadyInThePort(passengerShips[pSID - 1])) {
                                            checkIfShipInPort = true;
                                            std::cout << "�������� ��� ����������� � ����� " << "\"" << ports[i].GetPortName() << "\" " << std::endl;
                                            std::cout << "�������� �� ������ �����?" << std::endl;
                                            std::cout << "1. ���" << std::endl;
                                            std::cout << "2. ͳ" << std::endl;
                                            std::cout << "3. ����� � �����" << std::endl;
                                            int choiceMove;
                                            std::cin >> choiceMove;
                                            std::cout << std::endl;
                                            if (choiceMove == 1) {
                                                ports[i].ShipLeftPort(passengerShips[pSID - 1]);
                                                showPorts(ports);
                                                std::cout << "������ ����, � ���� �� ������ ��������� ��������: ";
                                                std::cin >> portsID;
                                                std::cout << std::endl;
                                                ports[portsID - 1].ShipEnteredPort(passengerShips[pSID - 1]);
                                                std::cout << "³���! �������� ������ � ����!" << std::endl;
                                                std::cout << std::endl;
                                                break;
                                            }
                                            else if (choiceMove == 3)
                                            {
                                                ports[i].ShipLeftPort(passengerShips[pSID - 1]);
                                                std::cout << "�������� ������ � ����� " << "\"" << ports[i].GetPortName() << "\"" << std::endl;
                                                std::cout << std::endl;
                                                break;
                                            }
                                            else {
                                                break;
                                            }
                                        }
                                    }
                                    if (!checkIfShipInPort) {
                                        showPorts(ports);
                                        std::cout << "������ ����, � ���� �� ������ ��������� ��������: ";
                                        std::cin >> portsID;
                                        std::cout << std::endl;
                                        ports[portsID - 1].ShipEnteredPort(passengerShips[pSID - 1]);
                                        std::cout << "³���! �������� ������ � ����!" << std::endl;
                                        std::cout << std::endl;
                                    }
                                }
                                break;

                            case 2:
                                if (cargoShips.empty()) {
                                    std::cout << "� ��� ���� ��������� �������!" << std::endl;
                                    std::cout << std::endl;
                                }
                                else {
                                    showCargoShips(cargoShips);
                                    std::cout << "������ ID �������, ���� �� ������ ��������: ";
                                    int cSID;
                                    std::cin >> cSID;
                                    std::cout << std::endl;
                                    bool checkIfShipInPort = false;
                                    for (int i = 0; i < ports.size(); i++) {
                                        if (ports[i].ifShipAlreadyInThePort(cargoShips[cSID - 1])) {
                                            checkIfShipInPort = true;
                                            std::cout << "�������� ��� ����������� � ����� " << "\"" << ports[i].GetPortName() << "\" " << std::endl;
                                            std::cout << "�������� �� ������ �����?" << std::endl;
                                            std::cout << "1. ���" << std::endl;
                                            std::cout << "2. ͳ" << std::endl;
                                            std::cout << "3. ����� � �����" << std::endl;
                                            int choiceMove;
                                            std::cin >> choiceMove;
                                            std::cout << std::endl;
                                            if (choiceMove == 1) {
                                                ports[i].ShipLeftPort(cargoShips[cSID - 1]);
                                                showPorts(ports);
                                                std::cout << "������ ����, � ���� �� ������ ��������� ��������: ";
                                                std::cin >> portsID;
                                                std::cout << std::endl;
                                                ports[portsID - 1].ShipEnteredPort(cargoShips[cSID - 1]);
                                                std::cout << "³���! �������� ������ � ����!" << std::endl;
                                                std::cout << std::endl;
                                                break;
                                            }
                                            else if (choiceMove == 3)
                                            {
                                                ports[i].ShipLeftPort(cargoShips[cSID - 1]);
                                                std::cout << "�������� ������ � ����� " << "\"" << ports[i].GetPortName() << "\"" << std::endl;
                                                std::cout << std::endl;
                                                break;
                                            }
                                            else {
                                                break;
                                            }
                                        }
                                    }
                                    if (!checkIfShipInPort) {
                                        showPorts(ports);
                                        std::cout << "������ ����, � ���� �� ������ ��������� ��������: ";
                                        std::cin >> portsID;
                                        std::cout << std::endl;
                                        ports[portsID - 1].ShipEnteredPort(cargoShips[cSID - 1]);
                                        std::cout << "³���! �������� ������ � ����!" << std::endl;
                                        std::cout << std::endl;
                                    }
                                }
                                break;
                            case 3:
                                if (warShips.empty()) {
                                    std::cout << "� ��� ���� ��������� �������!" << std::endl;
                                    std::cout << std::endl;
                                }
                                else {
                                    showWarShips(warShips);
                                    std::cout << "������ ID �������, ���� �� ������ ��������: ";
                                    int wSID;
                                    std::cin >> wSID;
                                    std::cout << std::endl;
                                    bool checkIfShipInPort = false;
                                    for (int i = 0; i < ports.size(); i++) {
                                        if (ports[i].ifShipAlreadyInThePort(warShips[wSID - 1])) {
                                            checkIfShipInPort = true;
                                            std::cout << "�������� ��� ����������� � ����� " << "\"" << ports[i].GetPortName() << "\" " << std::endl;
                                            std::cout << "�������� �� ������ �����?" << std::endl;
                                            std::cout << "1. ���" << std::endl;
                                            std::cout << "2. ͳ" << std::endl;
                                            std::cout << "3. ����� � �����" << std::endl;
                                            int choiceMove;
                                            std::cin >> choiceMove;
                                            std::cout << std::endl;
                                            if (choiceMove == 1) {
                                                ports[i].ShipLeftPort(warShips[wSID - 1]);
                                                showPorts(ports);
                                                std::cout << "������ ����, � ���� �� ������ ��������� ��������: ";
                                                std::cin >> portsID;
                                                std::cout << std::endl;
                                                ports[portsID - 1].ShipEnteredPort(warShips[wSID - 1]);
                                                std::cout << "³���! �������� ������ � ����!" << std::endl;
                                                std::cout << std::endl;
                                                break;
                                            }
                                            else if (choiceMove == 3)
                                            {
                                                ports[i].ShipLeftPort(warShips[wSID - 1]);
                                                std::cout << "�������� ������ � ����� " << "\"" << ports[i].GetPortName() << "\"" << std::endl;
                                                std::cout << std::endl;
                                                break;
                                            }
                                            else {
                                                break;
                                            }
                                        }
                                    }
                                    if (!checkIfShipInPort) {
                                        showPorts(ports);
                                        std::cout << "������ ����, � ���� �� ������ ��������� ��������: ";
                                        std::cin >> portsID;
                                        std::cout << std::endl;
                                        ports[portsID - 1].ShipEnteredPort(warShips[wSID - 1]);
                                        std::cout << "³���! �������� ������ � ����!" << std::endl;
                                        std::cout << std::endl;
                                    }
                                }
                                break;
                        }
                    }
                    break;
                case 6:
                    showPorts(ports);
                    break;
            }
        }
        catch (std::invalid_argument& ia)
        {
            std::cerr << ia.what() << std::endl;
        }

    } while (choice != 0);

    return 0;
}

void showPorts(std::vector<Port>& ports) {
    std::cout << "--������� �����--" << std::endl;
    for (int i = 0; i < ports.size(); i++) {
        std::cout << "ID �����: " << i + 1 << std::endl;
        std::cout << ports[i].PortInfo();
        ports[i].Print();
    }
}

void showPassengerShips(std::vector<PassengerShip*>& ships) {
    std::cout << "---���������� ������---" << std::endl;
    for (unsigned i = 0; i < ships.size(); i++) {
        std::cout << "ID �������: " << i + 1 << std::endl;
        std::cout << ships[i]->Info() << std::endl;
    }
}
void showCargoShips(std::vector<CargoShip*>& ships) {
    std::cout << "---������� ������---" << std::endl;
    for (unsigned i = 0; i < ships.size(); i++) {
        std::cout << "ID �������: " << i + 1 << std::endl;
        std::cout << ships[i]->Info() << std::endl;
    }
}
void showWarShips(std::vector<WarShip*>& ships) {
    std::cout << "---³������ ������---" << std::endl;
    for (unsigned i = 0; i < ships.size(); i++) {
        std::cout << "ID �������: " << i + 1 << std::endl;
        std::cout << ships[i]->Info() << std::endl;
    }
}

void createPassengerShip(std::vector<PassengerShip*>& ships) {
    std::string name;
    std::string homePort;
    int enginePower;
    int displacement;
    int numberOfCrew;
    int numberOfPassengers;
    std::vector<Boat*> boats;

    int numberOfBoats;

    std::cout << "--������ ��� ������ �������--" << std::endl;
    std::cout << "����� �������: ";
    std::cin >> name;
    for (auto ship : ships)
    {
        if (name == ship->GetName()) {
            std::cout << "������������ �������� � ����� ������ ��� ����!" << std::endl;
            return;
        }
    }
    std::cout << "���� ��������: ";
    std::cin >> homePort;
    std::cout << "��������� ������� � ���: ";
    std::cin >> enginePower;
    std::cout << "�������������� � ������: ";
    std::cin >> displacement;
    std::cout << "���������� ������: ";
    std::cin >> numberOfCrew;
    std::cout << "ʳ������ ���������: ";
    std::cin >> numberOfPassengers;
    std::cout << std::endl;
    std::cout << "������������!!! ��� ����� ������ ������� �����. ���� ����� ���� ����������� ��� ��� ����� �� �����, �������� ����������� ������� ���������� �������" << std::endl;
    std::cout << std::endl;
    std::cout << "ʳ������ �����: ";
    std::cin >> numberOfBoats;
    std::cout << std::endl;

    if (numberOfBoats == 1) {
        int capacity;
        std::cout << "̳������ �����: ";
        std::cin >> capacity;
        boats.push_back(new Boat(capacity));
    }

    else {
        std::cout << "������� ����� �������� �������?" << std::endl;
        std::cout << "1. ���" << std::endl;
        std::cout << "2. ͳ, � ����� ������� ��� ����� ���������" << std::endl;
        int choiceBoat;
        std::cin >> choiceBoat;
        std::cout << std::endl;
        int capacity;
        if (choiceBoat == 1) {
            std::cout << "̳������ �����: ";
            std::cin >> capacity;
            for (int i = 0; i < numberOfBoats; i++) {
                boats.push_back(new Boat(capacity));
            }
        }
        else if (choiceBoat == 2) {
            while (numberOfBoats > 0) {
                std::cout << "̳������ �����: ";
                std::cin >> capacity;
                std::cout << "ʳ������ ����� � ������� " << capacity << ": ";
                int numBoatsWithSameCapacity;
                std::cin >> numBoatsWithSameCapacity;
                for (int i = 0; i < numBoatsWithSameCapacity; i++) {
                    boats.push_back(new Boat(capacity));
                }
                numberOfBoats -= numBoatsWithSameCapacity;
                if (numberOfBoats > 0)
                    std::cout << "ʳ������ �����, �� ���������� ��������: " << numberOfBoats << std::endl;
            }
        }
    }

    ships.push_back(new PassengerShip(name, homePort, enginePower, displacement, numberOfCrew, numberOfPassengers, boats));
    ships[ships.size() - 1]->AddBoatsToSafeNumber();
    std::cout << std::endl;
    std::cout << "³���!! ���� �������� ������������ ��������!" << std::endl;
}
void createCargoShip(std::vector<CargoShip*>& ships) {
    std::string name;
    std::string homePort;
    int enginePower;
    int displacement;
    int numberOfCrew;
    int loadCapacity;

    std::cout << "--������ ��� ������ �������--" << std::endl;
    std::cout << "����� �������: ";
    std::cin >> name;
    for (auto ship : ships)
    {
        if (name == ship->GetName()) {
            std::cout << "��������� �������� � ����� ������ ��� ����!" << std::endl;
            return;
        }
    }
    std::cout << "���� ��������: ";
    std::cin >> homePort;
    std::cout << "��������� ������� � ���: ";
    std::cin >> enginePower;
    std::cout << "�������������� � ������: ";
    std::cin >> displacement;
    std::cout << "���������� ������: ";
    std::cin >> numberOfCrew;
    std::cout << "���������������� � �����: ";
    std::cin >> loadCapacity;

    ships.push_back(new CargoShip(name, homePort, enginePower, displacement, numberOfCrew, loadCapacity));
    std::cout << std::endl;
    std::cout << "³���!! ���� �������� ��������� ��������!" << std::endl;
}
void createWarShip(std::vector<WarShip*>& ships) {
    std::string name;
    std::string homePort;
    int enginePower;
    int displacement;
    int numberOfCrew;
    WeaponType weaponType;

    std::cout << "--������ ��� ������ �������--" << std::endl;
    std::cout << "����� �������: ";
    std::cin >> name;
    for (auto ship : ships)
    {
        if (name == ship->GetName()) {
            std::cout << "³�������� �������� � ����� ������ ��� ����!" << std::endl;
            return;
        }
    }
    std::cout << "���� ��������: ";
    std::cin >> homePort;
    std::cout << "��������� ������� � ���: ";
    std::cin >> enginePower;
    std::cout << "�������������� � ������: ";
    std::cin >> displacement;
    std::cout << "���������� ������: ";
    std::cin >> numberOfCrew;
    std::cout << "---������ ��� ����--- " << std::endl;
    std::cout << "1. ��������" << std::endl;
    std::cout << "2. �������������" << std::endl;
    std::cout << "3. ���������" << std::endl;
    std::cout << "4. ̳����" << std::endl;
    std::cout << "5. ������������" << std::endl;
    int weaponChoice;
    std::cin >> weaponChoice;
    switch (weaponChoice)
    {
        case 1:
            weaponType = WeaponType::missile;
            break;
        case 2:
            weaponType = WeaponType::artillery;
            break;
        case 3:
            weaponType = WeaponType::torpedo;
            break;
        case 4:
            weaponType = WeaponType::mine;
            break;
        case 5:
            weaponType = WeaponType::antiSubmarine;
            break;
    }
    ships.push_back(new WarShip(name, homePort, enginePower, displacement, numberOfCrew, weaponType));
    std::cout << std::endl;
    std::cout << "³���!! �������� ��������� ��������!" << std::endl;
}

void modifyPassengerShip(int choice, int ID, std::vector<PassengerShip*>& ships) {
    switch (choice) {
        case 1: {
            std::string newHomePort;
            std::cout << "������ ����� ���� ��������: ";
            std::cin >> newHomePort;
            ships[ID - 1]->ChangeHomePort(newHomePort);
            break;
        }
        case 2:
            std::cout << "������ ���� ��������� �������: ";
            int newEnginePower;
            std::cin >> newEnginePower;
            ships[ID - 1]->ChangeEnginePower(newEnginePower);
            break;
        case 3:
            std::cout << "������ ���� �������������: ";
            int newDisplacement;
            std::cin >> newDisplacement;
            ships[ID - 1]->ChangeDisplacement(newDisplacement);
            break;
        case 4:
            std::cout << "������ ���� ������� ������: ";
            int newNumberOfCrew;
            std::cin >> newNumberOfCrew;
            ships[ID - 1]->ChangeNumberOfCrew(newNumberOfCrew);
            break;
        case 5:
            std::cout << "������ ���� ������� ��������: ";
            int newNumberOfPassengers;
            std::cin >> newNumberOfPassengers;
            ships[ID - 1]->ChangeNumberOfPassengers(newNumberOfPassengers);
            break;
        case 6:
            std::cout << "������ ����� �� ������ ������ �� ��������?" << std::endl;
            int numBoats;
            std::cin >> numBoats;
            std::cout << std::endl;
            if (numBoats == 1) {
                std::cout << "������ ������� �����: ";
                int capacity;
                std::cin >> capacity;
                ships[ID - 1]->AddBoats(new Boat(capacity), 1);
            }

            else {
                while (numBoats)
                {
                    std::cout << "̳������ �����: ";
                    int capacity;
                    std::cin >> capacity;
                    std::cout << "ʳ������ ����� � ������� " << capacity << ": ";
                    int numBoatsWithSameCapacity;
                    std::cin >> numBoatsWithSameCapacity;
                    ships[ID - 1]->AddBoats(new Boat(capacity), numBoatsWithSameCapacity);
                    numBoats -= numBoatsWithSameCapacity;
                    if (numBoats > 0)
                        std::cout << "ʳ������ �����, �� ���������� ��������: " << numBoats << std::endl;
                }
            }
            break;
        case 7:
            std::cout << std::endl;
            std::cout << "������������!!! ���� ����� ���� ����������� ��� ��� ����� �� �����, �������� ����������� ������� ���������� �������" << std::endl;
            std::cout << std::endl;
            ships[ID - 1]->PrintBoats();
            std::cout << "������ ID �����, ���� �� ������ ��������: ";
            int boatID;
            std::cin >> boatID;
            ships[ID - 1]->DeleteBoat(boatID - 1);
            break;
    }
}
void modifyCargoShip(int choice, int ID, std::vector<CargoShip*>& ships) {
    switch (choice) {
        case 1: {
            std::string newHomePort;
            std::cout << "������ ����� ���� ��������: ";
            std::cin >> newHomePort;
            ships[ID - 1]->ChangeHomePort(newHomePort);
            break;
        }
        case 2:
            std::cout << "������ ���� ��������� �������: ";
            int newEnginePower;
            std::cin >> newEnginePower;
            ships[ID - 1]->ChangeEnginePower(newEnginePower);
            break;
        case 3:
            std::cout << "������ ���� �������������: ";
            int newDisplacement;
            std::cin >> newDisplacement;
            ships[ID - 1]->ChangeDisplacement(newDisplacement);
            break;
        case 4:
            std::cout << "������ ���� ������� ������: ";
            int newNumberOfCrew;
            std::cin >> newNumberOfCrew;
            ships[ID - 1]->ChangeNumberOfCrew(newNumberOfCrew);
            break;
        case 5:
            std::cout << "������ ���� ����������������: ";
            int newLoadCapacity;
            std::cin >> newLoadCapacity;
            ships[ID - 1]->ChangeLoadCapacity(newLoadCapacity);
            break;
    }
}
void modifyWarShip(int choice, int ID, std::vector<WarShip*>& ships) {
    switch (choice) {
        case 1: {
            std::string newHomePort;
            std::cout << "������ ����� ���� ��������: ";
            std::cin >> newHomePort;
            ships[ID - 1]->ChangeHomePort(newHomePort);
            break;
        }
        case 2:
            std::cout << "������ ���� ��������� �������: ";
            int newEnginePower;
            std::cin >> newEnginePower;
            ships[ID - 1]->ChangeEnginePower(newEnginePower);
            break;
        case 3:
            std::cout << "������ ���� �������������: ";
            int newDisplacement;
            std::cin >> newDisplacement;
            ships[ID - 1]->ChangeDisplacement(newDisplacement);
            break;
        case 4:
            std::cout << "������ ���� ������� ������: ";
            int newNumberOfCrew;
            std::cin >> newNumberOfCrew;
            ships[ID - 1]->ChangeNumberOfCrew(newNumberOfCrew);
            break;
        case 5:
            std::cout << "---������ ����� ��� ����--- " << std::endl;
            std::cout << "1. ��������" << std::endl;
            std::cout << "2. �������������" << std::endl;
            std::cout << "3. ���������" << std::endl;
            std::cout << "4. ̳����" << std::endl;
            std::cout << "5. ������������" << std::endl;
            int weaponChoice;
            WeaponType newWeaponType;
            std::cin >> weaponChoice;
            switch (weaponChoice)
            {
                case 1:
                    newWeaponType = WeaponType::missile;
                    break;
                case 2:
                    newWeaponType = WeaponType::artillery;
                    break;
                case 3:
                    newWeaponType = WeaponType::torpedo;
                    break;
                case 4:
                    newWeaponType = WeaponType::mine;
                    break;
                case 5:
                    newWeaponType = WeaponType::antiSubmarine;
                    break;
            }
            ships[ID - 1]->ChangeWeaponType(newWeaponType);
            break;
    }
}