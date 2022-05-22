#include "vex.h"

namespace arm {
  double auton {75.0};
  double normal {75.0};
  double amount {200.0};
  double start {60.0};
  brakeType stopping {brake};

  void up() {
    Arm.spinFor(forward, amount, degrees, true);
  }
  void up(double custom) {
    Arm.spinFor(forward, custom, degrees, true);
  }
  void up(bool block_program) {
    Arm.spinFor(forward, amount, degrees, block_program);
  }
  void up(double custom, bool block_program) {
    Arm.spinFor(forward, custom, degrees, block_program);
  }

  void down() {
    Arm.spinFor(reverse, amount, degrees, true);
  }
  void down(double custom) {
    Arm.spinFor(reverse, custom, degrees, true);
  }
  void down(bool block_program) {
    Arm.spinFor(reverse, amount, degrees, block_program);
  }
  void down(double custom, bool block_program) {
    Arm.spinFor(reverse, custom, degrees, block_program);
  }

  void reset() {
    up(start);
  }
  void reset(bool block_program) {
    up(start, block_program);
  }

  void unreset() {
    down(start);
  }
  void unreset(bool block_program) {
    down(start, block_program);
  }
}