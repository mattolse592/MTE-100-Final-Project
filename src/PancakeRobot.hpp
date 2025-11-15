#pragma once

#include "vex.h"

using namespace vex;
class PancakeRobot {
 public:
  LinearSlide x;
  LinearSlide y;
  LinearSlide z;

  Flipper flipper;

  TouchLED TouchLED_;
  BumperSensor BumperSensor_;

 public:
  PancakeRobot()
  : x(Motor(PORT6, reverse), PID(0.9, 0.0, 1, 0)),
    y(Motor(PORT1, reverse), PID(0.9, 0.0, 1, 0)),
    z(Motor(PORT11, reverse), PID(0.9, 0.0, 1, 0)),
    flipper(Motor(PORT7, reverse), PID(1.6, 0.0, 7, 0)),
    TouchLED_(PORT9),
    BumperSensor_(PORT8)
  {

  }

  void InputTick()  // put sensors ticks in here
  {
    x.InputTick();
    y.InputTick();
    z.InputTick();
    TouchLED_.Tick();
    BumperSensor_.Tick();
    flipper.InputTick();
  }

  void OutputTick() {
    x.OutputTick();
    y.OutputTick();
    z.OutputTick();
    flipper.OutputTick();
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
