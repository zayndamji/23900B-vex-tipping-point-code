#include "vex.h"
#include "custom.h"

extern bool
  hold_code;

namespace buttons {
  void R1() {
    Lift.setVelocity(lift::normal, percent);
    while (Controller1.ButtonR1.pressing()) {
      Lift.spin(forward);
    wait(5, msec);
    }
    Lift.stop();
  }
  void R2() {
    Lift.setVelocity(lift::normal, percent);
    while (Controller1.ButtonR2.pressing()) {
      Lift.spin(reverse);
      wait(5, msec);
    }
    Lift.stop();
  }

  void L1() {
    if (rollers::dir == 1.0) {
      rollers::stp();
    }
    else {
      Rollers.setVelocity(rollers::normal, percent);
      rollers::fwd();
    }
  }
  void L2() {
    if (rollers::dir == -1.0) {
      rollers::stp();
    }
    else {
      Rollers.setVelocity(rollers::normal, percent);
      rollers::rev();
    }
  }

  void Down() {
    Claw.setVelocity(claw::normal, percent);
    while (Controller1.ButtonDown.pressing()) {
      Claw.spin(reverse);
    wait(5, msec);
    }
    Claw.stop();
  }
  void Up() {
    Claw.setVelocity(claw::normal, percent);
    while (Controller1.ButtonUp.pressing()) {
      Claw.spin(forward);
      wait(5, msec);
    }
    Claw.stop();
  }

  void B() {
    Arm.setVelocity(arm::normal, percent);
    while (Controller1.ButtonB.pressing()) {
      Arm.spin(reverse);
      wait(5, msec);
    }
    Arm.stop();
    Arm.setStopping(hold);
  }

  void X() {
    Arm.setVelocity(arm::normal, percent);
    while (Controller1.ButtonX.pressing()) {
      Arm.spin(forward);
      wait(5, msec);
    }
    Arm.stop();
  }

  void A() {
    if (hold_code) {
      hold_code = false;
      Drivetrain.setStopping(brake);
      Controller1.Screen.setCursor(1, 1);
      Controller1.Screen.print("BRAKE");
    }
    else {
      hold_code = true;
      Drivetrain.setStopping(hold);
      Controller1.Screen.setCursor(1, 1);
      Controller1.Screen.print("HOLD ");
    }
  }

  void Y() {
    arm::up(90.0);
  }
}