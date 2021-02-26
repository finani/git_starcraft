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
    Marine marine;
    marine.SetLocation(0,0);
    marine.AddTargetLocation(50,50);
    Stalker stalker;
    stalker.SetLocation(0,0);
    stalker.AddTargetLocation(10,20);
    stalker.AddTargetLocation(50,50);
    while (!zergling.GetDone() || !marine.GetDone() || !stalker.GetDone()) {
        zergling.IsSpeedUpgraded();
        marine.IsZerglingNear(zergling.GetLocation());
        stalker.Blink(simTime);
        zergling.Move(simTime, dt);
        marine.Move(simTime, dt);
        stalker.Move(simTime, dt);
        if (simTime - checkTime > 5.0-dt) {
            cout << ">>simTime<<\t" << simTime << endl;
            zergling.DisplayCurrentState();
            marine.DisplayCurrentState();
            stalker.DisplayCurrentState();
            checkTime = simTime;
        }
        simTime += dt;
    }
    zergling.DisplayDoneState();
    marine.DisplayDoneState();
    stalker.DisplayDoneState();
    return 0;
}