
#include "vex.h"
#include "left.h"

void autonLeft(){
<<<<<<< HEAD
  // start of code Rasing lift arm and going to goal
=======
  //sets velocity and torque and variables
>>>>>>> 1459d337e8b8ebb188cfb73617eed18abfd11b4c
  MotorGroup4.setVelocity(100,percent);
  MotorGroup4.setMaxTorque(100,percent);
  leftDriveMotor.setVelocity(49,percent);
  rightDriveMotor.setVelocity(49,percent);
<<<<<<< HEAD
  MotorGroup4.spinFor(reverse,3,rev,false);
  leftDriveMotor.spinFor(forward,7,rev,false);
  rightDriveMotor.spinFor(forward,7,rev,false);
  pickupMotor.setVelocity(7.5,percent);
  pickupMotor.spinFor(forward,0.3,rev);
  wait(.8,sec);


  // reversing away from goal and turning twords match load
  leftDriveMotor.spinFor(reverse,0.55,rev,false);
  rightDriveMotor.spinFor(reverse,0.55,rev);
=======

  //moves twords the goal with the triball
  MotorGroup4.spinFor(reverse,4,rev,false);
  //raise arm
  leftDriveMotor.spinFor(forward,7,rev,false);
  rightDriveMotor.spinFor(forward,7,rev,true);
  //moves the manipulation arm
  pickupMotor.setVelocity(5.9,percent);
  pickupMotor.spinFor(forward,0.3,rev);
  wait(.5,sec);
  //moves away twords goal
  leftDriveMotor.spinFor(reverse,0.6,rev,false);
  rightDriveMotor.spinFor(reverse,0.6,rev);
  //raises the manipulator 
>>>>>>> 1459d337e8b8ebb188cfb73617eed18abfd11b4c
  pickupMotor.spinFor(reverse,0.1,rev,false);
  //turns the robot twords the match loader
  leftDriveMotor.spin(reverse);
    // turning twords match load zone
  waitUntil(InertialSens.heading() <= 261 && InertialSens.heading() > 50);
  leftDriveMotor.stop();
  //sets the velocity of the drive motors
  leftDriveMotor.setVelocity(25,percent);
  rightDriveMotor.setVelocity(25,percent);
  //drives forward to the match loader
  leftDriveMotor.spinFor(forward,3.25,rev,false);
  rightDriveMotor.spinFor(forward,3.50,rev,false);
  //picks up triball in the match loader
  pickupMotor.spinFor(forward,0.27,rev,false);
<<<<<<< HEAD
  wait(2.25,sec);
    //picking up match load
  rightDriveMotor.spinFor(reverse,0.05,rev,false);
  leftDriveMotor.spinFor(reverse,0.05,rev,false);
=======
  wait(2,sec);
  //
>>>>>>> 1459d337e8b8ebb188cfb73617eed18abfd11b4c
  pickupMotor.setVelocity(50,percent);
  pickupMotor.spinFor(reverse,0.4,rev);
  //turns the robot to move twords the elevation bar57-w
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