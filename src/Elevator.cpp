#include <iostream>
#include <algorithm>
#include "../include/Elevator.h"

Elevator::Elevator(int id) {
    this->id = id;
    currentFloor = 0;
    direction = IDLE;
}

void Elevator::pressInsideButton(int floor) {

    // avoid duplicate requests
    if(std::find(insideRequests.begin(), insideRequests.end(), floor) 
        == insideRequests.end()) {
        insideRequests.push_back(floor);
    }

    std::sort(insideRequests.begin(), insideRequests.end());
}

void Elevator::move() {

    if (insideRequests.empty()) {
        direction = IDLE;
        return;
    }

    int target = insideRequests.front();

    if (currentFloor < target) {
        direction = UP;
        currentFloor++;
    }
    else if (currentFloor > target) {
        direction = DOWN;
        currentFloor--;
    }

    if (currentFloor == target) {
        insideRequests.erase(insideRequests.begin());
    }
}

void Elevator::printStatus() {

    std::string dir;

    if(direction == UP) dir = "UP";
    else if(direction == DOWN) dir = "DOWN";
    else dir = "IDLE";

    std::cout << "Elevator " << id
              << " | Floor: " << currentFloor
              << " | Direction: " << dir
              << " | Requests: ";

    for(int r : insideRequests)
        std::cout << r << " ";

    std::cout << std::endl;
}

int Elevator::getCurrentFloor() {
    return currentFloor;
}

Direction Elevator::getDirection() {
    return direction;
}