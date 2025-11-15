#pragma once

#include "iq2_cpp.h"

class TouchLED {
private:
    vex::touchled TouchLED_;
    int Pressing_ = 0;

public:
    TouchLED(char PortNum) : TouchLED_{ PortNum } {}

    void Tick() {
        Pressing_ = TouchLED_.value();
    }

    int Pressing(){
        return Pressing_;
    }

    void setColor(vex::color color) {
        TouchLED_.setColor(color);
    }
};