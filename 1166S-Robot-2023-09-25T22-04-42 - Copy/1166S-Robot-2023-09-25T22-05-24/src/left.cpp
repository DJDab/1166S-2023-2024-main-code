
#include "vex.h"
#include "left.h"

void autonLeft(){
  MotorGroup4.setVelocity(100,percent);
  MotorGroup4.setMaxTorque(100,percent);
  leftDriveMotor.setVelocity(49,percent);
  rightDriveMotor.setVelocity(49,percent);
  MotorGroup4.spinFor(reverse,4,rev,false);
  leftDriveMotor.spinFor(forward,7,rev,false);
  rightDriveMotor.spinFor(forward,7,rev,false);
  pickupMotor.setVelocity(5.9,percent);
  pickupMotor.spinFor(forward,0.3,rev);
  wait(.5,sec);



  leftDriveMotor.spinFor(reverse,0.6,rev,false);
  rightDriveMotor.spinFor(reverse,0.6,rev);
  pickupMotor.spinFor(reverse,0.1,rev,false);
  leftDriveMotor.spin(reverse);
  waitUntil(InertialSens.heading() <= 260 &&InertialSens.heading() > 10);
  leftDriveMotor.stop();
  leftDriveMotor.setVelocity(25,percent);
  rightDriveMotor.setVelocity(25,percent);
  leftDriveMotor.spinFor(forward,3.25,rev,false);
  rightDriveMotor.spinFor(forward,3.50,rev,false);
  pickupMotor.spinFor(forward,0.27,rev,false);
  wait(2,sec);
  pickupMotor.setVelocity(50,percent);
  pickupMotor.spinFor(reverse,0.4,rev);
  leftDriveMotor.setVelocity(35,percent);
  leftDriveMotor.spinFor(reverse,2,rev,false);
  rightDriveMotor.spinFor(reverse,1.5,rev);
  rightDriveMotor.setVelocity(50,percent);
  rightDriveMotor.spin(forward);
  waitUntil(InertialSens.heading() <= 150);
  rightDriveMotor.stop();
  rightDriveMotor.setVelocity(70,percent);
  leftDriveMotor.setVelocity(50,percent);
  rightDriveMotor.spinFor(forward,3,rev,false);
  leftDriveMotor.spinFor(forward,3,rev);
  
}