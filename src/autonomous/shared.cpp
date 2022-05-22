#include "vex.h"
#include "custom.h"

int continued_clawing() {
  Claw.spin(reverse);
  wait(0.5, seconds);
  Claw.stop();
  return 0;
}

int continued_arming() {
  Arm.spin(reverse);
  wait(0.15, seconds);
  Arm.stop();
  arm::reset();
  return 0;
}