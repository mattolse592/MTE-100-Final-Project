/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       matthew                                                   */
/*    Created:      9/23/2025, 5:33:30 PM                                     */
/*    Description:  IQ2 project                                               */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the IQ2 brain screen
vex::brain Brain;

Motor dtLeftMotor(PORT1, vex::reverse);
Motor dtRightMotor(PORT6); // reversed
DistanceSensor dist(PORT4);

PID pid(0.5, 0.02, 0.5, 150);

int main() {
  while (1) {
    // Allow other tasks to run
    this_thread::sleep_for(10);

    dist.Tick();
    dtLeftMotor.Tick();
    dtRightMotor.Tick();

    Brain.Screen.clearLine(1);
    Brain.Screen.clearLine(2);
    Brain.Screen.printAt(2, 30, "%d", pid.getMaxki());

    dtLeftMotor.SetSpeed(pid.Calculate(dist.GetDistance()));
    dtRightMotor.SetSpeed(pid.Calculate(dist.GetDistance()));

    wait(20, msec);
  }
}