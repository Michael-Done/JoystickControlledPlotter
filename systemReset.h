#include "constants.h"
#include "Actuate.h"
void systemReset()
{
    motor[X_AXIS] = 0;
    motor[Y_AXIS] = 0;

    actuate(-1, 0);

    nMotorEncoder[X_AXIS] = 0;
    motor[X_AXIS] = 25;
    while(SensorValue[COLOR_SENSOR] != (int)colorRed && nMotorEncoder[X_AXIS] < X_LIMIT)
    {}
    motor[X_AXIS] = 0;

    nMotorEncoder[Y_AXIS] = 0;
    motor[Y_AXIS] = -25;
    while(SensorValue[COLOR_SENSOR] != (int)colorBlack && nMotorEncoder[Y_AXIS] < Y_LIMIT)
    {}
    motor[Y_AXIS] = 0;

    //resetGyro(X_GYRO);
    //resetGyro(Y_GYRO);
}
