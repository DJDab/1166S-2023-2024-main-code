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
// Drivetrain           drivetrain    1, 2, 5         
// Controller1          controller                    
// MotorGroup6          motor_group   6, 7            
// MotorGroup8          motor_group   8, 9            
// Controller2          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // setting commands for motor group 6 elevation
  MotorGroup6.setMaxTorque(100,percent);
  MotorGroup6.setVelocity(45,percent);
  MotorGroup6.setStopping(hold);

  //setting commands for motor group 8 elevation grabber
  MotorGroup8.setMaxTorque(100,percent);
  MotorGroup8.setVelocity(45,percent);
  MotorGroup8.setStopping(hold);
   
  bool ptoEnabled = true;
  //double forward ;
  //double turn ;

 // If PTO is false that means all 4 motors are on drive train if true that means that only 2 motors are on drive train.
  while(1)
  {
    if(ptoEnabled == false){
      
    }else if(ptoEnabled == true){
      if(Controller1.ButtonR1.pressing()){
        MotorGroup6.spin(forward);
      }else if(Controller1.ButtonL1.pressing()){
        MotorGroup6.spin(reverse);
      }else{
        MotorGroup6.stop();
      }

      if(Controller2.ButtonLeft.pressing()){
        MotorGroup8.spin(forward);
      }else if(Controller2.ButtonRight.pressing()){
        MotorGroup8.spin(reverse);
      }else{
        MotorGroup8.stop();
      }
    }
  }



}
