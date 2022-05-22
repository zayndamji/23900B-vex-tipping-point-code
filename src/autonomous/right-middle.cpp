#include "vex.h"
#include "custom.h"

int auton_right_middle_goal() {
  wait(0.7, seconds);
  lift::up(2000.0);
  wait(0.5, seconds);
  lift::up(500.0);
  return 0;
}

void auton_right_middle() {
  Lift.setTimeout(1, seconds);
  Claw.setTimeout(1, seconds);
  Lift.spinFor(reverse, lift::amount, degrees, false);
  claw::down(70.0, false);
  thread arm_down = thread(continued_arming);
  drive::forwards(0.7);
  wait(0.5, seconds);
  Drivetrain.setTurnVelocity(30, percent);
  turn::left(0.42);
  Drivetrain.setTurnVelocity(80, percent);
  drive::forwards(1.5);
  Drivetrain.setDriveVelocity(30, percent);
  drive::forwards(0.5);
  Drivetrain.setDriveVelocity(100, percent);
  claw::down(80.0);
  thread claw_down = thread(continued_clawing);
  drive::backwards(2.4);
  wait(0.3, seconds);
}