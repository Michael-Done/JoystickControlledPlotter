#include "constants.h"
/*  void setSpeed : sets the speed of the x and y axes and account for the maximum and minumum encoder values
    Parameters:
        int targetXSpeed             : the target x speed (0 - 100)
        int targetYSpeed             : the target y speed (0 - 100)
        const struct constants *CON  : structure containing all constants specific to the physical robot
*/
void setSpeed(int targetXSpeed, int targetYSpeed){
    if(targetXSpeed > 0 && nMotorEncoder[X_AXIS] >= X_LIMIT)
        targetXSpeed = 0;
    else if(targetXSpeed < 0 && nMotorEncoder[X_AXIS] <= 0)
        targetXSpeed = 0;

    if(targetYSpeed > 0 && nMotorEncoder[Y_AXIS] >= Y_LIMIT)
        targetYSpeed = 0;
    else if(targetYSpeed < 0 && nMotorEncoder[Y_AXIS] <= 0)
        targetYSpeed = 0;

    motor[X_AXIS] = targetXSpeed;
    motor[y_AXIS] = targetYSpeed;
}

/*  void moveTo : will move the drawing head to a specified x and y position
    Parameters:
        int x                        : the target x value (in encoder ticks)
        int y                        : the target y value (in encoder ticks)
        int speed                    : the speed the drawing head will move at (0 - 100)
*/
void moveTo(int x, int y, int speed) {
    while(abs(nMotorEncoder[X_AXIS]-x) > MOVE_TO_TOL && abs(nMotorEncoder[Y_AXIS]-y) > MOVE_TO_TOL)){
        int dist = sqrt(pow(nMotorEncoder[X_AXIS]-x, 2) + pow(nMotorEncoder[Y_AXIS]-y 2));
        int xSpeed = speed*((nMotorEncoder[X_AXIS]-x)/dist);
        int ySpeed = speed*((nMotorEncoder[Y_AXIS]-y)/dist);
        setSpeed(xSpeed, ySpeed, X_LIMIT, Y_LIMIT);
    }
}

/*  void actuate: actuates the drawing head to be in the "drawing" or "not drawing" position
    Parameters:
        bool dir                     : specifies whether or not the drawing utensil should be raised (false) or lowered (true)
*/
void actuate(bool dir){
    // TO DO
}
