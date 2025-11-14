#pragma once

#include "vex.h"

class AutonBrain {
 public:
  vex::brain Brain_;

  PancakeRobot Robot_;

 public:
  AutonBrain() {}

  void Tick() {
    Robot_.InputTick();    

    Robot_.OutputTick();
  }
};
