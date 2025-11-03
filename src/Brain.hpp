#pragma once

#include "vex.h"

class Brain {
 public:
  vex::brain Brain_;
  vex::controller Controller_;

  Robot Robot_;
  

 public:
  Brain() {}

  void Tick() {
    Brain_.Screen.clearScreen();
    
    Robot_.InputTick();

    int throttle = Controller_.AxisA.position();  // -100..100
    int turn = Controller_.AxisC.position();      // -100..100

    int leftSpeed = throttle + turn;
    int rightSpeed = throttle - turn;

    Robot_.dtLeftMotor_.SetSpeed(leftSpeed);
    Robot_.dtRightMotor_.SetSpeed(rightSpeed);

    
    Brain_.Screen.setCursor(1, 1);
    Brain_.Screen.print("Right Motor: %.2f", Robot_.dtRightMotor_.GetSpeed());

  }  // put motor ticks in here
};
