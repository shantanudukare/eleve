#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <vector>
#include "enums.h"

class Elevator {
private:
    int id;
    int currentFloor;
    Direction direction;
    std::vector<int> insideRequests;

public:
    Elevator(int id);

    void pressInsideButton(int floor);
    void move();
    void printStatus();

    int getCurrentFloor();
    Direction getDirection();
};

#endif