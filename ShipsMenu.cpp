#include <iostream>
#include <vector>


#include "ShipsMenu.h"

ShipsMenu::~ShipsMenu()
{
    for (auto & ships : ships) { delete ships; }
}

void ShipsMenu::menu()
{
    int choice1;
    std::string name;
    unsigned number;
    do {
        std::cout << "0. Вихід" << std::endl;
        std::cout << "1. Створити корабель" << std::endl;
        std::cout << "2. Видалити корабель" << std::endl;
        std::cout << "3. Показати інформацію про кораблі" << std::endl;

        std::cin >> choice1;

        try {
            switch (choice1) {
                case 1:
                    int choice2;
                    std::cout << "Який тип корабля створити?" << std::endl;
                    std::cout << "1. Пасажирськеий судно" << std::endl;
                    std::cout << "2. Вантажне судно" << std::endl;
                    std::cout << "3. Військовий корабель" << std::endl;
                    std::cin >> choice2;
            }
        }
        catch (const std::exception &) {
                std::cout << "Помилка!" << std::endl;
            }
        }
        while (choice1 != '0');
}