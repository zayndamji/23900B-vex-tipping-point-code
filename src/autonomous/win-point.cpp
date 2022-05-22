#include "vex.h"
#include "custom.h"

int auton_win_point_goal() {
  wait(1.2, seconds);
  lift::up(2000.0);
  wait(0.5, seconds);
  lift::up(500.0);
  return 0;
}

void auton_win_point() {
  Lift.setTimeout(1, seconds);
  Claw.setTimeout(1, seconds);
  arm::up(100.0, false);
  Lift.spinFor(reverse, lift::amount, degrees, false);
  Drivetrain.setDriveVelocity(40, percent);
  drive::forwards(0.35);
  claw::down(90.0);
  Drivetrain.turnFor(right, 10, degrees, true);
  claw::up(90.0, false);
  arm::down(70.0, false);
  Drivetrain.setTurnVelocity(30, percent);
  drive::backwards(0.3);
  turn::right(0.9);
  drive::backwards(0.75);
  turn::right(1);
  Drivetrain.setTurnVelocity(100, percent);
  Drivetrain.setDriveVelocity(60, percent);
  drive::backwards(3.6);
  thread win_point_goal = thread(auton_win_point_goal);
  drive::backwards(1.05, false);
  wait(2, seconds);
  drive::forwards(1);
  rollers::fwd();
  wait(0.5, seconds);
  turn::right(0.5);
  Drivetrain.setDriveVelocity(100, percent);
  lift::down(750.0);
  drive::forwards(0.3);
}