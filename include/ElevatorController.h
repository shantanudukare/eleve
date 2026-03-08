#ifndef ELEVATOR_CONTROLLER_H
#define ELEVATOR_CONTROLLER_H

#include <vector>
#include "Elevator.h"
#include "enums.h"

class ElevatorController {
private:
    std::vector<Elevator> elevators;
    int lastAssigned;

public:
    ElevatorController(int numElevators);

    void assignRequest(int floor, Direction dir);
    void step();
    void printStatus();

    Elevator& getElevator(int index);
};

#endif