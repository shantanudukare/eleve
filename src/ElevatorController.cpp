#include <iostream>
#include "../include/ElevatorController.h"

ElevatorController::ElevatorController(int numElevators) {

    for(int i = 0; i < numElevators; i++)
        elevators.push_back(Elevator(i + 1));

    lastAssigned = -1;
}

void ElevatorController::assignRequest(int floor, Direction dir) {

    lastAssigned = (lastAssigned + 1) % elevators.size();

    elevators[lastAssigned].pressInsideButton(floor);

    std::cout << "Request for floor " << floor
              << " assigned to Elevator "
              << lastAssigned + 1 << std::endl;
}

void ElevatorController::step() {

    for(auto &e : elevators)
        e.move();
}

void ElevatorController::printStatus() {

    std::cout << "\n----- Elevator Status -----\n";

    for(auto &e : elevators)
        e.printStatus();
}

Elevator& ElevatorController::getElevator(int index) {
    return elevators[index];
}