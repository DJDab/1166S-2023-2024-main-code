#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor MotorGroup4MotorA = motor(PORT2, ratio18_1, false);
motor MotorGroup4MotorB = motor(PORT7, ratio18_1, true);
motor_group MotorGroup4 = motor_group(MotorGroup4MotorA, MotorGroup4MotorB);
motor MotorGroup8MotorA = motor(PORT8, ratio18_1, true);
motor MotorGroup8MotorB = motor(PORT9, ratio18_1, true);
motor_group MotorGroup8 = motor_group(MotorGroup8MotorA, MotorGroup8MotorB);
controller Controller2 = controller(partner);
motor leftDriveMotor = motor(PORT15, ratio18_1, false);
motor rightDriveMotor = motor(PORT16, ratio18_1, true);
motor ptoRightMotor = motor(PORT17, ratio36_1, true);
motor ptoLeftMotor = motor(PORT18, ratio36_1, false);
digital_out ptoPh = digital_out(Brain.ThreeWirePort.E);
motor pickupMotor = motor(PORT20, ratio36_1, true);
inertial InertialSens = inertial(PORT11);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}