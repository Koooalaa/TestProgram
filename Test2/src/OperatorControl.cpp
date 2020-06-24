#include "vex.h"
#include "OperatorControl.h"

using namespace vex;

void joyStickControl(){
frontLeft.spin(fwd, Controller1.Axis3.position(), pct);
backLeft.spin(fwd, Controller1.Axis3.position(), pct);
frontRight.spin(fwd, Controller1.Axis2.position(), pct);
backRight.spin(fwd, Controller1.Axis2.position(), pct);

}

void intakeControl(){
  if(Controller1.ButtonR1.pressing()){
    intakeRight.spin(fwd, 100, pct);
    intakeLeft.spin(fwd, 100, pct);
  }
  else if(Controller1.ButtonR2.pressing()){
    intakeRight.spin(fwd, -100, pct);
    intakeLeft.spin(fwd, -100, pct);
  }
  else{
    intakeRight.stop(brake);
    intakeLeft.stop(brake);
  }
}