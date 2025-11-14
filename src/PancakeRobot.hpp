#pragma once

#include "vex.h"

using namespace vex;
class PancakeRobot {
 public:
  LinearSlide x;
  LinearSlide y;
  LinearSlide z;

 public:
  PancakeRobot()
  : x(Motor(PORT6, reverse), PID(0.9, 0.0, 1, 0)),
    y(Motor(PORT1, reverse), PID(0.9, 0.0, 1, 0)),
    z(Motor(PORT11, reverse), PID(0.9, 0.0, 1, 0))
  {

  }

  void InputTick()  // put sensors ticks in here
  {
    x.InputTick();
    y.InputTick();
    z.InputTick();
  }

  void OutputTick() {
    x.OutputTick();
    y.OutputTick();
    z.OutputTick();
  }

  void waitPid() {
    x.wait_steady();
    y.wait_steady();
    z.wait_steady();
  }

  void waitZero() {
    x.wait_zero();
    y.wait_zero();
    z.wait_zero();
  }
};
