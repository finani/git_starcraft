#include "../include/units/units.h"

using namespace std;

float simTime = 0.0;
float checkTime = 0.0;
float dt = 0.001;

int main() {
    cout << "Hello, World!" << endl;
    cout << fixed << setprecision(2);
    Zergling zergling;
    zergling.SetLocation(0,0);
    zergling.AddTargetLocation(50,0);
    zergling.AddTargetLocation(50,50);
    Firebat firebat;
    firebat.SetLocation(0,0);
    firebat.AddTargetLocation(50,50);
    Dragoon dragoon;
    dragoon.SetLocation(0,0);
    dragoon.AddTargetLocation(10,20);
    dragoon.AddTargetLocation(50,50);
    while (!zergling.GetDone() || !firebat.GetDone() || !dragoon.GetDone()) {
        zergling.IsSpeedUpgraded();
        zergling.Move(simTime, dt);
        firebat.Move(simTime, dt);
        dragoon.Move(simTime, dt);
        if (simTime - checkTime > 5.0-dt) {
            cout << ">>simTime<<\t" << simTime << endl;
            zergling.DisplayCurrentState();
            firebat.DisplayCurrentState();
            dragoon.DisplayCurrentState();
            checkTime = simTime;
        }
        simTime += dt;
    }
    zergling.DisplayDoneState();
    firebat.DisplayDoneState();
    dragoon.DisplayDoneState();
    return 0;
}