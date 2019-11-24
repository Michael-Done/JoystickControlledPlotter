#include "constants.h"

/*  void setSpeed : sets the speed of the x and y axes and account for the maximum and minumum encoder values
    Parameters:
        int targetXSpeed             : the target x speed (0 - 100)
        int targetYSpeed             : the target y speed (0 - 100)
*/
void setSpeed(int targetXSpeed, int targetYSpeed){
    if(targetXSpeed > 0 && nMotorEncoder[X_AXIS] > X_LIMIT)
        targetXSpeed = 0;
    else if(targetXSpeed < 0 && nMotorEncoder[X_AXIS] < 0)
        targetXSpeed = 0;

    if(targetYSpeed > 0 && nMotorEncoder[Y_AXIS] > Y_LIMIT)
        targetYSpeed = 0;
    else if(targetYSpeed < 0 && nMotorEncoder[Y_AXIS] < 0)
        targetYSpeed = 0;

    motor[X_AXIS] = targetXSpeed;
    motor[Y_AXIS] = targetYSpeed;
}

/*  void moveTo : will move the drawing head to a specified x and y position
    Parameters:
        int x                        : the target x value (in encoder ticks)
        int y                        : the target y value (in encoder ticks)
        int speed                    : the speed the drawing head will move at (0 - 100)
        bool stopAtEnd               : true will make the drawin head stop once the target is reached
*/
void moveTo(int x, int y, int speed, bool stopAtEnd) {
    x = max(min(x, X_LIMIT), 0);
    y = max(min(y, Y_LIMIT), 0);
    while(abs(nMotorEncoder[X_AXIS]-x) > MOVE_TO_TOL || abs(nMotorEncoder[Y_AXIS]-y) > MOVE_TO_TOL){
        int xSpeed = 0;
        int ySpeed = 0;
        float dist = sqrt(pow(x-nMotorEncoder[X_AXIS], 2) + pow(y-nMotorEncoder[Y_AXIS], 2));
        if(dist > 0.1){
        	xSpeed = speed*((x-nMotorEncoder[X_AXIS]*1.0)/dist);
        	ySpeed = speed*((y-nMotorEncoder[Y_AXIS]*1.0)/dist);
        }
        setSpeed(xSpeed, ySpeed);
    }
    if(stopAtEnd)
    	setSpeed(0, 0);
}
