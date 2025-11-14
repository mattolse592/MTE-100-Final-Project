#pragma once

#include "iq2_cpp.h"

class Motor {
 public:
  int MotorSpeed_ = 0;
  double MotorLocation_ = 0;

  bool ZeroMode_ = false;
  const int ZERO_SPEED = 75;

  vex::directionType Direction_ = vex::forward;

  vex::motor Motor_;

 public:
  Motor(char PortNum, vex::directionType Direction = vex::forward)
      : Motor_(PortNum), Direction_(Direction) {
    Motor_.setStopping(vex::brakeType::hold);
  }

  void InputTick() {
    MotorLocation_ = Motor_.position(vex::rotationUnits::deg);

    if (ZeroMode_) {
      if (Motor_.velocity(vex::velocityUnits::pct) < ZERO_SPEED / 10 && Motor_.current() > 0.3) {
        Motor_.setPosition(0, vex::rotationUnits::deg);
        ZeroMode_ = false;
        Stop();
      }
    }
  }

  void SetSpeed(int motorSpeed) {
    if (ZeroMode_) {
      if (Direction_ == vex::reverse) {
        Motor_.spin(vex::directionType::fwd, ZERO_SPEED, vex::percentUnits::pct);
      }
      else {
        Motor_.spin(vex::directionType::rev, ZERO_SPEED, vex::percentUnits::pct);
      }

    } else {
      MotorSpeed_ = motorSpeed;  // values from -100 to 100
      Motor_.spin(Direction_, MotorSpeed_, vex::percentUnits::pct);
    }
  }

  void Stop() {
    SetSpeed(0);
  }

  void Zero() {
    ZeroMode_ = true;
  }

  double GetRotation() {
    if (Direction_ == vex::reverse) {
      return -MotorLocation_;
    }
    return MotorLocation_;
  }

  double GetSpeed() {
    return MotorSpeed_;
  }
};