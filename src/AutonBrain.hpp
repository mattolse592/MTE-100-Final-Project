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
    Brain_.Screen.print("Dist: %f", Robot_.slideMotor_.Motor_.GetRotation());

    Robot_.OutputTick();
  }
};
