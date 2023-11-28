#include "vex.h"

void autonRight(){
  pickupMotor.setVelocity(100,percent);
  pickupMotor.setMaxTorque(100,percent);
  pickupMotor.spinFor(reverse,0.4,rev);
}