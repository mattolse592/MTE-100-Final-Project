#pragma once

#include "Motor.hpp"
#include "PID.hpp"

class Flipper {
 private:
  PID PID_;

  int MotorSpeed_ = 0;

 public:
  Motor Motor_;

  Flipper(Motor Motor, PID PID) : Motor_(Motor), PID_(PID) {}

  void InputTick() {
    Motor_.InputTick();

    MotorSpeed_ = PID_.Calculate(Motor_.GetRotation());
  }

  void OutputTick() {
    Motor_.SetSpeed(MotorSpeed_);
  }

  void Stop() {
    MotorSpeed_ = 0;
  }

  void MoveTo(int rotation) {
    PID_.setTarget(rotation);
  }

  void wait_steady() {
    PID_.wait_steady();
  }

  void DispenseOn() {
    MoveTo(180);
  }

  void DispenseOff() {
    MoveTo(0);
  }
};