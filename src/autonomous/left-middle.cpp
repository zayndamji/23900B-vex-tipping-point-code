#include "vex.h"
#include "custom.h"

void auton_left_middle() {
  Drivetrain.setDriveVelocity(60, percent);
  Lift.setTimeout(1, seconds);
  Claw.setTimeout(1, seconds);
  arm::reset(false);
  claw::up(false);
  drive::forwards(0.8);
  wait(0.2, seconds);
  turn::right(1);
  drive::forwards(1.1);
  turn::left(0.67);
  drive::forwards(1.1);
  Drivetrain.setDriveVelocity(30, percent);
  drive::forwards(0.3);
  Drivetrain.setDriveVelocity(80, percent);
  Drivetrain.turnFor(left, 5, degrees, true);
  claw::down();
  drive::backwards(1.6);
  claw::up();
  wait(0.3, seconds);
  turn::left(1.4);
  drive::forwards(1.3);
  turn::right(0.8);
  Drivetrain.setDriveVelocity(30, percent);
  drive::backwards(0.4);
  lift::up(2000.0);
  rollers::fwd();
}