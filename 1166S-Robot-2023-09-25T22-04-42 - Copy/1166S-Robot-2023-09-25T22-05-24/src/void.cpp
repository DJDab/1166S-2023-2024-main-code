
/*#include "vex.h"

void driverControl(){


   bool ptoEnabled = true;
  //double forward ;
  //double turn ;

  //setting commands for the pnematics


  // setting commands for motor group 6 elevation
    MotorGroup4.setMaxTorque(100,percent);
    MotorGroup4.setVelocity(45,percent);
    MotorGroup4.setStopping(hold);

  //setting commands for motor group 8 elevation grabber
    MotorGroup8.setMaxTorque(100,percent);
    MotorGroup8.setVelocity(20,percent);
    MotorGroup8.setStopping(hold);

  //setting comands for the pickup motors
    pickupMotor.setMaxTorque(100,percent);
    pickupMotor.setVelocity(90,percent);
    pickupMotor.setStopping(brake);

  //setting commands for Drive motors
    //Left motor
    leftDriveMotor.setMaxTorque(100,percent);
    leftDriveMotor.setVelocity(100,percent);
    leftDriveMotor.setStopping(coast);

    //Right motor
    rightDriveMotor.setMaxTorque(100,percent);
    rightDriveMotor.setVelocity(100,percent);
    rightDriveMotor.setStopping(coast);

  //setting commands for PTO motors
    //left motor
    ptoLeftMotor.setMaxTorque(100,percent);
    ptoLeftMotor.setVelocity(100,percent);
    ptoLeftMotor.setStopping(hold);
    
    //right motor
    ptoRightMotor.setMaxTorque(100,percent);
    ptoRightMotor.setVelocity(100,percent);
    ptoRightMotor.setStopping(hold);

 // If PTO is false that means all 4 motors are on drive train if true that means that only 2 motors are on drive train.
  while(1)
  {
    Controller1.Screen.print(ptoEnabled);
  
    if(ptoEnabled == true){

        //code for pickup fork
      if (Controller2.ButtonR2.pressing()){
        pickupMotor.setVelocity(30,percent);
        pickupMotor.spin(forward);
      }else if(Controller2.ButtonL2.pressing()){
        pickupMotor.setVelocity(25,percent);
        pickupMotor.spin(reverse);
      }else{
        pickupMotor.stop();
      }

      //controlls for the elevation bar ports
      if(Controller2.ButtonR1.pressing()){
        MotorGroup4.spin(forward);
      }else if(Controller2.ButtonL1.pressing()){
        MotorGroup4.spin(reverse);
      }else{
        MotorGroup4.stop();
      }

      //controlls for the elevation GRABBER ports 8/9
      if(Controller2.ButtonLeft.pressing()){
        MotorGroup8.spin(forward);
      }else if(Controller2.ButtonRight.pressing()){
        MotorGroup8.spin(reverse);
      }else{
        MotorGroup8.stop();
      }
    

    //Primary drive train when PTO is True (its on catapult)
      //foreward button movment
      if(Controller1.ButtonR2.pressing()){
        
        leftDriveMotor.spin(forward);
        rightDriveMotor.spin(forward);

        //turning while moving foreward  
            
        if(Controller1.Axis4.position(percent) >= 20){
          rightDriveMotor.setVelocity(25,percent);
        }else if(Controller1.Axis4.position(percent) <= -20){
          leftDriveMotor.setVelocity(25,percent);
        }else{
          leftDriveMotor.setVelocity(100,percent);
          rightDriveMotor.setVelocity(100,percent);
        }
          
      //reverse button movment
      } else if(Controller1.ButtonL2.pressing()){
        leftDriveMotor.spin(reverse);
        rightDriveMotor.spin(reverse);

        //turning in reverse
        
        if(Controller1.Axis4.position(percent) >= 20){
          rightDriveMotor.setVelocity(25,percent);
        }else if(Controller1.Axis4.position(percent) <= -20){
          leftDriveMotor.setVelocity(25,percent);
        }else{
          leftDriveMotor.setVelocity(100,percent);
          rightDriveMotor.setVelocity(100,percent);
        }
          
      }else{
        //leftDriveMotor.setVelocity(100,percent);
        //rightDriveMotor.setVelocity(100,percent);
        
        //turning code for when the robot is holding still
        double crtlPct = Controller1.Axis4.position(percent) - 20;
        if(crtlPct <= -40 ){
          rightDriveMotor.spin(forward,-crtlPct,percent);
          leftDriveMotor.spin(forward,crtlPct,percent);
        }else if(crtlPct>= 40){
           rightDriveMotor.spin(forward,-crtlPct,percent);
          leftDriveMotor.spin(forward,crtlPct,percent);
        }else{
          leftDriveMotor.stop();
          rightDriveMotor.stop();
        }
      }
    
      if (Controller1.ButtonR1.pressing()){
        ptoLeftMotor.spin(forward);
        ptoRightMotor.spin(reverse);
      }else{
        ptoLeftMotor.stop();
        ptoRightMotor.stop();
      }


      if(Controller1.ButtonA.pressing()){
          ptoRightMotor.spinToPosition(90,degrees,50, rpm,false);
          ptoLeftMotor.spinToPosition(90,degrees,50,rpm,false);
          ptoRightMotor.spinToPosition(90,degrees,50,rpm,false);
          ptoLeftMotor.spinToPosition(90,degrees,50,rpm,false);
        
      
      
        ptoEnabled = false;
        


        //settings for motors
        ptoLeftMotor.setVelocity(30,percent);
        ptoLeftMotor.setStopping(hold);

        ptoRightMotor.setVelocity(30,percent);
        ptoRightMotor.setStopping(hold);
      }
        //fixing possitions of off timed pto gears
        
      
    
    //driving when PTO is dissabled all 4 motors are working
    }else if(ptoEnabled == false){


        //code for pickup fork
      if (Controller2.ButtonR2.pressing()){
        pickupMotor.spin(forward);
      }else if(Controller2.ButtonL2.pressing()){
        pickupMotor.spin(reverse);
      }else{
        pickupMotor.stop();
      }

      //controlls for the elevation bar ports
      if(Controller2.ButtonR1.pressing()){
        MotorGroup4.spin(forward);
      }else if(Controller2.ButtonL1.pressing()){
        MotorGroup4.spin(reverse);
      }else{
        MotorGroup4.stop();
      }

      //controlls for the elevation GRABBER ports 8/9
      if(Controller2.ButtonLeft.pressing()){
        MotorGroup8.spin(forward);
      }else if(Controller2.ButtonRight.pressing()){
        MotorGroup8.spin(reverse);
      }else{
        MotorGroup8.stop();
      }
    

    //Primary drive train when PTO is True (its on catapult)
      //foreward button movment
      if(Controller1.ButtonR2.pressing()){
        
        leftDriveMotor.spin(forward);
        rightDriveMotor.spin(forward);
        ptoLeftMotor.spin(forward);
        ptoRightMotor.spin(forward);

        //turning while moving foreward  
         
        if(Controller1.Axis4.position(percent) >= 20){
          rightDriveMotor.setVelocity(25,percent);
        }else if(Controller1.Axis4.position(percent) <= -20){
          leftDriveMotor.setVelocity(25,percent);
        }else{
          leftDriveMotor.setVelocity(100,percent);
          rightDriveMotor.setVelocity(100,percent);
        }
          
      //reverse button movment
      } else if(Controller1.ButtonL2.pressing()){
        leftDriveMotor.spin(reverse);
        rightDriveMotor.spin(reverse);
        ptoLeftMotor.spin(reverse);
        ptoRightMotor.spin(reverse);

        //turning in reverse
        
        if(Controller1.Axis4.position(percent) >= 20){
          rightDriveMotor.setVelocity(25,percent);
        }else if(Controller1.Axis4.position(percent) <= -20){
          leftDriveMotor.setVelocity(25,percent);
        }else{
          leftDriveMotor.setVelocity(100,percent);
          rightDriveMotor.setVelocity(100,percent);
        }
          
      }else{
        //leftDriveMotor.setVelocity(100,percent);
        //rightDriveMotor.setVelocity(100,percent);
        
        //turning code for when the robot is holding still
        double crtlPct = Controller1.Axis4.position(percent) - 20;
        if(crtlPct <= -40 ){
          rightDriveMotor.spin(forward,-crtlPct,percent);
          leftDriveMotor.spin(forward,crtlPct,percent);
        }else if(crtlPct>= 40){
           rightDriveMotor.spin(forward,-crtlPct,percent);
          leftDriveMotor.spin(forward,crtlPct,percent);
        }else{
          leftDriveMotor.stop();
          rightDriveMotor.stop();
          ptoLeftMotor.stop();
          ptoRightMotor.stop();
        }
      }


      if(Controller1.ButtonA.pressing()){
        ptoEnabled = true;


        //settings for motors
        ptoLeftMotor.setVelocity(100,percent);
        ptoLeftMotor.setStopping(coast);

        ptoRightMotor.setVelocity(100,percent);
        ptoRightMotor.setStopping(coast);

      }


  //swap between PTO true and false, if true motors on drive if false motors on catapult
   if(ptoEnabled == true and Controller1.ButtonA.pressing()){
    if (ptoLeftMotor.position(degrees) != 0){
      ptoLeftMotor.spinToPosition(0,degrees);
    }
    if (ptoRightMotor.position(degrees) != 0){
      ptoRightMotor.spinToPosition(0,degrees,-100,rpm);
    }
    
    ptoEnabled = false;
    ptoLeftPh.set(false);
    ptoRightPh.set(false);

    //settings for motors
    ptoLeftMotor.setVelocity(30,percent);
    ptoLeftMotor.setStopping(hold);

    ptoRightMotor.setVelocity(30,percent);
    ptoRightMotor.setStopping(hold);

    }else if(ptoEnabled == false and Controller1.ButtonA.pressing()){
    ptoEnabled = true;
    ptoLeftPh.set(true);
    ptoRightPh.set(true);

    //settings for motors
    ptoLeftMotor.setVelocity(100,percent);
    ptoLeftMotor.setStopping(coast);

    ptoRightMotor.setVelocity(100,percent);
    ptoRightMotor.setStopping(coast);

    }
  }

  }

}
*/