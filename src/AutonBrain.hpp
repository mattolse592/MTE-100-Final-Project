#pragma once

#include "vex.h"

class AutonBrain {
 public:
  vex::brain Brain_;

  Robot Robot_;
  PID drivePid_;

 public:
  AutonBrain() : drivePid_(0.9, 0.0001, 0, 350) {}

  void Tick() {
    Brain_.Screen.clearScreen();

    Robot_.InputTick();

    double output = drivePid_.Calculate(Robot_.dist_.GetDistance());

    Robot_.dtRightMotor_.SetSpeed(output);
    Robot_.dtLeftMotor_.SetSpeed(output);

    Brain_.Screen.setCursor(1, 1);
    Brain_.Screen.print("Dist: %d", Robot_.dist_.GetDistance());
  }
};
