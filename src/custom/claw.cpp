#include "vex.h"

namespace claw {
  double auton {100.0};
  double normal {100.0};
  double amount {125.0};
  brakeType stopping {coast};

  void up() {
    Claw.spinFor(forward, amount, degrees, true);
  }
  void up(double custom) {
    Claw.spinFor(forward, custom, degrees, true);
  }
  void up(bool block_program) {
    Claw.spinFor(forward, amount, degrees, block_program);
  }
  void up(double custom, bool block_program) {
    Claw.spinFor(forward, custom, degrees, block_program);
  }

  void down() {
    Claw.spinFor(reverse, amount, degrees, true);
  }
  void down(double custom) {
    Claw.spinFor(reverse, custom, degrees, true);
  }
  void down(bool block_program) {
    Claw.spinFor(reverse, amount, degrees, block_program);
  }
  void down(double custom, bool block_program) {
    Claw.spinFor(reverse, custom, degrees, block_program);
  }
}