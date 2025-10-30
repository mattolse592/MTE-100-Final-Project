#pragma once

#include "vex.h"

class Brain {
 public:
  vex::brain Brain_;
  vex::controller Controller_;

  Robot Robot_;
  PID drivePid_;

 public:
  Brain() : drivePid_(0.9, 0.02, 3.5, 150) {}

  void Tick() {
    Robot_.InputTick();

    int throttle = Controller_.AxisA.position();  // -100..100
    int turn = Controller_.AxisC.position();      // -100..100

    int leftSpeed = throttle + turn;
    int rightSpeed = throttle - turn;

    Robot_.dtLeftMotor_.SetSpeed(6);
    Robot_.dtRightMotor_.SetSpeed(6);
    Robot_.dtLeftMotor_.Stop();
    Robot_.dtRightMotor_.Stop();
    
    Brain_.Screen.clearScreen();
    Brain_.Screen.print("Left Motor: %.2f", Robot_.dtLeftMotor_.GetRotation());

  }  // put motor ticks in here
};
