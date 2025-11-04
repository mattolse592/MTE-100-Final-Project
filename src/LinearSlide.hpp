#pragma once

#include "Motor.hpp"
#include "PID.hpp"

class LinearSlide {
 private:
  PID PID_;

  int MotorSpeed_ = 0;
  bool PIDActive_ = false;

 public:    
  Motor Motor_;

  LinearSlide(Motor Motor, PID PID) : Motor_(Motor), PID_(PID) {}

  void InputTick() {
    Motor_.InputTick();
    if (PIDActive_) {
      MotorSpeed_ = PID_.Calculate(Motor_.GetRotation());
    }
  }

  void OutputTick() {
    Motor_.SetSpeed(MotorSpeed_);
  }

  void Stop() {
    PIDActive_ = false;
    MotorSpeed_ = 0;
  }

  void MoveTo(int position) {
    PIDActive_ = true;
    PID_.setTarget(position);
  }

  void Zero()  {
    PIDActive_ = false;
    Motor_.Zero();
  }
};