#pragma once

#include "vex.h"

using namespace vex;
class Robot
{

public:

Motor dtLeftMotor_;
Motor dtRightMotor_;
DistanceSensor dist_;


public:
    Robot() 
    :   dtLeftMotor_(PORT1),
        dtRightMotor_(PORT6),
        dist_(PORT4)
    {}

    void InputTick() // put sensors ticks in here
    {  
        dist_.Tick();
        dtLeftMotor_.InputTick();
        dtRightMotor_.InputTick();
    }

    void OutputTick() {

     }
};
