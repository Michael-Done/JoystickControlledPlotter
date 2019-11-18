#include "constants.h" //constant values file
#include "sensitivity.h" //sensitivity value generator
#include "movement.h" //includes setSpeed

/*  void joystickControl : moves plotter according to joystick gyro tilts
    Parameters:
        int sensitivity_Val              : the sensitivity value (0 - 100)
*/
void joystickControl(int sensitivity_Val)
{
    int xSpeed = 0; //will remain at 0 if the gyros are within the dead zone
    int ySpeed = 0;
    int xGyro = getGyroDegrees(X_GYRO);
    int yGyro = getGyroDegrees(Y_GYRO);
    if(sqrt(pow(xGyro,2) + pow(yGyro, 2)) > INNER_GYRO_LIMIT)
    {
        float magnitude = (((min(OUTER_GYRO_LIMIT, sqrt(pow(xGyro,2) + pow(yGyro, 2)))) / OUTER_GYRO_LIMIT) - INNER_GYRO_LIMIT/OUTER_GYRO_LIMIT*100) * OUTER_GYRO_LIMIT/INNER_GYRO_LIMIT * sensitivity_Val/100;
        xSpeed=magnitude*cos(arctan(xGyro,yGyro));
        ySpeed=magnitude*sin(arctan(xGyro,yGyro));
    }

    setSpeed(xSpeed,ySpeed);
    wait1Msec(50);
}
