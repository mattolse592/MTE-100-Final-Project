#pragma once

#include "vex.h"

using namespace vex;
class SlideTestRobot {
 public:
  LinearSlide slideMotor_;
  LinearSlide slideMotor2_;

 public:
  SlideTestRobot()
      : slideMotor_(Motor(PORT1), PID(0.9, 0.0001, 1, 350)),
        slideMotor2_(Motor(PORT6, reverse), PID(0.9, 0.0001, 1, 350)) {}

  void InputTick()  // put sensors ticks in here
  {
    slideMotor_.InputTick();
    slideMotor2_.InputTick();
  }

  void OutputTick() {
    slideMotor_.OutputTick();
    slideMotor2_.OutputTick();
  }
};
