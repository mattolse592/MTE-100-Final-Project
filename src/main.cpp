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

void startingScreenGraphics() {
  vex::brain::lcd* s = &robot.Brain_.Screen;
  s->clearScreen();
  s->drawRectangle(-1, -1, 480, 240, vex::color::red);
  s->setPenColor(vex::color::black);
  s->drawRectangle(2, 2, 155, 105, vex::color::black);

  int numPancake = 0;
  bool prevPresLeft = false;
  bool prevPresRight = false;
  bool done = false;
  int counter = 0;

  while (!done) {
    counter++;
    if (robot.Brain_.buttonLeft.pressing() && prevPresLeft == false) {
      if (numPancake > 0) {
        numPancake--;
      }

      prevPresLeft = true;
    } else {
      prevPresLeft = robot.Brain_.buttonLeft.pressing();
    }

    if (robot.Brain_.buttonRight.pressing() && prevPresRight == false) {
      if (numPancake < 5) {
        numPancake++;
      }

      prevPresRight = true;
    } else {
      prevPresRight = robot.Brain_.buttonRight.pressing();
    }

    if (counter % 10 == 0) {
      s->setPenColor(vex::color::black);
      s->drawRectangle(2, 2, 155, 105, vex::color::black);
      s->setPenColor(vex::color::white);
      s->setCursor(3, 3);
      s->print("Pancakes: %d", numPancake);
    }

    if (robot.Brain_.buttonCheck.pressing() && numPancake > 0) {
      s->clearScreen();
      s->drawRectangle(-1, -1, 480, 240, vex::color::green);
      s->setPenColor(vex::color::black);
      s->drawRectangle(2, 2, 155, 105, vex::color::black);

      s->setPenColor(vex::color::black);
      s->drawRectangle(2, 2, 155, 105, vex::color::black);
      s->setPenColor(vex::color::white);
      s->setCursor(3, 3);
      s->print("Pancakes: %d", numPancake);
      robot.Brain_.playSound(vex::soundType::tollBooth);

      done = true;
    }

    wait(10, vex::msec);
  }
}

int main() {
  thread mythread = thread(BrainTick);
  PancakeRobot *r = &robot.Robot_;

  startingScreenGraphics();

  r->x.Zero();
  r->y.Zero();
  r->z.Zero();
  r->waitZero();

  r->x.MoveTo(350);
  r->y.MoveTo(100);
  r->z.MoveTo(200);
  r->waitPid();
}