#include "vex.h"
#include "custom.h"

int auton_right_near_goal() {
  wait(1.65, seconds);
  lift::up(2000.0);
  wait(1.5, seconds);
  lift::up(500.0);
  return 0;
}

void auton_right_near() {
  Lift.setTimeout(1, seconds);
  Claw.setTimeout(1, seconds);
  Lift.spinFor(reverse, lift::amount, degrees, false);
  claw::down(70.0, false);
  thread arm_down = thread(continued_arming);
  drive::forwards(1.72, false);
  wait(1.1, seconds);
  claw::down(80.0);
  thread claw_down = thread(continued_clawing);
  arm::up(20.0, false);
  drive::backwards(1.35);
}