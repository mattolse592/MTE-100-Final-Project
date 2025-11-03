/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       matthew                                                   */
/*    Created:      9/23/2025, 5:33:30 PM                                     */
/*    Description:  IQ2 project                                               */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "AutonBrain.hpp"

using namespace vex;

AutonBrain robot;

void BrainTick() {
  while (true) {
    robot.Tick();
    this_thread::sleep_for(10);
  }
}

int main() {
  thread mythread = thread(BrainTick);

  robot.drivePid_.setTarget(300);  // set target distance
  robot.drivePid_.wait_steady();
  robot.drivePid_.setTarget(450);  // set target distance
  robot.drivePid_.wait_steady();
  robot.drivePid_.setTarget(300);  // set target distancesssssssssssssssssssssssssssssssssssss
  robot.drivePid_.wait_steady(); 
  robot.drivePid_.setTarget(450);  
  robot.drivePid_.wait_steady(); 
}