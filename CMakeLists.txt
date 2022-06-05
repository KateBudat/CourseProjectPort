cmake_minimum_required(VERSION 3.22)
project(CourseProjectPort)

set(CMAKE_CXX_STANDARD 20)

add_executable(CourseProjectPort main.cpp BasicShip.cpp BasicShip.h PassengerShip.cpp PassengerShip.h CargoShip.cpp CargoShip.h WarShip.cpp WarShip.h Port.cpp Port.h Boat.cpp Boat.h)
