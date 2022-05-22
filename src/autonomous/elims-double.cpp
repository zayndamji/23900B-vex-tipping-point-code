#include "vex.h"
#include "custom.h"

void auton_elims_double() {
  Lift.setTimeout(1, seconds);
  Claw.setTimeout(1, seconds);
  claw::down(70.0, false);
  thread arm_down = thread(continued_arming);
  drive::forwards(1.72, false);
  wait(1.1, seconds);
  claw::down(80.0);
  thread claw_down = thread(continued_clawing);
  arm::up(20.0, false);
  drive::backwards(1.1);
  claw::up();
  drive::backwards(0.5);
  arm::down(20.0, false);
  wait(0.4, seconds);
  turn::left(0.31);
  claw::down(55.0, false);
  drive::forwards(1.8);
  Drivetrain.setDriveVelocity(30, percent);
  drive::forwards(0.6);
  claw::down(80.0);
  thread claw_down_2 = thread(continued_clawing);
  Drivetrain.setDriveVelocity(80, percent);
  drive::backwards(1.4);
}