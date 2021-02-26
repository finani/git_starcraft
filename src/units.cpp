#include "../include/units/units.h"

Unit::Unit()
        : mCurrentLocation{0, 0},
//      mTargetPositions{vector<Location>{0,0}},
          mTargetNumber(0),
          mMoveSpeed(0),
          mHeading_deg(0.0),
          mDone(false),
          mDoneTime(0.0),
          mDonePosition{0,0}
{}

void Unit::SetLocation(float x_, float y_) {
    mCurrentLocation.mX = x_;
    mCurrentLocation.mY = y_;
    return;
}

Location Unit::GetLocation() const {
    return mCurrentLocation;
}

void Unit::AddTargetLocation(float x_, float y_) {
    Location targetLocation{x_, y_};
    mTargetPositions.push_back(targetLocation);
    return;
}

vector<Location> Unit::GetTargetLocations() const {
    return mTargetPositions;
}

void Unit::ClearTargetLocations() {
    mTargetPositions.clear();
    mTargetNumber = 0;
    return;
}

bool Unit::GetDone() const {
    return mDone;
}

Location Unit::GetDonePosition() const {
    return mDonePosition;
}

void Unit::Move(float simTime_, float dt_) {
    float dX, dY, dXY;
    if (!mDone && (mTargetPositions.size() == 0 || mTargetPositions.size() == mTargetNumber)) {
        mDone = true;
        mDoneTime = simTime_;
        mDonePosition.mX = mCurrentLocation.mX;
        mDonePosition.mY = mCurrentLocation.mY;
        return;
    }
    else if (!mDone) {
        dX = mTargetPositions[mTargetNumber].mX - mCurrentLocation.mX;
        dY = mTargetPositions[mTargetNumber].mY - mCurrentLocation.mY;
        dXY = sqrtf(dX * dX + dY * dY);
        mHeading_deg = atan2(dY, dX) * const_R2D();
        if (dXY < mMoveSpeed * dt_) {
            mCurrentLocation.mX += dX * dt_;
            mCurrentLocation.mY += dY * dt_;
            mTargetNumber++;
        } else {
            mCurrentLocation.mX += dX * mMoveSpeed / dXY * dt_;
            mCurrentLocation.mY += dY * mMoveSpeed / dXY * dt_;
        }
    }
    return;
}



Zergling::Zergling()
        :Unit(),
         mSpeedUpgrade(false)
{
    mMoveSpeed = 1;
}

Zergling::Zergling(float x_, float y_)
        :Unit(),
         mSpeedUpgrade(false)
{
    mCurrentLocation.mX = x_;
    mCurrentLocation.mY = y_;
    mMoveSpeed = 1;
}

void Zergling::IsSpeedUpgraded() {
    if (mTargetNumber > 0) {
        mSpeedUpgrade = true;
        mMoveSpeed = 2;
    }
    else {
        mSpeedUpgrade = false;
        mMoveSpeed = 1;
    }
    return;
}

void Zergling::DisplayCurrentState() {
    cout << "\t[Zergling Location Display]" << endl;
    cout << "[Location.x,y]\t" << mCurrentLocation.mX << "\t" << mCurrentLocation.mY << "\t" << \
    "[Heading_deg]\t" << mHeading_deg << endl;
    cout << "[Speed]\t" << mMoveSpeed << "\t[SpeedUpgrade]\t" << mSpeedUpgrade << endl;
    cout << endl;
    return;
}

void Zergling::DisplayDoneState() {
    cout << "\t[Zergling Done State]" << endl;
    cout << "[DoneTime]\t" << mDoneTime << endl;
    cout << "[DonePosition]\t" << mDonePosition.mX << "\t" << mDonePosition.mY << endl;
    cout << endl;
    return;
}



Firebat::Firebat()
        :Unit()
{
    mMoveSpeed = 1;
}

Firebat::Firebat(float x_, float y_)
        :Unit()
{
    mCurrentLocation.mX = x_;
    mCurrentLocation.mY = y_;
    mMoveSpeed = 1;
}

void Firebat::DisplayCurrentState() {
    string srStimPack;
    cout << "\t[Marine Location Display]" << endl;
    cout << "[Location.x,y]\t" << mCurrentLocation.mX << "\t" << mCurrentLocation.mY << "\t" << \
    "[Heading_deg]\t" << mHeading_deg << endl;
    cout << "[Speed]\t" << mMoveSpeed << endl;
    cout << endl;
    return;
}

void Firebat::DisplayDoneState() {
    cout << "\t[Marine Done State]" << endl;
    cout << "[DoneTime]\t" << mDoneTime << endl;
    cout << "[DonePosition]\t" << mDonePosition.mX << "\t" << mDonePosition.mY << endl;
    cout << endl;
    return;
}



Dragoon::Dragoon()
        :Unit()
{
    mMoveSpeed = 1;
}

Dragoon::Dragoon(float x_, float y_)
        :Unit()
{
    mCurrentLocation.mX = x_;
    mCurrentLocation.mY = y_;
    mMoveSpeed = 1;
}

void Dragoon::DisplayCurrentState() {
    cout << "\t[Stalker Location Display]" << endl;
    cout << "[Location.x,y]\t" << mCurrentLocation.mX << "\t" << mCurrentLocation.mY << "\t" << \
    "[Heading_deg]\t" << mHeading_deg << endl;
    cout << "[Speed]\t" << mMoveSpeed << endl;
    cout << endl;
    return;
}

void Dragoon::DisplayDoneState() {
    cout << "\t[Stalker Done State]" << endl;
    cout << "[DoneTime]\t" << mDoneTime << endl;
    cout << "[DonePosition]\t" << mDonePosition.mX << "\t" << mDonePosition.mY << endl;
    cout << endl;
    return;
}