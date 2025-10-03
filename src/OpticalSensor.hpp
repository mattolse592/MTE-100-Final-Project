#pragma once

#include "iq2_cpp.h"

class OpticalSensor {
private:
    vex::optical OpticalSensor_;
    double Hue_;
    int Proximity_;

public:
    OpticalSensor(char PortNum) : OpticalSensor_{ PortNum } {}

    void Tick() {
        Proximity_ = OpticalSensor_.value(); //idk what value is right now, it seems like there's no way to get the proximity
        Hue_ = OpticalSensor_.hue();
    }

    void LEDon() {
        OpticalSensor_.setLight(vex::ledState::on);
    }

    void LEDoff() {
        OpticalSensor_.setLight(vex::ledState::off);
    }

    double GetHue(){
        return Hue_;
    }
};