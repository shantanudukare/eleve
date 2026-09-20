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

    // Get current elevator position
    int getCurrentFloor();

    // Get current elevator direction
    Direction getDirection();

    // Get number of pending requests
    int getPendingRequests();
};

#endif