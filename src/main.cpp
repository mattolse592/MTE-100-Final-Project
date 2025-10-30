/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       matthew                                                   */
/*    Created:      9/23/2025, 5:33:30 PM                                     */
/*    Description:  IQ2 project                                               */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "Brain.hpp"

using namespace vex;

Brain robot;

int main() {
  while (1) {
    // Allow other tasks to run
    this_thread::sleep_for(10);

    robot.Tick();

    wait(10, msec);
  }
}