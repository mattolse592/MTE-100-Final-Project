#pragma once

#include "iq2_cpp.h"

class DistanceSensor {
 private:
  int Distance_ = 0;

  vex::distance DistanceSensor_;

 public:
  DistanceSensor(char PortNum) : DistanceSensor_(PortNum) 
  {
    
  }

  void Tick() {
    Distance_ = DistanceSensor_.value();
  }

  int GetDistance() {
    return Distance_;
  }
};