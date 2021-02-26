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

class Firebat : public Unit {
public:
    Firebat();
    Firebat(float x_, float y_);
    void DisplayCurrentState() override;
    void DisplayDoneState() override;
private:
};

class Dragoon : public Unit {
public:
    Dragoon();
    Dragoon(float x_, float y_);
    void DisplayCurrentState() override;
    void DisplayDoneState() override;
private:
};

#endif //CPP_ONBOARDING_RUN_UNITS_H
