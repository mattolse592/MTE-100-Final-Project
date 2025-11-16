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

int startingScreenGraphics() {
  vex::brain::lcd* s = &robot.Brain_.Screen;
  s->clearScreen();
  s->drawRectangle(-1, -1, 480, 240, vex::color::red);
  s->setPenColor(vex::color::black);
  s->drawRectangle(2, 2, 155, 105, vex::color::black);
  robot.Robot_.TouchLED_.setColor(vex::color::red);

  int numPancake = 0;
  bool prevPresLeft = false;
  bool prevPresRight = false;
  int counter = 0;

  while (true) {
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

    if (robot.Robot_.TouchLED_.Pressing() && numPancake > 0) {
      s->clearScreen();
      s->drawRectangle(-1, -1, 480, 240, vex::color::blue);
      s->setPenColor(vex::color::black);
      s->drawRectangle(2, 2, 155, 105, vex::color::black);
      robot.Robot_.TouchLED_.setColor(vex::color::blue);

      s->setPenColor(vex::color::black);
      s->drawRectangle(2, 2, 155, 105, vex::color::black);
      s->setPenColor(vex::color::white);
      s->setCursor(3, 3);
      s->setFont(vex::fontType::mono15);
      s->print("Making %d Pancakes", numPancake);
      robot.Brain_.playSound(vex::soundType::tollBooth);

      return numPancake;
    }

    wait(10, vex::msec);
  }
}

int main() {
  thread mythread = thread(BrainTick);
  PancakeRobot* r = &robot.Robot_;

  // int pancakeAmount = startingScreenGraphics();
  // int pancakeCount = 0;  // sssssssssssssssssssss

  // r->x.Zero();
  // r->y.Zero();
  // r->x.wait_steady();
  // r->y.wait_steady();

  double centerX = 650;  // mid of your 100–1200 range
  double centerY = 550;  // mid of your 100–1000 range
  double radius = 400;   // safe radius inside your bounds
  double step = 0.05;    // radians per loop (smaller = smoother)

  while (true) {
    for (double theta = 0; theta < 2 * M_PI; theta += step) {
      double x = centerX + radius * cos(theta);
      double y = centerY + radius * sin(theta);

      r->x.MoveTo(x);
      r->y.MoveTo(y);

      // optional: wait for both axes to reach the point
      wait(20, vex::msec);
    }
  }

  // TODO make move to function in inches or cm for linear slidesss
  /*
    while (pancakeCount < pancakeAmount) {
      pancakeCount++;
      r->x.Zero();
      r->y.Zero();
      r->z.Zero();
      r->waitZero();

      r->x.MoveTo(350);
      r->y.MoveTo(100);
      r->z.MoveTo(200);
      r->waitPid();

      r->flipper.DispenseOn();
      r->flipper.wait_steady();
      wait(2000, msec);
      r->flipper.DispenseOff();
      r->flipper.wait_steady();

      r->x.MoveTo(0);
      r->y.MoveTo(0);
      r->z.MoveTo(0);
      wait(120, sec);

      r->x.MoveTo(350);
      r->y.MoveTo(100);
      r->z.MoveTo(200);
      r->waitPid();

      r->z.MoveTo(300);
      r->waitPid();

      r->y.MoveTo(100);
      r->waitPid();

      r->z.MoveTo(200);
      r->waitPid();

      r->flipper.MoveTo(200);
      r->flipper.wait_steady();

      r->x.MoveTo(0);
      r->y.MoveTo(0);
      r->z.MoveTo(0);
      r->waitPid();

      r->flipper.MoveTo(0);
      wait(60, sec);

      r->x.MoveTo(350);
      r->y.MoveTo(300);
      r->z.MoveTo(200);
      r->waitPid();

      r->z.MoveTo(300);
      r->waitPid();

      r->y.MoveTo(600);
      r->waitPid();

      r->z.MoveTo(200);
      r->waitPid();

      r->y.MoveTo(800);
      r->waitPid();

      r->flipper.MoveTo(200);
      r->flipper.wait_steady();

      r->x.MoveTo(0);
      r->y.MoveTo(0);
      r->z.MoveTo(0);
      r->flipper.MoveTo(0);
      r->waitPid();

      robot.Brain_.playSound(vex::soundType::siren);
      pancakeCount++;
    }
  */
}