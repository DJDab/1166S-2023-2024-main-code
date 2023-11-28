using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor_group MotorGroup4;
extern motor_group MotorGroup8;
extern controller Controller2;
extern motor leftDriveMotor;
extern motor rightDriveMotor;
extern motor ptoRightMotor;
extern motor ptoLeftMotor;
extern digital_out ptoPh;
extern motor pickupMotor;
extern inertial InertialSens;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );