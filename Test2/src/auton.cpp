#include "auton.h"
#include "vex.h"

using namespace vex;

/* Motors will keep going forever*/
/*Encoder = a thing inside the motor that sees how many times it spins*/
void moveForwardSimple(int speed){
  frontLeft.spin(fwd, speed, pct);
  backLeft.spin(fwd, speed, pct);
  frontRight.spin(fwd, speed, pct);
  backRight.spin(fwd, speed, pct);
} 

void moveForwardWalk(int speed, double distanceIN){
  double wheelDiameter = 3.25;
  double circumference = 3.14 * wheelDiameter;
  double degreesToRotate = ((360 * distanceIN) / circumference);

  frontLeft.rotateFor(fwd, degreesToRotate, rotationUnits::deg, speed, velocityUnits::pct, false); /*Blocking feature = false, false = don't block the motor. If it was true then the motors would not spin together*/
  backLeft.rotateFor(fwd, degreesToRotate, rotationUnits::deg, speed, velocityUnits::pct, false);
  frontRight.rotateFor(fwd, degreesToRotate, rotationUnits::deg, speed, velocityUnits::pct, false);
  backRight.rotateFor(fwd, degreesToRotate, rotationUnits::deg, speed, velocityUnits::pct);
}

void turnRight(int speed, double distanceIN){
  double wheelDiameter = 3.25;
  double circumference = 3.14 * wheelDiameter;
  double degreesToRotate = ((360 * distanceIN) / circumference);

  frontLeft.rotateFor(90, degrees);
  backLeft.rotateFor(90, degrees);
  frontRight.rotateFor(90, degrees);
  backRight.rotateFor(90, degrees);
} 

void turnLeft(int speed, double distanceIN){
  double wheelDiameter = 3.25;
  double circumference = 3.14 * wheelDiameter;
  double degreesToRotate = ((360 * distanceIN) / circumference);

  frontLeft.rotateFor(90, degrees);
  backLeft.rotateFor(90, degrees);
  frontRight.rotateFor(90, degrees);
  backRight.rotateFor(90, degrees);
} 