#ifndef CPP_ONBOARDING_RUN_UNITS_H
#define CPP_ONBOARDING_RUN_UNITS_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

constexpr double const_PI() { return atan(1) * 4; }
constexpr double const_R2D() { return 180.0 / const_PI(); }
constexpr double const_D2R() { return const_PI() / 180.0; }

struct Location {
    float mX;
    float mY;
};

class Unit {
public:
    Unit();
    void SetLocation(float x_, float y_);
    Location GetLocation() const;
    void AddTargetLocation(float x_, float y_);
    vector<Location> GetTargetLocations() const;
    void ClearTargetLocations();
    bool GetDone() const;
    Location GetDonePosition() const;
    void Move(float simTime_, float dt_);
    virtual void DisplayCurrentState() = 0;
    virtual void DisplayDoneState() = 0;
protected:
    Location mCurrentLocation;
    vector<Location> mTargetPositions;
    int mTargetNumber;
    int mMoveSpeed;
    float mHeading_deg;
    bool mDone;
    float mDoneTime;
    Location mDonePosition;
};

class Zergling : public Unit {
public:
    Zergling();
    Zergling(float x_, float y_);
    void IsSpeedUpgraded();
    void DisplayCurrentState() override;
    void DisplayDoneState() override;
private:
    bool mSpeedUpgrade;
};

class Marine : public Unit {
public:
    Marine();
    Marine(float x_, float y_);
    void IsZerglingNear(Location zerglingCurrentLocation_);
    void DisplayCurrentState() override;
    void DisplayDoneState() override;
private:
    bool mStimPack;
};

class Stalker : public Unit {
public:
    Stalker();
    Stalker(float x_, float y_);
    void Blink(float simTime_);
    void DisplayCurrentState() override;
    void DisplayDoneState() override;
private:
    float mBlinkDistance;
    float mBlinkCoolTime;
    float mBlinkTime;
};

#endif //CPP_ONBOARDING_RUN_UNITS_H
