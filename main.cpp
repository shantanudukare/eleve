#include <iostream>
#include "../include/ElevatorController.h"

using namespace std;

const int MAX_FLOORS = 5;
const int NUM_ELEVATORS = 2;

void drawBuilding(ElevatorController &controller) {

    cout << "\n========= BUILDING =========\n\n";

    for(int f = MAX_FLOORS; f >= 0; f--) {

        cout << "Floor " << f << " | ";

        for(int e = 0; e < NUM_ELEVATORS; e++) {

            if(controller.getElevator(e).getCurrentFloor() == f)
                cout << "[E" << e+1 << "] ";
            else
                cout << "[ ]  ";
        }

        cout << endl;
    }

    cout << "\n============================\n";
}

int main() {

    ElevatorController controller(NUM_ELEVATORS);
    int choice;

    while(true) {

        drawBuilding(controller);

        cout << "\n===== Elevator System =====\n";
        cout << "1. Press UP button\n";
        cout << "2. Press DOWN button\n";
        cout << "3. Press inside elevator button\n";
        cout << "4. Step simulation\n";
        cout << "5. Show elevator status\n";
        cout << "0. Exit\n";

        cin >> choice;

        if(choice == 0) break;

        int floor, elevator;

        switch(choice) {

        case 1:
            cout << "Enter floor: ";
            cin >> floor;
            controller.assignRequest(floor, UP);
            break;

        case 2:
            cout << "Enter floor: ";
            cin >> floor;
            controller.assignRequest(floor, DOWN);
            break;

        case 3:
            cout << "Elevator ID: ";
            cin >> elevator;

            cout << "Destination floor: ";
            cin >> floor;

            controller.getElevator(elevator-1).pressInsideButton(floor);
            break;

        case 4:
            controller.step();
            break;

        case 5:
            controller.printStatus();
            break;
        }
    }

    return 0;
}