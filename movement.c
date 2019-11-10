/*  void setSpeed : sets the speed of the x and y axes and account for the maximum and minumum encoder values
    Parameters:
        int targetXSpeed    : the target x speed (0 - 100)
        int targetYSpeed    : the target y speed (0 - 100)
        const int X_LIMIT   : the encoder limit for the x-axis
        const int Y_LIMIT   : the encoder limit for the y-axis
*/
void setSpeed(int targetXSpeed, int targetYSpeed, const int X_LIMIT, const int Y_LIMIT){
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
        int x               : the target x value (in encoder ticks)
        int y               : the target y value (in encoder ticks)
        int speed           : the speed the drawing head will move at (0 - 100)
        const int X_LIMIT   : the encoder limit for the x-axis
        const int Y_LIMIT   : the encoder limit for the y-axis
        const int TOL       : the encoder tolerance within which the movement will be considered successull
*/
void moveTo(int x, int y, int speed, const int X_LIMIT, const int Y_LIMIT, const int TOL) {
    while(abs(nMotorEncoder[X_AXIS]-x) > TOL) && abs(nMotorEncoder[Y_AXIS]-y) > TOL)){
        int dist = sqrt(pow(nMotorEncoder[X_AXIS]-x, 2) + pow(nMotorEncoder[Y_AXIS]-y 2));
        int xSpeed = speed*((nMotorEncoder[X_AXIS]-x)/dist);
        int ySpeed = speed*((nMotorEncoder[Y_AXIS]-y)/dist);
        setSpeed(xSpeed, ySpeed, X_LIMIT, Y_LIMIT);
    }
}