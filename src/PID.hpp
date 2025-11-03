#pragma once

#include <math.h>

#include "vex.h"

class PID {
 private:
  double maxki = 10000.0;

  double currentValue;

  double kp_, ki_, kd_;    // PID gains
  double target_;          // Target position in degrees
  double previous_error_;  // Previous loop error for derivative
  double integral_;        // Cumulative sum for integral

 public:
  PID(double kp, double ki, double kd, double target)
      : kp_(kp), ki_(ki), kd_(kd), target_(target), previous_error_(0), integral_(0) 
      {  }

  double Calculate(double measured_value) {
    // Calculate the error
    double error = target_ - measured_value;

    // Proportional term
    double proportional = kp_ * error;

    // Integral term
    integral_ += error;
    if (integral_ > abs(maxki)) {
      integral_ = maxki;
    } else if (integral_ < -abs(maxki)) {
      integral_ = -maxki;
    }
    double integral = ki_ * integral_;

    // Derivative term
    double derivative = kd_ * (error - previous_error_);
    previous_error_ = error;

    // PID output
    double output = proportional + integral + derivative;

    // Limit output to motor's accepted range (-100 to 100)
    if (output > 100) {
      output = 100;
    }

    if (output < -100) {
      output = -100;
    }

    currentValue = output;
    return currentValue;
  }

  void setTarget(double target) {
    target_ = target;
  }

  double getTarget() {
    return target_;
  }

  double getCurrentValue() {
    return currentValue;
  }

  double getMaxki() {
    return 100.0;
  }

  void wait_steady() {
    do {
      wait(20, vex::msec);
    } while (fabs(currentValue) > 2.0 || fabs(previous_error_) > 2.0);
  }
};
