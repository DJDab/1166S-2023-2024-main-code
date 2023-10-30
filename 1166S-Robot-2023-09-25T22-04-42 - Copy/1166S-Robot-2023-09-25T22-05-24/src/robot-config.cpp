#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftDriveSmart = motor(PORT1, ratio18_1, false);
motor RightDriveSmart = motor(PORT2, ratio18_1, true);
inertial DrivetrainInertial = inertial(PORT5);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainInertial, 319.19, 320, 40, mm, 1);
controller Controller1 = controller(primary);
motor MotorGroup4MotorA = motor(PORT4, ratio18_1, false);
motor MotorGroup4MotorB = motor(PORT7, ratio18_1, true);
motor_group MotorGroup4 = motor_group(MotorGroup4MotorA, MotorGroup4MotorB);
motor MotorGroup8MotorA = motor(PORT8, ratio18_1, true);
motor MotorGroup8MotorB = motor(PORT9, ratio18_1, false);
motor_group MotorGroup8 = motor_group(MotorGroup8MotorA, MotorGroup8MotorB);
controller Controller2 = controller(partner);
motor leftDriveMotor = motor(PORT15, ratio18_1, false);
motor rightDriveMotor = motor(PORT16, ratio18_1, true);
motor ptoRightMotor = motor(PORT17, ratio18_1, true);
motor ptoLeftMotor = motor(PORT18, ratio18_1, false);
digital_out ptoRightPh = digital_out(Brain.ThreeWirePort.A);
digital_out ptoLeftPh = digital_out(Brain.ThreeWirePort.B);
motor pickupMotor = motor(PORT20, ratio18_1, true);
digital_out PoleTopper = digital_out(Brain.ThreeWirePort.D);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain Inertial
  wait(200, msec);
  DrivetrainInertial.calibrate();
  Brain.Screen.print("Calibrating Inertial for Drivetrain");
  // wait for the Inertial calibration process to finish
  while (DrivetrainInertial.isCalibrating()) {
    wait(25, msec);
  }
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}