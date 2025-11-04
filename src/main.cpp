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

  while (true) {
    if (robot.Brain_.buttonLeft.pressing()) {
      robot.Robot_.slideMotor_.MoveTo(100);
      robot.Robot_.slideMotor2_.MoveTo(100);
    }
    if (robot.Brain_.buttonRight.pressing()) {
      robot.Robot_.slideMotor_.MoveTo(200);
      robot.Robot_.slideMotor2_.MoveTo(200);
    }
    if (robot.Brain_.buttonCheck.pressing()) {
      robot.Robot_.slideMotor_.Zero();
      robot.Robot_.slideMotor2_.Zero();
    }
//ssssssssssssssssssssssssss
    wait(10, msec);
  }
}