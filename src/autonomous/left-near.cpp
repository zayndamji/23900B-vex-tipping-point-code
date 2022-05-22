#include "vex.h"
#include "custom.h"

void auton_left_near() {
  Lift.setTimeout(1, seconds);
  Claw.setTimeout(1, seconds);
  Lift.spinFor(reverse, lift::amount, degrees, false);
  claw::down(70.0, false);
  thread arm_down = thread(continued_arming);
  drive::forwards(1.8, false);
  wait(1.2, seconds);
  claw::down(80.0);
  thread claw_down = thread(continued_clawing);
  arm::up(20.0, false);
  drive::backwards(1.85);
  wait(0.5, seconds);
  claw::up(false);
  wait(0.75, seconds);
  Drivetrain.turnFor(left, 130, degrees, true);
  Drivetrain.setDriveVelocity(30, percent);
  drive::backwards(0.7, false);
  wait(1, seconds);
  Lift.spinFor(forward, 1000, degrees, true);
  wait(0.25, seconds);
  drive::forwards(0.35);
  Lift.spinFor(forward, 500, degrees, true);
  wait(0.5, seconds);
  rollers::fwd();
  wait(2, seconds);
  Lift.spinFor(reverse, 1000, degrees, true);
  rollers::stp();
  drive::forwards(0.4);
  turn::right(1.2);
  Drivetrain.setDriveVelocity(30, percent);
  arm::down(20.0, false);
  drive::forwards(0.3);
  Drivetrain.setDriveVelocity(100, percent);
  claw::down();
}