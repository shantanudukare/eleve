#include "../include/Floor.h"

Floor::Floor(int number) {
    floorNumber = number;
}

void Floor::pressUpButton(ElevatorController &controller) {
    controller.assignRequest(floorNumber, UP);
}

void Floor::pressDownButton(ElevatorController &controller) {
    controller.assignRequest(floorNumber, DOWN);
}