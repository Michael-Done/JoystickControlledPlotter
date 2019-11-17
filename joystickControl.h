/*  void joystickControl : moves plotter according to joystick gyro tilts
    Parameters:
       None.
*/
#include "constants.h" //constant values file
#include "sensitivity.h" //sensitivity value generator
#include "movement.h" //includes setSpeed


void joystickControl(int sensitivity_Val)
{
    int xSpeed= 0; //will remain at 0 if the gyros are within the dead zone
    int ySpeed = 0;

    if (abs(getGyroDegrees(X_GYRO))>X_GYRO_LIMIT)
        xSpeed=(getGyroDegrees(X_GYRO) - X_GYRO_LIMIT)*sensitivity_Val/100;

    if (abs(getGyroDegrees(Y_GYRO))>Y_GYRO_LIMIT)
        ySpeed=(getGyroDegrees(Y_GYRO) - Y_GYRO_LIMIT)*sensitivity_Val/100;


    setSpeed(xSpeed,ySpeed);
    wait1Msec(50);
}
