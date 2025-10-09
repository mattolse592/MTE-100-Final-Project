#pragma once

#include <math.h>

class PID
{
private:
    double kp;
    double ki;
    double kd;
    double target;

    double maxki = 0.0;

    double currentValue;

public:
    PID(double kp, double ki, double kd, double target)
        : kp_(kp), ki_(ki), kd_(kd), target_(target), previous_error_(0), integral_(0) {
            maxki = 50.0/ki; //maximum motor speed is 50, so with the maximum integral, this means the max motor speed movement from the integral is 50
        }

    double Calculate(double measured_value)
    {
        // Calculate the error
        double error = target_ - measured_value;

        // Proportional term
        double proportional = kp_ * error;

        // Integral term
        integral_ += error;
        if (fabs(error) < 4) // deadband of 4 degrees
        {
            integral_ = 0.0;
        }
        if (integral_ > abs(maxki))
        {
            integral_ = 100;
        }
        else if (integral_ < -abs(maxki))
        {
            integral_ = -100;
        }
        double integral = ki_ * integral_;

        // Derivative term
        double derivative = kd_ * (error - previous_error_);
        previous_error_ = error;

        // PID output
        double output = proportional + integral + derivative;

        // Limit output to motor's accepted range (-100 to 100)
        if (output > 100)
        {
            output = 100;
        }

        if (output < -100)
        {
            output = -100;
        }
        currentValue = output;
        return currentValue;
    }

    void setTarget(double target)
    {
        target_ = target;
    }

    double getTarget()
    {
        return target;
    }

    double getCurrentValue()
    {
        return currentValue;
    }

    double getMaxki() {
        return 100;
    }

private:
    double kp_, ki_, kd_;   // PID gains
    double target_;         // Target position in degrees
    double previous_error_; // Previous loop error for derivative
    double integral_;       // Cumulative sum for integral
};
