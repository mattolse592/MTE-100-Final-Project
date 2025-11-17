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
  // int pancakeCount = 0;  // sssssssssssssssssssssssssssss

  r->x.Zero();
  r->x.wait_zero();
  r->x.MoveTo(70);
  r->x.wait_steady();
  r->y.Zero();
  r->y.wait_zero();
  r->y.MoveTo(150);
  r->y.wait_steady();
  r->z.Zero();
  r->z.wait_zero();
  r->z.MoveTo(50);
  r->z.wait_steady();

#pragma region test




r->x.MoveTo(176.99);
r->y.MoveTo(194.13);
wait(1000, msec);
r->z.MoveTo(126.00);
wait(600, msec);
r->x.MoveTo(190.72);
r->y.MoveTo(178.33);
wait(157, msec);
r->x.MoveTo(200.54);
r->y.MoveTo(164.73);
wait(136, msec);
r->x.MoveTo(206.87);
r->y.MoveTo(153.94);
wait(107, msec);
r->x.MoveTo(212.04);
r->y.MoveTo(142.71);
wait(112, msec);
r->x.MoveTo(215.93);
r->y.MoveTo(131.07);
wait(116, msec);
r->x.MoveTo(218.35);
r->y.MoveTo(119.08);
wait(119, msec);
r->x.MoveTo(219.07);
r->y.MoveTo(110.74);
wait(83, msec);
r->x.MoveTo(218.66);
r->y.MoveTo(98.00);
wait(127, msec);
r->x.MoveTo(217.79);
r->y.MoveTo(92.30);
wait(57, msec);
r->x.MoveTo(214.50);
r->y.MoveTo(81.86);
wait(104, msec);
r->x.MoveTo(212.19);
r->y.MoveTo(77.12);
wait(47, msec);
r->x.MoveTo(206.31);
r->y.MoveTo(68.67);
wait(84, msec);
r->x.MoveTo(202.79);
r->y.MoveTo(64.97);
wait(37, msec);
r->x.MoveTo(194.88);
r->y.MoveTo(58.69);
wait(79, msec);
r->x.MoveTo(190.52);
r->y.MoveTo(56.12);
wait(43, msec);
r->x.MoveTo(181.16);
r->y.MoveTo(52.24);
wait(93, msec);
r->x.MoveTo(176.24);
r->y.MoveTo(50.93);
wait(49, msec);
r->x.MoveTo(166.17);
r->y.MoveTo(49.60);
wait(100, msec);
r->x.MoveTo(160.98);
r->y.MoveTo(49.61);
wait(51, msec);
r->x.MoveTo(150.50);
r->y.MoveTo(51.05);
wait(104, msec);
r->x.MoveTo(145.36);
r->y.MoveTo(52.48);
wait(51, msec);
r->x.MoveTo(134.86);
r->y.MoveTo(56.89);
wait(105, msec);
r->x.MoveTo(130.07);
r->y.MoveTo(59.85);
wait(47, msec);
r->x.MoveTo(120.84);
r->y.MoveTo(67.39);
wait(92, msec);
r->x.MoveTo(116.66);
r->y.MoveTo(71.99);
wait(45, msec);
r->x.MoveTo(120.18);
r->y.MoveTo(52.98);
wait(190, msec);
r->x.MoveTo(128.49);
r->y.MoveTo(25.51);
wait(274, msec);
r->x.MoveTo(138.69);
r->y.MoveTo(0.00);
wait(255, msec);
r->x.MoveTo(80.69);
wait(580, msec);
r->x.MoveTo(82.74);
r->y.MoveTo(6.59);
wait(65, msec);
r->x.MoveTo(97.66);
r->y.MoveTo(47.01);
wait(404, msec);
r->x.MoveTo(99.64);
r->y.MoveTo(56.57);
wait(95, msec);
r->x.MoveTo(100.41);
r->y.MoveTo(63.17);
wait(66, msec);
r->x.MoveTo(87.72);
r->y.MoveTo(58.78);
wait(126, msec);
r->x.MoveTo(82.73);
r->y.MoveTo(56.03);
wait(49, msec);
r->x.MoveTo(72.06);
r->y.MoveTo(51.98);
wait(106, msec);
r->x.MoveTo(66.56);
r->y.MoveTo(50.72);
wait(55, msec);
r->x.MoveTo(55.15);
r->y.MoveTo(49.74);
wait(114, msec);
r->x.MoveTo(49.46);
r->y.MoveTo(50.03);
wait(56, msec);
r->x.MoveTo(38.31);
r->y.MoveTo(52.14);
wait(111, msec);
r->x.MoveTo(32.96);
r->y.MoveTo(54.02);
wait(53, msec);
r->x.MoveTo(22.98);
r->y.MoveTo(59.39);
wait(99, msec);
r->x.MoveTo(18.45);
r->y.MoveTo(62.90);
wait(45, msec);
r->x.MoveTo(10.56);
r->y.MoveTo(71.58);
wait(86, msec);
r->x.MoveTo(7.30);
r->y.MoveTo(76.77);
wait(51, msec);
r->x.MoveTo(2.43);
r->y.MoveTo(88.88);
wait(121, msec);
r->x.MoveTo(0.92);
r->y.MoveTo(95.74);
wait(68, msec);
r->x.MoveTo(0.08);
r->y.MoveTo(103.28);
wait(75, msec);
r->x.MoveTo(0.00);
r->y.MoveTo(111.33);
wait(80, msec);
r->x.MoveTo(0.69);
r->y.MoveTo(120.06);
wait(87, msec);
r->x.MoveTo(2.62);
r->y.MoveTo(130.41);
wait(103, msec);
r->x.MoveTo(5.73);
r->y.MoveTo(140.48);
wait(100, msec);
r->x.MoveTo(9.89);
r->y.MoveTo(150.37);
wait(98, msec);
r->x.MoveTo(16.84);
r->y.MoveTo(162.99);
wait(126, msec);
r->x.MoveTo(25.15);
r->y.MoveTo(174.90);
wait(119, msec);
r->x.MoveTo(36.99);
r->y.MoveTo(188.94);
wait(140, msec);
r->x.MoveTo(74.00);
r->y.MoveTo(223.63);
wait(370, msec);
r->x.MoveTo(106.67);
r->y.MoveTo(250.00);
wait(326, msec);
r->x.MoveTo(112.68);
wait(600, msec);
r->x.MoveTo(176.99);
r->y.MoveTo(194.13);
r->z.MoveTo(128.00);
wait(600, msec);
r->z.MoveTo(106.00);
wait(20, msec);


#pragma endregion

  // double centerX = 450;  // mid of your 100–1200 range
  // double centerY = 500;  // mid of your 100–1000 range
  // double radius = 400;   // safe radius inside your bounds
  // double step = 0.05;    // radians per loop (smaller = smoother)

  // #pragma region CircleMovement
  // while (true) {
  //   for (double theta = 0; theta < 2 * M_PI; theta += step) {
  //     double x = centerX + radius * cos(theta);
  //     double y = centerY + radius * sin(theta);s

  //     r->x.MoveTo(x);
  //     r->y.MoveTo(y);
  //     r->z.MoveTo(x/3 + 400);

  //     // optional: wait for both axes to reach the point
  //     wait(40, vex::msec);
  //   }
  // }
  // #pragma endregion

  // TODO make move to function in inches or cm for linear slidesss

  // prototype pancake autonomous full movements, plating, flipping, and
  // dispensing
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