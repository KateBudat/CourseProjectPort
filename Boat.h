#ifndef COURSEPROJECTPORT_BOAT_H
#define COURSEPROJECTPORT_BOAT_H

#include <string>

class Boat {
public:
    Boat(const int boatCapacity);
    int GetBoatCapacity() const;
    std::string GetBoatInfo() const;
private:
    const int boatCapacity;
};


#endif //COURSEPROJECTPORT_BOAT_H
