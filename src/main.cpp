// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 10, 4, 7     
// Rollers              motor         8               
// Claw                 motor         6               
// Lift                 motor         2               
// Arm                  motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "buttons.h"
#include "autonomous.h"
#include "custom.h"

competition Competition;

bool hold_code{false};

int display_temperatures();

void beginning_config() {
  Controller1.Screen.setCursor(1, 1);
  Controller1.Screen.print("BRAKE                   ");
  Claw.setStopping(claw::stopping);
  Arm.setStopping(arm::stopping);
  Lift.setStopping(lift::stopping);
  Drivetrain.setStopping(drive::stopping);
  Drivetrain.setDriveVelocity(drive::normal, percent);
  Drivetrain.setTurnVelocity(turn::normal, percent);
  Lift.setVelocity(lift::normal, percent);
  Rollers.setVelocity(rollers::normal, percent);
  Claw.setVelocity(claw::normal, percent);
  Arm.setVelocity(arm::normal, percent);
}

int auton_period() {
  beginning_config();
  Arm.setStopping(hold);
  Drivetrain.setDriveVelocity(drive::auton, percent);
  Drivetrain.setTurnVelocity(turn::auton, percent);
  Lift.setVelocity(lift::auton, percent);
  Rollers.setVelocity(rollers::auton, percent);
  Claw.setVelocity(claw::auton, percent);
  Arm.setVelocity(arm::auton, percent);

  auton_right_middle();
  return 0;
}

int driver_control_period() {
  beginning_config();
  return 0;
}

void VEXcode_driver_task() {
  vex::task drive0(driver_control_period);
  while(Competition.isDriverControl() && Competition.isEnabled()) {this_thread::sleep_for(10);}
  drive0.stop();
  return;
}

void VEXcode_auton_task() {
  vex::task auto0(auton_period);
  while(Competition.isAutonomous() && Competition.isEnabled()) {this_thread::sleep_for(10);}
  auto0.stop();
  return;
}

int main() {
  vex::competition::bStopTasksBetweenModes = false;
  vexcodeInit();
  Competition.autonomous(VEXcode_auton_task);
  Competition.drivercontrol(VEXcode_driver_task);

  Controller1.ButtonR1.pressed(buttons::R1);
  Controller1.ButtonR2.pressed(buttons::R2);

  Controller1.ButtonL1.pressed(buttons::L1);
  Controller1.ButtonL2.pressed(buttons::L2);

  Controller1.ButtonDown.pressed(buttons::Down);
  Controller1.ButtonUp.pressed(buttons::Up);

  Controller1.ButtonB.pressed(buttons::B);
  Controller1.ButtonX.pressed(buttons::X);
  Controller1.ButtonA.pressed(buttons::A);
  Controller1.ButtonY.pressed(buttons::Y);

  wait(15, msec);
  beginning_config();
  thread temps = thread(display_temperatures);
}

void printTemp(int lineNum, std::string motorName, motor motorObject) {
  int motorTemp = motorObject.temperature(celsius);

  Brain.Screen.setCursor(lineNum, 1);
  Brain.Screen.setPenColor(white);
  Brain.Screen.print(motorName.c_str());

  if (motorTemp != 21) {
    if (motorTemp >= 55) Brain.Screen.setPenColor(red);
    else if (motorTemp >= 50) Brain.Screen.setPenColor(yellow);
    else Brain.Screen.setPenColor(green);
    Brain.Screen.print(motorTemp);
  }

  else {
    Brain.Screen.setPenColor(orange);
    Brain.Screen.print("NOT CONNECTED");
  }
}

void printBrainBattery() {
  int brainBattery = Brain.Battery.capacity();

  Brain.Screen.setCursor(12, 1);
  Brain.Screen.setPenColor(white);
  Brain.Screen.print("Brain Battery: ");

  if (brainBattery > 50) Brain.Screen.setPenColor(green);
  else if (brainBattery > 25) Brain.Screen.setPenColor(yellow);
  else Brain.Screen.setPenColor(red);
  Brain.Screen.print(brainBattery);
  Brain.Screen.print("%%");
}

void printMotorTemperatures() {
  printTemp(1, "Right Motor 1: ", rightMotorA);
  printTemp(2, "Right Motor 2: ", rightMotorB);
  printTemp(3, "Left Motor 1: ", leftMotorA);
  printTemp(4, "Left Motor 2: ", leftMotorB);
  printTemp(5, "Rollers: ", Rollers);
  printTemp(6, "Lift: ", Lift);
  printTemp(7, "Arm: ", Arm);
  printTemp(8, "Claw: ", Claw);
}

void printControllerTemperatures() {
  Controller1.Screen.setCursor(1, 21);
  Controller1.Screen.print(int(rightMotorA.temperature(celsius)));
  Controller1.Screen.print("   ");
}

int display_temperatures() {
  while (true) {
    printMotorTemperatures();
    printBrainBattery();
    printControllerTemperatures();

    this_thread::sleep_for(10000);
  }

  return 0;
}