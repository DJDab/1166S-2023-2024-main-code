/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\dabrg                                            */
/*    Created:      Thu Sep 21 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// MotorGroup4          motor_group   2, 7            
// MotorGroup8          motor_group   8, 9            
// Controller2          controller                    
// leftDriveMotor       motor         15              
// rightDriveMotor      motor         16              
// ptoRightMotor        motor         17              
// ptoLeftMotor         motor         18              
// ptoPh                digital_out   E               
// pickupMotor          motor         20              
// InertialSens         inertial      11              
// ---- END VEXCODE CONFIGURED DEVICES ----


#include "driverControl.h"

#include "auton.h"

#include "vex.h"
#include <iostream>

using namespace vex;
using namespace std;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  InertialSens.calibrate();

  competition comsw;

  comsw.autonomous(auton);

  comsw.drivercontrol(driverControl);
}
//end of main bracket