#pragma once

#include "PancakeRobot.hpp"

class AutonBrain {
 public:
  vex::brain Brain_;

  PancakeRobot Robot_;

 public:
  AutonBrain() {}

  void Tick() {
    Robot_.InputTick();    

    if (Robot_.BumperSensor_.Pressed()) {
      Brain_.playSound(vex::soundType::wrongWaySlow);
      Brain_.programStop();
    }
    Robot_.OutputTick();
  }
};
