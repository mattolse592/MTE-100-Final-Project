#pragma once

#include "vex.h"

using namespace vex;
class SlideTestRobot
{

public:

    LinearSlide slideMotor_;


public:
    SlideTestRobot() 
    :   slideMotor_(Motor(PORT1), PID(0.9, 0.0001, 3, 350))
    {}

    void InputTick() // put sensors ticks in here
    {  
        slideMotor_.InputTick();
    }

    void OutputTick() {
        slideMotor_.OutputTick();
    }
};
