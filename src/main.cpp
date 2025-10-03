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

Motor dtLeftMotor(PORT1);
DistanceSensor dist(PORT3);

PID pid(0.4, -0.05, 0.00, 100);

int main() {
  Brain.Screen.printAt(2, 30, "Hello IQ2");

  int as = 0;
  
  while (1) {
    // Allow other tasks to run
    this_thread::sleep_for(10);
    dtLeftMotor.Tick();

    dtLeftMotor.SetSpeed(pid.Calculate(dtLeftMotor.GetRotation()));

    as += 5;

    if (as % 400 == 0) {
      pid.setTarget(0);
    } else if (as % 400 == 200) {
      pid.setTarget(300);
    }

    wait(20, msec);
  }
}