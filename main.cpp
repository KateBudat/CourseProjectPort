#include <iostream>
#include <vector>
#include <string>
#include "BasicShip.h"
#include "PassengerShip.h"
#include "CargoShip.h"
#include "WarShip.h"
#include "Port.h"

void showPorts(std::vector<Port*>& ports);

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

    std::vector<PassengerShip*> passengerShips;
    std::vector<CargoShip*> cargoShips;
    std::vector<WarShip*> warShips;

    std::vector<Port*> ports = {
            new Port ("Південний", 20),
            new Port("Одеський", 50),
            new Port("Чорноморський", 15),
            new Port("Ренійський", 20),
            new Port("Миколаївський", 20),
    };

    int choice;
    do {
        try {
            std::cout << "----------------------------------------" << std::endl;
            std::cout << "0. Вихід" << std::endl;
            std::cout << "1. Створити корабель" << std::endl;
            std::cout << "2. Модифікувати корабель" << std::endl;
            std::cout << "3. Видалити корабель" << std::endl;
            std::cout << "4. Показати повну інформацію про кораблі" << std::endl;
            std::cout << "5. Керувати кораблем" << std::endl;
            std::cout << "----------------------------------------" << std::endl;
            std::cin >> choice;

            switch (choice) {
                case 1:
                    std::cout << "Який тип корабля створити?" << std::endl;
                    std::cout << "1. Пасажирський корабель" << std::endl;
                    std::cout << "2. Вантажне судно" << std::endl;
                    std::cout << "3. Військовий корабель" << std::endl;
                    int choiceCreate;
                    std::cin >> choiceCreate;
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
                        std::cout << "У вас немає кораблів!" << std::endl;
                        break;
                    } else {
                        std::cout << "Який тип корабля потрібно модифікувати?" << std::endl;
                        std::cout << "1. Пасажирський корабель" << std::endl;
                        std::cout << "2. Вантажне судно" << std::endl;
                        std::cout << "3. Військовий корабель" << std::endl;
                        int choiceMod;
                        std::cin >> choiceMod;
                        switch (choiceMod) {
                            case 1:
                                if (passengerShips.empty()) {
                                    std::cout << "У вас немає пасажирських кораблів!" << std::endl;
                                    break;
                                } else {
                                    showPassengerShips(passengerShips);
                                    std::cout << "Введіть ID корабля, який треба модифікувати: " << std::endl;
                                    int pSID;
                                    std::cin >> pSID;
                                    std::cout << "Як його потрібно модифікувати?" << std::endl;
                                    std::cout << "1. Змінити потужність двигуна" << std::endl;
                                    std::cout << "2. Змінити кількість екіпажу" << std::endl;
                                    std::cout << "3. Змінити кількість пасажирів" << std::endl;
                                    std::cout << "4. Збільшити кількість човнів" << std::endl;
                                    std::cout << "5. Зменшити кількість човнів" << std::endl;
                                    int choiceModPS;
                                    std::cin >> choiceModPS;
                                    modifyPassengerShip(choiceModPS, pSID, passengerShips);
                                    break;
                                }
                            case 2:
                                if (cargoShips.empty()) {
                                    std::cout << "У вас немає вантажних кораблів!" << std::endl;
                                    break;
                                } else {
                                    showCargoShips(cargoShips);
                                    std::cout << "Введіть ID корабля, який треба модифікувати: " << std::endl;
                                    int cSID;
                                    std::cin >> cSID;
                                    std::cout << "Як його потрібно модифікувати?" << std::endl;
                                    std::cout << "1. Змінити потужність двигуна" << std::endl;
                                    std::cout << "2. Змінити кількість екіпажу" << std::endl;
                                    std::cout << "3. Змінити вантажопідйомність" << std::endl;
                                    int choiceModCS;
                                    std::cin >> choiceModCS;
                                    modifyCargoShip(choiceModCS, cSID, cargoShips);
                                    break;
                                }
                            case 3:
                                if (warShips.empty()) {
                                    std::cout << "У вас немає військових кораблів!" << std::endl;
                                    break;
                                } else {
                                    showWarShips(warShips);
                                    std::cout << "Введіть ID корабля, який треба модифікувати: " << std::endl;
                                    int wSID;
                                    std::cin >> wSID;
                                    std::cout << "Як його потрібно модифікувати?" << std::endl;
                                    std::cout << "1. Змінити потужність двигуна" << std::endl;
                                    std::cout << "2. Змінити кількість екіпажу" << std::endl;
                                    std::cout << "3. Змінити тип зброї" << std::endl;
                                    int choiceModWS;
                                    std::cin >> choiceModWS;
                                    modifyWarShip(choiceModWS, wSID, warShips);
                                    break;
                                }
                        }
                        break;
                    }
                case 3:
                    if (passengerShips.empty() && cargoShips.empty() && warShips.empty()) {
                        std::cout << "У вас немає кораблів!" << std::endl;
                        break;
                    } else {
                        int choiceToDelete;
                        std::cout << "Корабель якого типу ви бажаєте видалити?" << std::endl;
                        std::cout << "1. Пасажирський корабель" << std::endl;
                        std::cout << "2. Вантажне судно" << std::endl;
                        std::cout << "3. Військовий корабель" << std::endl;
                        std::cin >> choiceToDelete;
                        switch (choiceToDelete) {
                            case 1:
                                if (passengerShips.empty()) {
                                    std::cout << "У вас немає пасажирських кораблів!" << std::endl;
                                    break;
                                } else {
                                    showPassengerShips(passengerShips);
                                    std::cout << "Введіть ID корабля, який треба видалити: " << std::endl;
                                    int pSID;
                                    std::cin >> pSID;
                                    delete passengerShips[pSID - 1];
                                    break;
                                }
                            case 2:
                                if (cargoShips.empty()) {
                                    std::cout << "У вас немає вантажних кораблів!" << std::endl;
                                    break;
                                } else {
                                    showCargoShips(cargoShips);
                                    std::cout << "Введіть ID корабля, який треба видалити: " << std::endl;
                                    int cSID;
                                    std::cin >> cSID;
                                    delete cargoShips[cSID - 1];
                                    break;
                                }
                            case 3:
                                if (warShips.empty()) {
                                    std::cout << "У вас немає військових кораблів!" << std::endl;
                                    break;
                                } else {
                                    showWarShips(warShips);
                                    std::cout << "Введіть ID корабля, який треба видалити: " << std::endl;
                                    int wSID;
                                    std::cin >> wSID;
                                    delete warShips[wSID - 1];
                                    break;
                                }
                        }
                        break;
                    }
                case 4:
                    if (passengerShips.empty() && cargoShips.empty() && warShips.empty()) {
                        std::cout << "У вас нема кораблів!" << std::endl;
                    }

                    else {

                        if (passengerShips.empty()) {
                            std::cout << "У вас нема пасажирських кораблів!" << std::endl;
                        }

                        else if (!passengerShips.empty()) {
                            showPassengerShips(passengerShips);
                        }

                        if (cargoShips.empty()) {
                            std::cout << "У вас нема вантажних кораблів!" << std::endl;
                        }

                        else if (!cargoShips.empty()) {
                            showCargoShips(cargoShips);
                        }

                        if (warShips.empty()) {
                            std::cout << "У вас нема військових кораблів!" << std::endl;
                        }

                        else if (warShips.empty()) {
                            showWarShips(warShips);
                        }
                    }
                    break;
                case 5:
                    std::cout << "Кораблем якого типу ви будете керувати?" << std::endl;
                    std::cout << "1. Пасажирським" << std::endl;
                    std::cout << "2. Вантажним" << std::endl;
                    std::cout << "3. Військовиим" << std::endl;
                    int choiceDrive;
                    std::cin >> choiceDrive;
                    switch(choiceDrive)
                    {
                        case 1:
                            showPassengerShips(passengerShips);
                            std::cout << "Введіть ID корабля, яким ви будете керувати: " << std::endl;
                            int psID;
                            std::cin >> psID;
                            for (int i = 0; i < ports.size(); i++) {
                                if (ports[i]->ifShipAlreadyInThePort(passengerShips[psID - 1])) {
                                    std::cout << "Корабель вже знаходиться в цьому порту: " << ports[i]->GetPortName() << std::endl;
                                    std::cout << "Вирушить до іншого порту?" << std::endl;
                                    std::cout << "1. Так" << std::endl;
                                    std::cout << "2. Ні" << std::endl;
                                    int choiceMove;
                                    std::cin >> choiceMove;
                                    if (choiceMove == 1) {
                                        ports[i]->ShipLeftPort(psID - 1);
                                        std::cout << "Оберіть порт, в який ви бажаєте відправити корабель: " << std::endl;
                                        showPorts(ports);
                                        int portsID;
                                        std::cin >> portsID;
                                        ports[portsID]->ShipEnteredPort(passengerShips[psID - 1]);
                                        std::cout << "Вітаю! Кораель зайшов в порт!" << std::endl;
                                    }
                                    break;
                                }
                                else {
                                    std::cout << "Оберіть порт, в який ви бажаєте відправити корабель: " << std::endl;
                                    showPorts(ports);
                                    int portsID;
                                    std::cin >> portsID;
                                    ports[portsID - 1]->ShipEnteredPort(passengerShips[psID - 1]);
                                    std::cout << "Вітаю! Кораель зайшов в порт!" << std::endl;
                                    break;
                                }
                            }
                    }
            }
        }
        catch(std::invalid_argument& ia)
        {
            std::cerr << ia.what() << std::endl;
        }
    }
    while (choice != 0);
    return 0;
}

void showPorts(std::vector<Port*>& ports) {
    for(int i = 0; i < ports.size(); i++) {
        std::cout << "-------------------" << std::endl;
        std::cout << "ID порту: " << i + 1<< std::endl;
        std::cout << ports[i]->PortInfo() << std::endl;
        ports[i]->Print();
        std::cout << "-------------------" << std::endl;
    }
}

void showPassengerShips(std::vector<PassengerShip*>& ships) {
    std::cout << "---Пасажирські кораблі---"<< std::endl;
    for (unsigned i = 0; i < ships.size(); i++) {
        std::cout << "ID корабля: " << i + 1 << std::endl;
        std::cout << ships[i]->Info() << std::endl;
        std::cout << std::endl;
    }
}
void showCargoShips(std::vector<CargoShip*>& ships) {
    std::cout << "---Вантажні кораблі---"<< std::endl;
    for (unsigned i = 0; i < ships.size(); i++) {
        std::cout << "ID корабля: " << i + 1 << std::endl;
        std::cout << ships[i]->Info() << std::endl;
        std::cout << std::endl;
    }
}
void showWarShips(std::vector<WarShip*>& ships) {
    std::cout << "---Військові кораблі---"<< std::endl;
    for (unsigned i = 0; i < ships.size(); i++) {
        std::cout << "ID корабля: " << i + 1 << std::endl;
        std::cout << ships[i]->Info() << std::endl;
        std::cout << std::endl;
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

    std::cout << "Введіть настпуні дані вашого корабля: " << std::endl;
    std::cout << "Назва корабля: " << std::endl;
    std::cin >> name;
    std::cout << "Порт приписки: " << std::endl;
    std::cin >> homePort;
    std::cout << "Потужність двигуна в кВт: " << std::endl;
    std::cin >> enginePower;
    std::cout << "Водотоннажність в тоннах: " << std::endl;
    std::cin >> displacement;
    std::cout << "Чисельність екіпажу: " << std::endl;
    std::cin >> numberOfCrew;
    std::cout << "Кількість пассажирів: " << std::endl;
    std::cin >> numberOfPassengers;

    std::cout << "Введіть кількість човнів: " << std::endl;
    std::cout << "-- Попередження! Якщо човнів буде недостатньо для всіх людей на борту, програма автоматично додасть недостатню кількість --" << std::endl;
    std::cin >> numberOfBoats;
    std::cout << "Зробити човни однакової місткості?" << std::endl;
    std::cout << "1. Так" << std::endl;
    std::cout << "2. Ні, я введу місткість всіх човнів самостійно" << std::endl;
    int choiceBoat;
    std::cin >> choiceBoat;

    int capacity;
    if (choiceBoat == 1) {
        std::cout << "Введіть місткість човна: " << std::endl;
        std::cin >> capacity;
        for (int i = 0; i < numberOfBoats; i++) {
            boats.push_back(new Boat(capacity));
        }
    }
    else if (choiceBoat == 2) {
        while(numberOfBoats > 0)
        {
            std::cout << "Місткість човна: " << std::endl;
            std::cin >> capacity;
            std::cout << "Кількість човнів з місткістю " << capacity << ":"<< std::endl;
            int numBoatsWithSameCapacity;
            std::cin >> numBoatsWithSameCapacity;
            for (int i = 0; i < numBoatsWithSameCapacity; i++) {
                boats.push_back(new Boat(capacity));
            }
            numberOfBoats -= numBoatsWithSameCapacity;
            if (numberOfBoats > 0) std::cout << "Кільксть човнів, що залишилось створити: " << numberOfBoats << std::endl;
        }
    }

    ships.push_back(new PassengerShip(name, homePort, enginePower, displacement, numberOfCrew, numberOfPassengers, boats));
    std::cout<< "Вітаю!! Було створено пасажирський корабель!"<<std::endl;
}
void createCargoShip(std::vector<CargoShip*>& ships) {
    std::string name;
    std::string homePort;
    int enginePower;
    int displacement;
    int numberOfCrew;
    int loadCapacity;

    std::cout << "Введіть настпуні дані вашого корабля: " << std::endl;
    std::cout << "Назва корабля: " << std::endl;
    std::cin >> name;
    std::cout << "Порт приписки: " << std::endl;
    std::cin >> homePort;
    std::cout << "Потужність двигуна в кВт: " << std::endl;
    std::cin >> enginePower;
    std::cout << "Водотоннажність в тоннах: " << std::endl;
    std::cin >> displacement;
    std::cout << "Чисельність екіпажу: " << std::endl;
    std::cin >> numberOfCrew;
    std::cout << " : " << std::endl;
    std::cin >> loadCapacity;

    ships.push_back(new CargoShip(name, homePort, enginePower, displacement, numberOfCrew, loadCapacity));
    std::cout<< "Вітаю!! Було створено вантажний корабель!"<<std::endl;
}
void createWarShip(std::vector<WarShip*>& ships) {
    std::string name;
    std::string homePort;
    int enginePower;
    int displacement;
    int numberOfCrew;
    WeaponType weaponType;

    std::cout << "Введіть настпуні дані вашого корабля: " << std::endl;
    std::cout << "Назва корабля: " << std::endl;
    std::cin >> name;
    std::cout << "Порт приписки: " << std::endl;
    std::cin >> homePort;
    std::cout << "Потужність двигуна в кВт: " << std::endl;
    std::cin >> enginePower;
    std::cout << "Водотоннажність в тоннах: " << std::endl;
    std::cin >> displacement;
    std::cout << "Чисельність екіпажу: " << std::endl;
    std::cin >> numberOfCrew;
    std::cout << "Виберіть тип зброї: " << std::endl;
    std::cout << "1. Ракетний" << std::endl;
    std::cout << "2. Артилерійський" << std::endl;
    std::cout << "3. Торпедний" << std::endl;
    std::cout << "4. Мінний" << std::endl;
    std::cout << "5. Протичовнової" << std::endl;
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
    std::cout<< "Вітаю!! Створено військовий корабель!"<<std::endl;
}

void modifyPassengerShip(int choice, int ID, std::vector<PassengerShip*>& ships) {
    switch (choice) {
        case 1:
            std::cout << "Введіть нову потужність двигуна: " << std::endl;
            int newEnginePower;
            std::cin >> newEnginePower;
            ships[ID - 1]->ChangeEnginePower(newEnginePower);
            break;
        case 2:
            std::cout << "Введіть нову кількість екіпажу: " << std::endl;
            int newNumberOfCrew;
            std::cin >> newNumberOfCrew;
            ships[ID - 1]->ChangeNumberOfCrew(newNumberOfCrew);
            break;
        case 3:
            std::cout << "Введіть нову кількість пасажирів: " << std::endl;
            int newNumberOfPassengers;
            std::cin >> newNumberOfPassengers;
            ships[ID - 1]->ChangeNumberOfPassengers(newNumberOfPassengers);
            break;
        case 4:
            std::cout << "Скільки човнів ви бажаєте додати на корабель?" << std::endl;
            int numBoats;
            std::cin >> numBoats;
            if (numBoats == 1) {
                std::cout << "Введіть місткість човна: " << std::endl;
                int capacity;
                std::cin >> capacity;
                ships[ID - 1]->AddBoats(new Boat(capacity), 1);
            }

            else {
                while(numBoats)
                {
                    std::cout << "Місткість човна: " << std::endl;
                    int capacity;
                    std::cin >> capacity;
                    std::cout << "Кількість човнів з місткістю " << capacity << " :"<< std::endl;
                    int numBoatsWithSameCapacity;
                    std::cin >> numBoatsWithSameCapacity;
                    ships[ID - 1]->AddBoats(new Boat(capacity), numBoatsWithSameCapacity);
                    numBoats -= numBoatsWithSameCapacity;
                }
            }
            break;
        case 5:
            std::cout << "-- Попередження! Якщо човнів буде недостатньо для всіх людей на борту, програма автоматично додасть недостатню кількість --" << std::endl;
            ships[ID - 1]->PrintBoats();
            std::cout << "Введіть ID човну, який ви хочете видалити: " << std::endl;
            int boatID;
            std::cin >> boatID;
            ships[ID - 1]->DeleteBoat(boatID);
            break;
    }
}
void modifyCargoShip(int choice, int ID, std::vector<CargoShip*>& ships) {
    switch (choice) {
        case 1:
            std::cout << "Введіть нову потужність двигуна: " << std::endl;
            int newEnginePower;
            std::cin >> newEnginePower;
            ships[ID - 1]->ChangeEnginePower(newEnginePower);
            break;
        case 2:
            std::cout << "Введіть нову кількість екіпажу: " << std::endl;
            int newNumberOfCrew;
            std::cin >> newNumberOfCrew;
            ships[ID - 1]->ChangeNumberOfCrew(newNumberOfCrew);
            break;
        case 3:
            std::cout << "Введіть нову вантажопідйомність: " << std::endl;
            int newLoadCapacity;
            std::cin >> newLoadCapacity;
            ships[ID - 1]->ChangeLoadCapacity(newLoadCapacity);
            break;
    }
}
void modifyWarShip(int choice, int ID, std::vector<WarShip*>& ships) {
    switch (choice) {
        case 1:
            std::cout << "Введіть нову потужність двигуна: " << std::endl;
            int newEnginePower;
            std::cin >> newEnginePower;
            ships[ID - 1]->ChangeEnginePower(newEnginePower);
            break;
        case 2:
            std::cout << "Введіть нову кількість екіпажу: " << std::endl;
            int newNumberOfCrew;
            std::cin >> newNumberOfCrew;
            ships[ID - 1]->ChangeNumberOfCrew(newNumberOfCrew);
            break;
        case 3:
            std::cout << "---Оберіть тип зброї--- " << std::endl;
            std::cout << "1. Ракетний" << std::endl;
            std::cout << "2. Артилерійський" << std::endl;
            std::cout << "3. Торпедний" << std::endl;
            std::cout << "4. Мінний" << std::endl;
            std::cout << "5. Протичовнової" << std::endl;
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