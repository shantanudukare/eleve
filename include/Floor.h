#ifndef FLOOR_H
#define FLOOR_H

#include "ElevatorController.h"

class Floor {
private:
    int floorNumber;

public:
    Floor(int number);

    void pressUpButton(ElevatorController &controller);
    void pressDownButton(ElevatorController &controller);
};

#endif