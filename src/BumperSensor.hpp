#pragma once

#include "iq2_cpp.h"

class BumperSensor {
private:
    vex::bumper BumperSensor_;
    bool Pressed_ = false;

public:
    BumperSensor(char PortNum) : BumperSensor_{ PortNum } {}

    void Tick() {
        Pressed_ = BumperSensor_.value();
    }

    double GetPressed(){
        return Pressed_;
    }
};