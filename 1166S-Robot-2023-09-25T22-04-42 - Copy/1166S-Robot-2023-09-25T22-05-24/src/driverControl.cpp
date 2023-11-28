#include "vex.h"
#include "driverControl.h"

void driverControl(){

  ptoRightMotor.setVelocity(100,percent);
  ptoLeftMotor.setVelocity(100, percent);
  ptoRightMotor.setPosition(180,degrees);
  ptoLeftMotor.setPosition(180,degrees);
  int ct = 0;
  ptoRightMotor.setStopping(hold);
  ptoLeftMotor.setStopping(hold);
  while(1){
    // cata attached
    if(Controller1.ButtonA.pressing()){

      if(ct == 0){
        ptoRightMotor.spinToPosition(90,degrees,100, rpm,false);
        ptoLeftMotor.spinToPosition(90,degrees,100, rpm);
        
        ptoPh.set(false);
        ct++;
      }
     

    }
    else    //wheels attached
    if(Controller1.ButtonB.pressing()){
      ct = 0 ;
      ptoPh.set(true);

      
      
      
    }






    if(Controller2.ButtonR2.pressing()){
      MotorGroup4.spin(forward);
    }else if(Controller2.ButtonL2.pressing()){
      MotorGroup4.spin(reverse);
    }else{
      MotorGroup4.stop();
    }

    if(Controller1.ButtonUp.pressing()){
      ptoRightMotor.spin(forward);
      ptoLeftMotor.spin(forward);
    }
    else
     if(Controller1.ButtonDown.pressing()&& ct > 0){
      ptoRightMotor.spinFor(reverse,90,deg,100,rpm,false);
      ptoLeftMotor.spinFor(reverse,90,deg,100,rpm);
    }else
    if(Controller1.ButtonDown.pressing()&& ct == 0){
      ptoRightMotor.spin(reverse);
      ptoLeftMotor.spin(reverse);
    }else
    {
      ptoRightMotor.stop();
      ptoLeftMotor.stop();
    }


    double turnPct = Controller1.Axis1.position();
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
  }
}
  

