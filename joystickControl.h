/*  void joystickControl : moves plotter according to joystick gyro tilts
    Parameters:
       None.
*/
#include "constants.h" //constant values file
#include "Sensitivity.h" //sensitivity value generator 
#include "movement.h" //includes setSpeed

void joystickControl()
{
    int xSpeed= 0; //will remain at 0 if the gyros are within the dead zone
    int ySpeed = 0;

    if (abs(getGyroDegrees(X_GYRO))>5)
        xSpeed=getGyroDegrees(X_GYRO)*setSensitivity;
    if (abs(getGyroDegrees(Y_GYRO))>5)
        ySpeed=getGyroDegrees(Y_GYRO)*setSensitivity;
   
    setSpeed(xSpeed,ySpeed);
}