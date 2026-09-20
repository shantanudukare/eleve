#include <iostream>
#include <climits>
#include <cmath>
#include "../include/ElevatorController.h"


ElevatorController::ElevatorController(int numElevators) {

    for (int i = 0; i < numElevators; i++) {
        elevators.push_back(Elevator(i + 1));
    }

    lastAssigned = -1;
}


// Check if elevator is moving towards requested floor
bool ElevatorController::isMovingTowards(
    Elevator &elevator,
    int requestFloor,
    Direction requestDir) {

    int currentFloor = elevator.getCurrentFloor();
    Direction elevatorDir = elevator.getDirection();


    // Elevator must move in the same requested direction
    if (elevatorDir != requestDir) {
        return false;
    }


    // Elevator moving UP and request is above it
    if (requestDir == UP && currentFloor <= requestFloor) {
        return true;
    }


    // Elevator moving DOWN and request is below it
    if (requestDir == DOWN && currentFloor >= requestFloor) {
        return true;
    }


    return false;
}


// Calculate score for each elevator
int ElevatorController::calculateScore(
    Elevator &elevator,
    int requestFloor,
    Direction requestDir) {

    int score = 0;

    int currentFloor = elevator.getCurrentFloor();


    // ----------------------------------------
    // 1. Direction Priority
    // ----------------------------------------

    // Best case: same direction and moving toward request
    if (isMovingTowards(elevator, requestFloor, requestDir)) {
        score += 100;
    }

    // Second best: idle elevator
    else if (elevator.getDirection() == IDLE) {
        score += 60;
    }

    // Worst case: moving in wrong direction
    else {
        score += 10;
    }


    // ----------------------------------------
    // 2. Distance Priority
    // Closer elevator gets more score
    // ----------------------------------------

    int distance = std::abs(currentFloor - requestFloor);

    score += std::max(0, 50 - distance * 5);


    // ----------------------------------------
    // 3. Workload Penalty
    // More pending requests = lower score
    // ----------------------------------------

    int pendingRequests = elevator.getPendingRequests();

    score -= pendingRequests * 15;


    return score;
}


// Assign external floor request
void ElevatorController::assignRequest(int floor, Direction dir) {

    int bestElevator = -1;
    int bestScore = INT_MIN;


    for (int i = 0; i < elevators.size(); i++) {

        int score = calculateScore(
            elevators[i],
            floor,
            dir
        );

        std::cout << "Elevator "
                  << i + 1
                  << " score: "
                  << score
                  << std::endl;


        // Higher score wins
        if (score > bestScore) {
            bestScore = score;
            bestElevator = i;
        }

        // If scores are equal, use round robin for fairness
        else if (score == bestScore) {

            int nextExpected =
                (lastAssigned + 1) % elevators.size();

            if (i == nextExpected) {
                bestElevator = i;
            }
        }
    }


    // Assign request to best elevator
    elevators[bestElevator].pressInsideButton(floor);

    lastAssigned = bestElevator;


    std::cout << "\nRequest for floor "
              << floor
              << " assigned to Elevator "
              << bestElevator + 1
              << " | Score: "
              << bestScore
              << std::endl;
}


void ElevatorController::step() {

    for (auto &e : elevators) {
        e.move();
    }
}


void ElevatorController::printStatus() {

    std::cout << "\n----- Elevator Status -----\n";

    for (auto &e : elevators) {
        e.printStatus();
    }
}


Elevator& ElevatorController::getElevator(int index) {
    return elevators[index];
}