#pragma once

#include "iq2_cpp.h"

class Motor
{

private:
    int MotorSpeed_ = 0;
    double MotorLocation_ = 0;

    vex::directionType Direction_ = vex::forward;

    vex::motor Motor_;

public:
    Motor(char PortNum, vex::directionType Direction = vex::forward) 
    : Motor_(PortNum), Direction_(Direction)
    {
    }

    void Tick() {
        Motor_.spin(Direction_, MotorSpeed_, vex::percentUnits::pct);
        MotorLocation_ = Motor_.position(vex::rotationUnits::deg);
    }

    void SetSpeed(int motorSpeed) {
        // values from -100 to 100
        MotorSpeed_ = motorSpeed;
    }

    void Stop() {
        SetSpeed(0);
    }

    double GetRotation() {
        if (Direction_ == vex::reverse) {
            return -MotorLocation_;
        }
        return MotorLocation_;
    }
};