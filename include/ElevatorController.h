#ifndef ELEVATOR_CONTROLLER_H
#define ELEVATOR_CONTROLLER_H

#include <vector>
#include "Elevator.h"
#include "enums.h"

class ElevatorController {
private:
    std::vector<Elevator> elevators;
    int lastAssigned;

    // Calculate score for selecting the best elevator
    int calculateScore(
        Elevator &elevator,
        int requestFloor,
        Direction requestDir
    );

    // Check if elevator is moving towards the request
    bool isMovingTowards(
        Elevator &elevator,
        int requestFloor,
        Direction requestDir
    );

public:
    ElevatorController(int numElevators);

    // Assign external floor request
    void assignRequest(int floor, Direction dir);

    // Move all elevators one step
    void step();

    // Print status of all elevators
    void printStatus();

    // Get elevator by index
    Elevator& getElevator(int index);
};

#endif