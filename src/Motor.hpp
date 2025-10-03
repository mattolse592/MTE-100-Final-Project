#pragma once

#include "iq2_cpp.h"

class Motor
{

private:
    int MotorSpeed_ = 0;
    double MotorLocation_ = 0;

    vex::motor Motor_;

public:
    Motor(char PortNum) : Motor_(PortNum)
    {
    }

    void Tick() {
        Motor_.spin(vex::forward, MotorSpeed_, vex::percentUnits::pct);
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
        return MotorLocation_;
    }
};