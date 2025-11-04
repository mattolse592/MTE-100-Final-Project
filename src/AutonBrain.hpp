#pragma once

#include "vex.h"

class AutonBrain {
 public:
  vex::brain Brain_;

  SlideTestRobot Robot_;

 public:
  AutonBrain() {}

  void Tick() {
    Brain_.Screen.clearScreen();

    Robot_.InputTick();    

    Brain_.Screen.setCursor(1, 1);
    Brain_.Screen.print("rotation: %f", Robot_.slideMotor_.Motor_.GetRotation());
    Brain_.Screen.setCursor(2, 1);
    Brain_.Screen.print("Power: %f", Robot_.slideMotor_.Motor_.Motor_.current());

    Robot_.OutputTick();
  }
};
