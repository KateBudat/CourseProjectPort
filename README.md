# CourseProjectPort
Студент повинен реалізувати ієрархію класів, запропоновану викладачем та використати її у вирішенні прикладної задачі, вказаної в завданні до роботи. При цьому потрібно використовувати основні принципи ООП: інкапсуляцію, успадкування, поліморфізм. Перелік класів задається у варіанті завдання. 

Студент повинен реалізувати конструктори класів, поля та методи класу. Поля класу мають бути закритими, для доступу до них мають бути описані методи класів. Студенту задається ієрархія класів щодо відношень успадкування та композиції. Де потрібно, використовувати віртуальні методи, чисті віртуальні методи та абстрактні класи для реалізації ідеї динамічного поліморфізму. Використовувати, де необхідно, вбудовані класи мови С++, особливо клас string та шаблонний клас vector. При некоректних вхідних даних методів, конструкторів, функцій генерувати виняткові ситуації, та обробляти їх за допомогою блоків try..catch у функціях більш високого рівня. 


Варіант 9б. Створення ієрархії класів на тему «Порт»
Создать иерархию классов: корабль – базовый класс и пассажирский корабль – производный.

Корабль имеет  мощность двигателя, водоизмещение, название, порт приписки, количество членов экипажа. 

Пассажирский корабль имеет дополнительные поля: количество пассажиров, количество шлюпок, вместимость шлюпки. 

Реализовать метод проверки, что шлюпок хватает на пассажиров и членов экипажа и метод увеличения числа шлюпок до минимально необходимого, если их не хватает. 

Также реализовать класс грузовой корабль с дополнительным параметром  – грузоподъемность и военный корабль с дополнительным параметром – вид вооружения.

В основном проекте реализовать создание, модификацию и удаление кораблей, а также добавление шлюпок на пассажирские корабли.