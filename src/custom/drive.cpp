#include "vex.h"

namespace drive {
  double auton {100.0};
  double normal {95.0};
  double amount {23.2};
  brakeType stopping {brake};

  void forwards(double blocks) {
    Drivetrain.driveFor(vex::forward, (amount * blocks), inches, true);
  }
  void forwards(double blocks, bool block_program) {
    Drivetrain.driveFor(vex::forward, (amount * blocks), inches, block_program);
  }

  void backwards(double blocks) {
    Drivetrain.driveFor(vex::reverse, (amount * blocks), inches, true);
  }
  void backwards(double blocks, bool block_program) {
    Drivetrain.driveFor(vex::reverse, (amount * blocks), inches, block_program);
  }
}