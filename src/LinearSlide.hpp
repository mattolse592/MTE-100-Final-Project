#pragma once

#include "Motor.hpp"
#include "PID.hpp"

class LinearSlide {
 private:
  PID PID_;

  int MotorSpeed_ = 0;
  bool PIDActive_ = false;
  double degToMM_ = 0.0;  // conversion factor from degrees to mm

 public:
  Motor Motor_;

  LinearSlide(Motor Motor, PID PID, double maxDegrees, double length) : Motor_(Motor), PID_(PID) {
    degToMM_ = maxDegrees / length;
  }

  void InputTick() {
    Motor_.InputTick();
    if (PIDActive_) {
      MotorSpeed_ = PID_.Calculate(Motor_.GetRotation());
    } else {
      if (!Motor_.ZeroMode_) {
        MotorSpeed_ = 0;
      }
    }
  }

  void OutputTick() {
    Motor_.SetSpeed(MotorSpeed_);
  }

  void Stop() {
    PIDActive_ = false;
    MotorSpeed_ = 0;
  }

  void MoveTo(double position) {
    PIDActive_ = true;
    PID_.setTarget(position * degToMM_);
  }

  void Zero() {
    PIDActive_ = false;
    Motor_.Zero();
  }

  void wait_steady() {
    PID_.wait_steady();
  }

  void wait_zero() {
    while (Motor_.ZeroMode_) {
      wait(20, vex::msec);
    }
  }
};