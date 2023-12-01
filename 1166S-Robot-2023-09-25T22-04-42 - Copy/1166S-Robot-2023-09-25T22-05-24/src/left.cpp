
#include "vex.h"
#include "left.h"

void autonLeft(){
  // start of code Rasing lift arm and going to goal
  MotorGroup4.setVelocity(100,percent);
  MotorGroup4.setMaxTorque(100,percent);
  leftDriveMotor.setVelocity(49,percent);
  rightDriveMotor.setVelocity(49,percent);
  MotorGroup4.spinFor(reverse,3,rev,false);
  leftDriveMotor.spinFor(forward,7,rev,false);
  rightDriveMotor.spinFor(forward,7,rev,false);
  pickupMotor.setVelocity(7.5,percent);
  pickupMotor.spinFor(forward,0.3,rev);
  wait(.8,sec);


  // reversing away from goal and turning twords match load
  leftDriveMotor.spinFor(reverse,0.55,rev,false);
  rightDriveMotor.spinFor(reverse,0.55,rev);
  pickupMotor.spinFor(reverse,0.1,rev,false);
  leftDriveMotor.spin(reverse);
    // turning twords match load zone
  waitUntil(InertialSens.heading() <= 261 && InertialSens.heading() > 50);
  leftDriveMotor.stop();
  leftDriveMotor.setVelocity(25,percent);
  rightDriveMotor.setVelocity(25,percent);
  leftDriveMotor.spinFor(forward,3.25,rev,false);
  rightDriveMotor.spinFor(forward,3.50,rev,false);
  pickupMotor.spinFor(forward,0.27,rev,false);
  wait(2.25,sec);
    //picking up match load
  rightDriveMotor.spinFor(reverse,0.05,rev,false);
  leftDriveMotor.spinFor(reverse,0.05,rev,false);
  pickupMotor.setVelocity(50,percent);
  pickupMotor.spinFor(reverse,0.4,rev);
  leftDriveMotor.setVelocity(35,percent);
  leftDriveMotor.spinFor(reverse,2,rev,false);
  rightDriveMotor.spinFor(reverse,1.5,rev);
  rightDriveMotor.setVelocity(50,percent);
  rightDriveMotor.spin(forward);
  //turning twords elevation bar
  waitUntil(InertialSens.heading() <= 165);
  rightDriveMotor.stop();
  rightDriveMotor.setVelocity(70,percent);
  leftDriveMotor.setVelocity(50,percent);
  rightDriveMotor.spinFor(forward,3,rev,false);
  leftDriveMotor.spinFor(forward,1.8,rev);
  pickupMotor.spinFor(forward,0.3,rev);
  pickupMotor.spinFor(reverse,0.4,rev);
  leftDriveMotor.spinFor(forward,2.1,rev,false);
  rightDriveMotor.spinFor(forward,2.1,rev);
  pickupMotor.spinFor(forward,0.2,rev);
  
}