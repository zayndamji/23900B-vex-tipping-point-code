#include "vex.h"

namespace lift {
  double auton {100.0};
  double normal {100.0};
  double amount {580.0};
  brakeType stopping {hold};

  void up() {
    Lift.spinFor(forward, amount, degrees, true);
  }
  void up(double custom) {
    Lift.spinFor(forward, custom, degrees, true);
  }
  void up(bool block_program) {
    Lift.spinFor(forward, amount, degrees, block_program);
  }
  void up(double custom, bool block_program) {
    Lift.spinFor(forward, custom, degrees, block_program);
  }

  void down() {
    Lift.spinFor(reverse, amount, degrees, true);
  }
  void down(double custom) {
    Lift.spinFor(reverse, custom, degrees, true);
  }
  void down(bool block_program) {
    Lift.spinFor(reverse, amount, degrees, block_program);
  }
  void down(double custom, bool block_program) {
    Lift.spinFor(reverse, custom, degrees, block_program);
  }
}