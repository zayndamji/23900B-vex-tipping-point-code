#include "vex.h"
#include "custom.h"

int auton_double_neutral_goal() {
  wait(1.1, seconds);
  lift::up(2000.0);
  wait(0.2, seconds);
  lift::up(750.0);
  return 0;
}

void auton_double_neutral() {
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
  wait(0.5, seconds);
  claw::up();
  turn::left(0.4);
  Drivetrain.setDriveVelocity(45, percent);
  Lift.spinFor(reverse, lift::amount, degrees, false);
  drive::backwards(1.15);
  turn::left(0.88);
  thread right_goal = thread(auton_double_neutral_goal);
  drive::backwards(1.4, false);
  wait(3, seconds);
  rollers::fwd();
  Drivetrain.setDriveVelocity(80, percent);
  thread stop_goal = thread([]() {
    wait(1, seconds);
    Lift.spinFor(reverse, 1000, degrees, false);
  });
  drive::forwards(1);
  Drivetrain.setTurnVelocity(30, percent);
  turn::right(1.1);
  Drivetrain.setTurnVelocity(100, percent);
}