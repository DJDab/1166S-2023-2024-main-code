#include "vex.h"
#include "driverControl.h"

void driverControl(){

  ptoRightMotor.setVelocity(50,percent);
  ptoLeftMotor.setVelocity(50, percent);
  ptoRightMotor.setPosition(90,degrees);
  ptoLeftMotor.setPosition(90,degrees);
  pickupMotor.setPosition(180,deg);
  pickupMotor.setMaxTorque(100,pct);
  pickupMotor.setStopping(hold);
  pickupMotor.setVelocity(10,pct);
  int ct = 0;
  ptoRightMotor.setStopping(hold);
  ptoLeftMotor.setStopping(hold);
  while(1){
    
    if(Controller2.ButtonR2.pressing()){
      MotorGroup4.spin(forward);
    }else if(Controller2.ButtonL2.pressing()){
      MotorGroup4.spin(reverse);
    }else{
      MotorGroup4.setVelocity(100,percent);
      MotorGroup4.stop();
    }
    
    
    /*else if(Controller1.ButtonDown.pressing())
    {
       if((ptoRightMotor.position(deg) == ptoLeftMotor.position(deg)+50)||(ptoRightMotor.position(deg) == ptoLeftMotor.position(deg)-50)){
        ptoRightMotor.spinFor(reverse,90,deg,100,rpm,false);
        ptoLeftMotor.spinFor(reverse,90,deg,100,rpm);
       }else{
         int reset = ptoRightMotor.position(deg);
         ptoLeftMotor.spinToPosition(reset,deg, 50,rpm);
       }
    }else
    if(Controller1.ButtonDown.pressing()&& ct == 0){
      ptoRightMotor.spin(reverse);
      ptoLeftMotor.spin(reverse);
    }else
    {
      ptoRightMotor.stop();
      ptoLeftMotor.stop();
    }*/


    double turnPct = Controller1.Axis4.position();
    // Turns Right and moves forward
    if(turnPct> 20 && Controller1.ButtonR2.pressing())
    {
      
      leftDriveMotor.spin(forward,100,pct);
      rightDriveMotor.spin(forward,30,pct);
    }
    // Turns Left and moves backwards
    else if(turnPct> 20 && Controller1.ButtonL2.pressing())
    {
      
      leftDriveMotor.spin(reverse,100,pct);
      rightDriveMotor.spin(reverse,30,pct);
    }
    //Turns Left and moves forward
    else if(turnPct< -20 && Controller1.ButtonR2.pressing())
    {
      
      leftDriveMotor.spin(forward,30,pct);
      rightDriveMotor.spin(forward,100,pct);
    }
    //Turns Right and moves backwards
    else if(turnPct< -20 && Controller1.ButtonL2.pressing())
    {
      
      leftDriveMotor.spin(reverse,30,pct);
      rightDriveMotor.spin(reverse,100,pct);
    }
    //Turns Right 
    else if(turnPct > 20)
    {
      leftDriveMotor.spin(forward,turnPct,pct);
      rightDriveMotor.spin(reverse,turnPct,pct);
    }
    //Turns Left
    else if(turnPct < -20)
    {
      leftDriveMotor.spin(forward,turnPct,pct);
      rightDriveMotor.spin(reverse,turnPct,pct);
    }
    // Moves forward
    else if(Controller1.ButtonR2.pressing())
    {
      leftDriveMotor.spin(forward,100,pct);
      rightDriveMotor.spin(forward,100,pct);
    }
    //Moves Backwards
    else if(Controller1.ButtonL2.pressing())
    {
      leftDriveMotor.spin(reverse,100,pct);
      rightDriveMotor.spin(reverse,100,pct);
    }
    //robot stops
    else
    {
      leftDriveMotor.stop();
      rightDriveMotor.stop();
    }
    
    if (Controller1.ButtonY.pressing()){
      ptoLeftMotor.spinFor(reverse,0.75,rev,false);
      ptoRightMotor.spinFor(reverse,0.75,rev);
      wait(1,sec);
      ptoLeftMotor.spinFor(reverse,0.25,rev,false);
      ptoRightMotor.spinFor(reverse,0.25,rev);
    } else if(Controller1.ButtonLeft.pressing()){
      ptoRightMotor.spinFor(reverse,0.6,rev,false);
      ptoLeftMotor.spinFor(reverse,0.6,rev,false);
    }
    double rot = pickupMotor.position(deg);
    if(Controller2.ButtonR1.pressing()){
      pickupMotor.spin(forward);
    }else if(Controller2.ButtonL1.pressing()){
      pickupMotor.spin(reverse);
    }else{
      pickupMotor.stop();
    }
  }
}
  

