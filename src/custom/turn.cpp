#include "vex.h"

namespace turn {
  double auton {60.0};
  double normal {100.0};
  double amount {115.0};

  void left(double turns) {
    Drivetrain.turnFor(vex::turnType::left, (amount * turns), degrees, true);
  }
  void left(double turns, bool block_program) {
    Drivetrain.turnFor(vex::turnType::left, (amount * turns), degrees, block_program);
  }

  void right(double turns) {
    Drivetrain.turnFor(vex::turnType::right, (amount * turns), degrees, true);
  }
  void right(double turns, bool block_program) {
    Drivetrain.turnFor(vex::turnType::right, (amount * turns), degrees, block_program);
  }
}