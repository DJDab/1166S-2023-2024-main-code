using namespace vex;

extern brain Brain;

// VEXcode devices
extern smartdrive Drivetrain;
extern controller Controller1;
extern motor_group MotorGroup4;
extern motor_group MotorGroup8;
extern controller Controller2;
extern motor leftDriveMotor;
extern motor rightDriveMotor;
extern motor ptoRightMotor;
extern motor ptoLeftMotor;
extern digital_out ptoRightPh;
extern digital_out ptoLeftPh;
extern motor pickupMotor;
extern digital_out PoleTopper;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );